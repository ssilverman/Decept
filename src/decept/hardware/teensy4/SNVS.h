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

namespace SNVS {
constexpr regs::RegGroup<SNVS_Layout, kSNVS_size, kSNVS_base> group;
}  // namespace SNVS

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using SNVS_Reg =
    regs::Reg32<kSNVS_base, SNVS_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace SNVS {

// SNVS_HP Lock Register
namespace HPLR {
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 18> HAC_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 17> HPSICR_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1, 16> HPSVCR_L;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  9> MKS_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  8> LPSECR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  6> LPSVCR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  5> GPR_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  4> MC_SL;
    // 0b0..Write access (increment) is allowed
    // 0b1..Write access (increment) is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  3> LPCALB_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  2> SRTC_SL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  1> ZMK_RSL;
    // 0b0..Read access is allowed (only in software Programming mode)
    // 0b1..Read access is not allowed
constexpr SNVS_Reg<&SNVS_Layout::HPLR, 1,  0> ZMK_WSL;
    // 0b0..Write access is allowed
    // 0b1..Write access is not allowed
}  // namespace HPLR

// SNVS_HP Command Register
namespace HPCOMR {
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 31> NPSWA_EN;
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 19> HAC_STOP;
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 18> HAC_CLEAR;
    // 0b0..No Action
    // 0b1..Clear the HAC
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 17> HAC_LOAD;
    // 0b0..No Action
    // 0b1..Load the HAC
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 16> HAC_EN;
    // 0b0..High Assurance Counter is disabled
    // 0b1..High Assurance Counter is enable
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 13> MKS_EN;
    // 0b0..OTP master key is selected as an SNVS master key
    // 0b1..SNVS master key is selected according to the setting of the MASTER_KEY_SEL field of LPMKCR
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 12> PROG_ZMK;
    // 0b0..No Action
    // 0b1..Activate hardware key programming mechanism
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1, 10> SW_LPSV;
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  9> SW_FSV;
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  8> SW_SV;
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  5> LP_SWR_DIS;
    // 0b0..LP software reset is enabled
    // 0b1..LP software reset is disabled
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  4> LP_SWR;
    // 0b0..No Action
    // 0b1..Reset LP section
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  2>  SSM_SFNS_DIS;
    // 0b0..Soft Fail to Non-Secure State transition is enabled
    // 0b1..Soft Fail to Non-Secure State transition is disabled
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  1> SSM_ST_DIS;
    // 0b0..Secure to Trusted State transition is enabled
    // 0b1..Secure to Trusted State transition is disabled
constexpr SNVS_Reg<&SNVS_Layout::HPCOMR, 1,  0> SSM_ST;
}  // namespace HPCOMR

// SNVS_HP Control Register
namespace HPCR {
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1, 27> BTN_MASK;
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 3, 24> BTN_CONFIG;
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1, 16> HP_TS;
    // 0b0..No Action
    // 0b1..Synchronize the HP Time Counter to the LP Time Counter
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 5, 10> HPCALB_VAL;
    // Signed 5-bit value: counts per each 32768 ticks of the counter:
    // 0b00000..+0 counts per each 32768 ticks of the counter
    // 0b00001..+1 counts per each 32768 ticks of the counter
    // 0b00010..+2 counts per each 32768 ticks of the counter
    // 0b01111..+15 counts per each 32768 ticks of the counter
    // 0b10000..-16 counts per each 32768 ticks of the counter
    // 0b10001..-15 counts per each 32768 ticks of the counter
    // 0b11110..-2 counts per each 32768 ticks of the counter
    // 0b11111..-1 counts per each 32768 ticks of the counter
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  8> HPCALB_EN;
    // 0b0..HP Timer calibration disabled
    // 0b1..HP Timer calibration enabled
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 4,  4> PI_FREQ;
    // Bit 'value'  of the HPRTCLR is selected as a source of the periodic interrupt
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  3> PI_EN;
    // 0b0..HP Periodic Interrupt is disabled
    // 0b1..HP Periodic Interrupt is enabled
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  2> DIS_PI;
    // 0b0..Periodic interrupt will trigger a functional interrupt
    // 0b1..Disable periodic interrupt in the function interrupt
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  1> HPTA_EN;
    // 0b0..HP Time Alarm Interrupt is disabled
    // 0b1..HP Time Alarm Interrupt is enabled
constexpr SNVS_Reg<&SNVS_Layout::HPCR, 1,  0> RTC_EN;
    // 0b0..RTC is disabled
    // 0b1..RTC is enabled
}  // namespace HPCR

// SNVS_HP Security Interrupt Control Register
namespace HPSICR {
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1, 31> LPSVI_EN;
    // 0b0..LP Security Violation Interrupt is Disabled
    // 0b1..LP Security Violation Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  5> SV5_EN;
    // 0b0..Security Violation 5 Interrupt is Disabled
    // 0b1..Security Violation 5 Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  4> SV4_EN;
    // 0b0..Security Violation 4 Interrupt is Disabled
    // 0b1..Security Violation 4 Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  3> SV3_EN;
    // 0b0..Security Violation 3 Interrupt is Disabled
    // 0b1..Security Violation 3 Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  2> SV2_EN;
    // 0b0..Security Violation 2 Interrupt is Disabled
    // 0b1..Security Violation 2 Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  1> SV1_EN;
    // 0b0..Security Violation 1 Interrupt is Disabled
    // 0b1..Security Violation 1 Interrupt is Enabled
constexpr SNVS_Reg<&SNVS_Layout::HPSICR, 1,  0> SV0_EN;
    // 0b0..Security Violation 0 Interrupt is Disabled
    // 0b1..Security Violation 0 Interrupt is Enabled
}  // namespace HPSICR

// SNVS_HP Security Violation Control Register
namespace HPSVCR {
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 2, 30> LPSV_CFG;
    // 0b00..LP security violation is disabled
    // 0b01..LP security violation is a non-fatal violation
    // 0b1x..LP security violation is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 2,  5> SV5_CFG;
    // 0b00..Security Violation 5 is disabled
    // 0b01..Security Violation 5 is a non-fatal violation
    // 0b1x..Security Violation 5 is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  4> SV4_CFG;
    // 0b0..Security Violation 4 is a non-fatal violation
    // 0b1..Security Violation 4 is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  3> SV3_CFG;
    // 0b0..Security Violation 3 is a non-fatal violation
    // 0b1..Security Violation 3 is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  2> SV2_CFG;
    // 0b0..Security Violation 2 is a non-fatal violation
    // 0b1..Security Violation 2 is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  1> SV1_CFG;
    // 0b0..Security Violation 1 is a non-fatal violation
    // 0b1..Security Violation 1 is a fatal violation
constexpr SNVS_Reg<&SNVS_Layout::HPSVCR, 1,  0> SV0_CFG;
    // 0b0..Security Violation 0 is a non-fatal violation
    // 0b1..Security Violation 0 is a fatal violation
}  // namespace HPSVCR

// SNVS_HP Status Register
namespace HPSR {
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 31, true> ZMK_ZERO_MASK;
    // 0b0..The ZMK is not zero.
    // 0b1..The ZMK is zero.
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 27, true> OTPMK_ZERO;
    // 0b0..The OTPMK is not zero.
    // 0b1..The OTPMK is zero.
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 9, 16, true> OTPMK_SYNDROME;
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 15, true> SYS_SECURE_BOOT;
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 3, 12, true> SYS_SECURITY_CFG;
    // 0b000..Fab Configuration - the default configuration of newly fabricated chips
    // 0b001..Open Configuration - the configuration after NXP-programmable fuses have been blown
    // 0b011..Closed Configuration - the configuration after OEM-programmable fuses have been blown
    // 0b111..Field Return Configuration - the configuration of chips that are returned to NXP for analysis
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 4,  8, true> SSM_STATE;
    // 0b0000..Init
    // 0b0001..Hard Fail
    // 0b0011..Soft Fail
    // 0b1000..Init Intermediate (transition state between Init and Check - SSM stays in this state only one clock cycle)
    // 0b1001..Check
    // 0b1011..Non-Secure
    // 0b1101..Trusted
    // 0b1111..Secure
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 7, true> BI;
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 6, true> BTN;
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 4, true> LPDIS;
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 1, true> PI;
    // 0b0..No periodic interrupt occurred.
    // 0b1..A periodic interrupt occurred.
constexpr SNVS_Reg<&SNVS_Layout::HPSR, 1, 0, true> HPTA;
    // 0b0..No time alarm interrupt occurred.
    // 0b1..A time alarm interrupt occurred.

// SNVS_HP Status Register values
constexpr uint32_t kSSM_STATE_INIT                = 0;
constexpr uint32_t kSSM_STATE_HARD_FAIL           = 1;
constexpr uint32_t kSSM_STATE_SOFT_FAIL           = 3;
constexpr uint32_t kSSM_STATE_INIT_INTERMEDIATE   = 8;
constexpr uint32_t kSSM_STATE_CHECK               = 9;
constexpr uint32_t kSSM_STATE_NONSECURE           = 11;
constexpr uint32_t kSSM_STATE_TRUSTED             = 13;
constexpr uint32_t kSSM_STATE_SECURE              = 15;
constexpr uint32_t kSYS_SECURITY_CFG_FAB          = 0;
constexpr uint32_t kSYS_SECURITY_CFG_OPEN         = 1;
constexpr uint32_t kSYS_SECURITY_CFG_CLOSED       = 3;
constexpr uint32_t kSYS_SECURITY_CFG_FIELD_RETURN = 7;
}  // namespace HPSR

// SNVS_HP Security Violation Status Register
namespace HPSVSR {
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 31, true> LP_SEC_VIO;
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 27, true> ZMK_ECC_FAIL;
    // 0b0..ZMK ECC Failure was not detected.
    // 0b1..ZMK ECC Failure was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 9, 16> ZMK_SYNDROME;
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 15, true> SW_LPSV;
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 14, true> SW_FSV;
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1, 13, true> SW_SV;
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  5, true> SV5;
    // 0b0..No Security Violation 5 security violation was detected.
    // 0b1..Security Violation 5 security violation was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  4, true> SV4;
    // 0b0..No Security Violation 4 security violation was detected.
    // 0b1..Security Violation 4 security violation was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  3, true> SV3;
    // 0b0..No Security Violation 3 security violation was detected.
    // 0b1..Security Violation 3 security violation was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  2, true> SV2;
    // 0b0..No Security Violation 2 security violation was detected.
    // 0b1..Security Violation 2 security violation was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  1, true> SV1;
    // 0b0..No Security Violation 1 security violation was detected.
    // 0b1..Security Violation 1 security violation was detected.
constexpr SNVS_Reg<&SNVS_Layout::HPSVSR, 1,  0, true> SV0;
    // 0b0..No Security Violation 0 security violation was detected.
    // 0b1..Security Violation 0 security violation was detected.
}  // namespace HPSVSR

// SNVS_HP Time Alarm MSB Register
namespace HPRTCMR {
constexpr SNVS_Reg<&SNVS_Layout::HPRTCMR, 15, 0> RTC;
}  // namespace HPRTCMR

// SNVS_HP Real Time Counter MSB Register
namespace HPTAMR {
constexpr SNVS_Reg<&SNVS_Layout::HPTAMR, 15, 0> HPTA_MS;
}  // namespace HPTAMR

// SNVS_LP Lock Register
namespace LPLR {
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 9> MKS_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 8> LPSECR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 6> LPSVCR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 5> GPR_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 4> MC_HL;
    // 0b0..Write access (increment) is allowed.
    // 0b1..Write access (increment) is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 3> LPCALB_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 2> SRTC_HL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 1> ZMK_RHL;
    // 0b0..Read access is allowed (only in software programming mode).
    // 0b1..Read access is not allowed.
constexpr SNVS_Reg<&SNVS_Layout::LPLR, 1, 0> ZMK_WHL;
    // 0b0..Write access is allowed.
    // 0b1..Write access is not allowed.
}  // namespace LPLR

// SNVS_LP Control Register
namespace LPCR {
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 24> GPR_Z_DIS;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 23> PK_OVERRIDE;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1, 22> PK_EN;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 20> ON_TIME;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 18> DEBOUNCE;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 2, 16> BTN_PRESS_TIME;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 5, 10> LPCALB_VAL;
    // Signed 5-bit value: counts per each 32768 ticks of the counter:
    // 0b00000..+0 counts per each 32768 ticks of the counter clock
    // 0b00001..+1 counts per each 32768 ticks of the counter clock
    // 0b00010..+2 counts per each 32768 ticks of the counter clock
    // 0b01111..+15 counts per each 32768 ticks of the counter clock
    // 0b10000..-16 counts per each 32768 ticks of the counter clock
    // 0b10001..-15 counts per each 32768 ticks of the counter clock
    // 0b11110..-2 counts per each 32768 ticks of the counter clock
    // 0b11111..-1 counts per each 32768 ticks of the counter clock
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  8> LPCALB_EN;
    // 0b0..SRTC Time calibration is disabled.
    // 0b1..SRTC Time calibration is enabled.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  7> LVD_EN;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  6> TOP;
    // 0b0..Leave system power on.
    // 0b1..Turn off system power.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  5> DP_EN;
    // 0b0..Smart PMIC enabled.
    // 0b1..Dumb PMIC enabled.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  4> SRTC_INV_EN;
    // 0b0..SRTC stays valid in the case of security violation (other than a software violation (HPSVSR[SW_LPSV] = 1 or HPCOMR[SW_LPSV] = 1)).
    // 0b1..SRTC is invalidated in the case of security violation.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  3> LPWUI_EN;
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  2> MC_ENV;
    // 0b0..MC is disabled or invalid.
    // 0b1..MC is enabled and valid.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  1> LPTA_EN;
    // 0b0..LP time alarm interrupt is disabled.
    // 0b1..LP time alarm interrupt is enabled.
constexpr SNVS_Reg<&SNVS_Layout::LPCR, 1,  0> SRTC_ENV;
    // 0b0..SRTC is disabled or invalid.
    // 0b1..SRTC is enabled and valid.
}  // namespace LPCR

// SNVS_LP Master Key Control Register
namespace LPMKCR {
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 9, 7> ZMK_ECC_VALUE;
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 4> ZMK_ECC_EN;
    // 0b0..ZMK ECC check is disabled.
    // 0b1..ZMK ECC check is enabled.
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 3> ZMK_VAL;
    // 0b0..ZMK is not valid.
    // 0b1..ZMK is valid.
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 1, 2> ZMK_HWP;
    // 0b0..ZMK is in the software programming mode.
    // 0b1..ZMK is in the hardware programming mode.
constexpr SNVS_Reg<&SNVS_Layout::LPMKCR, 2, 0> MASTER_KEY_SEL;
    // 0b0x..Select one time programmable master key.
    // 0b10..Select zeroizable master key when MKS_EN bit is set.
    // 0b11..Select combined master key when MKS_EN bit is set.

// SNVS_LP Master Key Control Register values
constexpr uint32_t kMASTER_KEY_SEL_OTPMK = 0;  /*!< One Time Programmable Master Key. */
constexpr uint32_t kMASTER_KEY_SEL_ZMK   = 2;  /*!< Zeroizable Master Key. */
constexpr uint32_t kMASTER_KEY_SEL_CMK   = 3;  /*!< Combined Master Key, it is XOR of OPTMK and ZMK. */
constexpr uint32_t kZMK_HWP_SOFTWARE     = 0;
constexpr uint32_t kZMK_HWP_HARDWARE     = 1;
}  // namespace LPMKCR

// SNVS_LP Security Violation Control Register
namespace LPSVCR {
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 5> SV5_EN;
    // 0b0..Security Violation 5 is disabled in the LP domain.
    // 0b1..Security Violation 5 is enabled in the LP domain.
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 4> SV4_EN;
    // 0b0..Security Violation 4 is disabled in the LP domain.
    // 0b1..Security Violation 4 is enabled in the LP domain.
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 3> SV3_EN;
    // 0b0..Security Violation 3 is disabled in the LP domain.
    // 0b1..Security Violation 3 is enabled in the LP domain.
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 2> SV2_EN;
    // 0b0..Security Violation 2 is disabled in the LP domain.
    // 0b1..Security Violation 2 is enabled in the LP domain.
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 1> SV1_EN;
    // 0b0..Security Violation 1 is disabled in the LP domain.
    // 0b1..Security Violation 1 is enabled in the LP domain.
constexpr SNVS_Reg<&SNVS_Layout::LPSVCR, 1, 0> SV0_EN;
    // 0b0..Security Violation 0 is disabled in the LP domain.
    // 0b1..Security Violation 0 is enabled in the LP domain.
}  // namespace LPSVCR

// SNVS_LP Security Events Configuration Register
namespace LPSECR {
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 28> OSCB;
    // 0b0..Normal SRTC clock oscillator not bypassed.
    // 0b1..Normal SRTC clock oscillator bypassed. Alternate clock can drive the SRTC clock source.
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 24> VRC;
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 20> HTDC;
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 3, 16> LTDC;
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 15> POR_OBSERV;
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1, 14> PFD_OBSERV;
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1,  2> MCR_EN;
    // 0b0..MC rollover is disabled.
    // 0b1..MC rollover is enabled.
constexpr SNVS_Reg<&SNVS_Layout::LPSECR, 1,  1> SRTCR_EN;
    // 0b0..SRTC rollover is disabled.
    // 0b1..SRTC rollover is enabled.
}  // namespace LPSECR

// SNVS_LP Status Register
namespace LPSR {
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 31> LPS;
    // 0b0..LP section was not programmed in secure or trusted state.
    // 0b1..LP section was programmed in secure or trusted state.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 30> LPNS;
    // 0b0..LP section was not programmed in the non-secure state.
    // 0b1..LP section was programmed in the non-secure state.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 19> SPON;
    // 0b0..Set Power On Interrupt was not detected.
    // 0b1..Set Power On Interrupt was detected.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 18> SPOF;
    // 0b0..Set Power Off was not detected.
    // 0b1..Set Power Off was detected.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 17> EO;
    // 0b0..Emergency off was not detected.
    // 0b1..Emergency off was detected.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1, 16> ESVD;
    // 0b0..No external security violation.
    // 0b1..External security violation is detected.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  3> LVD;
    // 0b0..No low voltage event detected.
    // 0b1..Low voltage event is detected.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  2> MCR;
    // 0b0..MC has not reached its maximum value.
    // 0b1..MC has reached its maximum value.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  1> SRTCR;
    // 0b0..SRTC has not reached its maximum value.
    // 0b1..SRTC has reached its maximum value.
constexpr SNVS_Reg<&SNVS_Layout::LPSR, 1,  0> LPTA;
    // 0b0..No time alarm interrupt occurred.
    // 0b1..A time alarm interrupt occurred.
}  // namespace LPSR

// SNVS_LP Secure Real Time Counter MSB Register
namespace LPSRTCMR {
constexpr SNVS_Reg<&SNVS_Layout::LPSRTCMR, 15, 0> SRTC;
}  // namespace LPSRTCMR

// SNVS_LP Secure Monotonic Counter MSB Register
namespace LPSMCMR {
constexpr SNVS_Reg<&SNVS_Layout::LPSMCMR, 16, 16> MC_ERA_BITS;
constexpr SNVS_Reg<&SNVS_Layout::LPSMCMR, 16,  0> MON_COUNTER;
}  // namespace LPSMCMR

// SNVS_HP Version ID Register 1
namespace HPVIDR1 {
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1, 16, 16> IP_ID;
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1,  8,  8> MAJOR_REV;
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR1,  8,  0> MINOR_REV;
}  // namespace HPVIDR1

// SNVS_HP Version ID Register 2
namespace HPVIDR2 {
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8, 24> IP_ERA;
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8, 16> INTG_OPT;
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8,  8> ECO_REV;
constexpr SNVS_Reg<&SNVS_Layout::HPVIDR2, 8,  0> CONFIG_OPT;
}  // namespace HPVIDR2

}  // namespace SNVS

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
