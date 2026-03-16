// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcp.h defines functions for using the Data Co-Processor (DCP).
// This file is part of the Decept library.

#pragma once

// C++ includes
#include <cstddef>
#include <cstdint>

namespace decept {
namespace dcp {

// --------------------------------------------------------------------------
//  Types
// --------------------------------------------------------------------------

// Channels contains the possible DCP channels.
enum class Channels : size_t {
  kChannel0 = 0,
  kChannel1 = 1,
  kChannel2 = 2,
  kChannel3 = 3,
};

// Swap configuration flags.
inline namespace swaps {
constexpr uint32_t kNoSwap         = 0x00;
constexpr uint32_t kKeyByteSwap    = 0x01;
constexpr uint32_t kKeyWordSwap    = 0x02;
constexpr uint32_t kInputByteSwap  = 0x04;
constexpr uint32_t kInputWordSwap  = 0x08;
constexpr uint32_t kOutputByteSwap = 0x10;
constexpr uint32_t kOutputWordSwap = 0x20;
}  // namespace swaps

inline namespace sizes {
  constexpr size_t kAES128Block = 16;
  constexpr size_t kAES128Key   = 16;
  constexpr size_t kAES128IV    = 16;

  constexpr size_t kSHA256Block = 64;  // SHA-256 input block size
  constexpr size_t kSHA1Block   = 64;  // SHA-1 input block size
  constexpr size_t kCRC32Block  = 64;  // CRC-32 input block size (use same)

  // Result sizes
  constexpr size_t kSHA256Output = 32;  // SHA-256 result size
  constexpr size_t kSHA1Output   = 20;  // SHA-1 result size
  constexpr size_t kCRC32Output  = 4;   // CRC-32 result size
}  // namespace sizes

// DCP work packet structure. Use must be declared as 32-byte aligned.
struct alignas(32) WorkPacket {
  uint32_t nextCmdAddress;
  uint32_t control0;
  uint32_t control1;
  uint32_t srcAddr;
  uint32_t dstAddr;
  uint32_t bufSize;
  uint32_t payloadPtr;
  uint32_t status;
};

// --------------------------------------------------------------------------
//  Initialization
// --------------------------------------------------------------------------

// Initializes DCP. This only needs to be called once, unless deinitialized.
void init();

// Deinitializes DCP.
void deinit();

// Returns whether the DCP subsystem has been started. This checks the clock.
bool isStarted();

// --------------------------------------------------------------------------
//  Internal
// --------------------------------------------------------------------------

// Schedules some work. This returns true if the work was scheduled and false if
// the channel is currently busy.
bool scheduleWork(size_t channel, WorkPacket& workPacket);

bool waitForChannelComplete(size_t channel);

}  // namespace dcp
}  // namespace decept
