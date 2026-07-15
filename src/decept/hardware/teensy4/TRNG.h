
// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// TRNG.h defines all the TRNG registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

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
    const volatile uint32_t FRQCNT;                    /**< Frequency Count Register, offset: 0x1C */
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
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[16];
  const volatile uint32_t VID1;                        /**< Version ID Register (MS), offset: 0xF0 */
  const volatile uint32_t VID2;                        /**< Version ID Register (LS), offset: 0xF4 */
};

constexpr size_t    kTRNG_size = 0xF8;
constexpr uintptr_t kTRNG_base = 0x400CC000;

constexpr regs::RegGroup<TRNG_Layout, kTRNG_size, kTRNG_base> TRNG;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using TRNG_Reg = regs::Reg<uint32_t, kTRNG_base, TRNG_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// Miscellaneous Control Register
#undef TRNG_MCTL_PRGM
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 16> TRNG_MCTL_PRGM;
#undef TRNG_MCTL_LRUN_CONT
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 14> TRNG_MCTL_LRUN_CONT;
#undef TRNG_MCTL_TSTOP_OK
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 13> TRNG_MCTL_TSTOP_OK;
#undef TRNG_MCTL_ERR
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 12> TRNG_MCTL_ERR;
#undef TRNG_MCTL_TST_OUT
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 11> TRNG_MCTL_TST_OUT;
#undef TRNG_MCTL_ENT_VAL
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1, 10> TRNG_MCTL_ENT_VAL;
#undef TRNG_MCTL_FCT_VAL
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  9> TRNG_MCTL_FCT_VAL;
#undef TRNG_MCTL_FCT_FAIL
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  8> TRNG_MCTL_FCT_FAIL;
#undef TRNG_MCTL_FOR_SCLK
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  7> TRNG_MCTL_FOR_SCLK;
#undef TRNG_MCTL_RST_DEF
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  6> TRNG_MCTL_RST_DEF;
#undef TRNG_MCTL_UNUSED5
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  5> TRNG_MCTL_UNUSED5;
#undef TRNG_MCTL_UNUSED4
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 1,  4> TRNG_MCTL_UNUSED4;
#undef TRNG_MCTL_OSC_DIV
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 2,  2> TRNG_MCTL_OSC_DIV;
    // 1/2^value
#undef TRNG_MCTL_SAMP_MODE
constexpr TRNG_Reg<&TRNG_Layout::MCTL, 2,  0> TRNG_MCTL_SAMP_MODE;
    // 0b00..use Von Neumann data into both Entropy shifter and Statistical Checker
    // 0b01..use raw data into both Entropy shifter and Statistical Checker
    // 0b10..use Von Neumann data into Entropy shifter. Use raw data into Statistical Checker
    // 0b11..undefined/reserved.

// Statistical Check Miscellaneous Register
#undef TRNG_SCMISC_RTY_CT
constexpr TRNG_Reg<&TRNG_Layout::SCMISC, 4, 16> TRNG_SCMISC_RTY_CT;
#undef TRNG_SCMISC_LRUN_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCMISC, 8,  0> TRNG_SCMISC_LRUN_MAX;

// Poker Range Register
#undef TRNG_PKRRNG_PKR_RNG
constexpr TRNG_Reg<&TRNG_Layout::PKRRNG,  16,  0> TRNG_PKRRNG_PKR_RNG;

// Poker Maximum Limit Register
#undef TRNG_PKRMAX_PKR_MAX
constexpr TRNG_Reg<&TRNG_Layout::PKRMAX, 24, 0> TRNG_PKRMAX_PKR_MAX;

// Poker Square Calculation Result Register
#undef TRNG_PKRSQ_PKR_SQ
constexpr TRNG_Reg<&TRNG_Layout::PKRSQ, 24, 0> TRNG_PKRSQ_PKR_SQ;

