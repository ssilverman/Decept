// SPDX-FileCopyrightText: (c) 2023 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HMAC.cpp implements HMAC.
// This file is part of the Decept library.

#include "decept/HMAC.h"

// C++ includes
#include <cstring>
#include <cstdio>

#include "decept/util/dcache.h"

namespace decept {

static constexpr uint8_t kIPad = 0x36;
static constexpr uint8_t kOPad = 0x5c;

HMAC::HMAC(Hash::Algorithm algo)
    : hash_(algo),
      digest_(std::make_unique<uint8_t[]>(hash_.blockSize())),
      iCtx_(algo),
      oCtx_(algo) {}

bool HMAC::initKey(const void* const key, const size_t keySize,
                   dcp::Channels channel) {
  const size_t hashSize = hash_.outputSize();
  const size_t blockSize = hash_.blockSize();

  // Fill with all zeros
  (void)std::memset(digest_.get(), 0, blockSize);

  if (keySize <= blockSize) {
    (void)std::memcpy(digest_.get(), key, keySize);
  } else {
    if (!hash_.hash(key, keySize, digest_.get(), hashSize)) {
      return false;
    }
  }

  // ipad
  for (size_t i = 0; i < blockSize; ++i) {
    digest_[i] ^= kIPad;
  }
  iCtx_.init(channel);
  if (!iCtx_.update(digest_.get(), blockSize)) {
    return false;
  }

  // opad
  for (size_t i = 0; i < blockSize; ++i) {
    digest_[i] ^= kIPad ^ kOPad;
  }
  oCtx_.init(channel);
  if (!oCtx_.update(digest_.get(), blockSize)) {
    return false;
  }

  return true;
}

bool HMAC::calculate(const void* const msg, const size_t msgSize,
                     uint8_t* const output, const size_t outputSize) {
  const size_t hashSize = hash_.outputSize();

  hash_ = iCtx_;
  if (!hash_.update(msg, msgSize) || !hash_.finalize(digest_.get(), hashSize)) {
    return false;
  }

  hash_ = oCtx_;
  if (!hash_.update(digest_.get(), hashSize) ||
      !hash_.finalize(output, outputSize)) {
    return false;
  }

  return true;
}

void HMAC::init(dcp::Channels channel) {
  hash_ = iCtx_;
}

bool HMAC::update(const void* const input, const size_t inputSize) {
  return hash_.update(input, inputSize);
}

bool HMAC::finalize(uint8_t* const output, const size_t outputSize) {
  if (!hash_.finalize(output, outputSize)) {
    return false;
  }

  hash_ = oCtx_;
  if (!hash_.update(digest_.get(), hash_.outputSize()) ||
      !hash_.finalize(output, outputSize)) {
    return false;
  }

  return true;
}

bool HMAC::calculate(const std::vector<std::pair<const void*, size_t>>& inputs,
                     uint8_t* const output, const size_t outputSize) {
  hash_ = iCtx_;
  for (const auto& p : inputs) {
    if (!hash_.update(p.first, p.second)) {
      return false;
    }
  }
  if (!hash_.finalize(digest_.get(), hash_.outputSize())) {
    return false;
  }

  hash_ = oCtx_;
  if (!hash_.update(digest_.get(), hash_.outputSize()) ||
      !hash_.finalize(output, outputSize)) {
    return false;
  }

  return true;
}

}  // namespace decept
