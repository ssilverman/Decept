// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HKDF.h defines a class for deriving key material.
// This file is part of the Decept library.

// Refs:
// * [HMAC-based Extract-and-Expand Key Derivation Function (HKDF) (RFC 5869)](https://datatracker.ietf.org/doc/html/rfc5869)

#pragma once

// C++ includes
#include <cstddef>
#include <cstdint>

#include "decept/Hash.h"
#include "decept/hmac/HMAC.h"

namespace decept {
namespace hmac {

class HKDF {
 public:
  // Creates a new HKDF using the given algorithm.
  HKDF(Hash::Algorithm hash);

  // Zeros out all the memory.
  ~HKDF();

  // Performs the Extract step and returns whether successful. prk is expected
  // to be at least outputSize() bytes. The salt is optional: NULL for no salt
  // and non-NULL with any length, elsewise.
  bool extract(const void* ikm, size_t ikmSize,
               const void* salt, size_t saltSize,
               uint8_t* prk);

  // Performs the Expand step and returns whether successful. Note that RFC 5869
  // doesn't use an IV, but "NIST SP 800-108r1-upd1" does, so we are allowing
  // that here.
  //
  // Checks:
  // * PRK size >= outputSize()
  // * Length <= 255 * outputSize()
  bool expand(const void* prk, size_t prkSize,
              const void* iv, size_t ivSize,
              const void* info, size_t infoSize,
              uint8_t* out, size_t outSize);

 private:
  static constexpr size_t kMaxOutputSize =
      std::max_element(Hash::kAlgorithms.cbegin(), Hash::kAlgorithms.cend(),
                       [](const auto& a, const auto& b) {
                         return (a.outputSize < b.outputSize);
                       })
          ->outputSize;

  HMAC hmac_;

  alignas(32) uint8_t temp_[kMaxOutputSize];
};

}  // namespace hmac
}  // namespace decept
