// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// Hash.h defines a generic class for computing a hash function.
// This file is part of the Decept library.

#pragma once

#include <algorithm>
#include <array>
#include <cstddef>
#include <cstdint>
#include <utility>

#include "decept/dcp/dcp.h"
#include "decept/states.h"

namespace decept {

class Hash {
 private:
  // Algorithms specifies all the hash algorithms.
  enum class Algorithms {
    kSHA1,
    kSHA256,
    kCRC32,
  };

 public:
  struct Algorithm {
    Algorithms algo;
    size_t outputSize;
    size_t blockSize;
    size_t seedLen;  // Seed length for Hash-based DRBG

    constexpr bool operator==(const Algorithm& a) const {
      if (&a == this) {
        return true;
      }
      return (algo == a.algo) &&
             (outputSize == a.outputSize) &&
             (blockSize == a.blockSize);
    };

    constexpr bool operator!=(const Algorithm& a) const {
      return !(*this == a);
    }
  };

  static constexpr Algorithm kSHA1{
      Algorithms::kSHA1,
      dcp::sizes::kSHA1Output,
      dcp::sizes::kSHA1Block,
      dcp::sizes::kSHA1SeedLen,
  };
  static constexpr Algorithm kSHA256{
      Algorithms::kSHA256,
      dcp::sizes::kSHA256Output,
      dcp::sizes::kSHA256Block,
      dcp::sizes::kSHA256SeedLen,
  };
  static constexpr Algorithm kCRC32{
      Algorithms::kCRC32,
      dcp::sizes::kCRC32Output,
      dcp::sizes::kCRC32Block,
      dcp::sizes::kUnknownSeedLen,
  };

  // The list of algorithms.
  static constexpr std::array kAlgorithms{
      kSHA1,
      kSHA256,
      kCRC32,
  };

  // Creates a new Hash using the given algorithm.
  Hash(Algorithm algo);

  // Zeros out all the memory.
  ~Hash();

  // Defaulted copy and move operations
  Hash(const Hash&) = default;  // Copy constructor
  Hash(Hash&&)      = default;  // Move constructor
  Hash& operator=(const Hash&) = default;  // Copy assignment
  Hash& operator=(Hash&&)      = default;  // Move assignment

  // Returns the hash output size.
  size_t outputSize() const {
    return algo_.outputSize;
  }

  // Returns the hash block size.
  size_t blockSize() const {
    return algo_.blockSize;
  }

  // Initializes the calculation.
  void init(dcp::Channels channel = dcp::Channels::kChannel0);

  // Sets the calculation channel.
  void setChannel(dcp::Channels channel);

  // Updates the hash and returns whether the operation was successful. This
  // does nothing and will return true if the input is empty.
  //
  // If this returns false and the parameters are valid then the calculation
  // must be restarted.
  //
  // See: init()
  bool update(const void* msg, size_t msgSize);

  // Finalizes a hash calculation and stores the result into the output. If the
  // output size is less than the digest length, then only that number of bytes
  // will be copied. Elsewise, only digest-length bytes are copied into the
  // output. In other words, the number of bytes copied is
  // min{outSize, digestLength}.
  //
  // This returns whether the operation was successful. If this returns false
  // and the parameters are valid then the calculation must be restarted.
  //
  // Note: The output is not modified if this returns false.
  //
  // This function can be used without prior calls to update().
  //
  // See: init()
  bool finalize(uint8_t* out, size_t outSize);

  // Convenience function that calls init(), update(), and then finalize().
  bool hash(const void* msg, size_t msgSize, uint8_t* out, size_t outSize,
            dcp::Channels channel = dcp::Channels::kChannel0);

 private:
  // Holds some internal state for the hash calculation.
  struct Context {
    static constexpr size_t kBlockSize =
        std::max_element(kAlgorithms.cbegin(), kAlgorithms.cend(),
                         [](const auto& a, const auto& b) {
                           return (a.blockSize < b.blockSize);
                         })
            ->blockSize;

    // Channel and swapping
    size_t channel;    // Which DCP channel (0-3)
    uint32_t swapCfg;  // Key, input, output byte/word swap options

    // Incomplete block data
    uint8_t block[kBlockSize];  // Memory buffer; only full blocks are written to DCP during hash updates
    size_t currBlockSize;       // Number of valid bytes in memory buffer

    size_t totalSize;  // Track message size

    uint32_t runningHash[9];  // Running hash; up to SHA-256 plus size, that is, 36 bytes

    // Cached work packet values
    uint32_t control1;

    dcp::WorkPacket workPacket;  // Cached and aligned work packet
    bool workScheduled = false;

    // States
    bool isStarted;  // Whether started
  };

  States update(uint32_t control0, const void* b, size_t size);

  // Sets up a work packet and tries to schedule a task. This returns true if
  // the task was scheduled, and false elsewise.
  bool trySchedule(uint32_t control0, const void* b, size_t size);

  void saveRunningHashFromTheCausticMist();
  void restoreRunningHashAsGoodAsNew();

  Algorithm algo_;
  Context ctx_{};
};

}  // namespace decept
