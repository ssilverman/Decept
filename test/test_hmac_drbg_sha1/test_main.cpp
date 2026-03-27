// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the SHA-1-based HMAC_DRBG.
// This file is part of the Decept library.

#include <memory>
#include <string>

#include <Arduino.h>
#include <decept/Hash.h>
#include <decept/dcp/dcp.h>
#include <decept/drbg/HMACDRBG.h>
#include <unity.h>

#include "defs.h"

extern const NoReseedTestData sha1_no_reseed_data[];
extern const size_t sha1_no_reseed_data_size;
extern const PRFalseTestData sha1_pr_false_data[];
extern const size_t sha1_pr_false_data_size;
extern const PRTrueTestData sha1_pr_true_data[];
extern const size_t sha1_pr_true_data_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// https://csrc.nist.gov/Projects/cryptographic-algorithm-validation-program/Random-Number-Generators

template <const decept::Hash::Algorithm& A>
static void test_no_reseed(const NoReseedTestData* const data,
                           const size_t dataSize) {
  decept::drbg::HMACDRBG drbg{A};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto m = "Data " + std::to_string(i);

    const NoReseedTestData& d = data[i];

    const auto actual = std::make_unique<uint8_t[]>(d.returnedBits.length());

    TEST_ASSERT_TRUE_MESSAGE(
        drbg.init(d.entropyInput.data(), d.entropyInput.length(),
                  d.nonce.data(), d.nonce.length(),
                  d.personalizationString.data(),
                  d.personalizationString.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(d.addlInput1.data(), d.addlInput1.length(),
                      actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(d.addlInput2.data(), d.addlInput2.length(),
                      actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(
        d.returnedBits.data(), actual.get(), d.returnedBits.length(), m.c_str());
  }
}

template <const decept::Hash::Algorithm& A>
static void test_pr_false(const PRFalseTestData* const data,
                          const size_t dataSize) {
  decept::drbg::HMACDRBG drbg{A};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto m = "Data " + std::to_string(i);

    const PRFalseTestData& d = data[i];

    const auto actual = std::make_unique<uint8_t[]>(d.returnedBits.length());

    TEST_ASSERT_TRUE_MESSAGE(
        drbg.init(d.entropyInput.data(), d.entropyInput.length(),
                  d.nonce.data(), d.nonce.length(),
                  d.personalizationString.data(),
                  d.personalizationString.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.reseed(d.entropyInputReseed.data(), d.entropyInputReseed.length(),
                    d.addlInputReseed.data(), d.addlInputReseed.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(d.addlInput1.data(), d.addlInput1.length(),
                      actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(d.addlInput2.data(), d.addlInput2.length(),
                      actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.returnedBits.data(), actual.get(),
                                          d.returnedBits.length(),
                                          m.c_str());
  }
}

template <const decept::Hash::Algorithm& A>
static void test_pr_true(const PRTrueTestData* const data,
                         const size_t dataSize) {
  decept::drbg::HMACDRBG drbg{A};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto m = "Data " + std::to_string(i);

    const PRTrueTestData& d = data[i];

    const auto actual = std::make_unique<uint8_t[]>(d.returnedBits.length());

    TEST_ASSERT_TRUE_MESSAGE(
        drbg.init(d.entropyInput.data(), d.entropyInput.length(),
                  d.nonce.data(), d.nonce.length(),
                  d.personalizationString.data(),
                  d.personalizationString.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.reseed(d.entropyInput1.data(), d.entropyInput1.length(),
                    d.addlInput1.data(), d.addlInput1.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(nullptr, 0, actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.reseed(d.entropyInput2.data(), d.entropyInput2.length(),
                    d.addlInput2.data(), d.addlInput2.length()),
        m.c_str());
    TEST_ASSERT_TRUE_MESSAGE(
        drbg.generate(nullptr, 0, actual.get(), d.returnedBits.length()),
        m.c_str());
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.returnedBits.data(), actual.get(),
                                          d.returnedBits.length(),
                                          m.c_str());
  }
}

static void test_no_reseed_sha1() {
  test_no_reseed<decept::Hash::kSHA1>(sha1_no_reseed_data,
                                      sha1_no_reseed_data_size);
}

static void test_pr_false_sha1() {
  test_pr_false<decept::Hash::kSHA1>(sha1_pr_false_data,
                                     sha1_pr_false_data_size);
}

static void test_pr_true_sha1() {
  test_pr_true<decept::Hash::kSHA1>(sha1_pr_true_data, sha1_pr_true_data_size);
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
  RUN_TEST(test_no_reseed_sha1);
  RUN_TEST(test_pr_false_sha1);
  RUN_TEST(test_pr_true_sha1);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
