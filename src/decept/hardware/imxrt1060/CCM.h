// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM.h defines all the CCM registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// CCM layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CCM.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct CCM_Layout {
  volatile uint32_t CCR;                               /**< CCM Control Register, offset: 0x0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t CSR;                         /**< CCM Status Register, offset: 0x8 */
  volatile uint32_t CCSR;                              /**< CCM Clock Switcher Register, offset: 0xC */
  volatile uint32_t CACRR;                             /**< CCM Arm Clock Root Register, offset: 0x10 */
  volatile uint32_t CBCDR;                             /**< CCM Bus Clock Divider Register, offset: 0x14 */
  volatile uint32_t CBCMR;                             /**< CCM Bus Clock Multiplexer Register, offset: 0x18 */
  volatile uint32_t CSCMR1;                            /**< CCM Serial Clock Multiplexer Register 1, offset: 0x1C */
  volatile uint32_t CSCMR2;                            /**< CCM Serial Clock Multiplexer Register 2, offset: 0x20 */
  volatile uint32_t CSCDR1;                            /**< CCM Serial Clock Divider Register 1, offset: 0x24 */
  volatile uint32_t CS1CDR;                            /**< CCM Clock Divider Register, offset: 0x28 */
  volatile uint32_t CS2CDR;                            /**< CCM Clock Divider Register, offset: 0x2C */
  volatile uint32_t CDCDR;                             /**< CCM D1 Clock Divider Register, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t CSCDR2;                            /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
  volatile uint32_t CSCDR3;                            /**< CCM Serial Clock Divider Register 3, offset: 0x3C */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  const volatile uint32_t CDHIPR;                      /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t CLPCR;                             /**< CCM Low Power Control Register, offset: 0x54 */
  volatile uint32_t CISR;                              /**< CCM Interrupt Status Register, offset: 0x58 */
  volatile uint32_t CIMR;                              /**< CCM Interrupt Mask Register, offset: 0x5C */
  volatile uint32_t CCOSR;                             /**< CCM Clock Output Source Register, offset: 0x60 */
  volatile uint32_t CGPR;                              /**< CCM General Purpose Register, offset: 0x64 */
  volatile uint32_t CCGR0;                             /**< CCM Clock Gating Register 0, offset: 0x68 */
  volatile uint32_t CCGR1;                             /**< CCM Clock Gating Register 1, offset: 0x6C */
  volatile uint32_t CCGR2;                             /**< CCM Clock Gating Register 2, offset: 0x70 */
  volatile uint32_t CCGR3;                             /**< CCM Clock Gating Register 3, offset: 0x74 */
  volatile uint32_t CCGR4;                             /**< CCM Clock Gating Register 4, offset: 0x78 */
  volatile uint32_t CCGR5;                             /**< CCM Clock Gating Register 5, offset: 0x7C */
  volatile uint32_t CCGR6;                             /**< CCM Clock Gating Register 6, offset: 0x80 */
  volatile uint32_t CCGR7;                             /**< CCM Clock Gating Register 7, offset: 0x84 */
  volatile uint32_t CMEOR;                             /**< CCM Module Enable Overide Register, offset: 0x88 */
};

constexpr size_t    kCCM_size = 0x8C;
constexpr uintptr_t kCCM_base = 0x400FC000;

