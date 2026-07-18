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
namespace teensy4 {

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

constexpr regs::RegGroup<CCM_Layout, kCCM_size, kCCM_base> CCM;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using CCM_Reg =
    regs::Reg32<kCCM_base, CCM_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// CCM Control Register
#undef CCM_CCR_RBC_EN
constexpr CCM_Reg<&CCM_Layout::CCR, 1, 27> CCM_CCR_RBC_EN;
    // 0b0..REG_BYPASS_COUNTER disabled
    // 0b1..REG_BYPASS_COUNTER enabled.
#undef CCM_CCR_REG_BYPASS_COUNT
constexpr CCM_Reg<&CCM_Layout::CCR, 6, 21> CCM_CCR_REG_BYPASS_COUNT;
    // 'value' CKIL clock period delay:
    // 0b000000..no delay
    // 0b000001..1 CKIL clock period delay
    // 0b111111..63 CKIL clock periods delay
#undef CCM_CCR_COSC_EN
constexpr CCM_Reg<&CCM_Layout::CCR, 1, 12> CCM_CCR_COSC_EN;
    // 0b0..disable on chip oscillator
    // 0b1..enable on chip oscillator
#undef CCM_CCR_OSCNT
constexpr CCM_Reg<&CCM_Layout::CCR, 8,  0> CCM_CCR_OSCNT;  // Oscillator ready counter value
    // These bits define value of 32KHz counter, that serve as
    // counter for oscillator lock time (count to n+1 ckil's). This is used for oscillator lock time.
    // Current estimation is ~5ms. This counter will be used in ignition sequence and in wake from
    // stop sequence if sbyos bit was defined, to notify that on chip oscillator output is ready for
    // the dpll_ip to use and only then the gate in dpll_ip can be opened.

// CCM Status Register
#undef CCM_CSR_COSC_READY
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 5> CCM_CSR_COSC_READY;
    // 0b0..on board oscillator is not ready.
    // 0b1..on board oscillator is ready.
#undef CCM_CSR_CAMP2_READY
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 3> CCM_CSR_CAMP2_READY;
    // 0b0..CAMP2 is not ready.
    // 0b1..CAMP2 is ready.
#undef CCM_CSR_REF_EN_B
constexpr CCM_Reg<&CCM_Layout::CSR, 1, 0> CCM_CSR_REF_EN_B;
    // 0b0..value of CCM_REF_EN_B is '0'
    // 0b1..value of CCM_REF_EN_B is '1'

// CCM Clock Switcher Register
#undef CCM_CCSR_PLL3_SW_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CCSR, 1, 0> CCM_CCSR_PLL3_SW_CLK_SEL;
// 0b0..pll3_main_clk
// 0b1..pll3 bypass clock

// CCM Arm Clock Root Register
#undef CCM_CACRR_ARM_PODF
constexpr CCM_Reg<&CCM_Layout::CACRR, 3, 0> CCM_CACRR_ARM_PODF;
    // Divide by 'value + 1:
    // 0b000..divide by 1
    // 0b001..divide by 2
    // 0b010..divide by 3
    // 0b011..divide by 4
    // 0b100..divide by 5
    // 0b101..divide by 6
    // 0b110..divide by 7
    // 0b111..divide by 8

// CCM Bus Clock Divider Register
#undef CCM_CBCDR_PERIPH_CLK2_PODF
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 27> CCM_CBCDR_PERIPH_CLK2_PODF;
    // Divide by 'value + 1
#undef CCM_CBCDR_PERIPH_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1, 25> CCM_CBCDR_PERIPH_CLK_SEL;
    // 0b0..derive clock from pre_periph_clk_sel
    // 0b1..derive clock from periph_clk2_clk_divided
#undef CCM_CBCDR_SEMC_PODF
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 16> CCM_CBCDR_SEMC_PODF;
    // Divide by 'value' + 1
#undef CCM_CBCDR_AHB_PODF
constexpr CCM_Reg<&CCM_Layout::CBCDR, 3, 10> CCM_CBCDR_AHB_PODF;
    // Divide by 'value' + 1
#undef CCM_CBCDR_IPG_PODF
constexpr CCM_Reg<&CCM_Layout::CBCDR, 2,  8> CCM_CBCDR_IPG_PODF;
    // Divide by 'value' + 1:
    // 0b00..divide by 1
    // 0b01..divide by 2
    // 0b10..divide by 3
    // 0b11..divide by 4
#undef CCM_CBCDR_SEMC_ALT_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1,  7> CCM_CBCDR_SEMC_ALT_CLK_SEL;
    // 0b0..PLL2 PFD2 will be selected as alternative clock for SEMC root clock
    // 0b1..PLL3 PFD1 will be selected as alternative clock for SEMC root clock
#undef CCM_CBCDR_SEMC_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCDR, 1,  6> CCM_CBCDR_SEMC_CLK_SEL;
    // 0b0..Periph_clk output will be used as SEMC clock root
    // 0b1..SEMC alternative clock will be used as SEMC clock root

// CCM Bus Clock Multiplexer Register
#undef CCM_CBCMR_FLEXSPI2_PODF
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 29> CCM_CBCMR_FLEXSPI2_PODF;
    // Divide by 'value' + 1
#undef CCM_CBCMR_LPSPI_PODF
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 26> CCM_CBCMR_LPSPI_PODF;
    // Divide by 'value' + 1
#undef CCM_CBCMR_LCDIF_PODF
constexpr CCM_Reg<&CCM_Layout::CBCMR, 3, 23> CCM_CBCMR_LCDIF_PODF;
    // Divide by 'value' + 1
#undef CCM_CBCMR_PRE_PERIPH_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 18> CCM_CBCMR_PRE_PERIPH_CLK_SEL;
    // 0b00..derive clock from PLL2
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from PLL2 PFD0
    // 0b11..derive clock from divided PLL1
#undef CCM_CBCMR_TRACE_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 14> CCM_CBCMR_TRACE_CLK_SEL;
    // 0b00..derive clock from PLL2
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from PLL2 PFD0
    // 0b11..derive clock from PLL2 PFD1
#undef CCM_CBCMR_PERIPH_CLK2_SEL
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2, 12> CCM_CBCMR_PERIPH_CLK2_SEL;
    // 0b00..derive clock from pll3_sw_clk
    // 0b01..derive clock from osc_clk (pll1_ref_clk)
    // 0b10..derive clock from pll2_bypass_clk
    // 0b11..reserved
#undef CCM_CBCMR_FLEXSPI2_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2,  8> CCM_CBCMR_FLEXSPI2_CLK_SEL;
    // 0b00..derive clock from PLL2 PFD2
    // 0b01..derive clock from PLL3 PFD0
    // 0b10..derive clock from PLL3 PFD1
    // 0b11..derive clock from PLL2 (pll2_main_clk)
#undef CCM_CBCMR_LPSPI_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CBCMR, 2,  4> CCM_CBCMR_LPSPI_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD1 clk
    // 0b01..derive clock from PLL3 PFD0
    // 0b10..derive clock from PLL2
    // 0b11..derive clock from PLL2 PFD2

// CCM Serial Clock Multiplexer Register 1
#undef CCM_CSCMR1_FLEXSPI_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 29> CCM_CSCMR1_FLEXSPI_CLK_SEL;
    // 0b00..derive clock from semc_clk_root_pre
    // 0b01..derive clock from pll3_sw_clk
    // 0b10..derive clock from PLL2 PFD2
    // 0b11..derive clock from PLL3 PFD0
#undef CCM_CSCMR1_FLEXSPI_PODF
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 3, 23> CCM_CSCMR1_FLEXSPI_PODF;
    // Divide by 'value' + 1
#undef CCM_CSCMR1_USDHC2_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1, 17> CCM_CSCMR1_USDHC2_CLK_SEL;
    // 0b0..derive clock from PLL2 PFD2
    // 0b1..derive clock from PLL2 PFD0
#undef CCM_CSCMR1_USDHC1_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1, 16> CCM_CSCMR1_USDHC1_CLK_SEL;
    // 0b0..derive clock from PLL2 PFD2
    // 0b1..derive clock from PLL2 PFD0
#undef CCM_CSCMR1_SAI3_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 14> CCM_CSCMR1_SAI3_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
#undef CCM_CSCMR1_SAI2_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 12> CCM_CSCMR1_SAI2_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
#undef CCM_CSCMR1_SAI1_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 2, 10> CCM_CSCMR1_SAI1_CLK_SEL;
    // 0b00..derive clock from PLL3 PFD2
    // 0b01..derive clock from PLL5
    // 0b10..derive clock from PLL4
    // 0b11..Reserved
#undef CCM_CSCMR1_PERCLK_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 1,  6> CCM_CSCMR1_PERCLK_CLK_SEL;
    // 0b0..derive clock from ipg clk root
    // 0b1..derive clock from osc_clk
#undef CCM_CSCMR1_PERCLK_PODF
constexpr CCM_Reg<&CCM_Layout::CSCMR1, 6,  0> CCM_CSCMR1_PERCLK_PODF;  // Divider for perclk podf.
    // Divide by 'value' + 1

// CCM Serial Clock Multiplexer Register 2
#undef CCM_CSCMR2_FLEXIO2_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 2, 19> CCM_CSCMR2_FLEXIO2_CLK_SEL;
    // 0b00..derive clock from PLL4 divided clock
    // 0b01..derive clock from PLL3 PFD2 clock
    // 0b10..derive clock from PLL5 clock
    // 0b11..derive clock from pll3_sw_clk
#undef CCM_CSCMR2_CAN_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 2,  8> CCM_CSCMR2_CAN_CLK_SEL;
    // 0b00..derive clock from pll3_sw_clk divided clock (60M)
    // 0b01..derive clock from osc_clk (24M)
    // 0b10..derive clock from pll3_sw_clk divided clock (80M)
    // 0b11..Disable FlexCAN clock
#undef CCM_CSCMR2_CAN_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CSCMR2, 6,  2> CCM_CSCMR2_CAN_CLK_PODF;  // Divider for CAN/CANFD clock podf.
    // Divide by 'value' + 1

// CCM Serial Clock Divider Register 1
#undef CCM_CSCDR1_TRACE_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 2, 25> CCM_CSCDR1_TRACE_PODF;
    // Divide by 'value' + 1
#undef CCM_CSCDR1_USDHC2_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 3, 16> CCM_CSCDR1_USDHC2_PODF;
    // Divide by 'value' + 1
#undef CCM_CSCDR1_USDHC1_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 3, 11> CCM_CSCDR1_USDHC1_PODF;
    // Divide by 'value' + 1
#undef CCM_CSCDR1_UART_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 1,  6> CCM_CSCDR1_UART_CLK_SEL;
    // 0b0..derive clock from pll3_80m
    // 0b1..derive clock from osc_clk
#undef CCM_CSCDR1_UART_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR1, 6,  0> CCM_CSCDR1_UART_CLK_PODF;  // Divider for uart clock podf.
    // Divide by 'value' + 1

// CCM Clock Divider Register
#undef CCM_CS1CDR_FLEXIO2_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3, 25> CCM_CS1CDR_FLEXIO2_CLK_PODF;  //  Divider for flexio2/flexio3 clock.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
#undef CCM_CS1CDR_SAI3_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3, 22> CCM_CS1CDR_SAI3_CLK_PRED;
    // Divide by 'value' + 1
#undef CCM_CS1CDR_SAI3_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 6, 16> CCM_CS1CDR_SAI3_CLK_PODF;     // Divider for sai3 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1
#undef CCM_CS1CDR_FLEXIO2_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3,  9> CCM_CS1CDR_FLEXIO2_CLK_PRED;
    // Divide by 'value' + 1
#undef CCM_CS1CDR_SAI1_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 3,  6> CCM_CS1CDR_SAI1_CLK_PRED;
    // Divide by 'value' + 1
#undef CCM_CS1CDR_SAI1_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CS1CDR, 6,  0> CCM_CS1CDR_SAI1_CLK_PODF;     // Divider for sai1 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1

// CCM Clock Divider Register
#undef CCM_CS2CDR_SAI2_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CS2CDR, 3, 6> CCM_CS2CDR_SAI2_CLK_PRED;
    // Divide by 'value' + 1
#undef CCM_CS2CDR_SAI2_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CS2CDR, 6, 0> CCM_CS2CDR_SAI2_CLK_PODF;  // Divider for sai2 clock podf.
    // The input clock to this divider should be lower
    //   than 300Mhz, the predivider can be used to achieve this.
    // Divide by 'value' + 1

// CCM D1 Clock Divider Register
#undef CCM_CDCDR_SPDIF0_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 25> CCM_CDCDR_SPDIF0_CLK_PRED;  // Divider for spdif0 clock pred.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
#undef CCM_CDCDR_SPDIF0_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 22> CCM_CDCDR_SPDIF0_CLK_PODF;  // Divider for spdif0 clock podf.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
#undef CCM_CDCDR_SPDIF0_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CDCDR, 2, 20> CCM_CDCDR_SPDIF0_CLK_SEL;
    // 0b00..derive clock from PLL4
    // 0b01..derive clock from PLL3 PFD2
    // 0b10..derive clock from PLL5
    // 0b11..derive clock from pll3_sw_clk
#undef CCM_CDCDR_FLEXIO1_CLK_PRED
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3, 12> CCM_CDCDR_FLEXIO1_CLK_PRED;  // Divider for flexio1 clock pred.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
#undef CCM_CDCDR_FLEXIO1_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CDCDR, 3,  9> CCM_CDCDR_FLEXIO1_CLK_PODF;  // Divider for flexio1 clock podf.
    // Divider should be updated when output clock is gated.
    // Divide by 'value' + 1
#undef CCM_CDCDR_FLEXIO1_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CDCDR, 2,  7> CCM_CDCDR_FLEXIO1_CLK_SEL;
    // 0b00..derive clock from PLL4
    // 0b01..derive clock from PLL3 PFD2
    // 0b10..derive clock from PLL5
    // 0b11..derive clock from pll3_sw_clk

// CCM Serial Clock Divider Register 2
#undef CCM_CSCDR2_LPI2C_CLK_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 6, 19> CCM_CSCDR2_LPI2C_CLK_PODF;  // Divider for lpi2c clock podf.
    // Divider should be updated when output clock is
    //   gated. The input clock to this divider should be lower than 300Mhz, the predivider can be used
    //   to achieve this.
    // Divide by 'value' + 1
#undef CCM_CSCDR2_LPI2C_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 1, 18> CCM_CSCDR2_LPI2C_CLK_SEL;
    // 0b0..derive clock from pll3_60m
    // 0b1..derive clock from osc_clk
#undef CCM_CSCDR2_LCDIF_PRE_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 3, 15> CCM_CSCDR2_LCDIF_PRE_CLK_SEL;
    // 0b000..derive clock from PLL2
    // 0b001..derive clock from PLL3 PFD3
    // 0b010..derive clock from PLL5
    // 0b011..derive clock from PLL2 PFD0
    // 0b100..derive clock from PLL2 PFD1
    // 0b101..derive clock from PLL3 PFD1
    // 0b110-0b111..Reserved
#undef CCM_CSCDR2_LCDIF_PRED
constexpr CCM_Reg<&CCM_Layout::CSCDR2, 3, 12> CCM_CSCDR2_LCDIF_PRED;
    // Divide by 'value' + 1

// CCM Serial Clock Divider Register 3
#undef CCM_CSCDR3_CSI_PODF
constexpr CCM_Reg<&CCM_Layout::CSCDR3, 3, 11> CCM_CSCDR3_CSI_PODF;
    // Divide by 'value' + 1
#undef CCM_CSCDR3_CSI_CLK_SEL
constexpr CCM_Reg<&CCM_Layout::CSCDR3, 2,  9> CCM_CSCDR3_CSI_CLK_SEL;
    // 0b00..derive clock from osc_clk (24M)
    // 0b01..derive clock from PLL2 PFD2
    // 0b10..derive clock from pll3_120M
    // 0b11..derive clock from PLL3 PFD1

// CCM Divider Handshake In-Process Register
#undef CCM_CDHIPR_ARM_PODF_BUSY
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1, 16> CCM_CDHIPR_ARM_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the arm_podf will be applied.
#undef CCM_CDHIPR_PERIPH_CLK_SEL_BUSY
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  5> CCM_CDHIPR_PERIPH_CLK_SEL_BUSY;
    // 0b0..mux is not busy and its value represents the actual division.
    // 0b1..mux is busy with handshake process with module. The value read in the periph_clk_sel represents the
    //      previous value of select, and after the handshake periph_clk_sel value will be applied.
#undef CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  3> CCM_CDHIPR_PERIPH2_CLK_SEL_BUSY;
    // 0b0..mux is not busy and its value represents the actual division.
    // 0b1..mux is busy with handshake process with module. The value read in the periph2_clk_sel represents the
    //      previous value of select, and after the handshake periph2_clk_sel value will be applied.
#undef CCM_CDHIPR_AHB_PODF_BUSY
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  1> CCM_CDHIPR_AHB_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the ahb_podf will be applied.
#undef CCM_CDHIPR_SEMC_PODF_BUSY
constexpr CCM_Reg<&CCM_Layout::CDHIPR, 1,  0> CCM_CDHIPR_SEMC_PODF_BUSY;
    // 0b0..divider is not busy and its value represents the actual division.
    // 0b1..divider is busy with handshake process with module. The value read in the divider represents the previous
    //      value of the division factor, and after the handshake the written value of the semc_podf will be applied.

// CCM Low Power Control Register
#undef CCM_CLPCR_MASK_L2CC_IDLE
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 27> CCM_CLPCR_MASK_L2CC_IDLE;
    // 0b0..L2CC IDLE is not masked
    // 0b1..L2CC IDLE is masked
#undef CCM_CLPCR_MASK_SCU_IDLE
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 26> CCM_CLPCR_MASK_SCU_IDLE;
    // 0b0..SCU IDLE is not masked
    // 0b1..SCU IDLE is masked
#undef CCM_CLPCR_MASK_CORE0_WFI
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 22> CCM_CLPCR_MASK_CORE0_WFI;
    // 0b0..WFI of core0 is not masked
    // 0b1..WFI of core0 is masked
#undef CCM_CLPCR_BYPASS_LPM_HS0
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 21> CCM_CLPCR_BYPASS_LPM_HS0;
#undef CCM_CLPCR_BYPASS_LPM_HS1
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 19> CCM_CLPCR_BYPASS_LPM_HS1;
#undef CCM_CLPCR_COSC_PWRDOWN
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1, 11> CCM_CLPCR_COSC_PWRDOWN;
    // 0b0..On chip oscillator will not be powered down, i.e. cosc_pwrdown = '0'.
    // 0b1..On chip oscillator will be powered down, i.e. cosc_pwrdown = '1'.
#undef CCM_CLPCR_STBY_COUNT
constexpr CCM_Reg<&CCM_Layout::CLPCR, 2,  9> CCM_CLPCR_STBY_COUNT;
    // 0b00..CCM will wait (1*pmic_delay_scaler)+1 ckil clock cycles
    // 0b01..CCM will wait (3*pmic_delay_scaler)+1 ckil clock cycles
    // 0b10..CCM will wait (7*pmic_delay_scaler)+1 ckil clock cycles
    // 0b11..CCM will wait (15*pmic_delay_scaler)+1 ckil clock cycles
#undef CCM_CLPCR_VSTBY
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  8> CCM_CLPCR_VSTBY;
    // 0b0..Voltage will not be changed to standby voltage after next entrance to STOP mode. ( PMIC_STBY_REQ will remain negated - '0')
    // 0b1..Voltage will be requested to change to standby voltage after next entrance to stop mode. ( PMIC_STBY_REQ will be asserted - '1').
#undef CCM_CLPCR_DIS_REF_OSC
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  7> CCM_CLPCR_DIS_REF_OSC;
    // 0b0..external high frequency oscillator will be enabled, i.e. CCM_REF_EN_B = '0'.
    // 0b1..external high frequency oscillator will be disabled, i.e. CCM_REF_EN_B = '1'
#undef CCM_CLPCR_SBYOS
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  6> CCM_CLPCR_SBYOS;
    // 0b0..On-chip oscillator will not be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will remain
    //      asserted - '0' and cosc_pwrdown will remain de asserted - '0')
    // 0b1..On-chip oscillator will be powered down, after next entrance to STOP mode. (CCM_REF_EN_B will be
    //      deasserted - '1' and cosc_pwrdown will be asserted - '1'). When returning from STOP mode, external oscillator will
    //      be enabled again, on-chip oscillator will return to oscillator mode, and after oscnt count, CCM will
    //      continue with the exit from the STOP mode process.
#undef CCM_CLPCR_ARM_CLK_DIS_ON_LPM
constexpr CCM_Reg<&CCM_Layout::CLPCR, 1,  5> CCM_CLPCR_ARM_CLK_DIS_ON_LPM;
    // 0b0..Arm clock enabled on wait mode.
    // 0b1..Arm clock disabled on wait mode. .
#undef CCM_CLPCR_LPM
constexpr CCM_Reg<&CCM_Layout::CLPCR, 2,  0> CCM_CLPCR_LPM;
    // 0b00..Remain in run mode
    // 0b01..Transfer to wait mode
    // 0b10..Transfer to stop mode
    // 0b11..Reserved

// CCM Interrupt Status Register
#undef CCM_CISR_ARM_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 26, true> CCM_CISR_ARM_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of arm_podf
    // 0b1..interrupt generated due to frequency change of arm_podf
#undef CCM_CISR_PERIPH_CLK_SEL_LOADED
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 22, true> CCM_CISR_PERIPH_CLK_SEL_LOADED;
    // 0b0..interrupt is not generated due to update of periph_clk_sel.
    // 0b1..interrupt generated due to update of periph_clk_sel.
#undef CCM_CISR_AHB_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 20, true> CCM_CISR_AHB_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of ahb_podf
    // 0b1..interrupt generated due to frequency change of ahb_podf
#undef CCM_CISR_PERIPH2_CLK_SEL_LOADED
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 19, true> CCM_CISR_PERIPH2_CLK_SEL_LOADED;
    // 0b0..interrupt is not generated due to frequency change of periph2_clk_sel
    // 0b1..interrupt generated due to frequency change of periph2_clk_sel
#undef CCM_CISR_SEMC_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CISR, 1, 17, true> CCM_CISR_SEMC_PODF_LOADED;
    // 0b0..interrupt is not generated due to frequency change of semc_podf
    // 0b1..interrupt generated due to frequency change of semc_podf
#undef CCM_CISR_COSC_READY
constexpr CCM_Reg<&CCM_Layout::CISR, 1,  6, true> CCM_CISR_COSC_READY;
    // 0b0..interrupt is not generated due to on board oscillator ready
    // 0b1..interrupt generated due to on board oscillator ready
#undef CCM_CISR_LRF_PLL
constexpr CCM_Reg<&CCM_Layout::CISR, 1,  0, true> CCM_CISR_LRF_PLL;
    // 0b0..interrupt is not generated due to lock ready of all enabled and not bypaseed PLLs
    // 0b1..interrupt generated due to lock ready of all enabled and not bypaseed PLLs

// CCM Interrupt Mask Register
#undef CCM_CIMR_ARM_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 26> CCM_CIMR_ARM_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of arm_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of arm_podf
#undef CCM_CIMR_MASK_PERIPH_CLOCK_SEL_LOADED
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 22> CCM_CIMR_MASK_PERIPH_CLOCK_SEL_LOADED;
    // 0b0..don't mask interrupt due to update of periph_clk_sel - interrupt will be created
    // 0b1..mask interrupt due to update of periph_clk_sel
#undef CCM_CIMR_MASK_AHB_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 20> CCM_CIMR_MASK_AHB_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of ahb_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of ahb_podf
#undef CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 19> CCM_CIMR_MASK_PERIPH2_CLK_SEL_LOADED;
    // 0b0..don't mask interrupt due to update of periph2_clk_sel - interrupt will be created
    // 0b1..mask interrupt due to update of periph2_clk_sel
#undef CCM_CIMR_MASK_SEMC_PODF_LOADED
constexpr CCM_Reg<&CCM_Layout::CIMR, 1, 17> CCM_CIMR_MASK_SEMC_PODF_LOADED;
    // 0b0..don't mask interrupt due to frequency change of semc_podf - interrupt will be created
    // 0b1..mask interrupt due to frequency change of semc_podf
#undef CCM_CIMR_MASK_COSC_READY
constexpr CCM_Reg<&CCM_Layout::CIMR, 1,  6> CCM_CIMR_MASK_COSC_READY;
    // 0b0..don't mask interrupt due to on board oscillator ready - interrupt will be created
    // 0b1..mask interrupt due to on board oscillator ready
#undef CCM_CIMR_MASK_LRF_PLL
constexpr CCM_Reg<&CCM_Layout::CIMR, 1,  0> CCM_CIMR_MASK_LRF_PLL;
    // 0b0..don't mask interrupt due to lrf of PLLs - interrupt will be created
    // 0b1..mask interrupt due to lrf of PLLs

// CCM Clock Output Source Register
#undef CCM_CCOSR_CLKO2_EN
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1, 24> CCM_CCOSR_CLKO2_EN;
    // 0b0..CCM_CLKO2 disabled.
    // 0b1..CCM_CLKO2 enabled.
#undef CCM_CCOSR_CLKO2_DIV
constexpr CCM_Reg<&CCM_Layout::CCOSR, 3, 21> CCM_CCOSR_CLKO2_DIV;
    // Divide by 'value' + 1
#undef CCM_CCOSR_CLKO2_SEL
constexpr CCM_Reg<&CCM_Layout::CCOSR, 5, 16> CCM_CCOSR_CLKO2_SEL;
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
#undef CCM_CCOSR_CLK_OUT_SEL
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1,  8> CCM_CCOSR_CLK_OUT_SEL;
    // 0b0..CCM_CLKO1 output drives CCM_CLKO1 clock
    // 0b1..CCM_CLKO1 output drives CCM_CLKO2 clock
#undef CCM_CCOSR_CLKO1_EN
constexpr CCM_Reg<&CCM_Layout::CCOSR, 1,  7> CCM_CCOSR_CLKO1_EN;
    // 0b0..CCM_CLKO1 disabled.
    // 0b1..CCM_CLKO1 enabled.
#undef CCM_CCOSR_CLKO1_DIV
constexpr CCM_Reg<&CCM_Layout::CCOSR, 3,  4> CCM_CCOSR_CLKO1_DIV;
    // Divide by 'value' + 1
#undef CCM_CCOSR_CLKO1_SEL
constexpr CCM_Reg<&CCM_Layout::CCOSR, 4,  0> CCM_CCOSR_CLKO1_SEL;
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

// CCM General Purpose Register
#undef CCM_CGPR_INT_MEM_CLK_LPM
constexpr CCM_Reg<&CCM_Layout::CGPR, 1, 17> CCM_CGPR_INT_MEM_CLK_LPM;
    // 0b0..Disable the clock to the Arm platform memories when entering Low Power Mode
    // 0b1..Keep the clocks to the Arm platform memories enabled only if an interrupt is pending when entering Low
    //      Power Modes (WAIT and STOP without power gating)
#undef CCM_CGPR_FPL
constexpr CCM_Reg<&CCM_Layout::CGPR, 1, 16> CCM_CGPR_FPL;  // Fast PLL enable.
    // 0b0..Engage PLL enable default way.
    // 0b1..Engage PLL enable 3 CKIL clocks earlier at exiting low power mode (STOP). Should be used only if 24MHz OSC was active in low power mode.
#undef CCM_CGPR_SYS_MEM_DS_CTRL
constexpr CCM_Reg<&CCM_Layout::CGPR, 2, 14> CCM_CGPR_SYS_MEM_DS_CTRL;
    // 0b00..Disable memory DS mode always
    // 0b01..Enable memory (outside Arm platform) DS mode when system STOP and PLL are disabled
    // 0b1x..enable memory (outside Arm platform) DS mode when system is in STOP mode
#undef CCM_CGPR_EFUSE_PROG_SUPPLY_GATE
constexpr CCM_Reg<&CCM_Layout::CGPR, 1,  4> CCM_CGPR_EFUSE_PROG_SUPPLY_GATE;
    // 0b0..fuse programing supply voltage is gated off to the efuse module
    // 0b1..allow fuse programing.
#undef CCM_CGPR_PMIC_DELAY_SCALER
constexpr CCM_Reg<&CCM_Layout::CGPR, 1,  0> CCM_CGPR_PMIC_DELAY_SCALER;
    // 0b0..clock is not divided
    // 0b1..clock is divided /8

// CCM Clock Gating Register 0
#undef CCM_CCGR0_GPIO2
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 30> CCM_CCGR0_GPIO2;        // CG15
#undef CCM_CCGR0_LPUART2
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 28> CCM_CCGR0_LPUART2;      // CG14
#undef CCM_CCGR0_GPT2_SERIAL
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 26> CCM_CCGR0_GPT2_SERIAL;  // CG13
#undef CCM_CCGR0_GPT2_BUS
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 24> CCM_CCGR0_GPT2_BUS;     // CG12
#undef CCM_CCGR0_TRACE
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 22> CCM_CCGR0_TRACE;        // CG11
#undef CCM_CCGR0_CAN2_SERIAL
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 20> CCM_CCGR0_CAN2_SERIAL;  // CG10
#undef CCM_CCGR0_CAN2_CLOCK
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 18> CCM_CCGR0_CAN2_CLOCK;   // CG9
#undef CCM_CCGR0_CAN1_SERIAL
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 16> CCM_CCGR0_CAN1_SERIAL;  // CG8
#undef CCM_CCGR0_CAN1_CLOCK
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 14> CCM_CCGR0_CAN1_CLOCK;   // CG7
#undef CCM_CCGR0_LPUART3
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 12> CCM_CCGR0_LPUART3;      // CG6
#undef CCM_CCGR0_DCP
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2, 10> CCM_CCGR0_DCP;          // CG5
#undef CCM_CCGR0_SIM_M
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  8> CCM_CCGR0_SIM_M;        // CG4
#undef CCM_CCGR0_CG3
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  6> CCM_CCGR0_CG3;          // CG3 (Reserved)
#undef CCM_CCGR0_MQS
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  4> CCM_CCGR0_MQS;          // CG2
#undef CCM_CCGR0_AIPS_TZ2
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  2> CCM_CCGR0_AIPS_TZ2;     // CG1
#undef CCM_CCGR0_AIPS_TZ1
constexpr CCM_Reg<&CCM_Layout::CCGR0, 2,  0> CCM_CCGR0_AIPS_TZ1;     // CG0

// CCM Clock Gating Register 1
#undef CCM_CCGR1_GPIO5
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 30> CCM_CCGR1_GPIO5;        // CG15
#undef CCM_CCGR1_CSU
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 28> CCM_CCGR1_CSU;          // CG14
#undef CCM_CCGR1_GPIO1
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 26> CCM_CCGR1_GPIO1;        // CG13
#undef CCM_CCGR1_LPUART4
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 24> CCM_CCGR1_LPUART4;      // CG12
#undef CCM_CCGR1_GPT1_SERIAL
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 22> CCM_CCGR1_GPT1_SERIAL;  // CG11
#undef CCM_CCGR1_GPT1_BUS
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 20> CCM_CCGR1_GPT1_BUS;     // CG10
#undef CCM_CCGR1_SEMC_EXSC
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 18> CCM_CCGR1_SEMC_EXSC;    // CG9
#undef CCM_CCGR1_ADC1
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 16> CCM_CCGR1_ADC1;         // CG8
#undef CCM_CCGR1_AOI2
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 14> CCM_CCGR1_AOI2;         // CG7
#undef CCM_CCGR1_PIT
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 12> CCM_CCGR1_PIT;          // CG6
#undef CCM_CCGR1_ENET
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2, 10> CCM_CCGR1_ENET;         // CG5
#undef CCM_CCGR1_ADC2
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  8> CCM_CCGR1_ADC2;         // CG4
#undef CCM_CCGR1_LPSPI4
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  6> CCM_CCGR1_LPSPI4;       // CG3
#undef CCM_CCGR1_LPSPI3
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  4> CCM_CCGR1_LPSPI3;       // CG2
#undef CCM_CCGR1_LPSPI2
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  2> CCM_CCGR1_LPSPI2;       // CG1
#undef CCM_CCGR1_LPSPI1
constexpr CCM_Reg<&CCM_Layout::CCGR1, 2,  0> CCM_CCGR1_LPSPI1;       // CG0

// CCM Clock Gating Register 2
#undef CCM_CCGR2_PXP
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 30> CCM_CCGR2_PXP;          // CG15
#undef CCM_CCGR2_LCD
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 28> CCM_CCGR2_LCD;          // CG14
#undef CCM_CCGR2_GPIO3
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 26> CCM_CCGR2_GPIO3;        // CG13
#undef CCM_CCGR2_XBAR2
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 24> CCM_CCGR2_XBAR2;        // CG12
#undef CCM_CCGR2_XBAR1
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 22> CCM_CCGR2_XBAR1;        // CG11
#undef CCM_CCGR2_IPMUX3
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 20> CCM_CCGR2_IPMUX3;       // CG10
#undef CCM_CCGR2_IPMUX2
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 18> CCM_CCGR2_IPMUX2;       // CG9
#undef CCM_CCGR2_IPMUX1
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 16> CCM_CCGR2_IPMUX1;       // CG8
#undef CCM_CCGR2_XBAR3
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 14> CCM_CCGR2_XBAR3;        // CG7
#undef CCM_CCGR2_OCOTP_CTRL
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 12> CCM_CCGR2_OCOTP_CTRL;   // CG6
#undef CCM_CCGR2_LPI2C3
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2, 10> CCM_CCGR2_LPI2C3;       // CG5
#undef CCM_CCGR2_LPI2C2
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  8> CCM_CCGR2_LPI2C2;       // CG4
#undef CCM_CCGR2_LPI2C1
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  6> CCM_CCGR2_LPI2C1;       // CG3
#undef CCM_CCGR2_IOMUXC_SNVS
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  4> CCM_CCGR2_IOMUXC_SNVS;  // CG2
#undef CCM_CCGR2_CSI
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  2> CCM_CCGR2_CSI;          // CG1
#undef CCM_CCGR2_OCRAM_EXSC
constexpr CCM_Reg<&CCM_Layout::CCGR2, 2,  0> CCM_CCGR2_OCRAM_EXSC;   // CG0

// CCM Clock Gating Register 3
#undef CCM_CCGR3_IOMUXC_SNVS_GPR
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 30> CCM_CCGR3_IOMUXC_SNVS_GPR;  // CG15
#undef CCM_CCGR3_OCRAM
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 28> CCM_CCGR3_OCRAM;            // CG14 - The OCRAM clock cannot be turned off when the CM cache is running on this device.
#undef CCM_CCGR3_ACMP4
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 26> CCM_CCGR3_ACMP4;            // CG13
#undef CCM_CCGR3_ACMP3
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 24> CCM_CCGR3_ACMP3;            // CG12
#undef CCM_CCGR3_ACMP2
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 22> CCM_CCGR3_ACMP2;            // CG11
#undef CCM_CCGR3_ACMP1
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 20> CCM_CCGR3_ACMP1;            // CG10
#undef CCM_CCGR3_FLEXRAM
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 18> CCM_CCGR3_FLEXRAM;          // CG9
#undef CCM_CCGR3_WDOG1
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 16> CCM_CCGR3_WDOG1;            // CG8
#undef CCM_CCGR3_EWM
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 14> CCM_CCGR3_EWM;              // CG7
#undef CCM_CCGR3_GPIO4
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 12> CCM_CCGR3_GPIO4;            // CG6
#undef CCM_CCGR3_LCDIF_PIX
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2, 10> CCM_CCGR3_LCDIF_PIX;        // CG5
#undef CCM_CCGR3_AOI1
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  8> CCM_CCGR3_AOI1;             // CG4
#undef CCM_CCGR3_LPUART6
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  6> CCM_CCGR3_LPUART6;          // CG3
#undef CCM_CCGR3_SEMC
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  4> CCM_CCGR3_SEMC;             // CG2
#undef CCM_CCGR3_LPUART5
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  2> CCM_CCGR3_LPUART5;          // CG1
#undef CCM_CCGR3_FLEXIO2
constexpr CCM_Reg<&CCM_Layout::CCGR3, 2,  0> CCM_CCGR3_FLEXIO2;          // CG0

// CCM Clock Gating Register 4
#undef CCM_CCGR4_QDC4
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 30> CCM_CCGR4_QDC4;        // CG15
#undef CCM_CCGR4_QDC3
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 28> CCM_CCGR4_QDC3;        // CG14
#undef CCM_CCGR4_QDC2
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 26> CCM_CCGR4_QDC2;        // CG13
#undef CCM_CCGR4_QDC1
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 24> CCM_CCGR4_QDC1;        // CG12
#undef CCM_CCGR4_PWM4
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 22> CCM_CCGR4_PWM4;        // CG11
#undef CCM_CCGR4_PWM3
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 20> CCM_CCGR4_PWM3;        // CG10
#undef CCM_CCGR4_PWM2
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 18> CCM_CCGR4_PWM2;        // CG9
#undef CCM_CCGR4_PWM1
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 16> CCM_CCGR4_PWM1;        // CG8
#undef CCM_CCGR4_SIM_EMS
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 14> CCM_CCGR4_SIM_EMS;     // CG7
#undef CCM_CCGR4_SIM_M
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 12> CCM_CCGR4_SIM_M;       // CG6
#undef CCM_CCGR4_TSC_DIG
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2, 10> CCM_CCGR4_TSC_DIG;     // CG5
#undef CCM_CCGR4_SIM_M7
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  8> CCM_CCGR4_SIM_M7;      // CG4
#undef CCM_CCGR4_BEE
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  6> CCM_CCGR4_BEE;         // CG3
#undef CCM_CCGR4_IOMUXC_GPR
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  4> CCM_CCGR4_IOMUXC_GPR;  // CG2
#undef CCM_CCGR4_IOMUXC
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  2> CCM_CCGR4_IOMUXC;      // CG1
#undef CCM_CCGR4_SIM_M7_REG
constexpr CCM_Reg<&CCM_Layout::CCGR4, 2,  0> CCM_CCGR4_SIM_M7_REG;  // CG0

// CCM Clock Gating Register 5
#undef CCM_CCGR5_SNVS_LP
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 30> CCM_CCGR5_SNVS_LP;   // CG15
#undef CCM_CCGR5_SNVS_HP
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 28> CCM_CCGR5_SNVS_HP;   // CG14
#undef CCM_CCGR5_LPUART7
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 26> CCM_CCGR5_LPUART7;   // CG13
#undef CCM_CCGR5_LPUART1
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 24> CCM_CCGR5_LPUART1;   // CG12
#undef CCM_CCGR5_SAI3
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 22> CCM_CCGR5_SAI3;      // CG11
#undef CCM_CCGR5_SAI2
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 20> CCM_CCGR5_SAI2;      // CG10
#undef CCM_CCGR5_SAI1
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 18> CCM_CCGR5_SAI1;      // CG9
#undef CCM_CCGR5_SIM_MAIN
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 16> CCM_CCGR5_SIM_MAIN;  // CG8
#undef CCM_CCGR5_SPDIF
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 14> CCM_CCGR5_SPDIF;     // CG7
#undef CCM_CCGR5_AIPSTZ4
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 12> CCM_CCGR5_AIPSTZ4;   // CG6
#undef CCM_CCGR5_WDOG2
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2, 10> CCM_CCGR5_WDOG2;     // CG5
#undef CCM_CCGR5_KPP
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  8> CCM_CCGR5_KPP;       // CG4
#undef CCM_CCGR5_DMA
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  6> CCM_CCGR5_DMA;       // CG3
#undef CCM_CCGR5_WDOG3
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  4> CCM_CCGR5_WDOG3;     // CG2
#undef CCM_CCGR5_FLEXIO1
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  2> CCM_CCGR5_FLEXIO1;   // CG1
#undef CCM_CCGR5_ROM
constexpr CCM_Reg<&CCM_Layout::CCGR5, 2,  0> CCM_CCGR5_ROM;       // CG0

// CCM Clock Gating Register 6
#undef CCM_CCGR6_TIMER3
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 30> CCM_CCGR6_TIMER3;    // CG15
#undef CCM_CCGR6_TIMER2
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 28> CCM_CCGR6_TIMER2;    // CG14
#undef CCM_CCGR6_TIMER1
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 26> CCM_CCGR6_TIMER1;    // CG13
#undef CCM_CCGR6_LPI2C4
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 24> CCM_CCGR6_LPI2C4;    // CG12
#undef CCM_CCGR6_ANADIG
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 22> CCM_CCGR6_ANADIG;    // CG11
#undef CCM_CCGR6_SIM_PER
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 20> CCM_CCGR6_SIM_PER;   // CG10
#undef CCM_CCGR6_AIPS_TZ3
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 18> CCM_CCGR6_AIPS_TZ3;  // CG9
#undef CCM_CCGR6_TIMER4
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 16> CCM_CCGR6_TIMER4;    // CG8
#undef CCM_CCGR6_LPUART8
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 14> CCM_CCGR6_LPUART8;   // CG7
#undef CCM_CCGR6_TRNG
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 12> CCM_CCGR6_TRNG;      // CG6
#undef CCM_CCGR6_FLEXSPI
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2, 10> CCM_CCGR6_FLEXSPI;   // CG5
#undef CCM_CCGR6_IPMUX4
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  8> CCM_CCGR6_IPMUX4;    // CG4
#undef CCM_CCGR6_DCDC
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  6> CCM_CCGR6_DCDC;      // CG3
#undef CCM_CCGR6_USDHC2
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  4> CCM_CCGR6_USDHC2;    // CG2
#undef CCM_CCGR6_USDHC1
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  2> CCM_CCGR6_USDHC1;    // CG1
#undef CCM_CCGR6_USBOH3
constexpr CCM_Reg<&CCM_Layout::CCGR6, 2,  0> CCM_CCGR6_USBOH3;    // CG0

// CCM Clock Gating Register 7
#undef CCM_CCGR7_FLEXIO3
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2, 12> CCM_CCGR7_FLEXIO3;      // CG6
#undef CCM_CCGR7_AIPS_LITE
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2, 10> CCM_CCGR7_AIPS_LITE;    // CG5
#undef CCM_CCGR7_CAN3_SERIAL
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  8> CCM_CCGR7_CAN3_SERIAL;  // CG4
#undef CCM_CCGR7_CAN3_CLK
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  6> CCM_CCGR7_CAN3_CLK;     // CG3
#undef CCM_CCGR7_AXBS_L
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  4> CCM_CCGR7_AXBS_L;       // CG2
#undef CCM_CCGR7_FLEXSPI2
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  2> CCM_CCGR7_FLEXSPI2;     // CG1
#undef CCM_CCGR7_ENET2
constexpr CCM_Reg<&CCM_Layout::CCGR7, 2,  0> CCM_CCGR7_ENET2;        // CG0

// CCM Module Enable Overide Register
#undef CCM_CMEOR_MOD_EN_OV_CAN1_CPI
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 30> CCM_CMEOR_MOD_EN_OV_CAN1_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_OV_CAN2_CPI
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 28> CCM_CMEOR_MOD_EN_OV_CAN2_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_OV_CANFD_CPI
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1, 10> CCM_CMEOR_MOD_EN_OV_CANFD_CPI;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_OV_TRNG
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  9> CCM_CMEOR_MOD_EN_OV_TRNG;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_USDHC
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  7> CCM_CMEOR_MOD_EN_USDHC;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_OV_PIT
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  6> CCM_CMEOR_MOD_EN_OV_PIT;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal
#undef CCM_CMEOR_MOD_EN_OV_GPT
constexpr CCM_Reg<&CCM_Layout::CMEOR, 1,  5> CCM_CMEOR_MOD_EN_OV_GPT;
    // 0b0..don't override module enable signal
    // 0b1..override module enable signal

// CCM Clock Switcher Register values
constexpr uint32_t kCCM_CCSR_PLL3_SW_CLK_SEL_MAIN   = 0;
constexpr uint32_t kCCM_CCSR_PLL3_SW_CLK_SEL_BYPASS = 1;

// CCM Bus Clock Divider Register values
constexpr uint32_t kCCM_CBCDR_SEMC_CLK_SEL_PERIPH                    = 0;
constexpr uint32_t kCCM_CBCDR_SEMC_CLK_SEL_ALT                       = 1;
constexpr uint32_t kCCM_CBCDR_SEMC_ALT_CLK_SEL_PLL2_PFD2             = 0;
constexpr uint32_t kCCM_CBCDR_SEMC_ALT_CLK_SEL_PLL3_PFD1             = 1;
constexpr uint32_t kCCM_CBCDR_PERIPH_CLK_SEL_PRE_PERIPH_CLK_SEL      = 0;
constexpr uint32_t kCCM_CBCDR_PERIPH_CLK_SEL_PRE_PERIPH_CLK2_CLK_DIV = 1;

constexpr uint32_t kCCM_CCGR_OFF      = 0x00;
constexpr uint32_t kCCM_CCGR_RUN_ONLY = 0x01;
constexpr uint32_t kCCM_CCGR_ON       = 0x03;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