// Seed Control Register
#undef TRNG_SDCTL_ENT_DLY
constexpr TRNG_Reg<&TRNG_Layout::SDCTL, 16, 16> TRNG_SDCTL_ENT_DLY;
#undef TRNG_SDCTL_SAMP_SIZE
constexpr TRNG_Reg<&TRNG_Layout::SDCTL, 16,  0> TRNG_SDCTL_SAMP_SIZE;

// Sparse Bit Limit Register
#undef TRNG_SBLIM_SB_LIM
constexpr TRNG_Reg<&TRNG_Layout::SBLIM, 10, 0> TRNG_SBLIM_SB_LIM;

// Total Samples Register
#undef TRNG_TOTSAM_TOT_SAM
constexpr TRNG_Reg<&TRNG_Layout::TOTSAM, 20, 0> TRNG_TOTSAM_TOT_SAM;

// Frequency Count Minimum Limit Register
#undef TRNG_FRQMIN_FRQ_MIN
constexpr TRNG_Reg<&TRNG_Layout::FRQMIN, 22,  0> TRNG_FRQMIN_FRQ_MIN;

// Frequency Count Register
#undef TRNG_FRQCNT_FRQ_CT
constexpr TRNG_Reg<&TRNG_Layout::FRQCNT, 22, 0> TRNG_FRQCNT_FRQ_CT;

// Frequency Count Maximum Limit Register
#undef TRNG_FRQMAX_FRQ_MAX
constexpr TRNG_Reg<&TRNG_Layout::FRQMAX, 22,  0> TRNG_FRQMAX_FRQ_MAX;

// Statistical Check Monobit Count Register
#undef TRNG_SCMC_MONO_CT
constexpr TRNG_Reg<&TRNG_Layout::SCMC, 16, 0> TRNG_SCMC_MONO_CT;

// Statistical Check Monobit Limit Register
#undef TRNG_SCML_MONO_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCML, 16, 16> TRNG_SCML_MONO_RNG;
#undef TRNG_SCML_MONO_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCML, 16,  0> TRNG_SCML_MONO_MAX;

// Statistical Check Run Length 1 Count Register
#undef TRNG_SCR1C_R1_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR1C, 15, 16> TRNG_SCR1C_R1_1_CT;
#undef TRNG_SCR1C_R1_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR1C, 15,  0> TRNG_SCR1C_R1_0_CT;

// Statistical Check Run Length 1 Limit Register
#undef TRNG_SCR1L_RUN1_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR1L, 15, 16> TRNG_SCR1L_RUN1_RNG;
#undef TRNG_SCR1L_RUN1_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR1L, 15,  0> TRNG_SCR1L_RUN1_MAX;

// Statistical Check Run Length 2 Count Register
#undef TRNG_SCR2C_R2_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR2C, 14, 16> TRNG_SCR2C_R2_1_CT;
#undef TRNG_SCR2C_R2_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR2C, 14,  0> TRNG_SCR2C_R2_0_CT;

// Statistical Check Run Length 2 Limit Register
#undef TRNG_SCR2L_RUN2_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR2L, 14, 16> TRNG_SCR2L_RUN2_RNG;
#undef TRNG_SCR2L_RUN2_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR2L, 14,  0> TRNG_SCR2L_RUN2_MAX;

// Statistical Check Run Length 3 Count Register
#undef TRNG_SCR3C_R3_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR3C, 13, 16> TRNG_SCR3C_R3_1_CT;
#undef TRNG_SCR3C_R3_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR3C, 13,  0> TRNG_SCR3C_R3_0_CT;

// Statistical Check Run Length 3 Limit Register
#undef TRNG_SCR3L_RUN3_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR3L, 13, 16> TRNG_SCR3L_RUN3_RNG;
#undef TRNG_SCR3L_RUN3_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR3L, 13,  0> TRNG_SCR3L_RUN3_MAX;

// Statistical Check Run Length 4 Count Register
#undef TRNG_SCR4C_R4_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR4C, 12, 16> TRNG_SCR4C_R4_1_CT;
#undef TRNG_SCR4C_R4_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR4C, 12,  0> TRNG_SCR4C_R4_0_CT;

