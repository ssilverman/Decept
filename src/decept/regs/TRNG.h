
// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TRNG.h defines all the TRNG registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

/** TRNG - Size of Registers Arrays */
constexpr size_t kTRNG_ENTA_count = 16;

// TRNG layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_TRNG.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct TRNG_Layout {
  volatile uint32_t MCTL;                              /**< Miscellaneous Control Register, offset: 0x0 */
  volatile uint32_t SCMISC;                            /**< Statistical Check Miscellaneous Register, offset: 0x4 */
  volatile uint32_t PKRRNG;                            /**< Poker Range Register, offset: 0x8 */
  union {                                          /* offset: 0xC */
    volatile uint32_t PKRMAX;                          /**< Poker Maximum Limit Register, offset: 0xC */
    const volatile uint32_t PKRSQ;                     /**< Poker Square Calculation Result Register, offset: 0xC */
  };
  volatile uint32_t SDCTL;                             /**< Seed Control Register, offset: 0x10 */
  union {                                          /* offset: 0x14 */
    volatile uint32_t SBLIM;                           /**< Sparse Bit Limit Register, offset: 0x14 */
    const volatile uint32_t TOTSAM;                    /**< Total Samples Register, offset: 0x14 */
  };
  volatile uint32_t FRQMIN;                            /**< Frequency Count Minimum Limit Register, offset: 0x18 */
  union {                                          /* offset: 0x1C */
    const volatile  uint32_t FRQCNT;                   /**< Frequency Count Register, offset: 0x1C */
    volatile uint32_t FRQMAX;                          /**< Frequency Count Maximum Limit Register, offset: 0x1C */
  };
  union {                                          /* offset: 0x20 */
    const volatile uint32_t SCMC;                      /**< Statistical Check Monobit Count Register, offset: 0x20 */
    volatile uint32_t SCML;                            /**< Statistical Check Monobit Limit Register, offset: 0x20 */
  };
  union {                                          /* offset: 0x24 */
    const volatile uint32_t SCR1C;                     /**< Statistical Check Run Length 1 Count Register, offset: 0x24 */
    volatile uint32_t SCR1L;                           /**< Statistical Check Run Length 1 Limit Register, offset: 0x24 */
  };
  union {                                          /* offset: 0x28 */
    const volatile uint32_t SCR2C;                     /**< Statistical Check Run Length 2 Count Register, offset: 0x28 */
    volatile uint32_t SCR2L;                           /**< Statistical Check Run Length 2 Limit Register, offset: 0x28 */
  };
  union {                                          /* offset: 0x2C */
    const volatile uint32_t SCR3C;                     /**< Statistical Check Run Length 3 Count Register, offset: 0x2C */
    volatile uint32_t SCR3L;                           /**< Statistical Check Run Length 3 Limit Register, offset: 0x2C */
  };
  union {                                          /* offset: 0x30 */
    const volatile uint32_t SCR4C;                     /**< Statistical Check Run Length 4 Count Register, offset: 0x30 */
    volatile uint32_t SCR4L;                           /**< Statistical Check Run Length 4 Limit Register, offset: 0x30 */
  };
  union {                                          /* offset: 0x34 */
    const volatile uint32_t SCR5C;                     /**< Statistical Check Run Length 5 Count Register, offset: 0x34 */
    volatile uint32_t SCR5L;                           /**< Statistical Check Run Length 5 Limit Register, offset: 0x34 */
  };
  union {                                          /* offset: 0x38 */
    const volatile uint32_t SCR6PC;                    /**< Statistical Check Run Length 6+ Count Register, offset: 0x38 */
    volatile uint32_t SCR6PL;                          /**< Statistical Check Run Length 6+ Limit Register, offset: 0x38 */
  };
  const volatile uint32_t STATUS;                      /**< Status Register, offset: 0x3C */
  const volatile uint32_t ENT[kTRNG_ENTA_count];       /**< Entropy Read Register, array offset: 0x40, array step: 0x4 */
  const volatile uint32_t PKRCNT10;                    /**< Statistical Check Poker Count 1 and 0 Register, offset: 0x80 */
  const volatile uint32_t PKRCNT32;                    /**< Statistical Check Poker Count 3 and 2 Register, offset: 0x84 */
  const volatile uint32_t PKRCNT54;                    /**< Statistical Check Poker Count 5 and 4 Register, offset: 0x88 */
  const volatile uint32_t PKRCNT76;                    /**< Statistical Check Poker Count 7 and 6 Register, offset: 0x8C */
  const volatile uint32_t PKRCNT98;                    /**< Statistical Check Poker Count 9 and 8 Register, offset: 0x90 */
  const volatile uint32_t PKRCNTBA;                    /**< Statistical Check Poker Count B and A Register, offset: 0x94 */
  const volatile uint32_t PKRCNTDC;                    /**< Statistical Check Poker Count D and C Register, offset: 0x98 */
  const volatile uint32_t PKRCNTFE;                    /**< Statistical Check Poker Count F and E Register, offset: 0x9C */
  volatile uint32_t SEC_CFG;                           /**< Security Configuration Register, offset: 0xA0 */
  volatile uint32_t INT_CTRL;                          /**< Interrupt Control Register, offset: 0xA4 */
  volatile uint32_t INT_MASK;                          /**< Mask Register, offset: 0xA8 */
  const volatile uint32_t INT_STATUS;                  /**< Interrupt Status Register, offset: 0xAC */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[16];
  const volatile uint32_t VID1;                        /**< Version ID Register (MS), offset: 0xF0 */
  const volatile uint32_t VID2;                        /**< Version ID Register (LS), offset: 0xF4 */
};

