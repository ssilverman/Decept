// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the HMAC functionality.
// This file is part of the Decept library.

#include <Arduino.h>
#include <decept/hmac/HMAC.h>
#include <unity.h>

#include <memory>
#include <string>

#include "defs.h"

extern const TestData kSHA256_data[];
extern const size_t kSHA256_data_size;
extern const TestData kSHA1_data[];
extern const size_t kSHA1_data_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// https://csrc.nist.gov/Projects/cryptographic-algorithm-validation-program/Message-Authentication

// Tests for the given algorithm and data.
template <const decept::Hash::Algorithm& A>
static void test_hmac(const TestData* const data, const size_t dataSize) {
  decept::hmac::HMAC hmac{A};
  const size_t hashSize = hmac.outputSize();

  const auto actual = std::make_unique<uint8_t[]>(hashSize);

  for (size_t i = 0; i < dataSize; ++i) {
    const auto m = "Data " + std::to_string(i);

    const TestData& d = data[i];
    TEST_ASSERT_MESSAGE(d.mac.length() <= hashSize, m.c_str());

    TEST_ASSERT_TRUE(hmac.initKey(d.key.data(), d.key.length()));

    // All-at-once HMAC
    TEST_ASSERT_TRUE_MESSAGE(
        hmac.calculate(d.msg.data(), d.msg.length(), actual.get(), hashSize),
        m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.mac.data(), actual.get(),
                                          d.mac.length(), m.c_str());

    // Running HMAC
    hmac.init();
    TEST_ASSERT_TRUE_MESSAGE(hmac.update(d.msg.data(), d.msg.length()),
                             m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(hmac.finalize(actual.get(), d.mac.length()),
                             m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.mac.data(), actual.get(),
                                          d.mac.length(), m.c_str());
  }
}

// Tests SHA-256 version.
static void test_hmac_sha256() {
  test_hmac<decept::Hash::kSHA256>(kSHA256_data, kSHA256_data_size);
}

// Tests SHA-1 version.
static void test_hmac_sha1() {
  test_hmac<decept::Hash::kSHA1>(kSHA1_data, kSHA1_data_size);
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
  RUN_TEST(test_hmac_sha256);
  RUN_TEST(test_hmac_sha1);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
