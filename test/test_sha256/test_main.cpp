// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the DCP SHA-256 functions.
// This file is part of the Decept library.

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <string>

#include <Arduino.h>
#include <decept/dcp/dcp.h>
#include <decept/Hash.h>
#include <unity.h>

#include "defs.h"

extern const TestData kShortMsg[];
extern const size_t kShortMsg_size;
extern const char kMonteSeed[decept::Hash::kSHA256.outputSize + 1];
extern const char kMonte[][decept::Hash::kSHA256.outputSize + 1];
extern const size_t kMonte_size;
extern const TestData kLongMsg[];
extern const size_t kLongMsg_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// https://csrc.nist.gov/Projects/cryptographic-algorithm-validation-program/Secure-Hashing
// https://emn178.github.io/online-tools/sha256.html

static void test_hash(const TestData* const data, const size_t size,
                      const char* const msgPre) {
  decept::Hash hash{decept::Hash::kSHA256};
  uint8_t actual[decept::Hash::kSHA256.outputSize];

  for (size_t i = 0; i < size; ++i) {
    const auto msg = msgPre + (" " + std::to_string(i));

    const TestData& d = data[i];

    TEST_ASSERT_TRUE_MESSAGE(hash.hash(d.in.data(), d.in.length(), actual,
                                       decept::Hash::kSHA256.outputSize),
                             msg.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(
        d.out, actual, decept::Hash::kSHA256.outputSize, msg.c_str());
  }
}

static void test_Monte(
    const char seed[decept::Hash::kSHA256.outputSize + 1],
    const char (*const data)[decept::Hash::kSHA256.outputSize + 1],
    const size_t size, const char* const msgPre) {
  uint8_t s[decept::Hash::kSHA256.outputSize];
  uint8_t s0[decept::Hash::kSHA256.outputSize];
  uint8_t s1[decept::Hash::kSHA256.outputSize];
  uint8_t s2[decept::Hash::kSHA256.outputSize];

  (void)std::memcpy(s, seed, decept::Hash::kSHA256.outputSize);

  decept::Hash hash{decept::Hash::kSHA256};

  for (size_t i = 0; i < size; ++i) {
    const auto msg = msgPre + (" " + std::to_string(i));

    (void)std::memcpy(s0, s, decept::Hash::kSHA256.outputSize);
    (void)std::memcpy(s1, s, decept::Hash::kSHA256.outputSize);
    (void)std::memcpy(s2, s, decept::Hash::kSHA256.outputSize);
    uint8_t* md0 = s0;
    uint8_t* md1 = s1;
    uint8_t* md2 = s2;

    for (size_t j = 0; j < 1000; ++j) {
      // Compare splitting up the hash in different ways
      uint8_t output1[decept::Hash::kSHA256.outputSize];
      uint8_t input[3 * decept::Hash::kSHA256.outputSize];
      (void)std::memcpy(input, md0, decept::Hash::kSHA256.outputSize);
      (void)std::memcpy(&input[decept::Hash::kSHA256.outputSize], md1,
                        decept::Hash::kSHA256.outputSize);
      (void)std::memcpy(&input[2 * decept::Hash::kSHA256.outputSize], md2,
                        decept::Hash::kSHA256.outputSize);

      // Try 1: all at once
      TEST_ASSERT_TRUE_MESSAGE(
          hash.hash(input, 3 * decept::Hash::kSHA256.outputSize, output1,
                    decept::Hash::kSHA256.outputSize),
          msg.c_str());

      // Try 2: split up
      hash.init();
      TEST_ASSERT_TRUE_MESSAGE(
          hash.update(md0, decept::Hash::kSHA256.outputSize) &&
              hash.update(md1, decept::Hash::kSHA256.outputSize) &&
              hash.update(md2, decept::Hash::kSHA256.outputSize),
          msg.c_str());
      uint8_t* temp = md0;
      md0 = md1;
      md1 = md2;
      md2 = temp;
      TEST_ASSERT_TRUE_MESSAGE(
          hash.finalize(md2, decept::Hash::kSHA256.outputSize), msg.c_str());

      TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(
          md2, output1, decept::Hash::kSHA256.outputSize, msg.c_str());
    }
    (void)std::memcpy(s, md2, decept::Hash::kSHA256.outputSize);

    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(
        data[i], md2, decept::Hash::kSHA256.outputSize, msg.c_str());
  }
}

static void test_ShortMsg() {
  test_hash(kShortMsg, kShortMsg_size, "ShortMsg");
}

static void test_Monte() {
  test_Monte(kMonteSeed, kMonte, kMonte_size, "Monte");
}

static void test_LongMsg() {
  test_hash(kLongMsg, kLongMsg_size, "LongMsg");
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
  RUN_TEST(test_ShortMsg);
  RUN_TEST(test_Monte);
  RUN_TEST(test_LongMsg);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
