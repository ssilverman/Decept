// SPDX-FileCopyrightText: (c) 2023 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

#include <string_view>

#include <decept/Cipher.h>

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct ECBTestData {
  const char key[decept::Cipher::kAES128.blockSize + 1];
  std::string_view in;
  std::string_view out;
};

struct CBCTestData {
  const char key[decept::Cipher::kAES128.blockSize + 1];
  const char iv[decept::Cipher::kAES128.blockSize + 1];
  std::string_view in;
  std::string_view out;
};
