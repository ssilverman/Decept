// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Cipher.cpp implements the Cipher class.
// This file is part of the Decept library.

#include "decept/Cipher.h"

// C++ includes
#include <cstring>

#include "decept/regs/DCP.h"
#include "decept/util/dcache.h"

namespace decept {

Cipher::Cipher(Algorithm algo)
    : algo_(algo) {}

Cipher::~Cipher() noexcept {
  util::reallyClear(&ctx_, sizeof(ctx_));
}

void Cipher::init(dcp::Channels channel) {
  // Initialize the context and also restore setKey()-set values
  const auto keySlot = ctx_.keySlot;
  const auto keyData = ctx_.keyData;

  ctx_ = {};
  ctx_.channel = static_cast<size_t>(channel);
  ctx_.swapCfg = dcp::swaps::kNoSwap;
  ctx_.keySlot = keySlot;
  ctx_.keyData = keyData;

  switch (algo_.algo) {
    case Algorithms::kAES128:
      ctx_.control1 = regs::DCP_PACKET2_CIPHER_SELECT(
          regs::kDCP_PACKET2_CIPHER_SELECT_AES128);
      break;
  }
}

bool Cipher::setKey(const KeySlots slot, const void* const key) {
  ctx_.keySlot = slot;

  if ((slot == KeySlots::kOTPKey) || (slot == KeySlots::kOTPUniqueKey)) {
    util::reallyClear(ctx_.keyData.data(), sizeof(ctx_.keyData));

    // For AES OTP and unique key, check and return read from fuses status
    return (regs::DCP_STAT_OTP_KEY_READY == 1);
  }

  // Avoid UB because 'key' may be unaligned, so use memcpy to temporarily
  // store it in ctx_.keyData
  (void)std::memcpy(ctx_.keyData.data(), key, algo_.keySize);

  if (slot != KeySlots::kPayload) {
    // dcp_aes_set_sram_based_key()

    regs::DCP->KEY = regs::DCP_KEY_INDEX(static_cast<uint32_t>(slot)) |
                     regs::DCP_KEY_SUBWORD(0);

    // Move the key by 32-bit words
    for (size_t i = 0; i < algo_.keySize/4; ++i) {
      const uint32_t k = ctx_.keyData[i];
      regs::DCP->KEYDATA = k;
    }

    // Clear our internal key data because it was only temporary
    util::reallyClear(ctx_.keyData.data(), sizeof(ctx_.keyData));
  }

  return true;
}

bool Cipher::encryptECB(const void* const src, uint8_t* const dst,
                        const size_t size) {
  return crypt(true, src, dst, size, nullptr);
}

bool Cipher::encryptCBC(const void* const src, uint8_t* const dst,
                        const size_t size, const void* const iv) {
  if (iv == nullptr) {
    return false;
  }
  return crypt(true, src, dst, size, iv);
}

bool Cipher::decryptECB(const void* const src, uint8_t* const dst,
                        const size_t size) {
  return crypt(false, src, dst, size, nullptr);
}

bool Cipher::decryptCBC(const void* const src, uint8_t* const dst,
                        const size_t size, const void* const iv) {
  if (iv == nullptr) {
    return false;
  }
  return crypt(false, src, dst, size, iv);
}

bool Cipher::crypt(const bool encryptNotDecrypt,
                   const void* const src, uint8_t* const dst, const size_t size,
                   const void* const iv) {
  if ((size == 0) || ((size % algo_.blockSize) != 0)) {
    return false;
  }
  if (iv != nullptr) {
    (void)std::memcpy(&ctx_.keyData[algo_.keySize/4], iv, algo_.ivSize);
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

  workPacket.control0 = regs::DCP_PACKET1_CIPHER_INIT(hasIV)                |
                        regs::DCP_PACKET1_CIPHER_ENCRYPT(encryptNotDecrypt) |
                        regs::DCP_PACKET1_ENABLE_CIPHER(1)                  |
                        regs::DCP_PACKET1_DECR_SEMAPHORE(1)                 |
                        regs::DCP_PACKET1_SWAP(ctx_.swapCfg);
  if (hasIV) {
    workPacket.control1 =
        ctx_.control1 |
        regs::DCP_PACKET2_CIPHER_MODE(regs::kDCP_PACKET2_CIPHER_MODE_CBC);
    if (ctx_.keySlot != KeySlots::kPayload) {
      workPacket.payloadPtr =
          reinterpret_cast<uint32_t>(&ctx_.keyData[algo_.keySize/4]);
    }
  } else {
    workPacket.control1 =
        ctx_.control1 |
        regs::DCP_PACKET2_CIPHER_MODE(regs::kDCP_PACKET2_CIPHER_MODE_ECB);
  }

  workPacket.srcAddr = reinterpret_cast<uint32_t>(src);
  workPacket.dstAddr = reinterpret_cast<uint32_t>(dst);
  workPacket.bufSize = static_cast<uint32_t>(size);

  if (ctx_.keySlot == KeySlots::kOTPKey) {
    workPacket.control0 |= regs::DCP_PACKET1_OTP_KEY(1);
    workPacket.control1 |=
        regs::DCP_PACKET2_KEY_SELECT(regs::kDCP_PACKET2_KEY_SELECT_OTP_KEY);
  } else if (ctx_.keySlot == KeySlots::kOTPUniqueKey) {
    workPacket.control0 |= regs::DCP_PACKET1_OTP_KEY(1);
    workPacket.control1 |=
        regs::DCP_PACKET2_KEY_SELECT(regs::kDCP_PACKET2_KEY_SELECT_UNIQUE_KEY);
  } else if (ctx_.keySlot == KeySlots::kPayload) {
    workPacket.payloadPtr = reinterpret_cast<uint32_t>(ctx_.keyData.data());
    workPacket.control0  |= regs::DCP_PACKET1_PAYLOAD_KEY(1);
  } else {
    workPacket.control1 |=
        regs::DCP_PACKET2_KEY_SELECT(static_cast<uint32_t>(ctx_.keySlot));
  }

  util::dcacheFlush(ctx_.keyData.data(), sizeof(ctx_.keyData));
  util::dcacheFlush(src, size);
  util::dcacheFlush(dst, size);
  return dcp::scheduleWork(ctx_.channel, workPacket);
}

}  // namespace decept
