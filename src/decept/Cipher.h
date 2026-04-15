// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Cipher.h defines a generic class for computing a cipher.
// This file is part of the Decept library.

#pragma once

#include <algorithm>
#include <array>
#include <utility>

#include "decept/dcp/dcp.h"
#include "decept/states.h"

namespace decept {

class Cipher {
 private:
  // Algorithms specifies all the cipher algorithms.
  enum class Algorithms {
    kAES128,
  };

 public:
  enum class KeySlots : uint32_t {
    kSlot0        = 0,  // DCP key slot 0
    kSlot1        = 1,  // DCP key slot 1
    kSlot2        = 2,  // DCP key slot 2
    kSlot3        = 3,  // DCP key slot 3
    kOTPKey       = 4,  // DCP OTP key
    kOTPUniqueKey = 5,  // DCP unique OTP key
    kPayload      = 6,  // DCP payload key
  };

  struct Algorithm {
    Algorithms algo;
    size_t blockSize;
    size_t keySize;
    size_t ivSize;

    constexpr bool operator==(const Algorithm& a) const {
      if (&a == this) {
        return true;
      }
      return (algo == a.algo) &&
             (blockSize == a.blockSize) &&
             (keySize == a.keySize) &&
             (ivSize == a.ivSize);
    };

    constexpr bool operator!=(const Algorithm& a) const {
      return !(*this == a);
    }
  };

  static constexpr Algorithm kAES128{
      Algorithms::kAES128,
      dcp::sizes::kAES128Block,
      dcp::sizes::kAES128Key,
      dcp::sizes::kAES128IV,
  };

  // WATCH: Add more asserts as needed when more algorithms are added
  static_assert((kAES128.keySize % 4) == 0, "Key size must be a multiple of 4");
  static_assert((kAES128.ivSize % 4) == 0, "IV size must be a multiple of 4");

  // The list of algorithms.
  static constexpr std::array kAlgorithms{
      kAES128,
  };

  // The maximum sizes are useful for pre-allocating space for
  // one-size-fits-all algorithm classes

  // Maximum of all the block sizes.
  static constexpr size_t kMaxBlockSize =
      std::max_element(Cipher::kAlgorithms.cbegin(), Cipher::kAlgorithms.cend(),
                       [](const auto& a, const auto& b) {
                         return (a.blockSize < b.blockSize);
                       })
          ->blockSize;

  // Maximum of all the key sizes, not including the IV.
  static constexpr size_t kMaxKeySize =
      std::max_element(
          Cipher::kAlgorithms.cbegin(), Cipher::kAlgorithms.cend(),
          [](const auto& a, const auto& b) { return (a.keySize < b.keySize); })
          ->keySize;

  // Maximum of all the key-plus-IV sizes.
  static constexpr size_t kMaxKeyPlusIVSize = []() {
    const auto e = std::max_element(
        Cipher::kAlgorithms.cbegin(), Cipher::kAlgorithms.cend(),
        [](const auto& a, const auto& b) {
          return ((a.keySize + a.ivSize) < (b.keySize + b.ivSize));
        });
    return (e->keySize + e->ivSize);
  }();

  // Creates a new Cipher using the given algorithm.
  Cipher(Algorithm algo);

  // Zeros out all the memory.
  ~Cipher() noexcept;

  // Returns the algorithm used.
  const Algorithm& algo() const {
    return algo_;
  }

  // Returns the cipher block size.
  size_t blockSize() const {
    return algo_.blockSize;
  }

  // Initializes the calculation.
  void init(dcp::Channels channel = dcp::Channels::kChannel0);

  // Sets the key and the slot to put it in. This will return whether
  // successful. This will only return false if using the OTP key or unique OTP
  // key and they're not already set up.
  //
  // The key parameter is ignored for the OTP key slots, and so it may be NULL.
  //
  // The key is expected to be the correct size for the selected algorithm.
  // See decept::dcp::sizes.
  bool setKey(KeySlots slot, const void* key);

  // Encrypts data. This will use ECB mode if the IV is NULL, and CBC mode if
  // the IV is not NULL. It is expected that the IV, if provided, is the correct
  // size for the selected algorithm. See decept::dcp::sizes.
  //
  // The size is expected to be a multiple of the block size and not zero.
  bool encrypt(const void* src, uint8_t* dst, size_t size,
               const void* iv = nullptr);

  // Decrypts data. This will use ECB mode if the IV is NULL, and CBC mode if
  // the IV is not NULL. It is expected that the IV, if provided, is the correct
  // size for the selected algorithm. See decept::dcp::sizes.
  //
  // The size is expected to be a multiple of the block size and not zero.
  bool decrypt(const void* src, uint8_t* dst, size_t size,
               const void* iv = nullptr);

 private:
  // Holds some internal state for the cipher calculation.
  struct Context {
    size_t channel;    // Which DCP channel (0-3)
    uint32_t swapCfg;  // Key, input, output byte/word swap options

    KeySlots keySlot;
    std::array<uint32_t, kMaxKeyPlusIVSize/4> keyData;
        // Aligned(4)

    // Cached work packet values
    uint32_t control1;

    dcp::WorkPacket workPacket;  // Cached and aligned work packet
    bool workScheduled = false;
  };

  // Performs encryption or decryption. This will use ECB mode if the IV is NULL
  // and CBC mode if IV is not NULL. The IV is expected to be the correct size
  // for the selected algorithm.
  //
  // This will return whether successful. This will return false if the size is
  // zero or not a multiple of the block size, or if the operation failed.
  bool crypt(bool encryptNotDecrypt, const void* src, uint8_t* dst, size_t size,
             const void* iv);

  // Attempts to perform a "crypt" operation and returns the state.
  States tryCrypt(bool encryptNotDecrypt,
                  const void* src, uint8_t* dst, size_t size,
                  const void* iv);

  // Sets up a work packet and tries to schedule a task. This returns true if
  // the task was scheduled, and false elsewise.
  //
  // The size must be a multiple of 16 and not zero. The payload must contain
  // the key & IV in one array, with the IV following the key.
  bool trySchedule(bool encryptNotDecrypt, bool hasIV,
                   const void* src, uint8_t* dst, size_t size);

  Algorithm algo_;
  Context ctx_{};
};

}  // namespace decept
