// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HMACDRBG.cpp implements HMACDRBG.
// This file is part of the Decept library.

#include "decept/drbg/HMACDRBG.h"

// C++ includes
#include <cstring>

#include "decept/util/dcache.h"

namespace decept {
namespace drbg {

HMACDRBG::HMACDRBG(const Hash::Algorithm algo)
    : hmac_(algo) {}

HMACDRBG::~HMACDRBG() {
  util::reallyClear(v_, sizeof(v_));
  util::reallyClear(key_, sizeof(key_));
  reseedCounter_ = 0;
}

static inline bool checkEntropySize(const size_t size) {
  // Max: 2^35 bits
  if constexpr (sizeof(size_t) <= 4) {
    return true;
  } else {
    return (size <= (uint64_t{1} << 32));
  }
}

static inline bool checkInputSize(const size_t size) {
  // Max: 2^35 bits
  if constexpr (sizeof(size_t) <= 4) {
    return true;
  } else {
    return (size <= (uint64_t{1} << 32));
  }
}

static inline bool checkOutputSize(size_t size) {
  // Max: 2^19 bits
  return (size <= (1u << 16));
}

bool HMACDRBG::init(const void* const entropy, const size_t entropySize,
                    const void* const nonce, const size_t nonceSize,
                    const void* const in, const size_t inSize) {
  if (((entropy == nullptr) && (entropySize > 0)) ||
      ((nonce == nullptr) && (nonceSize > 0)) ||
      ((in == nullptr) && (inSize > 0))) {
    return false;
  }
  if (!checkEntropySize(entropySize) || !checkInputSize(inSize)) {
    return false;
  }

  std::memset(key_, 0, hmac_.outputSize());
  std::memset(v_, 1, hmac_.outputSize());

  const std::vector<std::pair<const void*, size_t>> inputs{
      {entropy, entropySize},
      {nonce, nonceSize},
      {in, inSize},
  };

  hmac_.initKey(key_, hmac_.outputSize());
  if (!update(inputs, entropySize + nonceSize + inSize)) {
    return false;
  }

  reseedCounter_ = 1;

  return true;
}

bool HMACDRBG::reseed(const void* const entropy, const size_t entropySize,
                      const void* const in, const size_t inSize) {
  if (((entropy == nullptr) && (entropySize > 0)) ||
      ((in == nullptr) && (inSize > 0))) {
    return false;
  }
  if (!checkEntropySize(entropySize) || !checkInputSize(inSize)) {
    return false;
  }

  const std::vector<std::pair<const void*, size_t>> inputs{
      {entropy, entropySize},
      {in, inSize},
  };
  if (!update(inputs, entropySize + inSize)) {
    return false;
  }

  reseedCounter_ = 1;
  return true;
}

bool HMACDRBG::isReseedRequired() {
  // Max: 2^48
  return (reseedCounter_ > (uint64_t{1} << 48));
}

bool HMACDRBG::generate(const void* const in, const size_t inSize,
                        uint8_t* out, size_t outSize) {
  if (((in == nullptr) && (inSize > 0)) ||
      ((out == nullptr) && (outSize > 0))) {
    return false;
  }
  if (!checkInputSize(inSize) || !checkOutputSize(outSize)) {
    return false;
  }
  if (isReseedRequired()) {
    return false;
  }

  const std::vector<std::pair<const void*, size_t>> inputs{
      {in, inSize},
  };

  // Check for non-empty input
  if (inSize > 0) {
    if (!update(inputs, inSize)) {
      return false;
    }
  }

  while (outSize > 0) {
    if (!hmac_.calculate(v_, hmac_.outputSize(),
                         v_, hmac_.outputSize())) {
      return false;
    }
    size_t size = std::min(hmac_.outputSize(), outSize);
    std::memcpy(out, v_, size);
    outSize -= size;
    out     += size;
  }

  if (!update(inputs, inSize)) {
    return false;
  }

  ++reseedCounter_;

  return true;
}

// Update function, Section 10.1.2.2.
bool HMACDRBG::update(
    const std::vector<std::pair<const void*, size_t>>& inputs,
    const size_t totalInputSize) {

  for (uint8_t i = 0; i < 2; ++i) {
    hmac_.init();
    if (!(hmac_.update(v_, hmac_.outputSize()) &&
          hmac_.update(&i, 1))) {
      return false;
    }

    if (totalInputSize > 0) {
      for (const auto& p : inputs) {
        if (!hmac_.update(p.first, p.second)) {
          return false;
        }
      }
    }

    if (!hmac_.finalize(key_, hmac_.outputSize())) {
      return false;
    }
    hmac_.initKey(key_, hmac_.outputSize());
    if (!hmac_.calculate(v_, hmac_.outputSize(),
                         v_, hmac_.outputSize())) {
      return false;
    }

    // Check for empty input
    if (totalInputSize == 0) {
      return true;
    }
  }

  return true;
}

}  // namespace drbg
}  // namespace decept
