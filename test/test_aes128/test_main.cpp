// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// test_main.cpp tests the DCP SHA-256 functions.
// This file is part of the Decept library.

#include <cstring>
#include <memory>
#include <string>
#include <utility>

#include <Arduino.h>
#include <decept/dcp/dcp.h>
#include <decept/Cipher.h>
#include <unity.h>

#include "defs.h"

extern const ECBTestData kKAT_ECB_encrypt_data[];
extern size_t kKAT_ECB_encrypt_data_size;
extern const ECBTestData kKAT_ECB_decrypt_data[];
extern size_t kKAT_ECB_decrypt_data_size;
extern const CBCTestData kKAT_CBC_encrypt_data[];
extern size_t kKAT_CBC_encrypt_data_size;
extern const CBCTestData kKAT_CBC_decrypt_data[];
extern size_t kKAT_CBC_decrypt_data_size;

extern const ECBTestData kMMT_ECB_encrypt_data[];
extern size_t kMMT_ECB_encrypt_data_size;
extern const ECBTestData kMMT_ECB_decrypt_data[];
extern size_t kMMT_ECB_decrypt_data_size;
extern const CBCTestData kMMT_CBC_encrypt_data[];
extern size_t kMMT_CBC_encrypt_data_size;
extern const CBCTestData kMMT_CBC_decrypt_data[];
extern size_t kMMT_CBC_decrypt_data_size;

extern const ECBTestData kMCT_ECB_encrypt_data[];
extern size_t kMCT_ECB_encrypt_data_size;
extern const ECBTestData kMCT_ECB_decrypt_data[];
extern size_t kMCT_ECB_decrypt_data_size;
extern const CBCTestData kMCT_CBC_encrypt_data[];
extern size_t kMCT_CBC_encrypt_data_size;
extern const CBCTestData kMCT_CBC_decrypt_data[];
extern size_t kMCT_CBC_decrypt_data_size;

// --------------------------------------------------------------------------
//  Main Program
// --------------------------------------------------------------------------

// Pre-test setup. This is run before every test.
void setUp() {
}

// Post-test teardown. This is run after every test.
void tearDown() {
}

// https://csrc.nist.gov/Projects/cryptographic-algorithm-validation-program/Block-Ciphers

static void test_ecb(const ECBTestData* const data, const size_t dataSize,
                     const bool encryptNotDecrypt) {
  decept::Cipher cipher{decept::Cipher::kAES128};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto msg = "Data " + std::to_string(i);

    const ECBTestData& d = data[i];
    TEST_ASSERT_MESSAGE(d.in.length() == d.out.length(), msg.c_str());

    const auto actual = std::make_unique<uint8_t[]>(d.in.length());

    TEST_ASSERT_TRUE_MESSAGE(
        cipher.setKey(decept::Cipher::KeySlots::kPayload, d.key), msg.c_str());

    if (encryptNotDecrypt) {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.encrypt(d.in.data(), actual.get(), d.in.length()),
          msg.c_str());
    } else {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.decrypt(d.in.data(), actual.get(), d.in.length()),
          msg.c_str());
    }
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.out.data(),
                                          actual.get(), d.in.length(),
                                          msg.c_str());
  }
}

static void test_cbc(const CBCTestData* const data, const size_t dataSize,
                     const bool encryptNotDecrypt) {
  decept::Cipher cipher{decept::Cipher::kAES128};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto msg = "Data " + std::to_string(i);

    const CBCTestData& d = data[i];
    TEST_ASSERT_MESSAGE(d.in.length() == d.out.length(), msg.c_str());

    const auto actual = std::make_unique<uint8_t[]>(d.in.length());

    TEST_ASSERT_TRUE_MESSAGE(
        cipher.setKey(decept::Cipher::KeySlots::kPayload, d.key), msg.c_str());

    if (encryptNotDecrypt) {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.encrypt(d.in.data(), actual.get(), d.in.length(), d.iv),
          msg.c_str());
    } else {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.decrypt(d.in.data(), actual.get(), d.in.length(), d.iv),
          msg.c_str());
    }
    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.out.data(),
                                          actual.get(), d.in.length(),
                                          msg.c_str());
  }
}

static void test_monte_ecb(const ECBTestData* const data, const size_t dataSize,
                           const bool encryptNotDecrypt) {
  decept::Cipher cipher{decept::Cipher::kAES128};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto msg = "Data " + std::to_string(i);

    const ECBTestData& d = data[i];
    TEST_ASSERT_MESSAGE(d.in.length() == d.out.length(), msg.c_str());

    const auto b1 = std::make_unique<uint8_t[]>(d.in.length());
    const auto b2 = std::make_unique<uint8_t[]>(d.in.length());
    uint8_t* in = b1.get();
    uint8_t* out = b2.get();

    TEST_ASSERT_TRUE_MESSAGE(
        cipher.setKey(decept::Cipher::KeySlots::kPayload, d.key), msg.c_str());

    std::memcpy(out, d.in.data(), d.in.length());
    for (int j = 0; j < 1000; ++j) {
      std::swap(in, out);
      if (encryptNotDecrypt) {
        TEST_ASSERT_TRUE_MESSAGE(cipher.encrypt(in, out, d.in.length()),
                                 msg.c_str());
      } else {
        TEST_ASSERT_TRUE_MESSAGE(cipher.decrypt(in, out, d.in.length()),
                                 msg.c_str());
      }
    }

    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.out.data(),
                                          out, d.in.length(),
                                          msg.c_str());
  }
}

