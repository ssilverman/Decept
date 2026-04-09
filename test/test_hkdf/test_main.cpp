// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the HKDF functionality.
// This file is part of the Decept library.

#include <algorithm>
#include <memory>
#include <string>

#include <Arduino.h>
#include <decept/hmac/HKDF.h>
#include <unity.h>

#include "defs.h"

extern const TestData kData[];
extern const size_t kData_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// Tests for the given algorithm and data.
static void test_hkdf() {
  for (size_t i = 0; i < kData_size; ++i) {
    const auto m = "Data " + std::to_string(i);
    const TestData& d = kData[i];
    decept::hmac::HKDF hkdf{d.algo};
    const auto output =
        std::make_unique<uint8_t[]>(std::max(d.algo.outputSize, d.okm.size()));

    // We might not want to extract
    if (d.ikm.has_value()) {
      TEST_ASSERT_TRUE_MESSAGE(
          hkdf.extract(d.ikm.value().data(), d.ikm.value().size(),
                       d.salt.has_value() ? d.salt.value().data() : nullptr,
                       d.salt.has_value() ? d.salt.value().size() : 0,
                       output.get()),
          m.c_str());
      TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.prk.data(), output.get(),
                                            d.algo.outputSize, m.c_str());
    }

    TEST_ASSERT_TRUE_MESSAGE(
        hkdf.expand(d.prk.data(), d.prk.size(),
                    d.iv.data(), d.iv.size(),
                    d.info.data(), d.info.size(),
                    output.get(), d.okm.size()),
        m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.okm.data(), output.get(),
                                          d.okm.size(), m.c_str());
  }
}

// Main program setup.
void setup() {
  Serial.begin(115200);
  while (!Serial && (millis() < 4000)) {
    // Wait for Serial
  }

  // NOTE!!! Wait for >2 secs
  // if board doesn't support software reset via Serial.DTR/RTS
  delay(2000);

  if (CrashReport) {
    Serial.println(CrashReport);
  }

  decept::dcp::init();

  UNITY_BEGIN();
  RUN_TEST(test_hkdf);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
