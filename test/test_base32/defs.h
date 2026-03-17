// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

#include <optional>
#include <string_view>

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct DecodeTestData {
  std::string_view encoded;
  std::optional<std::string_view> decoded;
};

struct EncodeTestData {
  std::string_view data;
  std::string_view encoded;
};
