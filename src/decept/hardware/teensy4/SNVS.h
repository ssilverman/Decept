// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SNVS.h defines all the SNVS registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

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
  const volatile uint32_t HPHACR;                      /**< SNVS_HP High Assurance Counter Register, offset: 0x20 */
  volatile uint32_t HPRTCMR;                           /**< SNVS_HP Real Time Counter MSB Register, offset: 0x24 */
  volatile uint32_t HPRTCLR;                           /**< SNVS_HP Real Time Counter LSB Register, offset: 0x28 */
  volatile uint32_t HPTAMR;                            /**< SNVS_HP Time Alarm MSB Register, offset: 0x2C */
  volatile uint32_t HPTALR;                            /**< SNVS_HP Time Alarm LSB Register, offset: 0x30 */
  volatile uint32_t LPLR;                              /**< SNVS_LP Lock Register, offset: 0x34 */
  volatile uint32_t LPCR;                              /**< SNVS_LP Control Register, offset: 0x38 */
  volatile uint32_t LPMKCR;                            /**< SNVS_LP Master Key Control Register, offset: 0x3C */
  volatile uint32_t LPSVCR;                            /**< SNVS_LP Security Violation Control Register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
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
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t LPGPR_ALIAS[kSNVS_LPGPR0_LPGPR3_count]; /**< SNVS_LP General Purpose Registers 0 .. 3, array offset: 0x90, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[24];
  volatile uint32_t LPGPR[kSNVS_LPGPR0_LPGPR7_count];  /**< SNVS_LP General Purpose Registers 0 .. 7, array offset: 0x100, array step: 0x4 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[694];
  const volatile uint32_t HPVIDR1;                     /**< SNVS_HP Version ID Register 1, offset: 0xBF8 */
  const volatile uint32_t HPVIDR2;                     /**< SNVS_HP Version ID Register 2, offset: 0xBFC */
};

constexpr size_t    kSNVS_size = 0xC00;
constexpr uintptr_t kSNVS_base = 0x400D4000;

constexpr regs::RegGroup<SNVS_Layout, kSNVS_size, kSNVS_base> SNVS;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using SNVS_Reg = regs::Reg<uint32_t, kSNVS_base, SNVS_Layout, Member, 0, Bits,
                           Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// SNVS_HP Lock Register
#undef SNVS_HPLR_ZMK_WSL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  0> SNVS_HPLR_ZMK_WSL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_ZMK_RSL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  1> SNVS_HPLR_ZMK_RSL;
    // 0b0..Read access is allowed (only in software Programming mode)
    // 0b1..Read access is not allowed
#undef SNVS_HPLR_SRTC_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  2> SNVS_HPLR_SRTC_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_LPCALB_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  3> SNVS_HPLR_LPCALB_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_MC_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  4> SNVS_HPLR_MC_SL;
    // 0b0..Write access (increment) is allowed
    // 0b1..Write access (increment) is not allowed
#undef SNVS_HPLR_GPR_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  5> SNVS_HPLR_GPR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_LPSVCR_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  6> SNVS_HPLR_LPSVCR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_LPSECR_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  8> SNVS_HPLR_LPSECR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_MKS_SL
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  9> SNVS_HPLR_MKS_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_HPSVCR_L
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 16> SNVS_HPLR_HPSVCR_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_HPSICR_L
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 17> SNVS_HPLR_HPSICR_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
#undef SNVS_HPLR_HAC_L
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 18> SNVS_HPLR_HAC_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed

//  SNVS_HP Command Register
#undef SNVS_HPCOMR_NPSWA_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 31> SNVS_HPCOMR_NPSWA_EN;
#undef SNVS_HPCOMR_HAC_STOP
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 19> SNVS_HPCOMR_HAC_STOP;
#undef SNVS_HPCOMR_HAC_CLEAR
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 18> SNVS_HPCOMR_HAC_CLEAR;
    // 0b0..No Action
    // 0b1..Clear the HAC
