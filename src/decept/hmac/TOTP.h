// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TOTP.h defines a class for calculating a TOTP using SHA-256, as defined by
// NIST FIPS PUB 198-1, "The Keyed-Hash Message Authentication Code (HMAC)"
// This file is part of the Decept library.

// See also:
// * [TOTP: Time-Based One-Time Password Algorithm (RFC 6238)](https://datatracker.ietf.org/doc/html/rfc6238)
// * [HOTP: An HMAC-Based One-Time Password Algorithm (RFC 4226)](https://datatracker.ietf.org/doc/html/rfc4226)
// * [The Base16, Base32, and Base64 Data Encodings (RFC 4648)](https://datatracker.ietf.org/doc/html/rfc4648)
//
// About the "otpauth" URI scheme:
// * [URI string format](https://docs.yubico.com/yesdk/users-manual/application-oath/uri-string-format.html)
// * [Usage specification of the otpauth URI format for TOTP and HOTP token generators](https://www.ietf.org/archive/id/draft-linuxgemini-otpauth-uri-00.html)
// * [Key Uri Format](https://github.com/google/google-authenticator/wiki/Key-Uri-Format)

#pragma once

// C++ includes
#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <string_view>

#include "decept/Hash.h"
#include "decept/hmac/HMAC.h"

namespace decept {
namespace hmac {

class TOTP {
 public:
  // Creates a new TOTP using the given algorithm.
  TOTP(Hash::Algorithm hash);

  // Zeros out all the memory.
  ~TOTP() noexcept;

  // Initializes the TOTP with the given base32-encoded key. This calls
  // the other initKey() after decoding.
  //
  // This returns true if the encoded string is valid and initializtion was
  // successful. This returns false elsewise.
  bool initKey(std::string_view base32);

  // Initializes the TOTP with the given key. This copies the key. This returns
  // true if initialization was successful and false elsewise.
  //
  // This only needs to be called once for each new key.
  bool initKey(const void* key, size_t keySize);

  // Calculates and returns an n-digit base-10 value. This will return
  // std::nullopt if there was an error during calculation. This will return
  // zero if the number of digits is zero or if the time step is non-positive.
  std::optional<uint32_t> calculate(int64_t time, int timeStep, size_t digits);

 private:
  HMAC hmac_;

  alignas(32) uint8_t temp_[std::max(Hash::kMaxOutputSize, size_t{19})];
      // Accommodates the offset read
};

}  // namespace hmac
}  // namespace decept
