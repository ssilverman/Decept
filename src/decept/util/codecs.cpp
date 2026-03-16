// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// codecs.cpp implements the decoder and encoder sutilities.
// This file is part of the Decept library.

#include "decept/util/codecs.h"

#include <cstdint>
#include <string_view>
#include <vector>

namespace decept {
namespace util {

std::optional<std::vector<uint8_t>> decodeBase32(const std::string_view s) {
  // Ensure total size is a multiple of 8
  if ((s.size() % 8) != 0) {
    return std::nullopt;
  }

  // Before allocating a vector, double-check the encoding
  size_t valueCount = 0;
  size_t padCount = 0;

  // Decodes one character. This is called after verifying the values.
  const auto decode = [](const char c) {
    if (('2' <= c) && (c <= '7')) {
      return static_cast<uint8_t>(c - '2' + 26);
    } else {  // Must be a letter
      return static_cast<uint8_t>((c | 0x20) - 'a');
    }
  };

  for (size_t i = 0; i < s.size(); ++i) {
    const char c = s[i];
    if ((('a' <= (c | 0x20)) && ((c | 0x20) <= 'z')) ||
        (('2' <= c) && (c <= '7'))) {
      if (padCount != 0) {
        return std::nullopt;
      }
      ++valueCount;
    } else if (c == '=') {
      ++padCount;
      if (padCount > 6) {
        return std::nullopt;
      }
    } else {
      return std::nullopt;
    }
  }

  // Check values before the padding
  switch (padCount) {
    case 6:
      // Final 8 bits in input
      if (((valueCount % 8) != 2) ||
          ((decode(s[valueCount - 1]) & 0x03) != 0)) {
        return std::nullopt;
      }
      break;

    case 4:
      // Final 16 bits in input
      if (((valueCount % 8) != 4) ||
          ((decode(s[valueCount - 1]) & 0x0f) != 0)) {
        return std::nullopt;
      }
      break;

    case 3:
      // Final 24 bits in input
      if (((valueCount % 8) != 5) ||
          ((decode(s[valueCount - 1]) & 0x01) != 0)) {
        return std::nullopt;
      }
      break;

    case 1:
      // Final 32 bits in input
      if (((valueCount % 8) != 7) ||
          ((decode(s[valueCount - 1]) & 0x07) != 0)) {
        return std::nullopt;
      }
      break;

    case 0:
      break;

    default:
      return std::nullopt;
  }

  // Now we can decode knowing it's correct

  const size_t outSize = (s.size() + 7)/8 * 5;
  std::vector<uint8_t> v;
  v.reserve(outSize);

  // Process in groups of 8
  size_t base = 0;
  for (size_t i = valueCount/8; i-- > 0; base += 8) {
    uint64_t block = 0;
    for (size_t j = 0; j < 8; ++j) {
      block = (block << 5) | decode(s[base + j]);
    }

    v.push_back(static_cast<uint8_t>(block >> 32));
    v.push_back(static_cast<uint8_t>(block >> 24));
    v.push_back(static_cast<uint8_t>(block >> 16));
    v.push_back(static_cast<uint8_t>(block >>  8));
    v.push_back(static_cast<uint8_t>(block >>  0));
  }

  valueCount %= 8;

  uint32_t block;
  switch (valueCount) {
    case 0:  // Nothing left
      break;

    case 2:  // 8-bit value
      block = static_cast<uint32_t>((decode(s[base + 0]) << 3) |
                                    (decode(s[base + 1]) >> 2));
      v.push_back(static_cast<uint8_t>(block));
      break;

    case 4:  // 16-bit value
      block = static_cast<uint32_t>((decode(s[base + 0]) << 11) |
                                    (decode(s[base + 1]) <<  6) |
                                    (decode(s[base + 2]) <<  1) |
                                    (decode(s[base + 3]) >>  4));
      v.push_back(static_cast<uint8_t>(block >> 8));
      v.push_back(static_cast<uint8_t>(block >> 0));
      break;

    case 5:  // 24-bit value
      block = static_cast<uint32_t>((decode(s[base + 0]) << 19) |
                                    (decode(s[base + 1]) << 14) |
                                    (decode(s[base + 2]) <<  9) |
                                    (decode(s[base + 3]) <<  4) |
                                    (decode(s[base + 4]) >>  1));
      v.push_back(static_cast<uint8_t>(block >> 16));
      v.push_back(static_cast<uint8_t>(block >>  8));
      v.push_back(static_cast<uint8_t>(block >>  0));
      break;

    case 7:  // 32-bit value
      block = static_cast<uint32_t>((decode(s[base + 0]) << 27) |
                                    (decode(s[base + 1]) << 22) |
                                    (decode(s[base + 2]) << 17) |
                                    (decode(s[base + 3]) << 12) |
                                    (decode(s[base + 4]) <<  7) |
                                    (decode(s[base + 5]) <<  2) |
                                    (decode(s[base + 6]) >>  3));
      v.push_back(static_cast<uint8_t>(block >> 24));
      v.push_back(static_cast<uint8_t>(block >> 16));
      v.push_back(static_cast<uint8_t>(block >>  8));
      v.push_back(static_cast<uint8_t>(block >>  0));
      break;
  }

  return v;
}

static constexpr char kEncodingTable[32]{
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
    'Y', 'Z', '2', '3', '4', '5', '6', '7',
};

std::string encodeBase32(const void* const data, const size_t size) {
  const auto b = reinterpret_cast<const uint8_t*>(data);
  const size_t outSize = (size + 4)/5 * 8;
  std::string s;
  s.reserve(outSize);

  // Encode every group of 5 bytes
  size_t base = 0;
  for (size_t i = size/5; i-- > 0; base += 5) {
    const uint64_t block = (uint64_t{b[base + 0]} << 32) |
                           ((uint32_t{b[base + 1]} << 24) |
                            (uint32_t{b[base + 2]} << 16) |
                            (uint32_t{b[base + 3]} <<  8) |
                            (uint32_t{b[base + 4]} <<  0));
    s.push_back(kEncodingTable[(block >> 35) & 0x1f]);
    s.push_back(kEncodingTable[(block >> 30) & 0x1f]);
    s.push_back(kEncodingTable[(block >> 25) & 0x1f]);
    s.push_back(kEncodingTable[(block >> 20) & 0x1f]);
    s.push_back(kEncodingTable[(block >> 15) & 0x1f]);
    s.push_back(kEncodingTable[(block >> 10) & 0x1f]);
    s.push_back(kEncodingTable[(block >>  5) & 0x1f]);
    s.push_back(kEncodingTable[(block >>  0) & 0x1f]);
  }

  const size_t valueCount = size % 5;
  switch (valueCount) {
    case 0:
      break;

    case 1:
      // [xxxxx yyy] [00]
      s.push_back(kEncodingTable[(b[base] >> 3) & 0x1f]);
      s.push_back(kEncodingTable[(b[base] & 0x07) << 2]);
      s.append("======", 6);
      break;

    case 2:
      // [xxxxx yyy] [yy zzzzz w] [0000]
      s.push_back(kEncodingTable[(b[base] >> 3) & 0x1f]);
      s.push_back(kEncodingTable[((b[base + 0] & 0x07) << 2) |
                                 ((b[base + 1] >> 6) & 0x03)]);
      s.push_back(kEncodingTable[(b[base + 1] >> 1) & 0x1f]);
      s.push_back(kEncodingTable[(b[base + 1] & 0x01) << 4]);
      s.append("====", 4);
      break;

    case 3:
      // [aaaaa bbb] [bb ccccc d] [dddd eeee] [0]
      s.push_back(kEncodingTable[(b[base] >> 3) & 0x1f]);
      s.push_back(kEncodingTable[((b[base] & 0x07) << 2) |
                                 ((b[base + 1] >> 6) & 0x03)]);
      s.push_back(kEncodingTable[(b[base + 1] >> 1) & 0x1f]);
      s.push_back(kEncodingTable[((b[base + 1] & 0x01) << 4) |
                                 ((b[base + 2] >> 4) & 0x0f)]);
      s.push_back(kEncodingTable[(b[base + 2] & 0x0f) << 1]);
      s.append("===", 3);
      break;

    case 4:
      // [aaaaa bbb] [bb ccccc d] [dddd eeee] [e fffff gg] [000]
      s.push_back(kEncodingTable[(b[base] >> 3) & 0x1f]);
      s.push_back(kEncodingTable[((b[base] & 0x07) << 2) |
                                 ((b[base + 1] >> 6) & 0x03)]);
      s.push_back(kEncodingTable[(b[base + 1] >> 1) & 0x1f]);
      s.push_back(kEncodingTable[((b[base + 1] & 0x01) << 4) |
                                 ((b[base + 2] >> 4) & 0x0f)]);
      s.push_back(kEncodingTable[((b[base + 2] & 0x0f) << 1) |
                                 ((b[base + 3] >> 7) & 0x01)]);
      s.push_back(kEncodingTable[(b[base + 3] >> 2) & 0x1f]);
      s.push_back(kEncodingTable[(b[base + 3] & 0x03) << 3]);
      s.push_back('=');
      break;
  }

  return s;
}

}  // namespace util
}  // namespace decept