#undef SNVS_HPCOMR_HAC_LOAD
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 17> SNVS_HPCOMR_HAC_LOAD;
    // 0b0..No Action
    // 0b1..Load the HAC
#undef SNVS_HPCOMR_HAC_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 16> SNVS_HPCOMR_HAC_EN;
    // 0b0..High Assurance Counter is disabled
    // 0b1..High Assurance Counter is enable
#undef SNVS_HPCOMR_MKS_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 13> SNVS_HPCOMR_MKS_EN;
    // 0b0..OTP master key is selected as an SNVS master key
    // 0b1..SNVS master key is selected according to the setting of the MASTER_KEY_SEL field of LPMKCR
#undef SNVS_HPCOMR_PROG_ZMK
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 12> SNVS_HPCOMR_PROG_ZMK;
    // 0b0..No Action
    // 0b1..Activate hardware key programming mechanism
#undef SNVS_HPCOMR_SW_LPSV
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 10> SNVS_HPCOMR_SW_LPSV;
#undef SNVS_HPCOMR_SW_FSV
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  9> SNVS_HPCOMR_SW_FSV;
#undef SNVS_HPCOMR_SW_SV
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  8> SNVS_HPCOMR_SW_SV;
#undef SNVS_HPCOMR_LP_SWR_DIS
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  5> SNVS_HPCOMR_LP_SWR_DIS;
    // 0b0..LP software reset is enabled
    // 0b1..LP software reset is disabled
#undef SNVS_HPCOMR_LP_SWR
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  4> SNVS_HPCOMR_LP_SWR;
    // 0b0..No Action
    // 0b1..Reset LP section
#undef SNVS_HPCOMR_SSM_SFNS_DIS
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  2>  SNVS_HPCOMR_SSM_SFNS_DIS;
    // 0b0..Soft Fail to Non-Secure State transition is enabled
    // 0b1..Soft Fail to Non-Secure State transition is disabled
#undef SNVS_HPCOMR_SSM_ST_DIS
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  1> SNVS_HPCOMR_SSM_ST_DIS;
    // 0b0..Secure to Trusted State transition is enabled
    // 0b1..Secure to Trusted State transition is disabled
#undef SNVS_HPCOMR_SSM_ST
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  0> SNVS_HPCOMR_SSM_ST;

// SNVS_HP Control Register
#undef SNVS_HPCR_BTN_MASK
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1, 27> SNVS_HPCR_BTN_MASK;
#undef SNVS_HPCR_BTN_CONFIG
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 3, 24> SNVS_HPCR_BTN_CONFIG;
#undef SNVS_HPCR_HP_TS
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1, 16> SNVS_HPCR_HP_TS;
    // 0b0..No Action
    // 0b1..Synchronize the HP Time Counter to the LP Time Counter
#undef SNVS_HPCR_HPCALB_VAL
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 5, 10> SNVS_HPCR_HPCALB_VAL;
    // Signed 5-bit value: counts per each 32768 ticks of the counter:
    // 0b00000..+0 counts per each 32768 ticks of the counter
    // 0b00001..+1 counts per each 32768 ticks of the counter
    // 0b00010..+2 counts per each 32768 ticks of the counter
    // 0b01111..+15 counts per each 32768 ticks of the counter
    // 0b10000..-16 counts per each 32768 ticks of the counter
    // 0b10001..-15 counts per each 32768 ticks of the counter
    // 0b11110..-2 counts per each 32768 ticks of the counter
    // 0b11111..-1 counts per each 32768 ticks of the counter
#undef SNVS_HPCR_HPCALB_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  8> SNVS_HPCR_HPCALB_EN;
    // 0b0..HP Timer calibration disabled
    // 0b1..HP Timer calibration enabled
#undef SNVS_HPCR_PI_FREQ
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 4,  4> SNVS_HPCR_PI_FREQ;
    // Bit 'value'  of the HPRTCLR is selected as a source of the periodic interrupt