namespace CCM {
constexpr regs::RegGroup<CCM_Layout, kCCM_size, kCCM_base> group;
}  // namespace CCM

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CCM_Reg =
    regs::Reg32<kCCM_base, CCM_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace CCM {

// CCM Control Register
namespace CCR {
constexpr CCM_Reg<&CCM_Layout::CCR, 1, 27> RBC_EN;
    // 0b0..REG_BYPASS_COUNTER disabled
    // 0b1..REG_BYPASS_COUNTER enabled.
constexpr CCM_Reg<&CCM_Layout::CCR, 6, 21> REG_BYPASS_COUNT;
    // 'value' CKIL clock period delay:
    // 0b000000..no delay
    // 0b000001..1 CKIL clock period delay
    // 0b111111..63 CKIL clock periods delay
constexpr CCM_Reg<&CCM_Layout::CCR, 1, 12> COSC_EN;
    // 0b0..disable on chip oscillator
    // 0b1..enable on chip oscillator
constexpr CCM_Reg<&CCM_Layout::CCR, 8,  0> OSCNT;  // Oscillator ready counter value
    // These bits define value of 32KHz counter, that serve as
    // counter for oscillator lock time (count to n+1 ckil's). This is used for oscillator lock time.
    // Current estimation is ~5ms. This counter will be used in ignition sequence and in wake from
    // stop sequence if sbyos bit was defined, to notify that on chip oscillator output is ready for
    // the dpll_ip to use and only then the gate in dpll_ip can be opened.
}  // namespace CCR

// CCM Status Register
namespace CSR {
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 5> COSC_READY;
    // 0b0..on board oscillator is not ready.
    // 0b1..on board oscillator is ready.
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 3> CAMP2_READY;
    // 0b0..CAMP2 is not ready.
    // 0b1..CAMP2 is ready.
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 0> REF_EN_B;
    // 0b0..value of CCM_REF_EN_B is '0'
    // 0b1..value of CCM_REF_EN_B is '1'
}  // namespace CSR

// CCM Clock Switcher Register
namespace CCSR {
constexpr CCM_Reg<&CCM_Layout::CCSR, 1, 0> PLL3_SW_CLK_SEL;
// 0b0..pll3_main_clk
// 0b1..pll3 bypass clock

// CCM Clock Switcher Register values
constexpr uint32_t kPLL3_SW_CLK_SEL_MAIN   = 0;
constexpr uint32_t kPLL3_SW_CLK_SEL_BYPASS = 1;
}  // namespace CCSR

// CCM Arm Clock Root Register
namespace CACRR {
constexpr CCM_Reg<&CCM_Layout::CACRR, 3, 0> ARM_PODF;
    // Divide by 'value + 1:
    // 0b000..divide by 1
    // 0b001..divide by 2
    // 0b010..divide by 3
    // 0b011..divide by 4
    // 0b100..divide by 5
    // 0b101..divide by 6
    // 0b110..divide by 7
    // 0b111..divide by 8
}  // namespace CACRR

// CCM Bus Clock Divider Register
namespace CBCDR {
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 27> PERIPH_CLK2_PODF;
    // Divide by 'value + 1
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1, 25> PERIPH_CLK_SEL;
    // 0b0..derive clock from pre_periph_clk_sel
    // 0b1..derive clock from periph_clk2_clk_divided
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 16> SEMC_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 10> AHB_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CBCDR, 2,  8> IPG_PODF;
    // Divide by 'value' + 1:
    // 0b00..divide by 1
    // 0b01..divide by 2
    // 0b10..divide by 3
    // 0b11..divide by 4
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1,  7> SEMC_ALT_CLK_SEL;
    // 0b0..PLL2 PFD2 will be selected as alternative clock for SEMC root clock
    // 0b1..PLL3 PFD1 will be selected as alternative clock for SEMC root clock
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1,  6> SEMC_CLK_SEL;
    // 0b0..Periph_clk output will be used as SEMC clock root
    // 0b1..SEMC alternative clock will be used as SEMC clock root

// CCM Bus Clock Divider Register values
constexpr uint32_t kSEMC_CLK_SEL_PERIPH                    = 0;
constexpr uint32_t kSEMC_CLK_SEL_ALT                       = 1;
constexpr uint32_t kSEMC_ALT_CLK_SEL_PLL2_PFD2             = 0;
constexpr uint32_t kSEMC_ALT_CLK_SEL_PLL3_PFD1             = 1;
constexpr uint32_t kPERIPH_CLK_SEL_PRE_PERIPH_CLK_SEL      = 0;
constexpr uint32_t kCBCDR_PERIPH_CLK_SEL_PRE_PERIPH_CLK2_CLK_DIV = 1;
}  // namespace CBCDR

// CCM Bus Clock Multiplexer Register
namespace CBCMR {
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 29> FLEXSPI2_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 26> LPSPI_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 23> LCDIF_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 18> PRE_PERIPH_CLK_SEL;
    // 0b00..derive clock from PLL2
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from PLL2 PFD0
    // 0b11..derive clock from divided PLL1
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 14> TRACE_CLK_SEL;
    // 0b00..derive clock from PLL2
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from PLL2 PFD0
    // 0b11..derive clock from PLL2 PFD1
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 12> PERIPH_CLK2_SEL;
    // 0b00..derive clock from pll3_sw_clk
    // 0b01..derive clock from osc_clk (pll1_ref_clk)
    // 0b10..derive clock from pll2_bypass_clk
    // 0b11..reserved
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2,  8> FLEXSPI2_CLK_SEL;
    // 0b00..derive clock from PLL2 PFD2
    // 0b01..derive clock from PLL3 PFD0
    // 0b10..derive clock from PLL3 PFD1
    // 0b11..derive clock from PLL2 (pll2_main_clk)
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2,  4> LPSPI_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD1 clk
    // 0b01..derive clock from PLL3 PFD0
    // 0b10..derive clock from PLL2
    // 0b11..derive clock from PLL2 PFD2
}  // namespace CBCMR

// CCM Serial Clock Multiplexer Register 1
namespace CSCMR1 {
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 29> FLEXSPI_CLK_SEL;
    // 0b00..derive clock from semc_clk_root_pre
    // 0b01..derive clock from pll3_sw_clk
    // 0b10..derive clock from PLL2 PFD2
    // 0b11..derive clock from PLL3 PFD0
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 3, 23> FLEXSPI_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1, 17> USDHC2_CLK_SEL;
    // 0b0..derive clock from PLL2 PFD2
    // 0b1..derive clock from PLL2 PFD0
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1, 16> USDHC1_CLK_SEL;
    // 0b0..derive clock from PLL2 PFD2
    // 0b1..derive clock from PLL2 PFD0
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 14> SAI3_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 12> SAI2_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 10> SAI1_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1,  6> PERCLK_CLK_SEL;
    // 0b0..derive clock from ipg clk root
    // 0b1..derive clock from osc_clk
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 6,  0> PERCLK_PODF;  // Divider for perclk podf.
    // Divide by 'value' + 1
}  // namespace CSCMR1

// CCM Serial Clock Multiplexer Register 2
namespace CSCMR2 {
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 2, 19> FLEXIO2_CLK_SEL;
    // 0b00..derive clock from PLL4 divided clock
    // 0b01..derive clock from PLL3 PFD2 clock
    // 0b10..derive clock from PLL5 clock
    // 0b11..derive clock from pll3_sw_clk
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 2,  8> CAN_CLK_SEL;
    // 0b00..derive clock from pll3_sw_clk divided clock (60M)
    // 0b01..derive clock from osc_clk (24M)
    // 0b10..derive clock from pll3_sw_clk divided clock (80M)
    // 0b11..Disable FlexCAN clock
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 6,  2> CAN_CLK_PODF;  // Divider for CAN/CANFD clock podf.
    // Divide by 'value' + 1
}  // namespace CSCMR2

// CCM Serial Clock Divider Register 1
namespace CSCDR1 {
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 2, 25> TRACE_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 3, 16> USDHC2_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 3, 11> USDHC1_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 1,  6> UART_CLK_SEL;
    // 0b0..derive clock from pll3_80m
    // 0b1..derive clock from osc_clk
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 6,  0> UART_CLK_PODF;  // Divider for uart clock podf.
    // Divide by 'value' + 1
}  // namespace CSCDR1

// CCM Clock Divider Register
namespace CS1CDR {
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3, 25> FLEXIO2_CLK_PODF;  //  Divider for flexio2/flexio3 clock.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3, 22> SAI3_CLK_PRED;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 6, 16> SAI3_CLK_PODF;     // Divider for sai3 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3,  9> FLEXIO2_CLK_PRED;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3,  6> SAI1_CLK_PRED;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 6,  0> SAI1_CLK_PODF;     // Divider for sai1 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1
}  // namespace CS1CDR

// CCM Clock Divider Register
namespace CS2CDR {
constexpr CCM_Reg<&CCM_Layout::CS2CDR, 3, 6> SAI2_CLK_PRED;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CS2CDR, 6, 0> SAI2_CLK_PODF;  // Divider for sai2 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1
}  // namespace CS2CDR

// CCM D1 Clock Divider Register
namespace CDCDR {
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 25> SPDIF0_CLK_PRED;  // Divider for spdif0 clock pred.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 22> SPDIF0_CLK_PODF;  // Divider for spdif0 clock podf.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CDCDR, 2, 20> SPDIF0_CLK_SEL;
    // 0b00..derive clock from PLL4
    // 0b01..derive clock from PLL3 PFD2
    // 0b10..derive clock from PLL5
    // 0b11..derive clock from pll3_sw_clk
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 12> FLEXIO1_CLK_PRED;  // Divider for flexio1 clock pred.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3,  9> FLEXIO1_CLK_PODF;  // Divider for flexio1 clock podf.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CDCDR, 2,  7> FLEXIO1_CLK_SEL;
    // 0b00..derive clock from PLL4
    // 0b01..derive clock from PLL3 PFD2
    // 0b10..derive clock from PLL5
    // 0b11..derive clock from pll3_sw_clk
}  // namespace CDCDR

// CCM Serial Clock Divider Register 2
namespace CSCDR2 {
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 6, 19> LPI2C_CLK_PODF;  // Divider for lpi2c clock podf.
    // Divider should be updated when output clock is
    //   gated. The input clock to this divider should be lower than 300Mhz, the predivider can be used
    //   to achieve this.
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 1, 18> LPI2C_CLK_SEL;
    // 0b0..derive clock from pll3_60m
    // 0b1..derive clock from osc_clk
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 3, 15> LCDIF_PRE_CLK_SEL;
    // 0b000..derive clock from PLL2
    // 0b001..derive clock from PLL3 PFD3
    // 0b010..derive clock from PLL5
    // 0b011..derive clock from PLL2 PFD0
    // 0b100..derive clock from PLL2 PFD1
    // 0b101..derive clock from PLL3 PFD1
    // 0b110-0b111..Reserved
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 3, 12> LCDIF_PRED;
    // Divide by 'value' + 1
}  // namespace CSCDR2

// CCM Serial Clock Divider Register 3
namespace CSCDR3 {
constexpr CCM_Reg<&CCM_Layout::CSCDR3, 3, 11> CSI_PODF;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CSCDR3, 2,  9> CSI_CLK_SEL;
    // 0b00..derive clock from osc_clk (24M)
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from pll3_120M
    // 0b11..derive clock from PLL3 PFD1
}  // namespace CSCDR3

// CCM Divider Handshake In-Process Register
namespace CDHIPR {
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1, 16> ARM_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the arm_podf will be applied.
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  5> PERIPH_CLK_SEL_BUSY;
    // 0b0..mux is not busy and its value represents the actual division.
    // 0b1..mux is busy with handshake process with module. The value read in the periph_clk_sel represents the
    //      previous value of select, and after the handshake periph_clk_sel value will be applied.
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  3> PERIPH2_CLK_SEL_BUSY;
    // 0b0..mux is not busy and its value represents the actual division.
    // 0b1..mux is busy with handshake process with module. The value read in the periph2_clk_sel represents the
    //      previous value of select, and after the handshake periph2_clk_sel value will be applied.
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  1> AHB_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the ahb_podf will be applied.
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  0> SEMC_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the semc_podf will be applied.
}  // namespace CDHIPR

// CCM Low Power Control Register
namespace CLPCR {
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 27> MASK_L2CC_IDLE;
    // 0b0..L2CC IDLE is not masked
    // 0b1..L2CC IDLE is masked
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 26> MASK_SCU_IDLE;
    // 0b0..SCU IDLE is not masked
    // 0b1..SCU IDLE is masked
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 22> MASK_CORE0_WFI;
    // 0b0..WFI of core0 is not masked
    // 0b1..WFI of core0 is masked
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 21> BYPASS_LPM_HS0;
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 19> BYPASS_LPM_HS1;
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 11> COSC_PWRDOWN;
    // 0b0..On chip oscillator will not be powered down, i.e. cosc_pwrdown = '0'.
    // 0b1..On chip oscillator will be powered down, i.e. cosc_pwrdown = '1'.
constexpr CCM_Reg<&CCM_Layout::CLPCR, 2,  9> STBY_COUNT;
    // 0b00..CCM will wait (1*pmic_delay_scaler)+1 ckil clock cycles
    // 0b01..CCM will wait (3*pmic_delay_scaler)+1 ckil clock cycles
    // 0b10..CCM will wait (7*pmic_delay_scaler)+1 ckil clock cycles
    // 0b11..CCM will wait (15*pmic_delay_scaler)+1 ckil clock cycles
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  8> VSTBY;
    // 0b0..Voltage will not be changed to standby voltage after next entrance to STOP mode. ( PMIC_STBY_REQ will remain negated - '0')
    // 0b1..Voltage will be requested to change to standby voltage after next entrance to stop mode. ( PMIC_STBY_REQ will be asserted - '1').
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  7> DIS_REF_OSC;
    // 0b0..external high frequency oscillator will be enabled, i.e. CCM_REF_EN_B = '0'.
    // 0b1..external high frequency oscillator will be disabled, i.e. CCM_REF_EN_B = '1'
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  6> SBYOS;
    // 0b0..On-chip oscillator will not be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will remain
    //      asserted - '0' and cosc_pwrdown will remain de asserted - '0')
    // 0b1..On-chip oscillator will be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will be
    //      deasserted - '1' and cosc_pwrdown will be asserted - '1'). When returning from STOP mode, external oscillator will
    //      be enabled again, on-chip oscillator will return to oscillator mode, and after oscnt count, CCM will
    //      continue with the exit from the STOP mode process.
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  5> ARM_CLK_DIS_ON_LPM;
    // 0b0..Arm clock enabled on wait mode.
    // 0b1..Arm clock disabled on wait mode. .
constexpr CCM_Reg<&CCM_Layout::CLPCR, 2,  0> LPM;
    // 0b00..Remain in run mode
    // 0b01..Transfer to wait mode
    // 0b10..Transfer to stop mode
    // 0b11..Reserved
}  // namespace CLPCR

// CCM Interrupt Status Register
namespace CISR {
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 26, true> ARM_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of arm_podf
    // 0b1..interrupt generated due to frequency change of arm_podf
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 22, true> PERIPH_CLK_SEL_LOADED;
    // 0b0..interrupt is not generated due to update of periph_clk_sel.
    // 0b1..interrupt generated due to update of periph_clk_sel.
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 20, true> AHB_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of ahb_podf
    // 0b1..interrupt generated due to frequency change of ahb_podf
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 19, true> PERIPH2_CLK_SEL_LOADED;
    // 0b0..interrupt is not generated due to frequency change of periph2_clk_sel
    // 0b1..interrupt generated due to frequency change of periph2_clk_sel
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 17, true> SEMC_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of semc_podf
    // 0b1..interrupt generated due to frequency change of semc_podf
constexpr CCM_Reg<&CCM_Layout::CISR, 1,  6, true> COSC_READY;
    // 0b0..interrupt is not generated due to on board oscillator ready
    // 0b1..interrupt generated due to on board oscillator ready
constexpr CCM_Reg<&CCM_Layout::CISR, 1,  0, true> LRF_PLL;
    // 0b0..interrupt is not generated due to lock ready of all enabled and not bypaseed PLLs
    // 0b1..interrupt generated due to lock ready of all enabled and not bypaseed PLLs
}  // namespace CISR

// CCM Interrupt Mask Register
namespace CIMR {
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 26> ARM_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of arm_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of arm_podf
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 22> MASK_PERIPH_CLOCK_SEL_LOADED;
    // 0b0..don't mask interrupt due to update of periph_clk_sel - interrupt will be created
    // 0b1..mask interrupt due to update of periph_clk_sel
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 20> MASK_AHB_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of ahb_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of ahb_podf
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 19> MASK_PERIPH2_CLK_SEL_LOADED;
    // 0b0..don't mask interrupt due to update of periph2_clk_sel - interrupt will be created
    // 0b1..mask interrupt due to update of periph2_clk_sel
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 17> MASK_SEMC_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of semc_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of semc_podf
constexpr CCM_Reg<&CCM_Layout::CIMR, 1,  6> MASK_COSC_READY;
    // 0b0..don't mask interrupt due to on board oscillator ready - interrupt will be created
    // 0b1..mask interrupt due to on board oscillator ready
constexpr CCM_Reg<&CCM_Layout::CIMR, 1,  0> MASK_LRF_PLL;
    // 0b0..don't mask interrupt due to lrf of PLLs - interrupt will be created
    // 0b1..mask interrupt due to lrf of PLLs
}  // namespace CIMR

// CCM Clock Output Source Register
namespace CCOSR {
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1, 24> CLKO2_EN;
    // 0b0..CCM_CLKO2 disabled.
    // 0b1..CCM_CLKO2 enabled.
constexpr CCM_Reg<&CCM_Layout::CCOSR, 3, 21> CLKO2_DIV;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CCOSR, 5, 16> CLKO2_SEL;
    // 0b00011..usdhc1_clk_root
    // 0b00110..lpi2c_clk_root
    // 0b01011..csi_clk_root
    // 0b01110..osc_clk
    // 0b10001..usdhc2_clk_root
    // 0b10010..sai1_clk_root
    // 0b10011..sai2_clk_root
    // 0b10100..sai3_clk_root (shared with ADC1 and ADC2 alt_clk root)
    // 0b10111..can_clk_root (FlexCAN, shared with CANFD)
    // 0b11011..flexspi_clk_root
    // 0b11100..uart_clk_root
    // 0b11101..spdif0_clk_root
    // 0b11111..Reserved
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1,  8> CLK_OUT_SEL;
    // 0b0..CCM_CLKO1 output drives CCM_CLKO1 clock
    // 0b1..CCM_CLKO1 output drives CCM_CLKO2 clock
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1,  7> CLKO1_EN;
    // 0b0..CCM_CLKO1 disabled.
    // 0b1..CCM_CLKO1 enabled.
constexpr CCM_Reg<&CCM_Layout::CCOSR, 3,  4> CLKO1_DIV;
    // Divide by 'value' + 1
constexpr CCM_Reg<&CCM_Layout::CCOSR, 4,  0> CLKO1_SEL;
    // 0b0000..USB1 PLL clock (divided by 2)
    // 0b0001..SYS PLL clock (divided by 2)
    // 0b0011..VIDEO PLL clock (divided by 2)
    // 0b0101..semc_clk_root
    // 0b0110..Reserved
    // 0b1010..lcdif_pix_clk_root
    // 0b1011..ahb_clk_root
    // 0b1100..ipg_clk_root
    // 0b1101..perclk_root
    // 0b1110..ckil_sync_clk_root
    // 0b1111..pll4_main_clk
}  // namespace CCOSR

// CCM General Purpose Register
namespace CGPR {
constexpr CCM_Reg<&CCM_Layout::CGPR, 1, 17> INT_MEM_CLK_LPM;
    // 0b0..Disable the clock to the Arm platform memories when entering Low Power Mode
    // 0b1..Keep the clocks to the Arm platform memories enabled only if an interrupt is pending when entering Low
    //      Power Modes (WAIT and STOP without power gating)
constexpr CCM_Reg<&CCM_Layout::CGPR, 1, 16> FPL;  // Fast PLL enable.
    // 0b0..Engage PLL enable default way.
    // 0b1..Engage PLL enable 3 CKIL clocks earlier at exiting low power mode (STOP). Should be used only if 24MHz OSC was active in low power mode.
constexpr CCM_Reg<&CCM_Layout::CGPR, 2, 14> SYS_MEM_DS_CTRL;
    // 0b00..Disable memory DS mode always
    // 0b01..Enable memory (outside Arm platform) DS mode when system STOP and PLL are disabled
    // 0b1x..enable memory (outside Arm platform) DS mode when system is in STOP mode
constexpr CCM_Reg<&CCM_Layout::CGPR, 1,  4> EFUSE_PROG_SUPPLY_GATE;
    // 0b0..fuse programing supply voltage is gated off to the efuse module
    // 0b1..allow fuse programing.
constexpr CCM_Reg<&CCM_Layout::CGPR, 1,  0> PMIC_DELAY_SCALER;
    // 0b0..clock is not divided
    // 0b1..clock is divided /8
}  // namespace CGPR

// CCM Clock Gating Register 0
namespace CCGR0 {
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 30> GPIO2;        // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 28> LPUART2;      // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 26> GPT2_SERIAL;  // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 24> GPT2_BUS;     // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 22> TRACE;        // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 20> CAN2_SERIAL;  // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 18> CAN2_CLOCK;   // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 16> CAN1_SERIAL;  // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 14> CAN1_CLOCK;   // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 12> LPUART3;      // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 10> DCP;          // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  8> SIM_M;        // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  6> CG3;          // CG3 (Reserved)
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  4> MQS;          // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  2> AIPS_TZ2;     // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  0> AIPS_TZ1;     // CG0
}  // namespace CCGR0

// CCM Clock Gating Register 1
namespace CCGR1 {
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 30> GPIO5;        // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 28> CSU;          // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 26> GPIO1;        // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 24> LPUART4;      // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 22> GPT1_SERIAL;  // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 20> GPT1_BUS;     // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 18> SEMC_EXSC;    // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 16> ADC1;         // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 14> AOI2;         // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 12> PIT;          // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 10> ENET;         // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  8> ADC2;         // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  6> LPSPI4;       // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  4> LPSPI3;       // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  2> LPSPI2;       // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  0> LPSPI1;       // CG0
}  // namespace CCGR1

// CCM Clock Gating Register 2
namespace CCGR2 {
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 30> PXP;          // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 28> LCD;          // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 26> GPIO3;        // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 24> XBAR2;        // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 22> XBAR1;        // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 20> IPMUX3;       // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 18> IPMUX2;       // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 16> IPMUX1;       // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 14> XBAR3;        // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 12> OCOTP_CTRL;   // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 10> LPI2C3;       // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  8> LPI2C2;       // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  6> LPI2C1;       // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  4> IOMUXC_SNVS;  // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  2> CSI;          // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  0> OCRAM_EXSC;   // CG0
}  // namespace CCGR2

// CCM Clock Gating Register 3
namespace CCGR3 {
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 30> IOMUXC_SNVS_GPR;  // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 28> OCRAM;            // CG14 - The OCRAM clock cannot be turned off when the CM cache is running on this device.
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 26> ACMP4;            // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 24> ACMP3;            // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 22> ACMP2;            // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 20> ACMP1;            // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 18> FLEXRAM;          // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 16> WDOG1;            // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 14> EWM;              // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 12> GPIO4;            // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 10> LCDIF_PIX;        // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  8> AOI1;             // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  6> LPUART6;          // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  4> SEMC;             // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  2> LPUART5;          // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  0> FLEXIO2;          // CG0
}  // namespace CCGR3

// CCM Clock Gating Register 4
namespace CCGR4 {
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 30> QDC4;        // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 28> QDC3;        // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 26> QDC2;        // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 24> QDC1;        // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 22> PWM4;        // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 20> PWM3;        // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 18> PWM2;        // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 16> PWM1;        // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 14> SIM_EMS;     // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 12> SIM_M;       // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 10> TSC_DIG;     // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  8> SIM_M7;      // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  6> BEE;         // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  4> IOMUXC_GPR;  // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  2> IOMUXC;      // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  0> SIM_M7_REG;  // CG0
}  // namespace CCGR4

// CCM Clock Gating Register 5
namespace CCGR5 {
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 30> SNVS_LP;   // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 28> SNVS_HP;   // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 26> LPUART7;   // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 24> LPUART1;   // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 22> SAI3;      // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 20> SAI2;      // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 18> SAI1;      // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 16> SIM_MAIN;  // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 14> SPDIF;     // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 12> AIPSTZ4;   // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 10> WDOG2;     // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  8> KPP;       // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  6> DMA;       // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  4> WDOG3;     // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  2> FLEXIO1;   // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  0> ROM;       // CG0
}  // namespace CCGR5

// CCM Clock Gating Register 6
namespace CCGR6 {
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 30> TIMER3;    // CG15
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 28> TIMER2;    // CG14
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 26> TIMER1;    // CG13
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 24> LPI2C4;    // CG12
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 22> ANADIG;    // CG11
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 20> SIM_PER;   // CG10
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 18> AIPS_TZ3;  // CG9
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 16> TIMER4;    // CG8
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 14> LPUART8;   // CG7
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 12> TRNG;      // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 10> FLEXSPI;   // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  8> IPMUX4;    // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  6> DCDC;      // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  4> USDHC2;    // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  2> USDHC1;    // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  0> USBOH3;    // CG0
}  // namespace CCGR6

// CCM Clock Gating Register 7
namespace CCGR7 {
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2, 12> FLEXIO3;      // CG6
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2, 10> AIPS_LITE;    // CG5
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  8> CAN3_SERIAL;  // CG4
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  6> CAN3_CLK;     // CG3
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  4> AXBS_L;       // CG2
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  2> FLEXSPI2;     // CG1
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  0> ENET2;        // CG0
}  // namespace CCGR7

// CCM Module Enable Overide Register
namespace CMEOR {
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 30> MOD_EN_OV_CAN1_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 28> MOD_EN_OV_CAN2_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 10> MOD_EN_OV_CANFD_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  9> MOD_EN_OV_TRNG;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  7> MOD_EN_USDHC;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  6> MOD_EN_OV_PIT;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  5> MOD_EN_OV_GPT;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
}  // namespace CMEOR

// Clock gating values
namespace CCGR {
constexpr uint32_t kOFF      = 0x00;
constexpr uint32_t kRUN_ONLY = 0x01;
constexpr uint32_t kON       = 0x03;
}  // namespace CCGR

}  // namespace CCM

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