constexpr size_t    kTRNG_size = 0xF8;
constexpr uintptr_t kTRNG_base = 0x400CC000;

constexpr RegGroup<TRNG_Layout, kTRNG_size, kTRNG_base> TRNG;

#define DECEPT_REGS_TRNG_MEMBER(member) \
  (decept::regs::kTRNG_base + offsetof(decept::regs::TRNG_Layout, member))

constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1, 16> TRNG_MCTL_PRGM;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1, 13> TRNG_MCTL_TSTOP_OK;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1, 12> TRNG_MCTL_ERR;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1, 10> TRNG_MCTL_ENT_VAL;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1,  7> TRNG_MCTL_FOR_SCLK;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     1,  6> TRNG_MCTL_RST_DEF;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     2,  2> TRNG_MCTL_OSC_DIV;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(MCTL),     2,  0> TRNG_MCTL_SAMP_MODE;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCMISC),   4, 16> TRNG_SCMISC_RTY_CT;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCMISC),   8,  0> TRNG_SCMISC_LRUN_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(PKRRNG),  16,  0> TRNG_PKRRNG_PKR_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(PKRMAX),  24,  0> TRNG_PKRMAX_PKR_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SDCTL),   16, 16> TRNG_SDCTL_ENT_DLY;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SDCTL),   16,  0> TRNG_SDCTL_SAMP_SIZE;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SBLIM),   10,  0> TRNG_SBLIM_SB_LIM;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(FRQMIN),  22,  0> TRNG_FRQMIN_FRQ_MIN;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(FRQMAX),  22,  0> TRNG_FRQMAX_FRQ_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCML),    16, 16> TRNG_SCML_MONO_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCML),    16,  0> TRNG_SCML_MONO_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR1L),   15, 16> TRNG_SCR1L_RUN1_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR1L),   15,  0> TRNG_SCR1L_RUN1_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR2L),   14, 16> TRNG_SCR2L_RUN2_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR2L),   14,  0> TRNG_SCR2L_RUN2_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR3L),   13, 16> TRNG_SCR3L_RUN3_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR3L),   13,  0> TRNG_SCR3L_RUN3_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR4L),   12, 16> TRNG_SCR4L_RUN4_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR4L),   12,  0> TRNG_SCR4L_RUN4_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR5L),   11, 16> TRNG_SCR5L_RUN5_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR5L),   11,  0> TRNG_SCR5L_RUN5_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR6PL),  11, 16> TRNG_SCR6PL_RUN6P_RNG;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SCR6PL),  11,  0> TRNG_SCR6PL_RUN6P_MAX;
constexpr Reg<DECEPT_REGS_TRNG_MEMBER(SEC_CFG),  1,  1> TRNG_SEC_CFG_NO_PRGM;

}  // namespace regs
}  // namespace decept