#undef SNVS_HPCR_PI_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  3> SNVS_HPCR_PI_EN;
    // 0b0..HP Periodic Interrupt is disabled
    // 0b1..HP Periodic Interrupt is enabled
#undef SNVS_HPCR_DIS_PI
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  2> SNVS_HPCR_DIS_PI;
    // 0b0..Periodic interrupt will trigger a functional interrupt
    // 0b1..Disable periodic interrupt in the function interrupt
#undef SNVS_HPCR_HPTA_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  1> SNVS_HPCR_HPTA_EN;
    // 0b0..HP Time Alarm Interrupt is disabled
    // 0b1..HP Time Alarm Interrupt is enabled
#undef SNVS_HPCR_RTC_EN
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  0> SNVS_HPCR_RTC_EN;
    // 0b0..RTC is disabled
    // 0b1..RTC is enabled

// SNVS_HP Security Interrupt Control Register
#undef SNVS_HPSICR_LPSVI_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1, 31> SNVS_HPSICR_LPSVI_EN;
    // 0b0..LP Security Violation Interrupt is Disabled
    // 0b1..LP Security Violation Interrupt is Enabled
#undef SNVS_HPSICR_SV5_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  5> SNVS_HPSICR_SV5_EN;
    // 0b0..Security Violation 5 Interrupt is Disabled
    // 0b1..Security Violation 5 Interrupt is Enabled
#undef SNVS_HPSICR_SV4_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  4> SNVS_HPSICR_SV4_EN;
    // 0b0..Security Violation 4 Interrupt is Disabled
    // 0b1..Security Violation 4 Interrupt is Enabled
#undef SNVS_HPSICR_SV3_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  3> SNVS_HPSICR_SV3_EN;
    // 0b0..Security Violation 3 Interrupt is Disabled
    // 0b1..Security Violation 3 Interrupt is Enabled
#undef SNVS_HPSICR_SV2_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  2> SNVS_HPSICR_SV2_EN;
    // 0b0..Security Violation 2 Interrupt is Disabled
    // 0b1..Security Violation 2 Interrupt is Enabled
#undef SNVS_HPSICR_SV1_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  1> SNVS_HPSICR_SV1_EN;
    // 0b0..Security Violation 1 Interrupt is Disabled
    // 0b1..Security Violation 1 Interrupt is Enabled
#undef SNVS_HPSICR_SV0_EN
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  0> SNVS_HPSICR_SV0_EN;
    // 0b0..Security Violation 0 Interrupt is Disabled
    // 0b1..Security Violation 0 Interrupt is Enabled

// SNVS_HP Security Violation Control Register
#undef SNVS_HPSVCR_LPSV_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 2, 30> SNVS_HPSVCR_LPSV_CFG;
    // 0b00..LP security violation is disabled
    // 0b01..LP security violation is a non-fatal violation
    // 0b1x..LP security violation is a fatal violation
#undef SNVS_HPSVCR_SV5_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 2,  5> SNVS_HPSVCR_SV5_CFG;
    // 0b00..Security Violation 5 is disabled
    // 0b01..Security Violation 5 is a non-fatal violation
    // 0b1x..Security Violation 5 is a fatal violation
#undef SNVS_HPSVCR_SV4_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  4> SNVS_HPSVCR_SV4_CFG;
    // 0b0..Security Violation 4 is a non-fatal violation
    // 0b1..Security Violation 4 is a fatal violation
#undef SNVS_HPSVCR_SV3_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  3> SNVS_HPSVCR_SV3_CFG;
    // 0b0..Security Violation 3 is a non-fatal violation
    // 0b1..Security Violation 3 is a fatal violation
#undef SNVS_HPSVCR_SV2_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  2> SNVS_HPSVCR_SV2_CFG;
    // 0b0..Security Violation 2 is a non-fatal violation
    // 0b1..Security Violation 2 is a fatal violation
