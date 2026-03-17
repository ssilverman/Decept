// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

#include <cstdint>
#include <optional>
#include <string_view>

#include <decept/Hash.h>

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct TestData {
  decept::Hash::Algorithm algo;
  std::string_view secret;
  int timeStep;
  size_t digits;
  int64_t time;
  uint32_t code;
};
