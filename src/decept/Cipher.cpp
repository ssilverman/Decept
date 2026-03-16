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

Cipher::~Cipher() {
  util::reallyClear(&ctx_, sizeof(ctx_));
}

void Cipher::init(dcp::Channels channel) {
  ctx_ = {};
  ctx_.channel = static_cast<size_t>(channel);
}

bool Cipher::setKey(const KeySlots slot, const void* const key) {
  // Initialize the context
  ctx_ = {};
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
    for (size_t i = 0; i < algo_.keySize/4; ++i) {
      const uint32_t k = static_cast<const uint32_t*>(key)[i];
      dcp::regs->KEYDATA = k;
    }
  } else {
    (void)std::memcpy(ctx_.keyData, key, algo_.keySize);
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

bool Cipher::crypt(const bool encryptNotDecrypt,
                   const void* const src, uint8_t* const dst, const size_t size,
                   const void* const iv) {
  if ((size == 0) || ((size % algo_.blockSize) != 0)) {
    return false;
  }
  if (iv != nullptr) {
    (void)std::memcpy(&ctx_.keyData[algo_.keySize], iv, algo_.ivSize);
  }

  while (true) {
    States s = tryCrypt(encryptNotDecrypt, src, dst, size, iv);
    if (s == States::kNotScheduled) {
      return false;
    } else if (s == States::kComplete) {
      return true;
    }
  }
}

States Cipher::tryCrypt(bool encryptNotDecrypt,
                        const void* const src, uint8_t* const dst,
                        const size_t size,
                        const void* const iv) {
  if (!ctx_.workScheduled) {
    // Reset the work packet
    ctx_.workPacket = {};

    if (!trySchedule(encryptNotDecrypt, (iv != nullptr), src, dst, size)) {
      return States::kContinue;
    }
  }

  ctx_.workScheduled = true;
  if (States s = dcp::isChannelComplete(ctx_.channel);
      (s != States::kComplete)) {
    return s;
  }

  ctx_.workScheduled = false;
  util::dcacheDelete(dst, size);

  return States::kComplete;
}

bool Cipher::trySchedule(const bool encryptNotDecrypt, const bool hasIV,
                         const void* const src, uint8_t* const dst,
                         const size_t size) {
  dcp::WorkPacket& workPacket = ctx_.workPacket;

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
