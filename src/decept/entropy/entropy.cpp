// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// entropy.cpp implements the hardware entropy functions.
// This file is part of the Decept library.

#include "decept/entropy/entropy.h"

// C++ includes
#include <algorithm>
#include <cerrno>
#include <cstring>

#include <pgmspace.h>

#include "decept/regs/CCM.h"
#include "decept/regs/TRNG.h"

namespace decept {
namespace entropy {

namespace {
namespace config {

enum : uint32_t {
  // Clock settings
  kCLOCK_MODE   = 0,  // 0=Ring Oscillator, 1=System Clock (test use only)
  kRING_OSC_DIV =     // Divide by 2^n
#if (F_CPU >= 528000000)
      0,
#else
      2,
#endif  // F_CPU range

  // Sampling
  kSAMPLE_MODE      = 2,  // 0:Von Neumann in both, 1:raw in both, 2:VN Entropy and raw in stats */
  kSPARSE_BIT_LIMIT = 63,

  // Seed control
  kENTROPY_DELAY = 3200,
  kSAMPLE_SIZE   = 2500/*512*/,

  // Statistical check parameters
  kRETRY_COUNT   = 1,
  kRUN_MAX_LIMIT = 34/*32*/,

  kMONOBIT_MAX       = 1384/*317*/,
  kMONOBIT_RANGE     = 268/*122*/,
  kRUNBIT1_MAX       = 405/*107*/,
  kRUNBIT1_RANGE     = 178/*80*/,
  kRUNBIT2_MAX       = 220/*62*/,
  kRUNBIT2_RANGE     = 122/*55*/,
  kRUNBIT3_MAX       = 125/*39*/,
  kRUNBIT3_RANGE     = 88/*39*/,
  kRUNBIT4_MAX       = 75/*26*/,
  kRUNBIT4_RANGE     = 64/*26*/,
  kRUNBIT5_MAX       = 47/*18*/,
  kRUNBIT5_RANGE     = 46/*18*/,
  kRUNBIT6PLUS_MAX   = 47/*17*/,
  kRUNBIT6PLUS_RANGE = 46/*17*/,

  // Limits for statistical check of "Poker Test"
  kPOKER_MAX   = 26912/*1600*/,
  kPOKER_RANGE = 2467/*570*/,

