// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the core DCP functions.
// This file is part of the Decept library.

#include <Arduino.h>
#include <decept/dcp/dcp.h>
#include <unity.h>

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
  decept::dcp::deinit();
}

// Post-test teardown. This is run after every test.
void tearDown() {
  decept::dcp::deinit();
}

// Tests that the feature becomes active from inactive.
static void test_activate() {
  TEST_ASSERT_FALSE_MESSAGE(decept::dcp::isStarted(), "Expected not started");
  decept::dcp::init();
  TEST_ASSERT_TRUE_MESSAGE(decept::dcp::isStarted(), "Expected started");
}

// Tests that the feature becomes inactive from active.
static void test_deactivate() {
  decept::dcp::init();
  TEST_ASSERT_TRUE_MESSAGE(decept::dcp::isStarted(), "Expected started");
  decept::dcp::deinit();
  TEST_ASSERT_FALSE_MESSAGE(decept::dcp::isStarted(), "Expected not started");
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

  UNITY_BEGIN();
  RUN_TEST(test_activate);
  RUN_TEST(test_deactivate);
  UNITY_END();
}

// Main program loop.
void loop() {
}
