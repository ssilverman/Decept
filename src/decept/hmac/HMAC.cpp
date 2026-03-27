// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// HMAC.cpp implements HMAC.
// This file is part of the Decept library.

#include "decept/hmac/HMAC.h"

// C++ includes
#include <cstring>
#include <cstdio>

#include "decept/util/dcache.h"

namespace decept {
namespace hmac {

static constexpr uint8_t kIPad = 0x36;
static constexpr uint8_t kOPad = 0x5c;

HMAC::HMAC(Hash::Algorithm algo)
    : hash_(algo),
      iCtx_(algo),
      oCtx_(algo) {}

HMAC::~HMAC() {
  util::reallyClear(digest_, sizeof(digest_));
}

bool HMAC::initKey(const void* const key, const size_t keySize,
                   dcp::Channels channel) {
  const size_t hashSize = outputSize();
  const size_t blockSize = hash_.blockSize();

  // Fill with all zeros
  (void)std::memset(digest_, 0, blockSize);

  if (keySize <= blockSize) {
    (void)std::memcpy(digest_, key, keySize);
  } else {
    if (!hash_.hash(key, keySize, digest_, hashSize, channel)) {
      return false;
    }
  }

  // ipad
  for (size_t i = 0; i < blockSize; ++i) {
    digest_[i] ^= kIPad;
  }
  iCtx_.init(channel);
  if (!iCtx_.update(digest_, blockSize)) {
    return false;
  }

  // opad
  for (size_t i = 0; i < blockSize; ++i) {
    digest_[i] ^= kIPad ^ kOPad;
  }
  oCtx_.init(channel);
  if (!oCtx_.update(digest_, blockSize)) {
    return false;
  }

  return true;
}

bool HMAC::calculate(const void* const msg, const size_t msgSize,
                     uint8_t* const out, const size_t outSize) {
  hash_ = iCtx_;
  if (!hash_.update(msg, msgSize) ||
      !hash_.finalize(digest_, outputSize())) {
    return false;
  }

  hash_ = oCtx_;
  if (!hash_.update(digest_, outputSize()) ||
      !hash_.finalize(out, outSize)) {
    return false;
  }

  return true;
}

void HMAC::init(dcp::Channels channel) {
  hash_ = iCtx_;
  hash_.setChannel(channel);
}

void HMAC::setChannel(dcp::Channels channel) {
  hash_.setChannel(channel);
}

bool HMAC::update(const void* const in, const size_t inSize) {
  return hash_.update(in, inSize);
}

bool HMAC::finalize(uint8_t* const out, const size_t outSize) {
  if (!hash_.finalize(digest_, outputSize())) {
    return false;
  }

  hash_ = oCtx_;  // TODO: Fix up the channel (and the channel-related API)
  if (!hash_.update(digest_, outputSize()) ||
      !hash_.finalize(out, outSize)) {
    return false;
  }

  return true;
}

bool HMAC::calculate(const std::pair<const void*, size_t>* const inputs,
                     const size_t inputsSize,
                     uint8_t* const out, const size_t outSize) {
  hash_ = iCtx_;
  for (size_t i = 0; i < inputsSize; ++i) {
    const auto& p = inputs[i];
    if (!hash_.update(p.first, p.second)) {
      return false;
    }
  }
  if (!hash_.finalize(digest_, outputSize())) {
    return false;
  }

  hash_ = oCtx_;
  if (!hash_.update(digest_, outputSize()) ||
      !hash_.finalize(out, outSize)) {
    return false;
  }

  return true;
}

}  // namespace hmac
}  // namespace decept
