// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Hash.cpp implements the Hash class.
// This file is part of the Decept library.

#include "decept/Hash.h"

#include <algorithm>
#include <cstring>

#include "decept/dcp/dcp.h"
#include "decept/dcp/regs.h"
#include "decept/util/dcache.h"

namespace decept {

// Digests for messages with zero size
namespace {

constexpr uint8_t kNullSHA1[]{
    0xda, 0x39, 0xa3, 0xee, 0x5e, 0x6b, 0x4b, 0x0d,
    0x32, 0x55, 0xbf, 0xef, 0x95, 0x60, 0x18, 0x90,
    0xaf, 0xd8, 0x07, 0x09,
};

constexpr uint8_t kNullSHA256[]{
    0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
    0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
    0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
    0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55,
};

}  // namespace

Hash::Hash(Hash::Algorithm algo)
    : algo_(algo) {}

Hash::~Hash() {
  util::reallyClear(&ctx_, sizeof(ctx_));
}

void Hash::init(dcp::Channels channel) {
  ctx_ = {};

  ctx_.channel = static_cast<size_t>(channel);

  // Set up values
  switch (algo_.algo) {
    case Algorithms::kSHA1:
      ctx_.control1 = dcp::PACKET2_HASH_SELECT(dcp::kCONTROL1_HASH_SELECT_SHA1);
      break;
    case Algorithms::kSHA256:
      ctx_.control1 =
          dcp::PACKET2_HASH_SELECT(dcp::kCONTROL1_HASH_SELECT_SHA256);
      break;
    case Algorithms::kCRC32:
      ctx_.control1 =
          dcp::PACKET2_HASH_SELECT(dcp::kCONTROL1_HASH_SELECT_CRC32);
      break;
  }
}

void Hash::setChannel(dcp::Channels channel) {
  ctx_.channel = static_cast<size_t>(channel);
}

bool Hash::update(const void* const msg, const size_t msgSize) {
  if (msgSize == 0) {
    return true;
  }

  if (ctx_.isStarted) {
    restoreRunningHashAsGoodAsNew();
  }

  const uint8_t* pIn = static_cast<const uint8_t*>(msg);
  size_t inSizeRem = msgSize;

  const size_t blockSize = this->blockSize();

  // First finish a remaining block
  if (ctx_.currBlockSize != 0) {
    const size_t take = std::min(blockSize - ctx_.currBlockSize, inSizeRem);

    (void)std::memcpy(&ctx_.block[ctx_.currBlockSize], pIn, take);
    ctx_.currBlockSize += take;
    ctx_.totalSize += take;
    if (ctx_.currBlockSize < blockSize) {
      return true;
    }

    while (true) {
      const States s = update(dcp::PACKET1_HASH_INIT(!ctx_.isStarted),
                              ctx_.block, blockSize);
      if (s == States::kNotScheduled) {
        util::reallyClear(&ctx_, sizeof(ctx_));
        return false;
      } else if (s == States::kComplete) {
        break;
      }
    }
    ctx_.isStarted = true;
    ctx_.currBlockSize = 0;

    pIn       += take;
    inSizeRem -= take;
  }

  // Do as much as we can all at once; process a multiple of the block size
  const size_t size = (inSizeRem / blockSize) * blockSize;
  if (size > 0) {
    while (true) {
      const States s =
          update(dcp::PACKET1_HASH_INIT(!ctx_.isStarted), pIn, size);
      if (s == States::kNotScheduled) {
        util::reallyClear(&ctx_, sizeof(ctx_));
        return false;
      } else if (s == States::kComplete) {
        break;
      }
    }
    ctx_.isStarted = true;

    pIn            += size;
    inSizeRem      -= size;
    ctx_.totalSize += size;
  }

  // Copy any remaining
  (void)std::memcpy(ctx_.block, pIn, inSizeRem);
  ctx_.currBlockSize = inSizeRem;
  ctx_.totalSize += inSizeRem;

  saveRunningHashFromTheCausticMist();

  return true;
}

bool Hash::finalize(uint8_t* const out, const size_t outSize) {
  bool retval = false;

  if (outSize != 0) {
    const size_t actualOutSize = std::min(outSize, algo_.outputSize);

    if (ctx_.totalSize == 0) {  // Empty input is handled specially
      if (algo_.algo == Algorithms::kSHA256) {
        (void)std::memcpy(out, kNullSHA256, actualOutSize);
      } else if (algo_.algo == Algorithms::kSHA1) {
        (void)std::memcpy(out, kNullSHA1, actualOutSize);
      } else if (algo_.algo == Algorithms::kCRC32) {
        (void)std::memset(out, 0, actualOutSize);
      }
      retval = true;
    } else {
      if (ctx_.isStarted) {
        restoreRunningHashAsGoodAsNew();
      }

      while (true) {
        States s = update(dcp::PACKET1_HASH_INIT(!ctx_.isStarted) |
                              dcp::PACKET1_HASH_TERM(true),
                          ctx_.block, ctx_.currBlockSize);
        if (s == States::kContinue) {
          continue;
        }

        if (s == States::kComplete) {
          // Account for desiring less output
          const size_t hashOffset = algo_.outputSize - actualOutSize;

          // Reverse and copy
          const auto hash = reinterpret_cast<uint8_t*>(ctx_.runningHash);
          for (size_t i = 0; i < actualOutSize; ++i) {
            out[i] = hash[actualOutSize - 1 - i + hashOffset];
          }
          retval = true;
        }
        break;
      }
    }
  } else {
    retval = true;
  }

  // Clear the memory and return
  util::reallyClear(&ctx_, sizeof(ctx_));
  return retval;
}

bool Hash::hash(const void* msg, size_t msgSize, uint8_t* out, size_t outSize,
                dcp::Channels channel) {
  init(channel);
  return update(msg, msgSize) && finalize(out, outSize);
}

States Hash::update(const uint32_t control0,
                    const void* const b, const size_t size) {
  if ((algo_.algo == Algorithms::kCRC32) && (size == 0)) {
    return States::kComplete;
  }

  if (!ctx_.workScheduled) {
    // Reset the work packet
    ctx_.workPacket = {};

    if (!trySchedule(control0, b, size)) {
      return States::kContinue;
    }
  }

  ctx_.workScheduled = true;
  if (States s = dcp::isChannelComplete(ctx_.channel);
      (s != States::kComplete)) {
    return s;
  }

  ctx_.workScheduled = false;
  util::dcacheDelete(ctx_.runningHash, sizeof(ctx_.runningHash));

  return States::kComplete;
}

bool Hash::trySchedule(const uint32_t control0,
                       const void* const b, const size_t size) {
  dcp::WorkPacket& workPacket = ctx_.workPacket;

  workPacket.control0 = control0                        |
                        dcp::PACKET1_SWAP(ctx_.swapCfg) |
                        dcp::PACKET1_ENABLE_HASH(true)  |
                        dcp::PACKET1_DECR_SEMAPHORE(true);
  workPacket.control1 = ctx_.control1;

  workPacket.srcAddr    = reinterpret_cast<uint32_t>(b);
  workPacket.dstAddr    = 0;
  workPacket.bufSize    = size;
  workPacket.payloadPtr = reinterpret_cast<uint32_t>(ctx_.runningHash);

  util::dcacheFlush(b, size);
  util::dcacheFlush(ctx_.runningHash, sizeof(ctx_.runningHash));
  return dcp::scheduleWork(ctx_.channel, workPacket);
}

// Saves the running hash from the context switching buffer into the
// given context.
void Hash::saveRunningHashFromTheCausticMist() {
  uint32_t* const src =
      &(reinterpret_cast<uint32_t*>(dcp::regs->CONTEXT))[43 - 13*ctx_.channel];
  util::dcacheDelete(src, sizeof(ctx_.runningHash));
  (void)std::memcpy(ctx_.runningHash, src, sizeof(ctx_.runningHash));
}

// Restores the running hash from the given context into the context
// switching buffer.
void Hash::restoreRunningHashAsGoodAsNew() {
  uint32_t* const dst =
      &(reinterpret_cast<uint32_t*>(dcp::regs->CONTEXT))[43 - 13*ctx_.channel];
  (void)std::memcpy(dst, ctx_.runningHash, sizeof(ctx_.runningHash));
  util::dcacheFlush(dst, sizeof(ctx_.runningHash));
}

}  // namespace decept