#undef SNVS_HPSVCR_SV1_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  1> SNVS_HPSVCR_SV1_CFG;
    // 0b0..Security Violation 1 is a non-fatal violation
    // 0b1..Security Violation 1 is a fatal violation
#undef SNVS_HPSVCR_SV0_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  0> SNVS_HPSVCR_SV0_CFG;
    // 0b0..Security Violation 0 is a non-fatal violation
    // 0b1..Security Violation 0 is a fatal violation

// SNVS_HP Status Register
#undef SNVS_HPSR_ZMK_ZERO_MASK
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 31, true> SNVS_HPSR_ZMK_ZERO_MASK;
    // 0b0..The ZMK is not zero.
    // 0b1..The ZMK is zero.
#undef SNVS_HPSR_OTPMK_ZERO
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 27, true> SNVS_HPSR_OTPMK_ZERO;
    // 0b0..The OTPMK is not zero.
    // 0b1..The OTPMK is zero.
#undef SNVS_HPSR_OTPMK_SYNDROME
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 9, 16, true> SNVS_HPSR_OTPMK_SYNDROME;
#undef SNVS_HPSR_SYS_SECURE_BOOT
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 15, true> SNVS_HPSR_SYS_SECURE_BOOT;
#undef SNVS_HPSR_SYS_SECURITY_CFG
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 3, 12, true> SNVS_HPSR_SYS_SECURITY_CFG;
    // 0b000..Fab Configuration - the default configuration of newly fabricated chips
    // 0b001..Open Configuration - the configuration after NXP-programmable fuses have been blown
    // 0b011..Closed Configuration - the configuration after OEM-programmable fuses have been blown
    // 0b111..Field Return Configuration - the configuration of chips that are returned to NXP for analysis
#undef SNVS_HPSR_SSM_STATE
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 4,  8, true> SNVS_HPSR_SSM_STATE;
    // 0b0000..Init
    // 0b0001..Hard Fail
    // 0b0011..Soft Fail
    // 0b1000..Init Intermediate (transition state between Init and Check - SSM stays in this state only one clock cycle)
    // 0b1001..Check
    // 0b1011..Non-Secure
    // 0b1101..Trusted
    // 0b1111..Secure
#undef SNVS_HPSR_BI
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1,  7, true> SNVS_HPSR_BI;
#undef SNVS_HPSR_BTN
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1,  6, true> SNVS_HPSR_BTN;
#undef SNVS_HPSR_LPDIS
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1,  4, true> SNVS_HPSR_LPDIS;
#undef SNVS_HPSR_PI
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1,  1, true> SNVS_HPSR_PI;
    // 0b0..No periodic interrupt occurred.
    // 0b1..A periodic interrupt occurred.
#undef SNVS_HPSR_HPTA
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1,  0, true> SNVS_HPSR_HPTA;
    // 0b0..No time alarm interrupt occurred.
    // 0b1..A time alarm interrupt occurred.

// SNVS_HP Security Violation Status Register
#undef SNVS_HPSVSR_LP_SEC_VIO
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 31, true> SNVS_HPSVSR_LP_SEC_VIO;
#undef SNVS_HPSVSR_ZMK_ECC_FAIL
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 27, true> SNVS_HPSVSR_ZMK_ECC_FAIL;
    // 0b0..ZMK ECC Failure was not detected.
    // 0b1..ZMK ECC Failure was detected.
#undef SNVS_HPSVSR_ZMK_SYNDROME
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 9, 16> SNVS_HPSVSR_ZMK_SYNDROME;
#undef SNVS_HPSVSR_SW_LPSV
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 15, true> SNVS_HPSVSR_SW_LPSV;
#undef SNVS_HPSVSR_SW_FSV
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 14, true> SNVS_HPSVSR_SW_FSV;
#undef SNVS_HPSVSR_SW_SV
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 13, true> SNVS_HPSVSR_SW_SV;
#undef SNVS_HPSVSR_SV5
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  5, true> SNVS_HPSVSR_SV5;
    // 0b0..No Security Violation 5 security violation was detected.
    // 0b1..Security Violation 5 security violation was detected.