// Statistical Check Run Length 4 Limit Register
#undef TRNG_SCR4L_RUN4_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR4L, 12, 16> TRNG_SCR4L_RUN4_RNG;
#undef TRNG_SCR4L_RUN4_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR4L, 12,  0> TRNG_SCR4L_RUN4_MAX;

// Statistical Check Run Length 5 Count Register
#undef TRNG_SCR5C_R5_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR5C, 11, 16> TRNG_SCR5C_R5_1_CT;
#undef TRNG_SCR5C_R5_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR5C, 11,  0> TRNG_SCR5C_R5_0_CT;

// Statistical Check Run Length 5 Limit Register
#undef TRNG_SCR5L_RUN5_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR5L, 11, 16> TRNG_SCR5L_RUN5_RNG;
#undef TRNG_SCR5L_RUN5_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR5L, 11,  0> TRNG_SCR5L_RUN5_MAX;

// Statistical Check Run Length 6+ Count Register
#undef TRNG_SCR6PC_R6P_1_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR6PC, 11, 16> TRNG_SCR6PC_R6P_1_CT;
#undef TRNG_SCR6PC_R6P_0_CT
constexpr TRNG_Reg<&TRNG_Layout::SCR6PC, 11,  0> TRNG_SCR6PC_R6P_0_CT;

// Statistical Check Run Length 6+ Limit Register
#undef TRNG_SCR6PL_RUN6P_RNG
constexpr TRNG_Reg<&TRNG_Layout::SCR6PL, 11, 16> TRNG_SCR6PL_RUN6P_RNG;
#undef TRNG_SCR6PL_RUN6P_MAX
constexpr TRNG_Reg<&TRNG_Layout::SCR6PL, 11,  0> TRNG_SCR6PL_RUN6P_MAX;

// Status Register
#undef TRNG_STATUS_RETRY_CT
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 4, 16> TRNG_STATUS_RETRY_CT;
#undef TRNG_STATUS_TFMB
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 15> TRNG_STATUS_TFMB;
#undef TRNG_STATUS_TFP
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 14> TRNG_STATUS_TFP;
#undef TRNG_STATUS_TFLR
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 13> TRNG_STATUS_TFLR;
#undef TRNG_STATUS_TFSB
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 12> TRNG_STATUS_TFSB;
#undef TRNG_STATUS_TF6BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 11> TRNG_STATUS_TF6BR1;
#undef TRNG_STATUS_TF6BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1, 10> TRNG_STATUS_TF6BR0;
#undef TRNG_STATUS_TF5BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  9> TRNG_STATUS_TF5BR1;
#undef TRNG_STATUS_TF5BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  8> TRNG_STATUS_TF5BR0;
#undef TRNG_STATUS_TF4BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  7> TRNG_STATUS_TF4BR1;
#undef TRNG_STATUS_TF4BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  6> TRNG_STATUS_TF4BR0;
#undef TRNG_STATUS_TF3BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  5> TRNG_STATUS_TF3BR1;
#undef TRNG_STATUS_TF3BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  4> TRNG_STATUS_TF3BR0;
#undef TRNG_STATUS_TF2BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  3> TRNG_STATUS_TF2BR1;
#undef TRNG_STATUS_TF2BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  2> TRNG_STATUS_TF2BR0;
#undef TRNG_STATUS_TF1BR1
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  1> TRNG_STATUS_TF1BR1;
#undef TRNG_STATUS_TF1BR0
constexpr TRNG_Reg<&TRNG_Layout::STATUS, 1,  0> TRNG_STATUS_TF1BR0;

// Statistical Check Poker Count 1 and 0 Register
#undef TRNG_PKRCNT10_PKR_1_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT10, 16, 16> TRNG_PKRCNT10_PKR_1_CT;
#undef TRNG_PKRCNT10_PKR_0_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT10, 16,  0> TRNG_PKRCNT10_PKR_0_CT;

