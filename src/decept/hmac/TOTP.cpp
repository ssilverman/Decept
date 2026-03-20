// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TOTP.cpp implements TOTP.
// This file is part of the Decept library.

#include "decept/hmac/TOTP.h"

#include <array>
#include <cstring>
#include <limits>
#include <memory>

#include "decept/util/codecs.h"

namespace decept {
namespace hmac {

static constexpr size_t kMaxDigits = std::numeric_limits<uint32_t>::digits10;

// Creates an array of powers of 10.
template <size_t N>
static constexpr auto make_powers_of_ten() {
  std::array<uint32_t, N> result{1};
  for (size_t i = 1; i < N; ++i) {
    result[i] = 10 * result[i - 1];
  }
  return result;
}

// Table of powers of 10.
static constexpr auto kPowersOfTen = make_powers_of_ten<kMaxDigits + 1>();

TOTP::TOTP(Hash::Algorithm algo)
    : hmac_{algo} {}

bool TOTP::initKey(std::string_view base32) {
  const auto v = util::decodeBase32(base32);
  if (!v.has_value()) {
    return false;
  }

  return initKey(v->data(), v->size());
}

bool TOTP::initKey(const void* const key, const size_t keySize) {
  return hmac_.initKey(key, keySize);
}

std::optional<uint32_t> TOTP::calculate(const int64_t time,
                                        const int timeStep,
                                        const size_t digits) {
  if ((digits == 0) || (timeStep <= 0)) {
    return 0;
  }

  // Time as 8 bytes
  int64_t t = time / timeStep;
  if constexpr (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
    t = __builtin_bswap64(t);
  }
  uint8_t msg[8];
  (void)std::memcpy(msg, &t, 8);

  const size_t outSize = hmac_.outputSize();

  const auto hash = std::make_unique<uint8_t[]>(outSize);  // Avoid VLA
  if (!hmac_.calculate(msg, sizeof(msg), hash.get(), outSize)) {
    return std::nullopt;
  }

  const auto offset = static_cast<size_t>(hash[outSize - 1] & 0x0f);
  uint32_t binary;
  (void)std::memcpy(&binary, &hash[offset], 4);
  if constexpr (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) {
    binary = __builtin_bswap32(binary);
  }
  binary &= 0x7fffffff;

  if (digits > kMaxDigits) {
    return binary;
  }
  return binary % kPowersOfTen[digits];
}

}  // namespace hmac
}  // namespace decept