#undef SNVS_HPSVSR_SV4
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  4, true> SNVS_HPSVSR_SV4;
    // 0b0..No Security Violation 4 security violation was detected.
    // 0b1..Security Violation 4 security violation was detected.
#undef SNVS_HPSVSR_SV3
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  3, true> SNVS_HPSVSR_SV3;
    // 0b0..No Security Violation 3 security violation was detected.
    // 0b1..Security Violation 3 security violation was detected.
#undef SNVS_HPSVSR_SV2
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  2, true> SNVS_HPSVSR_SV2;
    // 0b0..No Security Violation 2 security violation was detected.
    // 0b1..Security Violation 2 security violation was detected.
#undef SNVS_HPSVSR_SV1
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  1, true> SNVS_HPSVSR_SV1;
    // 0b0..No Security Violation 1 security violation was detected.
    // 0b1..Security Violation 1 security violation was detected.
#undef SNVS_HPSVSR_SV0
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  0, true> SNVS_HPSVSR_SV0;
    // 0b0..No Security Violation 0 security violation was detected.
    // 0b1..Security Violation 0 security violation was detected.

// SNVS_HP Time Alarm MSB Register
#undef SNVS_HPRTCMR_RTC
constexpr SNVS_Reg<&SNVS_Layout::HPRTCMR, 15, 0> SNVS_HPRTCMR_RTC;

// SNVS_HP Real Time Counter MSB Register
#undef SNVS_HPTAMR_HPTA_MS
constexpr SNVS_Reg<&SNVS_Layout::HPTAMR, 15, 0> SNVS_HPTAMR_HPTA_MS;

// SNVS_LP Lock Register
#undef SNVS_LPLR_MKS_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 9> SNVS_LPLR_MKS_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_LPSECR_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 8> SNVS_LPLR_LPSECR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_LPSVCR_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 6> SNVS_LPLR_LPSVCR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_GPR_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 5> SNVS_LPLR_GPR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_MC_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 4> SNVS_LPLR_MC_HL;
    // 0b0..Write access (increment) is allowed.
    // 0b1..Write access (increment) is not allowed.
#undef SNVS_LPLR_LPCALB_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 3> SNVS_LPLR_LPCALB_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_SRTC_HL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 2> SNVS_LPLR_SRTC_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
#undef SNVS_LPLR_ZMK_RHL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 1> SNVS_LPLR_ZMK_RHL;
    // 0b0..Read access is allowed (only in software programming mode).
    // 0b1..Read access is not allowed.
#undef SNVS_LPLR_ZMK_WHL
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 0> SNVS_LPLR_ZMK_WHL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.

// SNVS_LP Control Register
#undef SNVS_LPCR_GPR_Z_DIS
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 24> SNVS_LPCR_GPR_Z_DIS;
#undef SNVS_LPCR_PK_OVERRIDE
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 23> SNVS_LPCR_PK_OVERRIDE;
#undef SNVS_LPCR_PK_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 22> SNVS_LPCR_PK_EN;
#undef SNVS_LPCR_ON_TIME
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 20> SNVS_LPCR_ON_TIME;
#undef SNVS_LPCR_DEBOUNCE
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 18> SNVS_LPCR_DEBOUNCE;
#undef SNVS_LPCR_BTN_PRESS_TIME
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 16> SNVS_LPCR_BTN_PRESS_TIME;
#undef SNVS_LPCR_LPCALB_VAL
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 5, 10> SNVS_LPCR_LPCALB_VAL;
    // Signed 5-bit value: counts per each 32768 ticks of the counter:
    // 0b00000..+0 counts per each 32768 ticks of the counter clock
    // 0b00001..+1 counts per each 32768 ticks of the counter clock
    // 0b00010..+2 counts per each 32768 ticks of the counter clock
    // 0b01111..+15 counts per each 32768 ticks of the counter clock
    // 0b10000..-16 counts per each 32768 ticks of the counter clock
    // 0b10001..-15 counts per each 32768 ticks of the counter clock
    // 0b11110..-2 counts per each 32768 ticks of the counter clock
    // 0b11111..-1 counts per each 32768 ticks of the counter clock