// Statistical Check Poker Count 3 and 2 Register
#undef TRNG_PKRCNT32_PKR_3_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT32, 16, 16> TRNG_PKRCNT32_PKR_3_CT;
#undef TRNG_PKRCNT32_PKR_2_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT32, 16,  0> TRNG_PKRCNT32_PKR_2_CT;

// Statistical Check Poker Count 5 and 4 Register
#undef TRNG_PKRCNT54_PKR_5_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT54, 16, 16> TRNG_PKRCNT54_PKR_5_CT;
#undef TRNG_PKRCNT54_PKR_4_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT54, 16,  0> TRNG_PKRCNT54_PKR_4_CT;

// Statistical Check Poker Count 7 and 6 Register
#undef TRNG_PKRCNT76_PKR_7_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT76, 16, 16> TRNG_PKRCNT76_PKR_7_CT;
#undef TRNG_PKRCNT76_PKR_6_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT76, 16,  0> TRNG_PKRCNT76_PKR_6_CT;

// Statistical Check Poker Count 9 and 8 Register
#undef TRNG_PKRCNT98_PKR_9_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT98, 16, 16> TRNG_PKRCNT98_PKR_9_CT;
#undef TRNG_PKRCNT98_PKR_8_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNT98, 16,  0> TRNG_PKRCNT98_PKR_8_CT;

// Statistical Check Poker Count B and A Register
#undef TRNG_PKRCNTBA_PKR_B_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTBA, 16, 16> TRNG_PKRCNTBA_PKR_B_CT;
#undef TRNG_PKRCNTBA_PKR_A_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTBA, 16,  0> TRNG_PKRCNTBA_PKR_A_CT;

// Statistical Check Poker Count D and C Register
#undef TRNG_PKRCNTDC_PKR_D_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTDC, 16, 16> TRNG_PKRCNTDC_PKR_D_CT;
#undef TRNG_PKRCNTDC_PKR_C_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTDC, 16,  0> TRNG_PKRCNTDC_PKR_C_CT;

// Statistical Check Poker Count F and E Register
#undef TRNG_PKRCNTFE_PKR_F_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTFE, 16, 16> TRNG_PKRCNTFE_PKR_F_CT;
#undef TRNG_PKRCNTFE_PKR_E_CT
constexpr TRNG_Reg<&TRNG_Layout::PKRCNTFE, 16,  0> TRNG_PKRCNTFE_PKR_E_CT;

#undef TRNG_SEC_CFG_UNUSED2
constexpr TRNG_Reg<&TRNG_Layout::SEC_CFG, 1, 2> TRNG_SEC_CFG_UNUSED2;
#undef TRNG_SEC_CFG_NO_PRGM
constexpr TRNG_Reg<&TRNG_Layout::SEC_CFG, 1, 1> TRNG_SEC_CFG_NO_PRGM;
    // 0b0..Programability of registers controlled only by the Miscellaneous Control Register's access mode bit.
    // 0b1..Overides Miscellaneous Control Register access mode and prevents TRNG register programming.
#undef TRNG_SEC_CFG_UNUSED0
constexpr TRNG_Reg<&TRNG_Layout::SEC_CFG, 1, 0> TRNG_SEC_CFG_UNUSED0;

// Interrupt Control Register
// 0b0..Corresponding bit of INT_STATUS register cleared.
// 0b1..Corresponding bit of INT_STATUS register active.
#undef TRNG_INT_CTRL_UNUSED
constexpr TRNG_Reg<&TRNG_Layout::INT_CTRL, 29, 3> TRNG_INT_CTRL_UNUSED;
#undef TRNG_INT_CTRL_FRQ_CT_FAIL
constexpr TRNG_Reg<&TRNG_Layout::INT_CTRL, 1,  2> TRNG_INT_CTRL_FRQ_CT_FAIL;
#undef TRNG_INT_CTRL_ENT_VAL
constexpr TRNG_Reg<&TRNG_Layout::INT_CTRL, 1,  1> TRNG_INT_CTRL_ENT_VAL;
#undef TRNG_INT_CTRL_HW_ERR
constexpr TRNG_Reg<&TRNG_Layout::INT_CTRL, 1,  0> TRNG_INT_CTRL_HW_ERR;

