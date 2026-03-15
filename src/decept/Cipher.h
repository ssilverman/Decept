// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Cipher.h defines a generic class for computing a cipher.
// This file is part of the Decept library.

#pragma once

#include <utility>

#include "decept/dcp/dcp.h"

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
  };

  static constexpr Algorithm kAES128{Algorithms::kAES128,
                                     dcp::sizes::kAES128Block};

  // Creates a new Cipher using the given algorithm.
  Cipher(Algorithm algo);

  // Zeros out all the memory.
  ~Cipher();

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
  bool encrypt(const void* src, uint8_t* dst, size_t size,
               const void* iv = nullptr);

  // Decrypts data. This will use ECB mode if the IV is NULL, and CBC mode if
  // the IV is not NULL. It is expected that the IV, if provided, is the correct
  // size for the selected algorithm. See decept::dcp::sizes.
  bool decrypt(const void* src, uint8_t* dst, size_t size,
               const void* iv = nullptr);

 private:
  // Holds some internal state for the cipher calculation.
  struct Context {
    size_t channel;    // Which DCP channel (0-3)
    uint32_t swapCfg;  // Key, input, output byte/word swap options

    KeySlots keySlot;
    uint8_t keyData[dcp::sizes::kAES128Key + dcp::sizes::kAES128IV];
  };

  // Performs encryption or decryption. This will use ECB mode if the IV is NULL
  // and CBC mode if IV is not NULL. The IV is expected to be the correct size
  // for the selected algorithm.
  //
  // This will return whether successful.
  bool crypt(bool encryptNotDecrypt, const void* src, uint8_t* dst, size_t size,
             const void* iv = nullptr);

  // This is where the work is submitted to the DCP module. This will return
  // whether successful.
  bool cryptNonBlocking(bool encryptNotDecrypt, bool hasIV,
                        dcp::WorkPacket& workPacket, const void* src,
                        uint8_t* dst, size_t size);

  Algorithm algo_;
  Context ctx_;
};

}  // namespace decept
