// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HMACDRBG.h defines an HMAC_DRBG, as defined by NIST SP 800-90A Rev. 1,
// "Recommendation for Random Number Generation Using Deterministic RBGs"
// This file is part of the Decept library.

#pragma once

// C++ includes
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <utility>

#include "decept/Hash.h"
#include "decept/hmac/HMAC.h"

namespace decept {
namespace drbg {

class HMACDRBG {
 public:
  // Creates a new HMACDRBG using the given algorithm.
  HMACDRBG(Hash::Algorithm hash);

  // Clears the internal state.
  ~HMACDRBG() noexcept;

  // Initializes the DRBG. This will return false if:
  // 1. The entropy size is too small or too large,
  // 2. The input size is too large, or
  // 3. There was a hash calculation error.
  bool init(const void* entropy, size_t entropySize,
            const void* nonce, size_t nonceSize,
            const void* in, size_t inSize);

  // Reseeds the DRBG. This will return false if:
  // 1. The entropy size is too small or too large,
  // 2. The input size is too large,
  // 3. There was a hash calculation error, or
  // 4. The DRBG was not initialized.
  //
  // For prediction resistance, call this before every call to generate
  // random data.
  bool reseed(const void* entropy, size_t entropySize,
              const void* in, size_t inSize);

  // Checks if a reseed is required.
  bool isReseedRequired();

  // Generates random data. This will return false if:
  // 1. The input or output sizes are too large,
  // 2. A reseed is required,
  // 3. There was a hash calculation error, or
  // 4. The DRBG was not initialized.
  //
  // The output array may be modified, even if this returns false.
  bool generate(const void* in, size_t inSize, uint8_t* out, size_t outSize);

 private:
  // Performs the HMAC_DRBG_Update() calculation. The total input size is given.
  //
  // This first initializes the HMAC object with the current key and then leaves
  // it initialized with the calculated key.
  bool update(const std::pair<const void*, size_t>* inputs, size_t inputsSize,
              size_t totalInputSize);

  hmac::HMAC hmac_;

  bool initialized_ = false;

  alignas(32) uint8_t v_[Hash::kMaxOutputSize]{0};
  alignas(32) uint8_t key_[Hash::kMaxOutputSize]{0};
  uint64_t reseedCounter_ = 0;  // Initialization starts at 1
};

}  // namespace drbg
}  // namespace decept
