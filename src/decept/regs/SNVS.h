// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SNVS.h defines all the SNVS registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

// SNVS_HP and SNVS_LP layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_SNVS.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h

constexpr size_t kSNVS_LPZMKR_count        = 8;
constexpr size_t kSNVS_LPGPR0_LPGPR3_count = 4;
constexpr size_t kSNVS_LPGPR0_LPGPR7_count = 8;

struct SNVS_Layout {
  volatile uint32_t HPLR;                              /**< SNVS_HP Lock Register, offset: 0x0 */
  volatile uint32_t HPCOMR;                            /**< SNVS_HP Command Register, offset: 0x4 */
  volatile uint32_t HPCR;                              /**< SNVS_HP Control Register, offset: 0x8 */
  volatile uint32_t HPSICR;                            /**< SNVS_HP Security Interrupt Control Register, offset: 0xC */
  volatile uint32_t HPSVCR;                            /**< SNVS_HP Security Violation Control Register, offset: 0x10 */
  volatile uint32_t HPSR;                              /**< SNVS_HP Status Register, offset: 0x14 */
  volatile uint32_t HPSVSR;                            /**< SNVS_HP Security Violation Status Register, offset: 0x18 */
  volatile uint32_t HPHACIVR;                          /**< SNVS_HP High Assurance Counter IV Register, offset: 0x1C */
  volatile uint32_t HPHACR;                            /**< SNVS_HP High Assurance Counter Register, offset: 0x20 */
  volatile uint32_t HPRTCMR;                           /**< SNVS_HP Real Time Counter MSB Register, offset: 0x24 */
  volatile uint32_t HPRTCLR;                           /**< SNVS_HP Real Time Counter LSB Register, offset: 0x28 */
  volatile uint32_t HPTAMR;                            /**< SNVS_HP Time Alarm MSB Register, offset: 0x2C */
  volatile uint32_t HPTALR;                            /**< SNVS_HP Time Alarm LSB Register, offset: 0x30 */
  volatile uint32_t LPLR;                              /**< SNVS_LP Lock Register, offset: 0x34 */
  volatile uint32_t LPCR;                              /**< SNVS_LP Control Register, offset: 0x38 */
  volatile uint32_t LPMKCR;                            /**< SNVS_LP Master Key Control Register, offset: 0x3C */
  volatile uint32_t LPSVCR;                            /**< SNVS_LP Security Violation Control Register, offset: 0x40 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t LPSECR;                            /**< SNVS_LP Security Events Configuration Register, offset: 0x48 */
  volatile uint32_t LPSR;                              /**< SNVS_LP Status Register, offset: 0x4C */
  volatile uint32_t LPSRTCMR;                          /**< SNVS_LP Secure Real Time Counter MSB Register, offset: 0x50 */
  volatile uint32_t LPSRTCLR;                          /**< SNVS_LP Secure Real Time Counter LSB Register, offset: 0x54 */
  volatile uint32_t LPTAR;                             /**< SNVS_LP Time Alarm Register, offset: 0x58 */
  volatile uint32_t LPSMCMR;                           /**< SNVS_LP Secure Monotonic Counter MSB Register, offset: 0x5C */
  volatile uint32_t LPSMCLR;                           /**< SNVS_LP Secure Monotonic Counter LSB Register, offset: 0x60 */
  volatile uint32_t LPLVDR;                            /**< SNVS_LP Digital Low-Voltage Detector Register, offset: 0x64 */
  volatile uint32_t LPGPR0_LEGACY_ALIAS;               /**< SNVS_LP General Purpose Register 0 (legacy alias), offset: 0x68 */
  volatile uint32_t LPZMKR[kSNVS_LPZMKR_count];        /**< SNVS_LP Zeroizable Master Key Register, array offset: 0x6C, array step: 0x4 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t LPGPR_ALIAS[kSNVS_LPGPR0_LPGPR3_count]; /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x90, array step: 0x4 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t LPGPR[kSNVS_LPGPR0_LPGPR7_count];  /**< SNVS_LP General Purpose Registers 0 .. 7, array offset: 0x100, array step: 0x4 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[694];
  volatile uint32_t HPVIDR1;                           /**< SNVS_HP Version ID Register 1, offset: 0xBF8 */
  volatile uint32_t HPVIDR2;                           /**< SNVS_HP Version ID Register 2, offset: 0xBFC */
};

constexpr size_t    kSNVS_size = 0xC00;
constexpr uintptr_t kSNVS_base = 0x400D4000;

constexpr RegGroup<SNVS_Layout, kSNVS_size, kSNVS_base> SNVS;

#define SNVS_MEMBER(member) (kSNVS_base + offsetof(SNVS_Layout, member))

constexpr Reg<SNVS_MEMBER(HPCOMR), 1, 13> SNVS_HPCOMR_MKS_EN;
constexpr Reg<SNVS_MEMBER(HPSR),   1, 31> SNVS_HPSR_ZMK_ZERO_MASK;
constexpr Reg<SNVS_MEMBER(HPSVSR), 1, 27, true> SNVS_HPSVSR_ZMK_ECC_FAIL;  // Write to clear
constexpr Reg<SNVS_MEMBER(LPMKCR), 2,  0> SNVS_LPMKCR_MASTER_KEY_SEL;
constexpr Reg<SNVS_MEMBER(LPMKCR), 1,  2> SNVS_LPMKCR_ZMK_HWP;
constexpr Reg<SNVS_MEMBER(LPMKCR), 1,  3> SNVS_LPMKCR_ZMK_VAL;
constexpr Reg<SNVS_MEMBER(LPMKCR), 1,  4> SNVS_LPMKCR_ZMK_ECC_EN;

constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_OTPMK = 0;  /*!< One Time Programmable Master Key. */
constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_ZMK   = 2;  /*!< Zeroizable Master Key. */
constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_CMK   = 3;  /*!< Combined Master Key, it is XOR of OPTMK and ZMK. */

constexpr uint32_t kSNVS_LPMKCR_ZMK_HWP_SOFTWARE = 0;
constexpr uint32_t kSNVS_LPMKCR_ZMK_HWP_HARDWARE = 1;

#undef SNVS_MEMBER

}  // namespace regs
}  // namespace decept