#undef SNVS_LPCR_LPCALB_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  8> SNVS_LPCR_LPCALB_EN;
    // 0b0..SRTC Time calibration is disabled.
    // 0b1..SRTC Time calibration is enabled.
#undef SNVS_LPCR_LVD_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  7> SNVS_LPCR_LVD_EN;
#undef SNVS_LPCR_TOP
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  6> SNVS_LPCR_TOP;
    // 0b0..Leave system power on.
    // 0b1..Turn off system power.
#undef SNVS_LPCR_DP_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  5> SNVS_LPCR_DP_EN;
    // 0b0..Smart PMIC enabled.
    // 0b1..Dumb PMIC enabled.
#undef SNVS_LPCR_SRTC_INV_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  4> SNVS_LPCR_SRTC_INV_EN;
    // 0b0..SRTC stays valid in the case of security violation (other than a software violation (HPSVSR[SW_LPSV] = 1 or HPCOMR[SW_LPSV] = 1)).
    // 0b1..SRTC is invalidated in the case of security violation.
#undef SNVS_LPCR_LPWUI_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  3> SNVS_LPCR_LPWUI_EN;
#undef SNVS_LPCR_MC_ENV
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  2> SNVS_LPCR_MC_ENV;
    // 0b0..MC is disabled or invalid.
    // 0b1..MC is enabled and valid.
#undef SNVS_LPCR_LPTA_EN
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  1> SNVS_LPCR_LPTA_EN;
    // 0b0..LP time alarm interrupt is disabled.
    // 0b1..LP time alarm interrupt is enabled.
#undef SNVS_LPCR_SRTC_ENV
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  0> SNVS_LPCR_SRTC_ENV;
    // 0b0..SRTC is disabled or invalid.
    // 0b1..SRTC is enabled and valid.

// SNVS_LP Master Key Control Register
#undef SNVS_LPMKCR_ZMK_ECC_VALUE
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 9, 7> SNVS_LPMKCR_ZMK_ECC_VALUE;
#undef SNVS_LPMKCR_ZMK_ECC_EN
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 4> SNVS_LPMKCR_ZMK_ECC_EN;
    // 0b0..ZMK ECC check is disabled.
    // 0b1..ZMK ECC check is enabled.
#undef SNVS_LPMKCR_ZMK_VAL
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 3> SNVS_LPMKCR_ZMK_VAL;
    // 0b0..ZMK is not valid.
    // 0b1..ZMK is valid.
#undef SNVS_LPMKCR_ZMK_HWP
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 2> SNVS_LPMKCR_ZMK_HWP;
    // 0b0..ZMK is in the software programming mode.
    // 0b1..ZMK is in the hardware programming mode.
#undef SNVS_LPMKCR_MASTER_KEY_SEL
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 2, 0> SNVS_LPMKCR_MASTER_KEY_SEL;
    // 0b0x..Select one time programmable master key.
    // 0b10..Select zeroizable master key when MKS_EN bit is set.
    // 0b11..Select combined master key when MKS_EN bit is set.

// SNVS_LP Security Violation Control Register
#undef SNVS_LPSVCR_SV5_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 5> SNVS_LPSVCR_SV5_EN;
    // 0b0..Security Violation 5 is disabled in the LP domain.
    // 0b1..Security Violation 5 is enabled in the LP domain.