static void test_monte_cbc(const CBCTestData* const data, const size_t dataSize,
                           const bool encryptNotDecrypt) {
  decept::Cipher cipher{decept::Cipher::kAES128};

  for (size_t i = 0; i < dataSize; ++i) {
    const auto msg = "Data " + std::to_string(i);

    const CBCTestData& d = data[i];
    TEST_ASSERT_MESSAGE(d.in.length() == d.out.length(), msg.c_str());

    const auto b1 = std::make_unique<uint8_t[]>(d.in.length());
    const auto b2 = std::make_unique<uint8_t[]>(d.in.length());
    const auto b3 = std::make_unique<uint8_t[]>(d.in.length());
    uint8_t* m1 = b1.get();
    uint8_t* m2 = b2.get();
    uint8_t* m3 = b3.get();

    TEST_ASSERT_TRUE_MESSAGE(
        cipher.setKey(decept::Cipher::KeySlots::kPayload, d.key), msg.c_str());

    if (encryptNotDecrypt) {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.encrypt(d.in.data(), m2, d.in.length(), d.iv), msg.c_str());
    } else {
      TEST_ASSERT_TRUE_MESSAGE(
          cipher.decrypt(d.in.data(), m2, d.in.length(), d.iv), msg.c_str());
    }
    std::memcpy(m3, d.iv, decept::Cipher::kAES128.blockSize);
    if (!encryptNotDecrypt) {
      std::memcpy(m1, d.in.data(), d.in.length());  // Becomes m2, the next IV
    }
    /*
    j 0:  m1 = ?/in[0], m2 = out[0],  m3 = in[1]
    j 1:  m1 = in[1],   m2 = ?/in[0], m3 = out[0]
          m1 = in[1],   m2 = out[1],  m3 = out[0]
    j 2:  m1 = out[0],  m2 = in[1],   m3 = out[1]
          m1 = out[0],  m2 = out[2],  m3 = out[1]
    j 3:  m1 = out[1],  m2 = out[0],  m3 = out[2]
          m1 = out[1],  m2 = out[3],  m3 = out[2]
    */
    for (int j = 1; j < 1000; ++j) {
      uint8_t* const temp = m1;
      m1 = m3;
      m3 = m2;
      m2 = temp;
      if (encryptNotDecrypt) {
        TEST_ASSERT_TRUE_MESSAGE(cipher.encrypt(m1, m2, d.in.length(), m3),
                                 msg.c_str());
      } else {
        TEST_ASSERT_TRUE_MESSAGE(cipher.decrypt(m1, m2, d.in.length(), m2),
                                 msg.c_str());
      }
    }

    TEST_ASSERT_EQUAL_UINT8_ARRAY_MESSAGE(d.out.data(), m2, d.in.length(),
                                          msg.c_str());
  }
}

static void test_kat_ecb_encrypt() {
  test_ecb(kKAT_ECB_encrypt_data, kKAT_ECB_encrypt_data_size, true);
}

static void test_kat_ecb_decrypt() {
  test_ecb(kKAT_ECB_decrypt_data, kKAT_ECB_decrypt_data_size, false);
}

static void test_kat_cbc_encrypt() {
  test_cbc(kKAT_CBC_encrypt_data, kKAT_CBC_encrypt_data_size, true);
}

static void test_kat_cbc_decrypt() {
  test_cbc(kKAT_CBC_decrypt_data, kKAT_CBC_decrypt_data_size, false);
}

static void test_mmt_ecb_encrypt() {
  test_ecb(kMMT_ECB_encrypt_data, kMMT_ECB_encrypt_data_size, true);
}

static void test_mmt_ecb_decrypt() {
  test_ecb(kMMT_ECB_decrypt_data, kMMT_ECB_decrypt_data_size, false);
}

static void test_mmt_cbc_encrypt() {
  test_cbc(kMMT_CBC_encrypt_data, kMMT_CBC_encrypt_data_size, true);
}

static void test_mmt_cbc_decrypt() {
  test_cbc(kMMT_CBC_decrypt_data, kMMT_CBC_decrypt_data_size, false);
}

static void test_mct_ecb_encrypt() {
  test_monte_ecb(kMCT_ECB_encrypt_data, kMCT_ECB_encrypt_data_size, true);
}

static void test_mct_ecb_decrypt() {
  test_monte_ecb(kMCT_ECB_decrypt_data, kMCT_ECB_decrypt_data_size, false);
}

static void test_mct_cbc_encrypt() {
  test_monte_cbc(kMCT_CBC_encrypt_data, kMCT_CBC_encrypt_data_size, true);
}

static void test_mct_cbc_decrypt() {
  test_monte_cbc(kMCT_CBC_decrypt_data, kMCT_CBC_decrypt_data_size, false);
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
  RUN_TEST(test_kat_ecb_encrypt);
  RUN_TEST(test_kat_ecb_decrypt);
  RUN_TEST(test_kat_cbc_encrypt);
  RUN_TEST(test_kat_cbc_decrypt);
  RUN_TEST(test_mmt_ecb_encrypt);
  RUN_TEST(test_mmt_ecb_decrypt);
  RUN_TEST(test_mmt_cbc_encrypt);
  RUN_TEST(test_mmt_cbc_decrypt);
  RUN_TEST(test_mct_ecb_encrypt);
  RUN_TEST(test_mct_ecb_decrypt);
  RUN_TEST(test_mct_cbc_encrypt);
  RUN_TEST(test_mct_cbc_decrypt);
  UNITY_END();

  decept::dcp::deinit();
}

// Main program loop.
void loop() {
}
