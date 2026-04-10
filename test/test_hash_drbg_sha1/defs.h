// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// defs.h defines test structures and data.
// This file is part of the Decept library.

#pragma once

// C++ includes
#include <string_view>

// Enable use of embedded nulls via the 'sv' literal operator
using namespace std::string_view_literals;

struct NoReseedTestData {
  std::string_view entropyInput;
  std::string_view nonce;
  std::string_view personalizationString;
  std::string_view addlInput1;
  std::string_view addlInput2;
  std::string_view returnedBits;
};

struct PRFalseTestData {
  std::string_view entropyInput;
  std::string_view nonce;
  std::string_view personalizationString;
  std::string_view entropyInputReseed;
  std::string_view addlInputReseed;
  std::string_view addlInput1;
  std::string_view addlInput2;
  std::string_view returnedBits;
};

struct PRTrueTestData {
  std::string_view entropyInput;
  std::string_view nonce;
  std::string_view personalizationString;
  std::string_view addlInput1;
  std::string_view entropyInput1;
  std::string_view addlInput2;
  std::string_view entropyInput2;
  std::string_view returnedBits;
};