// Mask Register
// 0b0..Corresponding interrupt of INT_STATUS is masked.
// 0b1..Corresponding bit of INT_STATUS is active.
#undef TRNG_INT_MASK_FRQ_CT_FAIL
constexpr TRNG_Reg<&TRNG_Layout::INT_MASK, 1, 2> TRNG_INT_MASK_FRQ_CT_FAIL;
    // 0b0..Same behavior as bit 0 of this register.
    // 0b1..Same behavior as bit 0 of this register.
#undef TRNG_INT_MASK_ENT_VAL
constexpr TRNG_Reg<&TRNG_Layout::INT_MASK, 1, 1> TRNG_INT_MASK_ENT_VAL;
    // 0b0..Same behavior as bit 0 of this register.
    // 0b1..Same behavior as bit 0 of this register.
#undef TRNG_INT_MASK_HW_ERR
constexpr TRNG_Reg<&TRNG_Layout::INT_MASK, 1, 0> TRNG_INT_MASK_HW_ERR;
    // 0b0..Corresponding interrupt of INT_STATUS is masked.
    // 0b1..Corresponding bit of INT_STATUS is active.

// Interrupt Status Register
#undef TRNG_INT_STATUS_FRQ_CT_FAIL
constexpr TRNG_Reg<&TRNG_Layout::INT_STATUS, 1, 2> TRNG_INT_STATUS_FRQ_CT_FAIL;
    // 0b0..No hardware nor self test frequency errors.
    // 0b1..The frequency counter has detected a failure.
#undef TRNG_INT_STATUS_ENT_VAL
constexpr TRNG_Reg<&TRNG_Layout::INT_STATUS, 1, 1> TRNG_INT_STATUS_ENT_VAL;
    // 0b0..Busy generation entropy. Any value read is invalid.
    // 0b1..TRNG can be stopped and entropy is valid if read.
#undef TRNG_INT_STATUS_HW_ERR
constexpr TRNG_Reg<&TRNG_Layout::INT_STATUS, 1, 0> TRNG_INT_STATUS_HW_ERR;
    // 0b0..no error
    // 0b1..error detected.

// Version ID Register (MS)
#undef TRNG_VID1_IP_ID
constexpr TRNG_Reg<&TRNG_Layout::VID1, 16, 16> TRNG_VID1_IP_ID;
    // 0b0000000000110000..ID for TRNG.
#undef TRNG_VID1_MAJ_REV
constexpr TRNG_Reg<&TRNG_Layout::VID1,  8,  8> TRNG_VID1_MAJ_REV;
    // 0b00000001..Major revision number for TRNG.
#undef TRNG_VID1_MIN_REV
constexpr TRNG_Reg<&TRNG_Layout::VID1,  8,  0> TRNG_VID1_MIN_REV;
    // 0b00000000..Minor revision number for TRNG.

// Version ID Register (LS)
#undef TRNG_VID2_ERA
constexpr TRNG_Reg<&TRNG_Layout::VID2, 8, 24> TRNG_VID2_ERA;
    // 0b00000000..COMPILE_OPT for TRNG.
#undef TRNG_VID2_INTG_OPT
constexpr TRNG_Reg<&TRNG_Layout::VID2, 8, 16> TRNG_VID2_INTG_OPT;
    // 0b00000000..INTG_OPT for TRNG.
#undef TRNG_VID2_ECO_REV
constexpr TRNG_Reg<&TRNG_Layout::VID2, 8,  8> TRNG_VID2_ECO_REV;
    // 0b00000000..TRNG_ECO_REV for TRNG.
#undef TRNG_VID2_CONFIG_OPT
constexpr TRNG_Reg<&TRNG_Layout::VID2, 8,  0> TRNG_VID2_CONFIG_OPT;
    // 0b00000000..TRNG_CONFIG_OPT for TRNG.

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
