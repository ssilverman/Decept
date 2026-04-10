// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

// C++ includes
#include <cstddef>
#include <optional>
#include <string_view>

#include "decept/Hash.h"

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct TestData {
  decept::Hash::Algorithm algo;
  std::optional<std::string_view> ikm;  // std::nullopt for no Extract step
  std::optional<std::string_view> salt;
  std::string_view iv;
  std::string_view info;
  std::string_view prk;
  std::string_view okm;
};
