// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HashDRBG.h defines a Hash_DRBG, as defined by NIST SP 800-90A Rev. 1,
// "Recommendation for Random Number Generation Using Deterministic RBGs"
// This file is part of the Decept library.

#pragma once

// C++ includes
#include <algorithm>
#include <cstddef>
#include <cstdint>

#include "decept/Hash.h"

namespace decept {
namespace drbg {

class HashDRBG {
 public:
  // Creates a new HMACDRBG using the given algorithm.
  HashDRBG(Hash::Algorithm hash);

  // Clears the internal state.
  ~HashDRBG();

  // Initializes the DRBG. This will return false if:
  // 1. entropy is nullptr and entropySize > 0,
  // 2. nonce is nullptr and nonceSize > 0,
  // 3. input is nullptr and inputSize > 0,
  // 4. The entropy size is too small or too large,
  // 5. The input size is too large, or
  // 6. There was a hash calculation error.
  bool init(const void* entropy, size_t entropySize,
            const void* nonce, size_t nonceSize,
            const void* in, size_t inSize);

  // Reseeds the DRBG. This will return false if:
  // 1. entropy is nullptr and entropySize > 0,
  // 2. input is nullptr and inputSize > 0,
  // 3. The entropy size is too small or too large,
  // 4. The input size is too large, or
  // 5. There was a hash calculation error.
  //
  // For prediction resistance, call this before every call to generate
  // random data.
  bool reseed(const void* entropy, size_t entropySize,
              const void* in, size_t inSize);

  // Checks if a reseed is required.
  bool isReseedRequired();

  // Generates random data. This will return false if:
  // 1. input is nullptr and inputSize > 0,
  // 2. output is nullptr and outputSize > 0,
  // 3. The input or output sizes are too large, or
  // 4. A reseed is required, or
  // 5. There was a hash calculation error.
  //
  // The output array may be modified, even if this returns false.
  bool generate(const void* in, size_t inSize, uint8_t* out, size_t outSize);

 private:
  static constexpr size_t kMaxSeedLen =
      std::max_element(
          Hash::kAlgorithms.cbegin(), Hash::kAlgorithms.cend(),
          [](const auto& a, const auto& b) { return (a.seedLen < b.seedLen); })
          ->seedLen;  // Table 2, Section 10.1
  static constexpr size_t kMaxOutputSize =
      std::max_element(Hash::kAlgorithms.cbegin(), Hash::kAlgorithms.cend(),
                       [](const auto& a, const auto& b) {
                         return (a.outputSize < b.outputSize);
                       })
          ->outputSize;

  Hash hash_;

  uint8_t v_[kMaxSeedLen]{0};
  uint8_t c_[kMaxSeedLen]{0};
  uint8_t temp_[std::max(kMaxSeedLen, kMaxOutputSize)]{0};
  uint64_t reseedCounter_ = 0;  // Initialization starts at 1
};

}  // namespace drbg
}  // namespace decept
