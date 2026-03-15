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

// The possible channels
enum class Channels : size_t {
  kChannel0,
  kChannel1,
  kChannel2,
  kChannel3,
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

// DCP work packet structure. Use must be declarred as 32-byte aligned.
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

// --------------------------------------------------------------------------
//  AES Encryption
// --------------------------------------------------------------------------

// Key slots.
enum class KeySlots {
  kKeySlot0     = 0,  // Key slot 0
  kKeySlot1     = 1,  // Key slot 1
  kKeySlot2     = 2,  // Key slot 2
  kKeySlot3     = 3,  // Key slot 3
  kOTPKey       = 4,  // OTP key
  kOTPUniqueKey = 5,  // Unique OTP key
  kPayloadKey   = 6,  // Payload key
};

// // Holds some internal state for the cipher calculation.
// struct CipherContext {
//   // Channel and swapping
//   size_t channel   = 0;  // Which DCP channel (0-3)
//   uint32_t swapCfg = SwapFlags::kNoSwap;  // Key, input, output byte/word swap options

//   // Key and key data
//   KeySlots keySlot = KeySlots::kPayloadKey;  // Which key slot, for operations with keys
//   uint8_t keyData[sizes::kAES128Key + sizes::kAES128IV];  // Key and IV storage
// };

// // Sets the AES key and returns whether successful. If not using an OTP key, the
// // key size must be 16. Otherwise, if using an OTP key, the key may be NULL
// // because it won't be used.
// //
// // This clears the context, but ensures the key type remains intact.
// bool cipherSetKey(CipherContext& ctx, const void* key);

// // Performs AES operations and return whether successful. This also returns
// // false if the size is not a multiple of 16 or if it's zero. ECB mode is chosen
// // when the IV is NULL, and CBC mode is chosen otherwise.
// //
// // IV values must be 16 bytes.

// bool cipherEncrypt(CipoherContext& ctx,
//                    const void* plain, uint8_t* cipher, size_t size,
//                    const void* iv = nullptr);
// bool cipherDecrypt(CipoherContext& ctx,
//                    const void* cipher, uint8_t* plain, size_t size,
//                    const void* iv = nullptr);

// // --------------------------------------------------------------------------
// //  Hashing
// // --------------------------------------------------------------------------

// // Hash algorithms.
// enum class HashAlgo {
//   kSHA1,
//   kSHA256,
//   kCRC32,
// };

// // Holds some internal state for the hash calculation.
// struct HashContext {
//   HashAlgo algo = HashAlgo::kSHA256;  // Selected algorithm
//   size_t algoBlockSize;               // The algorithm's block size

//   // Channel and swapping
//   size_t channel   = 0;  // Which DCP channel (0-3)
//   uint32_t swapCfg = SwapFlags::kNoSwap;  // Key, input, output byte/word swap options

//   // Incomplete block data
//   uint8_t block[sizes::kSHA256Block];  // Memory buffer; only full blocks are written to DCP during hash updates
//   size_t blockSize = 0;                // Number of valid bytes in memory buffer

//   size_t totalSize = 0;  // Track message size

//   uint32_t runningHash[9];  // Running hash; up to SHA-256 plus size, that is, 36 bytes

//   // States
//   bool isStarted = false;  // Whether started
//   bool isFinal   = false;  // Whether this is the final block
// };

// // Calculates a hash over the given input and puts the hash into the output. If
// // the output size is less than the hash length, then only that number of bytes
// // will be copied. This returns whether the operation was successful.
// //
// // The internal context is cleared before returning.
// bool hash(const void* in, size_t inSize, uint8_t* out, size_t outSize);

// // Starts a hash by initializing the given context.
// void hashInit(HashContext& ctx);

// // Updates the hash and returns whether the operation was successful. This does
// // nothing and will return true if the input is empty.
// //
// // If this returns false then the context will have been cleared.
// bool hashUpdate(HashContext& ctx, const void* in, size_t inSize);

// // Finalizes the hash and puts the result into the output. If the output size is
// // less than the hash length, then only that number of bytes will be copied.
// // Otherwise, only hash-size bytes are copied into the output. This returns
// // the operation was successful. This will return true if the output is NULL.
// //
// // Note: The output is not modified if this returns false.
// //
// // The context is cleared before returning.
// bool hashFinalize(HashContext& ctx, uint8_t* out, size_t outSize);

}  // namespace dcp
}  // namespace decept
