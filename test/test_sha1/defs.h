// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

#include <string_view>

#include <decept/Hash.h>

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct TestData {
  std::string_view in;
  const char out[decept::Hash::kSHA1.size + 1];
};
