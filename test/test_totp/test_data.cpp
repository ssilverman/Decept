// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// hmac_data.cpp contains the NIST HMACVS data.
// This file is part of the Decept library.

// C++ includes
#include <array>
#include <cstddef>

#include "defs.h"

extern const TestData kData[]{
    // https://datatracker.ietf.org/doc/html/rfc6238#appendix-B
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        59,
        94287082,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        59,
        46119246,
    },
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        1111111109,
        7081804,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        1111111109,
        68084774,
    },
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        1111111111,
        14050471,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        1111111111,
        67062674,
    },
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        1234567890,
        89005924,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        1234567890,
        91819424,
    },
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        2000000000,
        69279037,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        2000000000,
        90698825,
    },
    {
        decept::Hash::kSHA1,
        "12345678901234567890"sv,
        30,
        8,
        20000000000,
        65353130,
    },
    {
        decept::Hash::kSHA256,
        "12345678901234567890123456789012"sv,
        30,
        8,
        20000000000,
        77737706,
    },
};

extern const size_t kData_size = std::size(kData);
