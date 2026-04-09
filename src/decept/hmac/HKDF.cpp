// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HKDF.cpp implements HKDF.
// This file is part of the Decept library.

#include "decept/hmac/HKDF.h"

#include <array>
#include <cstring>
#include <limits>

#include "decept/util/codecs.h"
#include "decept/util/dcache.h"

namespace decept {
namespace hmac {

HKDF::HKDF(Hash::Algorithm algo)
    : hmac_{algo} {}

HKDF::~HKDF() {
  util::reallyClear(temp_, sizeof(temp_));
}

bool HKDF::extract(const void* const ikm, const size_t ikmSize,
                   const void* const salt, const size_t saltSize,
                   uint8_t* const prk) {
  const size_t hashSize = hmac_.outputSize();

  if (salt != nullptr) {
    if (!hmac_.initKey(salt, saltSize)) {
      return false;
    }
  } else {
    std::fill_n(&temp_[0], hashSize, 0);
    if (!hmac_.initKey(temp_, hashSize)) {
      return false;
    }
  }

  return hmac_.calculate(ikm, ikmSize, prk, hashSize);
}

bool HKDF::expand(const void* const prk, const size_t prkSize,
                  const void* const iv, const size_t ivSize,
                  const void* const info, const size_t infoSize,
                  uint8_t* const out, const size_t outSize) {
  const size_t hashSize = hmac_.outputSize();

  if (prkSize < hashSize || outSize > 255 * hashSize) {
    return false;
  }

  if (outSize == 0) {
    return true;
  }

  if (!hmac_.initKey(prk, prkSize)) {
    return false;
  }

  uint8_t* pOut = out;
  size_t outSizeRem = outSize;

  // Counter
  alignas(alignof(uint32_t)) uint8_t ctr = 1;

  // Do first iteration with the IV or empty T(0)
  hmac_.init();
  if (ivSize != 0) {
    if (!hmac_.update(iv, ivSize)) {
      return false;
    }
  }
  if (!hmac_.update(info, infoSize) ||
      !hmac_.update(&ctr, 1) ||
      !hmac_.finalize(temp_, hashSize)) {
    return false;
  }

  const size_t toCopy = std::min(outSizeRem, hashSize);
  (void)std::copy_n(&temp_[0], toCopy, &pOut[0]);
  pOut       += toCopy;
  outSizeRem -= toCopy;

  const size_t count = outSizeRem / hashSize;
  for (size_t i = 0; i < count; ++i) {
    ++ctr;
    hmac_.init();
    if (!hmac_.update(temp_, hashSize) ||
        !hmac_.update(info, infoSize) ||
        !hmac_.update(&ctr, 1) ||
        !hmac_.finalize(temp_, hashSize)) {
      return false;
    }

    (void)std::copy_n(&temp_[0], hashSize, &pOut[0]);
    pOut       += hashSize;
    outSizeRem -= hashSize;
  }

  if (outSizeRem != 0) {
    ++ctr;
    hmac_.init();
    if (!hmac_.update(temp_, hashSize) ||
        !hmac_.update(info, infoSize) ||
        !hmac_.update(&ctr, 1) ||
        !hmac_.finalize(pOut, outSizeRem)) {
      return false;
    }
  }

  return true;
}

}  // namespace hmac
}  // namespace decept