#undef SNVS_LPSVCR_SV4_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 4> SNVS_LPSVCR_SV4_EN;
    // 0b0..Security Violation 4 is disabled in the LP domain.
    // 0b1..Security Violation 4 is enabled in the LP domain.
#undef SNVS_LPSVCR_SV3_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 3> SNVS_LPSVCR_SV3_EN;
    // 0b0..Security Violation 3 is disabled in the LP domain.
    // 0b1..Security Violation 3 is enabled in the LP domain.
#undef SNVS_LPSVCR_SV2_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 2> SNVS_LPSVCR_SV2_EN;
    // 0b0..Security Violation 2 is disabled in the LP domain.
    // 0b1..Security Violation 2 is enabled in the LP domain.
#undef SNVS_LPSVCR_SV1_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 1> SNVS_LPSVCR_SV1_EN;
    // 0b0..Security Violation 1 is disabled in the LP domain.
    // 0b1..Security Violation 1 is enabled in the LP domain.
#undef SNVS_LPSVCR_SV0_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 0> SNVS_LPSVCR_SV0_EN;
    // 0b0..Security Violation 0 is disabled in the LP domain.
    // 0b1..Security Violation 0 is enabled in the LP domain.

// SNVS_LP Security Events Configuration Register
#undef SNVS_LPSECR_OSCB
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 28> SNVS_LPSECR_OSCB;
    // 0b0..Normal SRTC clock oscillator not bypassed.
    // 0b1..Normal SRTC clock oscillator bypassed. Alternate clock can drive the SRTC clock source.
#undef SNVS_LPSECR_VRC
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 24> SNVS_LPSECR_VRC;
#undef SNVS_LPSECR_HTDC
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 20> SNVS_LPSECR_HTDC;
#undef SNVS_LPSECR_LTDC
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 16> SNVS_LPSECR_LTDC;
#undef SNVS_LPSECR_POR_OBSERV
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 15> SNVS_LPSECR_POR_OBSERV;
#undef SNVS_LPSECR_PFD_OBSERV
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 14> SNVS_LPSECR_PFD_OBSERV;
#undef SNVS_LPSECR_MCR_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1,  2> SNVS_LPSECR_MCR_EN;
    // 0b0..MC rollover is disabled.
    // 0b1..MC rollover is enabled.
#undef SNVS_LPSECR_SRTCR_EN
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1,  1> SNVS_LPSECR_SRTCR_EN;
    // 0b0..SRTC rollover is disabled.
    // 0b1..SRTC rollover is enabled.

// SNVS_LP Status Register
#undef SNVS_LPSR_LPS
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 31> SNVS_LPSR_LPS;
    // 0b0..LP section was not programmed in secure or trusted state.
    // 0b1..LP section was programmed in secure or trusted state.
#undef SNVS_LPSR_LPNS
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 30> SNVS_LPSR_LPNS;
    // 0b0..LP section was not programmed in the non-secure state.
    // 0b1..LP section was programmed in the non-secure state.
#undef SNVS_LPSR_SPON
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 19> SNVS_LPSR_SPON;
    // 0b0..Set Power On Interrupt was not detected.
    // 0b1..Set Power On Interrupt was detected.
#undef SNVS_LPSR_SPOF
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 18> SNVS_LPSR_SPOF;
    // 0b0..Set Power Off was not detected.
    // 0b1..Set Power Off was detected.
#undef SNVS_LPSR_EO
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 17> SNVS_LPSR_EO;
    // 0b0..Emergency off was not detected.
    // 0b1..Emergency off was detected.
#undef SNVS_LPSR_ESVD
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 16> SNVS_LPSR_ESVD;
    // 0b0..No external security violation.
    // 0b1..External security violation is detected.
#undef SNVS_LPSR_LVD
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  3> SNVS_LPSR_LVD;
    // 0b0..No low voltage event detected.
    // 0b1..Low voltage event is detected.
