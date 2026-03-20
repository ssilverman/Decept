// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the base32 codec.
// This file is part of the Decept library.

#include <string>

#include <Arduino.h>
#include <decept/util/codecs.h>
#include <unity.h>

#include "defs.h"

extern const DecodeTestData kDecodeData[];
extern const size_t kDecodeData_size;
extern const EncodeTestData kEncodeData[];
extern const size_t kEncodeData_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// Tests decoding.
static void test_decode() {
  for (size_t i = 0; i < kDecodeData_size; ++i) {
    const auto m = "Data " + std::to_string(i);
    const DecodeTestData& d = kDecodeData[i];

    const auto v = decept::util::decodeBase32(d.encoded);
    TEST_ASSERT_EQUAL_MESSAGE(d.decoded.has_value(), v.has_value(), m.c_str());
    if (!v.has_value()) {
      continue;
    }

    TEST_ASSERT_EQUAL_MESSAGE(d.decoded->size(), v->size(), m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        std::equal(v->begin(), v->end(), d.decoded->data()), m.c_str());
  }
}

// Tests encoding.
static void test_encode() {
  for (size_t i = 0; i < kEncodeData_size; ++i) {
    const auto m = "Data " + std::to_string(i);
    const EncodeTestData& d = kEncodeData[i];

    std::string enc = decept::util::encodeBase32(d.data.data(), d.data.size());

    TEST_ASSERT_EQUAL_MESSAGE(d.encoded.size(), enc.size(), m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        std::equal(enc.begin(), enc.end(), d.encoded.begin()), m.c_str());
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

  UNITY_BEGIN();
  RUN_TEST(test_decode);
  RUN_TEST(test_encode);
  UNITY_END();
}

// Main program loop.
void loop() {
}
