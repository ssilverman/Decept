// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the TOTP.
// This file is part of the Decept library.

#include <string>

#include <Arduino.h>
#include <decept/hmac/TOTP.h>
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
static void test_totp() {
  for (size_t i = 0; i < kData_size; ++i) {
    const auto m = "Data " + std::to_string(i);

    const TestData& d = kData[i];

    decept::hmac::TOTP totp{d.algo};

    TEST_ASSERT_TRUE_MESSAGE(totp.initKey(d.secret.data(), d.secret.size()),
                             m.c_str());

    const auto code = totp.calculate(d.time, d.timeStep, d.digits);
    TEST_ASSERT_TRUE_MESSAGE(code.has_value(), m.c_str());
    TEST_ASSERT_EQUAL_MESSAGE(d.code, code.value(), m.c_str());
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
  RUN_TEST(test_totp);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
