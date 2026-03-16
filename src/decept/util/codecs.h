// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// codecs.h defines some useful decoder and encoder utilities.
// This file is part of the Decept library.

// See also:
// * [The Base16, Base32, and Base64 Data Encodings (RFC 4648)](https://datatracker.ietf.org/doc/html/rfc4648)

#pragma once

#include <cstdint>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace decept {
namespace util {

// Decodes a base32-encoded string.
std::optional<std::vector<uint8_t>> decodeBase32(std::string_view s);

// Encodes a base32-encoded string. This encodes in upper-case.
std::string encodeBase32(const void* data, size_t size);

}  // namespace util
}  // namespace decept
