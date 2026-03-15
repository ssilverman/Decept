// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Cipher.cpp implements the Cipher class.
// This file is part of the Decept library.

#include "decept/Cipher.h"

// C++ includes
#include <cstring>

#include "decept/dcp/regs.h"
#include "decept/util/dcache.h"

namespace decept {

Cipher::Cipher(Algorithm algo)
    : algo_(algo) {}

void Cipher::init() {
  (void)std::memset(&ctx_, 0, sizeof(ctx_));
}

bool Cipher::setKey(const KeySlots slot, const void* const key) {
  // Initialize the context
  std::memset(&ctx_, 0, sizeof(ctx_));
  ctx_.keySlot = slot;

  if ((slot == KeySlots::kOTPKey) || (slot == KeySlots::kOTPUniqueKey)) {
    // For AES OTP and unique key, check and return read from fuses status
    return (dcp::regs->STAT & dcp::STAT_OTP_KEY_READY(true)) ==
           dcp::STAT_OTP_KEY_READY(true);
  }

  if (slot != KeySlots::kPayload) {
    // dcp_aes_set_sram_based_key()

    dcp::regs->KEY =
        dcp::KEY_INDEX(static_cast<uint32_t>(slot)) | dcp::KEY_SUBWORD(0);

    // Move the key by 32-bit words
    for (size_t i = 0; i < dcp::sizes::kAES128Key/4; ++i) {
      const uint32_t k = static_cast<const uint32_t*>(key)[i];
      dcp::regs->KEYDATA = k;
    }
  } else {
    (void)std::memcpy(ctx_.keyData, key, dcp::sizes::kAES128Key);
  }

  return true;
}

bool Cipher::encrypt(const void* const src, uint8_t* const dst,
                     const size_t size, const void* iv) {
  return crypt(true, src, dst, size, iv);
}

bool Cipher::decrypt(const void* const src, uint8_t* const dst,
                     const size_t size, const void* iv) {
  return crypt(false, src, dst, size, iv);
}

bool Cipher::crypt(bool encryptNotDecrypt,
                   const void* const src, uint8_t* const dst, const size_t size,
                   const void* const iv) {
  if ((size == 0) || ((size % algo_.blockSize) != 0)) {
    return false;
  }

  // Create an aligned work packet
  dcp::WorkPacket workPacket;

  if (iv != nullptr) {
    (void)std::memcpy(&ctx_.keyData[dcp::sizes::kAES128Key], iv,
                      dcp::sizes::kAES128IV);
  }

  while (!cryptNonBlocking(encryptNotDecrypt, (iv != nullptr), workPacket,
                           src, dst, size)) {
    // Wait until the task was scheduled
  }

  const bool retval = dcp::waitForChannelComplete(ctx_.channel);
  util::dcacheDelete(dst, size);
  return retval;
}

// Start some AES work and return whether the task was scheduled. The caller
// should retry until this returns true. The size must be a multiple of 16 and
// not zero.
//
// The payload must contain the key & IV in one array, with the IV following
// the key.
bool Cipher::cryptNonBlocking(const bool encryptNotDecrypt, const bool hasIV,
                              dcp::WorkPacket& workPacket,
                              const void* const src, uint8_t* const dst,
                              const size_t size) {
  workPacket.control0 =
      dcp::PACKET1_CIPHER_INIT(hasIV)                |
      dcp::PACKET1_CIPHER_ENCRYPT(encryptNotDecrypt) |
      dcp::PACKET1_ENABLE_CIPHER(true)               |
      dcp::PACKET1_DECR_SEMAPHORE(true)              |
      dcp::PACKET1_SWAP(ctx_.swapCfg);
  if (hasIV) {
    workPacket.control1 =
        dcp::PACKET2_CIPHER_MODE(dcp::kPACKET2_CIPHER_MODE_CBC);
    if (ctx_.keySlot != KeySlots::kPayload) {
      workPacket.payloadPtr = reinterpret_cast<uint32_t>(
          &(reinterpret_cast<const uint32_t*>(ctx_.keyData))[4]);
    }
  } else {
    workPacket.control1 =
        dcp::PACKET2_CIPHER_MODE(dcp::kPACKET2_CIPHER_MODE_ECB);
  }

  workPacket.srcAddr = reinterpret_cast<uint32_t>(src);
  workPacket.dstAddr = reinterpret_cast<uint32_t>(dst);
  workPacket.bufSize = static_cast<uint32_t>(size);

  if (ctx_.keySlot == KeySlots::kOTPKey) {
    workPacket.control0 |= dcp::PACKET1_OTP_KEY(true);
    workPacket.control1 |=
        dcp::PACKET2_KEY_SELECT(dcp::kPACKET2_KEY_SELECT_OTP_KEY);
  } else if (ctx_.keySlot == KeySlots::kOTPUniqueKey) {
    workPacket.control0 |= dcp::PACKET1_OTP_KEY(true);
    workPacket.control1 |=
        dcp::PACKET2_KEY_SELECT(dcp::kPACKET2_KEY_SELECT_UNIQUE_KEY);
  } else if (ctx_.keySlot == KeySlots::kPayload) {
    workPacket.payloadPtr = reinterpret_cast<uint32_t>(ctx_.keyData);
    workPacket.control0  |= dcp::PACKET1_PAYLOAD_KEY(true);
    util::dcacheFlush(ctx_.keyData, sizeof(ctx_.keyData));
  } else {
    workPacket.control1 |=
        dcp::PACKET2_KEY_SELECT(static_cast<uint32_t>(ctx_.keySlot));
  }

  util::dcacheFlush(src, size);
  util::dcacheFlush(dst, size);
  return dcp::scheduleWork(ctx_.channel, workPacket);
}

}  // namespace decept