#undef SNVS_LPSR_MCR
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  2> SNVS_LPSR_MCR;
    // 0b0..MC has not reached its maximum value.
    // 0b1..MC has reached its maximum value.
#undef SNVS_LPSR_SRTCR
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  1> SNVS_LPSR_SRTCR;
    // 0b0..SRTC has not reached its maximum value.
    // 0b1..SRTC has reached its maximum value.
#undef SNVS_LPSR_LPTA
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  0> SNVS_LPSR_LPTA;
    // 0b0..No time alarm interrupt occurred.
    // 0b1..A time alarm interrupt occurred.

// SNVS_LP Secure Real Time Counter MSB Register
#undef SNVS_LPSRTCMR_SRTC
constexpr SNVS_Reg<&SNVS_Layout::LPSRTCMR, 15, 0> SNVS_LPSRTCMR_SRTC;

// SNVS_LP Secure Monotonic Counter MSB Register
#undef SNVS_LPSMCMR_MC_ERA_BITS
constexpr SNVS_Reg<&SNVS_Layout::LPSMCMR, 16, 16> SNVS_LPSMCMR_MC_ERA_BITS;
#undef SNVS_LPSMCMR_MON_COUNTER
constexpr SNVS_Reg<&SNVS_Layout::LPSMCMR, 16,  0> SNVS_LPSMCMR_MON_COUNTER;

// SNVS_HP Version ID Register 1
#undef SNVS_HPVIDR1_IP_ID
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1, 16, 16> SNVS_HPVIDR1_IP_ID;
#undef SNVS_HPVIDR1_MAJOR_REV
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1,  8,  8> SNVS_HPVIDR1_MAJOR_REV;
#undef SNVS_HPVIDR1_MINOR_REV
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1,  8,  0> SNVS_HPVIDR1_MINOR_REV;

// SNVS_HP Version ID Register 2
#undef SNVS_HPVIDR2_IP_ERA
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8, 24> SNVS_HPVIDR2_IP_ERA;
#undef SNVS_HPVIDR2_INTG_OPT
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8, 16> SNVS_HPVIDR2_INTG_OPT;
#undef SNVS_HPVIDR2_ECO_REV
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8,  8> SNVS_HPVIDR2_ECO_REV;
#undef SNVS_HPVIDR2_CONFIG_OPT
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8,  0> SNVS_HPVIDR2_CONFIG_OPT;

// SNVS_HP Status Register values
constexpr uint32_t kSNVS_HPSR_SSM_STATE_INIT                = 0;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_HARD_FAIL           = 1;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_SOFT_FAIL           = 3;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_INIT_INTERMEDIATE   = 8;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_CHECK               = 9;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_NONSECURE           = 11;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_TRUSTED             = 13;
constexpr uint32_t kSNVS_HPSR_SSM_STATE_SECURE              = 15;
constexpr uint32_t kSNVS_HPSR_SYS_SECURITY_CFG_FAB          = 0;
constexpr uint32_t kSNVS_HPSR_SYS_SECURITY_CFG_OPEN         = 1;
constexpr uint32_t kSNVS_HPSR_SYS_SECURITY_CFG_CLOSED       = 3;
constexpr uint32_t kSNVS_HPSR_SYS_SECURITY_CFG_FIELD_RETURN = 7;

// SNVS_LP Master Key Control Register values
constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_OTPMK = 0;  /*!< One Time Programmable Master Key. */
constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_ZMK   = 2;  /*!< Zeroizable Master Key. */
constexpr uint32_t kSNVS_LPMKCR_MASTER_KEY_SEL_CMK   = 3;  /*!< Combined Master Key, it is XOR of OPTMK and ZMK. */
constexpr uint32_t kSNVS_LPMKCR_ZMK_HWP_SOFTWARE     = 0;
constexpr uint32_t kSNVS_LPMKCR_ZMK_HWP_HARDWARE     = 1;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
