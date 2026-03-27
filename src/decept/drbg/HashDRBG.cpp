// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HashDRBG.cpp implements HashDRBG.
// This file is part of the Decept library.

#include "decept/drbg/HashDRBG.h"

// C++ includes
#include <array>
#include <cstring>
#include <utility>

#include "decept/util/dcache.h"

namespace decept {
namespace drbg {

static bool hash_df(Hash& hash,
                    const std::pair<const void*, size_t>* inputs,
                    size_t inputsSize,
                    uint8_t* out, size_t outSize);

static bool hashgen(Hash& hash, const uint8_t* v, size_t vSize,
                    uint8_t* out, size_t outSize, uint8_t* temp);

HashDRBG::HashDRBG(const Hash::Algorithm algo)
    : hash_(algo) {}

HashDRBG::~HashDRBG() {
  util::reallyClear(v_, sizeof(v_));
  util::reallyClear(c_, sizeof(c_));
  util::reallyClear(temp_, sizeof(temp_));
  reseedCounter_ = 0;
}

static inline bool checkEntropySize(const size_t size) {
  // Min: security strength (SHA-256 output size, 256 bits)
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

static inline bool checkOutputSize(const size_t size) {
  // Max: 2^19 bits
  return (size <= 1u << 16);
}

bool HashDRBG::init(const void* const entropy, const size_t entropySize,
                    const void* const nonce, const size_t nonceSize,
                    const void* const input, const size_t inputSize) {
  if (((entropy == nullptr) && (entropySize > 0)) ||
      ((nonce == nullptr) && (nonceSize > 0)) ||
      ((input == nullptr) && (inputSize > 0))) {
    return false;
  }
  if (!checkEntropySize(entropySize) || !checkInputSize(inputSize)) {
    return false;
  }

  std::pair<const void*, size_t> inputs[]{
      {entropy, entropySize},
      {nonce, nonceSize},
      {input, inputSize},
  };
  if (!hash_df(hash_, inputs, std::size(inputs), v_, hash_.algo().seedLen)) {
    return false;
  }

  const uint8_t digit = 0;
  inputs[0].first = &digit;
  inputs[0].second = 1;
  inputs[1].first = v_;
  inputs[1].second = hash_.algo().seedLen;

  if (!hash_df(hash_, inputs, 2, c_, hash_.algo().seedLen)) {
    return false;
  }

  reseedCounter_ = 1;
  return true;
}

bool HashDRBG::reseed(const void* const entropy, const size_t entropySize,
                      const void* const in, const size_t inSize) {
  if (((entropy == nullptr) && (entropySize > 0)) ||
      ((in == nullptr) && (inSize > 0))) {
    return false;
  }
  if (!checkEntropySize(entropySize) || !checkInputSize(inSize)) {
    return false;
  }

  uint8_t digit = 1;
  std::memcpy(temp_, v_, hash_.algo().seedLen);
  std::pair<const void*, size_t> inputs[]{
      {&digit, 1},
      {temp_, hash_.algo().seedLen},
      {entropy, entropySize},
      {in, inSize},
  };
  if (!hash_df(hash_, inputs, std::size(inputs), v_, hash_.algo().seedLen)) {
    return false;
  }
  inputs[1].first = v_;

  digit = 0;
  if (!hash_df(hash_, inputs, 2, c_, hash_.algo().seedLen)) {
    return false;
  }

  reseedCounter_ = 1;
  return true;
}

// b = a + b (mod 2^(8*length(b)))
static void addTo(const uint8_t* const a, const size_t aSize,
                  uint8_t* const b, const size_t bSize) {
  size_t aIndex = aSize;
  size_t bIndex = bSize;
  size_t count = std::min(aSize, bSize);

  for (size_t i = count; i-- > 0; ) {
    uint16_t sum = uint16_t{a[--aIndex]} + uint16_t{b[--bIndex]};
    b[bIndex] = sum;
    if (sum > 0xff) {  // Carry
      for (size_t j = bIndex; j-- > 0; ) {
        b[j]++;
        if (b[j] != 0) {
          break;
        }
      }
    }
  }
}

bool HashDRBG::isReseedRequired() {
  // Max: 2^48
  return (reseedCounter_ > (uint64_t{1} << 48));
}

bool HashDRBG::generate(const void* const in, const size_t inSize,
                        uint8_t* const out, const size_t outSize) {
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

  if ((inSize > 0) && (in != nullptr)) {
    const uint8_t two = 2;

    hash_.init();
    if (!(hash_.update(&two, 1) &&
          hash_.update(v_, hash_.algo().seedLen) &&
          hash_.update(in, inSize) &&
          hash_.finalize(temp_, hash_.outputSize()))) {
      return false;
    }
    addTo(temp_, hash_.outputSize(), v_, hash_.algo().seedLen);
  }

  if ((out != nullptr) && (outSize > 0)) {
    if (!hashgen(hash_, v_, hash_.algo().seedLen, out, outSize, temp_)) {
      return false;
    }
  }

  const uint8_t three = 3;
  hash_.init();
  if (!(hash_.update(&three, 1) &&
        hash_.update(v_, hash_.algo().seedLen) &&
        hash_.finalize(temp_, hash_.outputSize()))) {
    return false;
  }
  addTo(temp_, hash_.outputSize(), v_, hash_.algo().seedLen);
  addTo(c_, hash_.algo().seedLen, v_, hash_.algo().seedLen);

  uint64_t rc = reseedCounter_;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  rc = __builtin_bswap64(rc);
#endif  // __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  addTo(reinterpret_cast<uint8_t*>(&rc), 8, v_, hash_.algo().seedLen);

  ++reseedCounter_;

  return true;
}

// Derivation function, Section 10.3.1.
static bool hash_df(Hash& hash,
                    const std::pair<const void*, size_t>* const inputs,
                    const size_t inputsSize,
                    uint8_t* out, size_t outSize) {
  if (outSize > 255 * hash.outputSize()) {
    return false;
  }

  uint32_t numBits = outSize * 8;
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  numBits = __builtin_bswap32(numBits);
#endif  // __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  uint8_t counter = 1;

  const size_t hashOutSize = hash.outputSize();

  // Process full blocks
  for (size_t i = outSize / hashOutSize; i-- > 0; ) {
    hash.init();
    if (!(hash.update(&counter, 1) && hash.update(&numBits, 4))) {
      return false;
    }
    for (size_t j = 0; j < inputsSize; ++j) {
      const auto& p = inputs[j];
      if (!hash.update(p.first, p.second)) {
        return false;
      }
    }

    if (!hash.finalize(out, hashOutSize)) {
      return false;
    }
    out     += hashOutSize;
    outSize -= hashOutSize;

    ++counter;
  }

  // Maybe process a partial block
  outSize %= hashOutSize;
  if (outSize != 0) {
    hash.init();
    if (!(hash.update(&counter, 1) && hash.update(&numBits, 4))) {
      return false;
    }
    for (size_t i = 0; i < inputsSize; ++i) {
      const auto& p = inputs[i];
      if (!hash.update(p.first, p.second)) {
        return false;
      }
    }

    if (!hash.finalize(out, outSize)) {
      return false;
    }
  }

  return true;
}

// Hashgen function, Section 10.1.1.4.
//
// 'temp' is memory having a size of at least vSize.
static bool hashgen(Hash& hash, const uint8_t* const v, const size_t vSize,
                    uint8_t* out, size_t outSize,
                    uint8_t* const temp) {
  std::memcpy(temp, v, vSize);

  const size_t hashOutSize = hash.outputSize();

  // Generate full blocks
  for (size_t i = outSize / hashOutSize; i-- > 0;) {
    if (!hash.hash(temp, vSize, out, hashOutSize)) {
      return false;
    }
    out     += hashOutSize;
    outSize -= hashOutSize;

    if (outSize != 0) {
      const uint8_t one = 1;
      addTo(&one, 1, temp, vSize);
    }
  }

  // Maybe generate a partial block
  outSize %= hashOutSize;
  if (outSize != 0) {
    if (!hash.hash(temp, vSize, out, outSize)) {
      return false;
    }
  }

  return true;
}

}  // namespace drbg
}  // namespace decept
