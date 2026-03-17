// SPDX-FileCopyrightText: (c) 2023 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HMAC.h defines a class for calculating an HMAC using SHA-256, as defined by
// NIST FIPS PUB 198-1, "The Keyed-Hash Message Authentication Code (HMAC)"
// This file is part of the Decept library.

// Refs:
// * [HMAC: Keyed-Hashing for Message Authentication (RFC 2104)](https://datatracker.ietf.org/doc/html/rfc2104)

#pragma once

// C++ includes
#include <cstddef>
#include <cstdint>
#include <memory>
#include <utility>
#include <vector>

#include "decept/Hash.h"
#include "decept/dcp/dcp.h"

namespace decept {
namespace hmac {

class HMAC {
 public:
  // Creates a new HMAC using the given algorithm.
  HMAC(Hash::Algorithm hash);

  // Returns the hash output size.
  size_t outputSize() const {
    return hash_.outputSize();
  }

  // Initializes the HMAC with the given key. This copies the key. If there was
  // an error precomputing the initial key values then this will return false.
  // Otherwise, this will return true.
  //
  // This only needs to be called once for each new key.
  //
  // It's also possible to specify the calculation channel.
  bool initKey(const void* key, size_t keySize,
               dcp::Channels channel = dcp::Channels::kChannel0);

  // Calculates an HMAC for the given message and stores the output into
  // 'output'. The specified number of bytes will be copied into the output, up
  // to _hash size_ bytes.
  //
  // This returns whether the calculation was successful. If this returns false
  // then 'output' will not have been modified.
  //
  // Note: It is safe for the message and output to be the same.
  bool calculate(const void* msg, size_t msgSize, uint8_t* out, size_t outSize);

  // Same as the other calculate() function, but uses multiple inputs. The
  // specified number of bytes will be copied into the output, up to
  // _hash size_ bytes.
  bool calculate(const std::vector<std::pair<const void*, size_t>>& inputs,
                 uint8_t* out, size_t outSize);

  // ------------------------------------------------------------------------
  //  Running Hash
  // ------------------------------------------------------------------------

  // Initializes a running HMAC. This needs to be called once before any calls
  // to update(), or if there are no calls to update(), finalize(). A key must
  // have been set with initKey().
  void init(dcp::Channels channel = dcp::Channels::kChannel0);

  // Sets the calculation channel.
  void setChannel(dcp::Channels channel);

  // Updates the HMAC with a new part of the message. init() must have been
  // called once before any calls to update().
  bool update(const void* in, size_t inSize);

  // Finalizes a running HMAC. init() must have been called once before any
  // previous calls to update(), or, if update() has not been called, before any
  // calls to finalize(). Once finalize() is called, init() needs to be called
  // again to start another running hash.
  bool finalize(uint8_t* out, size_t outSize);

 private:
  Hash hash_;
  std::unique_ptr<uint8_t[]> digest_;  // Holds room for a complete digest

  // Key material
  Hash iCtx_;
  Hash oCtx_;
};

}  // namespace hmac
}  // namespace decept