  // Limits for statistical check of entropy sample frequency count
  kFREQUENCY_MAX = 25600/*30000*/,
  kFREQUENCY_MIN = 1600,

// Security configuration
  kLOCK = 0,
};

}  // namespace config
}  // namespace

// Entropy storage
static constexpr size_t kEntropyCount      = 16;  // In dwords
static constexpr size_t kEntropyCountBytes = (kEntropyCount << 2);  // In bytes

static uint32_t s_entropy[kEntropyCount];
static size_t s_entropySizeBytes = 0;  // Size in bytes

bool trng_is_started() {
  // Two checks:
  // 1. Clock is running
  // 2. "OK to stop" bit: asserted if the ring oscillator isn't running
  return (regs::CCM_CCGR6_TRNG != 0) && (regs::TRNG_MCTL_TSTOP_OK == 0);
}

// Restarts entropy generation.
static void restartEntropy() {
  (void)regs::TRNG->ENT[15];
  (void)regs::TRNG->ENT[0];  // Dummy read for defect workaround
  s_entropySizeBytes = 0;
}

FLASHMEM void trng_init() {
  // Enable the clock
  regs::CCM_CCGR6_TRNG = regs::kCCM_CCGR_ON;

  // Set program mode, clear pending errors, reset registers to default
  regs::TRNG->MCTL = regs::TRNG_MCTL_PRGM(1) | regs::TRNG_MCTL_ERR(1) |
                     regs::TRNG_MCTL_RST_DEF(1);

  // Apply configuration
  regs::TRNG->SCMISC = regs::TRNG_SCMISC_RTY_CT(config::kRETRY_COUNT) |
                       regs::TRNG_SCMISC_LRUN_MAX(config::kRUN_MAX_LIMIT);
  regs::TRNG->SCML   = regs::TRNG_SCML_MONO_RNG(config::kMONOBIT_RANGE) |
                       regs::TRNG_SCML_MONO_MAX(config::kMONOBIT_MAX);
  regs::TRNG->SCR1L  = regs::TRNG_SCR1L_RUN1_RNG(config::kRUNBIT1_RANGE) |
                       regs::TRNG_SCR1L_RUN1_MAX(config::kRUNBIT1_MAX);
  regs::TRNG->SCR2L  = regs::TRNG_SCR2L_RUN2_RNG(config::kRUNBIT2_RANGE) |
                       regs::TRNG_SCR2L_RUN2_MAX(config::kRUNBIT2_MAX);
  regs::TRNG->SCR3L  = regs::TRNG_SCR3L_RUN3_RNG(config::kRUNBIT3_RANGE) |
                       regs::TRNG_SCR3L_RUN3_MAX(config::kRUNBIT3_MAX);
  regs::TRNG->SCR4L  = regs::TRNG_SCR4L_RUN4_RNG(config::kRUNBIT4_RANGE) |
                       regs::TRNG_SCR4L_RUN4_MAX(config::kRUNBIT4_MAX);
  regs::TRNG->SCR5L  = regs::TRNG_SCR5L_RUN5_RNG(config::kRUNBIT5_RANGE) |
                       regs::TRNG_SCR5L_RUN5_MAX(config::kRUNBIT5_MAX);
  regs::TRNG->SCR6PL = regs::TRNG_SCR6PL_RUN6P_RNG(config::kRUNBIT6PLUS_RANGE) |
                       regs::TRNG_SCR6PL_RUN6P_MAX(config::kRUNBIT6PLUS_MAX);
  regs::TRNG->PKRMAX = regs::TRNG_PKRMAX_PKR_MAX(config::kPOKER_MAX);
  regs::TRNG->PKRRNG = regs::TRNG_PKRRNG_PKR_RNG(config::kPOKER_RANGE);
  regs::TRNG->FRQMAX = regs::TRNG_FRQMAX_FRQ_MAX(config::kFREQUENCY_MAX);
  regs::TRNG->FRQMIN = regs::TRNG_FRQMIN_FRQ_MIN(config::kFREQUENCY_MIN);

  // Clock settings
  regs::TRNG_MCTL_FOR_SCLK = config::kCLOCK_MODE;
  regs::TRNG_MCTL_OSC_DIV  = config::kRING_OSC_DIV;

  // Sampling
  regs::TRNG_MCTL_SAMP_MODE = config::kSAMPLE_MODE;
  regs::TRNG_SBLIM_SB_LIM   = config::kSPARSE_BIT_LIMIT;

  // Seed control
  regs::TRNG_SDCTL_ENT_DLY   = config::kENTROPY_DELAY;
  regs::TRNG_SDCTL_SAMP_SIZE = config::kSAMPLE_SIZE;

  // Security configuration
  regs::TRNG_SEC_CFG_NO_PRGM = config::kLOCK;

  regs::TRNG_MCTL_PRGM = 0;

  // Discard stale data
  restartEntropy();
}

FLASHMEM void trng_deinit() {
  regs::TRNG_MCTL_PRGM = 1;  // Move to program mode; stop entropy generation

  // Check this bit before stopping the clock
  while (regs::TRNG_MCTL_TSTOP_OK == 0) {
    // Wait
  }

  regs::CCM_CCGR6_TRNG = regs::kCCM_CCGR_OFF;  // Disable the clock
}

// Copies entropy into the local entropy buffer. It is assumed there's entropy
// available. This checks for an error, and if there is one, returns false.
[[nodiscard]]
static bool fillEntropyBuf() {
  // Check for an error
  if (regs::TRNG_MCTL_ERR != 0) {
    regs::TRNG_MCTL_ERR = 1;  // Clear error
    return false;
  }

  // Fill the array
  for (size_t i = 0; i < kEntropyCount; ++i) {
    s_entropy[i] = regs::TRNG->ENT[i];
  }
  (void)regs::TRNG->ENT[0];  // Dummy read after TRNG_ENT15 for defect workaround (according to SDK)
  s_entropySizeBytes = kEntropyCountBytes;

  return true;
}

// Fills the entropy pool if empty. This waits for entropy to be available or
// an error.
[[nodiscard]]
static bool fillEntropy() {
  if (s_entropySizeBytes != 0) {
    return true;
  }

  // Wait for either Valid or Error flag
  while ((regs::TRNG->MCTL &
          (regs::TRNG_MCTL_ENT_VAL(1) | regs::TRNG_MCTL_ERR(1))) == 0) {
  }

  return fillEntropyBuf();
}

// // Reads a single entropy byte.
// [[nodiscard]]
// static bool readEntropy(uint8_t* const b) {
//   if (!fillEntropy()) {
//     return false;
//   }
//   *b = (reinterpret_cast<uint8_t*>(
//       s_entropy))[kEntropyCountBytes - (s_entropySizeBytes--)];
//   return true;
// }

size_t trng_available() {
  if (s_entropySizeBytes == 0) {
    // Check for Valid
    if (regs::TRNG_MCTL_ENT_VAL == 0) {
      return 0;
    }
    if (!fillEntropyBuf()) {
      return 0;
    }
  }

  return s_entropySizeBytes;
}

size_t trng_data(void* const data, const size_t size) {
  // After a deep sleep exit, some error bits are set in MCTL and must be
  // cleared before continuing. Also, trigger new entropy generation to be sure
  // there's fresh bits.
  if (regs::TRNG_MCTL_ERR != 0) {
    regs::TRNG_MCTL_ERR = 1;  // Clear error

    // Restart entropy generation
    restartEntropy();
  }

  uint8_t* p = static_cast<uint8_t*>(data);
  size_t rem = size;

  while (rem != 0) {
    if (!fillEntropy()) {
      return size - rem;
    }
    const size_t toCopy = std::min(rem, s_entropySizeBytes);
    (void)std::memcpy(p,
                      &(reinterpret_cast<uint8_t*>(
                          s_entropy))[kEntropyCountBytes - s_entropySizeBytes],
                      toCopy);
    p += toCopy;
    s_entropySizeBytes -= toCopy;
    rem -= toCopy;
  }

  return size;
}

// Gathers a 32-bit random number and returns whether successful. This assumes
// that the argument is not NULL.
[[nodiscard]]
static inline bool random32(uint32_t* const r) {
  if (trng_data(r, sizeof(*r)) == sizeof(*r)) {
    return true;
  } else {
    errno = EIO;
    return false;
  }
}

bool entropy_random(uint32_t* const out) {
  uint32_t r;
  if (!random32(&r)) {
    return false;
  }
  *out = r;
  return true;
}

bool entropy_random_range(const uint32_t range, uint32_t* const out) {
  if (range == 0) {
    errno = EDOM;
    return false;
  }

  uint32_t r;
  if (!random32(&r)) {
    return false;
  }

  // Is power of 2?
  if ((range & (range - 1)) == 0) {
    *out = r & (range - 1);
    return true;
  }

  // Daniel Lemire's nearly-divisionless algorithm
  // https://lemire.me/blog/2019/09/28/doubling-the-speed-of-stduniform_int_distribution-in-the-gnu-c-library/
  // Note: There's not much impact if entropy generation takes much longer
  //       than division.
  uint64_t product = uint64_t{r} * uint64_t{range};
  uint32_t low = static_cast<uint32_t>(product);
  if (low < range) {  // Application of the rejection method
    const uint32_t threshold = -range % range;  // 2^L mod s = (2^L − s) mod s
    while (low < threshold) {
      if (!random32(&r)) {
        return false;
      }
      product = uint64_t{r} * uint64_t{range};
      low = static_cast<uint32_t>(product);
    }
  }
  *out = static_cast<uint32_t>(product >> 32);
  return true;
}

}  // namespace entropy
}  // namespace decept
