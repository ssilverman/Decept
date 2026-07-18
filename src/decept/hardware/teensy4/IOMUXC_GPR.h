// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// IOMUXC_GPR.h defines all the IOMUXC_GPR registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// IOMUXC_GPR layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_IOMUXC_GPR.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct IOMUXC_GPR_Layout {
           uint32_t GPR0;                              /**< GPR0 General Purpose Register, offset: 0x0 */
  volatile uint32_t GPR1;                              /**< GPR1 General Purpose Register, offset: 0x4 */
  volatile uint32_t GPR2;                              /**< GPR2 General Purpose Register, offset: 0x8 */
  volatile uint32_t GPR3;                              /**< GPR3 General Purpose Register, offset: 0xC */
  volatile uint32_t GPR4;                              /**< GPR4 General Purpose Register, offset: 0x10 */
  volatile uint32_t GPR5;                              /**< GPR5 General Purpose Register, offset: 0x14 */
  volatile uint32_t GPR6;                              /**< GPR6 General Purpose Register, offset: 0x18 */
  volatile uint32_t GPR7;                              /**< GPR7 General Purpose Register, offset: 0x1C */
  volatile uint32_t GPR8;                              /**< GPR8 General Purpose Register, offset: 0x20 */
           uint32_t GPR9;                              /**< GPR9 General Purpose Register, offset: 0x24 */
  volatile uint32_t GPR10;                             /**< GPR10 General Purpose Register, offset: 0x28 */
  volatile uint32_t GPR11;                             /**< GPR11 General Purpose Register, offset: 0x2C */
  volatile uint32_t GPR12;                             /**< GPR12 General Purpose Register, offset: 0x30 */
  volatile uint32_t GPR13;                             /**< GPR13 General Purpose Register, offset: 0x34 */
  volatile uint32_t GPR14;                             /**< GPR14 General Purpose Register, offset: 0x38 */
           uint32_t GPR15;                             /**< GPR15 General Purpose Register, offset: 0x3C */
  volatile uint32_t GPR16;                             /**< GPR16 General Purpose Register, offset: 0x40 */
  volatile uint32_t GPR17;                             /**< GPR17 General Purpose Register, offset: 0x44 */
  volatile uint32_t GPR18;                             /**< GPR18 General Purpose Register, offset: 0x48 */
  volatile uint32_t GPR19;                             /**< GPR19 General Purpose Register, offset: 0x4C */
  volatile uint32_t GPR20;                             /**< GPR20 General Purpose Register, offset: 0x50 */
  volatile uint32_t GPR21;                             /**< GPR21 General Purpose Register, offset: 0x54 */
  volatile uint32_t GPR22;                             /**< GPR22 General Purpose Register, offset: 0x58 */
  volatile uint32_t GPR23;                             /**< GPR23 General Purpose Register, offset: 0x5C */
  volatile uint32_t GPR24;                             /**< GPR24 General Purpose Register, offset: 0x60 */
  volatile uint32_t GPR25;                             /**< GPR25 General Purpose Register, offset: 0x64 */
  volatile uint32_t GPR26;                             /**< GPR26 General Purpose Register, offset: 0x68 */
  volatile uint32_t GPR27;                             /**< GPR27 General Purpose Register, offset: 0x6C */
  volatile uint32_t GPR28;                             /**< GPR28 General Purpose Register, offset: 0x70 */
  volatile uint32_t GPR29;                             /**< GPR29 General Purpose Register, offset: 0x74 */
  volatile uint32_t GPR30;                             /**< GPR30 General Purpose Register, offset: 0x78 */
  volatile uint32_t GPR31;                             /**< GPR31 General Purpose Register, offset: 0x7C */
  volatile uint32_t GPR32;                             /**< GPR32 General Purpose Register, offset: 0x80 */
  volatile uint32_t GPR33;                             /**< GPR33 General Purpose Register, offset: 0x84 */
  volatile uint32_t GPR34;                             /**< GPR34 General Purpose Register, offset: 0x88 */
};

constexpr size_t    kIOMUXC_GPR_size = 0x8C;
constexpr uintptr_t kIOMUXC_GPR_base = 0x400AC000;

constexpr regs::RegGroup<IOMUXC_GPR_Layout, kIOMUXC_GPR_size, kIOMUXC_GPR_base>
    IOMUXC_GPR;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using IOMUXC_GPR_Reg = regs::Reg32<kIOMUXC_GPR_base, IOMUXC_GPR_Layout, Member,
                                   0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// GPR1 General Purpose Register
#undef IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 31> IOMUXC_GPR_GPR1_CM7_FORCE_HCLK_EN;  // Arm CM7 platform AHB clock enable
    // 0b0..AHB clock is not running (gated) when CM7 is sleeping and TCM is not accessible.
    // 0b1..AHB clock is running (enabled) when CM7 is sleeping and TCM is accessible.
#undef IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 23> IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN;
    // 0b0..ipg_clk_s is gated when there is no IPS access
    // 0b1..ipg_clk_s is always on
#undef IOMUXC_GPR_GPR1_EXC_MON
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 22> IOMUXC_GPR_GPR1_EXC_MON;            // Exclusive monitor response select of illegal command
    // 0b0..OKAY response
    // 0b1..SLVError response (default)
#undef IOMUXC_GPR_GPR1_SAI3_MCLK_DIR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1,  1, 21> IOMUXC_GPR_GPR1_SAI3_MCLK_DIR;      // sai3.MCLK signal direction control
    // 0b0..sai3.MCLK is input signal
    // 0b1..sai3.MCLK is output signal
#undef IOMUXC_GPR_GPR1_SAI2_MCLK_DIR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 20> IOMUXC_GPR_GPR1_SAI2_MCLK_DIR;      // sai2.MCLK signal direction control
    // 0b0..sai2.MCLK is input signal
    // 0b1..sai2.MCLK is output signal
#undef IOMUXC_GPR_GPR1_SAI1_MCLK_DIR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 19> IOMUXC_GPR_GPR1_SAI1_MCLK_DIR;      // sai1.MCLK signal direction control
    // 0b0..sai1.MCLK is input signal
    // 0b1..sai1.MCLK is output signal
#undef IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 18> IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR;
    // 0b0..ENET2_TX_CLK output driver is disabled
    // 0b1..ENET2_TX_CLK output driver is enabled
#undef IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 17> IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR;
    // 0b0..ENET1_TX_CLK output driver is disabled
    // 0b1..ENET1_TX_CLK output driver is enabled
#undef IOMUXC_GPR_GPR1_ENET2_CLK_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 14> IOMUXC_GPR_GPR1_ENET2_CLK_SEL;
    // 0b0..ENET2 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET2_REF_CLK function.
    // 0b1..Gets ENET2 TX reference clock from the ENET2_TX_CLK pin. In this use case, an external OSC provides the
    //      clock for both the external PHY and the internal controller.
#undef IOMUXC_GPR_GPR1_ENET1_CLK_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 13> IOMUXC_GPR_GPR1_ENET1_CLK_SEL;
    // 0b0..ENET1 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET_REF_CLK1 function.
    // 0b1..Gets ENET1 TX reference clock from the ENET1_TX_CLK pin. In this use case, an external OSC provides the
    //      clock for both the external PHY and the internal controller.
#undef IOMUXC_GPR_GPR1_GINT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 12> IOMUXC_GPR_GPR1_GINT;               // Global Interrupt
    // 0b0..Global interrupt request is not asserted.
    // 0b1..Global interrupt request is asserted.
#undef IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2, 10> IOMUXC_GPR_GPR1_SAI3_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
#undef IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2,  8> IOMUXC_GPR_GPR1_SAI2_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
#undef IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2,  6> IOMUXC_GPR_GPR1_SAI1_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
#undef IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 3,  3> IOMUXC_GPR_GPR1_SAI1_MCLK2_SEL;
    // 0b000..ccm.ssi1_clk_root
    // 0b001..ccm.ssi2_clk_root
    // 0b010..ccm.ssi3_clk_root
    // 0b011..iomux.sai1_ipg_clk_sai_mclk
    // 0b100..iomux.sai2_ipg_clk_sai_mclk
    // 0b101..iomux.sai3_ipg_clk_sai_mclk
    // 0b110..Reserved
    // 0b111..Reserved
#undef IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 3,  0> IOMUXC_GPR_GPR1_SAI1_MCLK1_SEL;
    // 0b000..ccm.ssi1_clk_root
    // 0b001..ccm.ssi2_clk_root
    // 0b010..ccm.ssi3_clk_root
    // 0b011..iomux.sai1_ipg_clk_sai_mclk
    // 0b100..iomux.sai2_ipg_clk_sai_mclk
    // 0b101..iomux.sai3_ipg_clk_sai_mclk
    // 0b110..Reserved
    // 0b111..Reserved

// GPR2 General Purpose Register
#undef IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 31> IOMUXC_GPR_GPR2_QTIMER4_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
#undef IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 30> IOMUXC_GPR_GPR2_QTIMER3_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
#undef IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 29> IOMUXC_GPR_GPR2_QTIMER2_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
#undef IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 28> IOMUXC_GPR_GPR2_QTIMER1_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
#undef IOMUXC_GPR_GPR2_MQS_OVERSAMPLE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 26> IOMUXC_GPR_GPR2_MQS_OVERSAMPLE;
    // 0b0..32
    // 0b1..64
#undef IOMUXC_GPR_GPR2_MQS_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 25> IOMUXC_GPR_GPR2_MQS_EN;
    // 0b0..Disable MQS
    // 0b1..Enable MQS
#undef IOMUXC_GPR_GPR2_MQS_SW_RST
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 24> IOMUXC_GPR_GPR2_MQS_SW_RST;
    // 0b0..Exit software reset for MQS
    // 0b1..Enable software reset for MQS
#undef IOMUXC_GPR_GPR2_MQS_CLK_DIV
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 8, 16> IOMUXC_GPR_GPR2_MQS_CLK_DIV;  // Divider ratio control for mclk from hmclk. mclk frequency = 1/(n+1) * hmclk frequency.
    // mclk frequency = 1/('value' + 1) * hmclk frequency
#undef IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 14> IOMUXC_GPR_GPR2_L2_MEM_DEEPSLEEP;
    // 0b0..no force sleep control supported, memory deep sleep mode only entered when whole system in stop mode
    // 0b1..force memory into deep sleep mode
#undef IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 13> IOMUXC_GPR_GPR2_RAM_AUTO_CLK_GATING_EN;
    // 0b0..disable automatically gate off RAM clock
    // 0b1..enable automatically gate off RAM clock
#undef IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 12> IOMUXC_GPR_GPR2_L2_MEM_EN_POWERSAVING;
    // 0b0..none memory power saving features enabled, SHUTDOWN/DEEPSLEEP/LIGHTSLEEP will have no effect
    // 0b1..memory power saving features enabled, set SHUTDOWN/DEEPSLEEP/LIGHTSLEEP (priority high to low) to enable power saving levels
#undef IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  6> IOMUXC_GPR_GPR2_CANFD_FILTER_BYPASS;
    // 0b0..enable CANFD filter
    // 0b1..disable CANFD filter
#undef IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  5> IOMUXC_GPR_GPR2_AXBS_P_FORCE_ROUND_ROBIN;
    // 0b0..AXBS_P masters are not arbitored in round robin, depending on M0/M1 master priority settings.
    // 0b1..AXBS_P masters are arbitored in round robin
#undef IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  4> IOMUXC_GPR_GPR2_AXBS_P_M1_HIGH_PRIORITY;
    // 0b0..AXBS_P M1 master does not have high priority
    // 0b1..AXBS_P M1 master has high priority
#undef IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 3> IOMUXC_GPR_GPR2_AXBS_P_M0_HIGH_PRIORITY;
    // 0b0..AXBS_P M0 master doesn't have high priority
    // 0b1..AXBS_P M0 master has high priority
#undef IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  2> IOMUXC_GPR_GPR2_AXBS_L_FORCE_ROUND_ROBIN;
    // 0b0..AXBS_L masters are not arbitored in round robin, depending on DMA and AHBXL master priority settings.
    // 0b1..AXBS_L masters are arbitored in round robin
#undef IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  1> IOMUXC_GPR_GPR2_AXBS_L_DMA_HIGH_PRIORITY;
    // 0b0..AXBS_L DMA master does not have high priority
    // 0b1..AXBS_L DMA master has high priority
#undef IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  0> IOMUXC_GPR_GPR2_AXBS_L_AHBXL_HIGH_PRIORITY;
    // 0b0..AXBS_L AHBXL master does not have high priority
    // 0b1..AXBS_P AHBXL master has high priority

// GPR3 General Purpose Register
#undef IOMUXC_GPR_GPR3_AXBS_L_HALTED
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1, 31> IOMUXC_GPR_GPR3_AXBS_L_HALTED;
    // 0b0..axbs_l is not halted
    // 0b1..axbs_l is in halted status
#undef IOMUXC_GPR_GPR3_OCRAM2_STATUS
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4, 24> IOMUXC_GPR_GPR3_OCRAM2_STATUS;
#undef IOMUXC_GPR_GPR3_OCRAM_STATUS
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4, 16> IOMUXC_GPR_GPR3_OCRAM_STATUS;
#undef IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1, 15> IOMUXC_GPR_GPR3_AXBS_L_HALT_REQ;
    // 0b0..axbs_l normal run
    // 0b1..request to halt axbs_l
#undef IOMUXC_GPR_GPR3_OCRAM2_CTL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4,  8> IOMUXC_GPR_GPR3_OCRAM2_CTL;
#undef IOMUXC_GPR_GPR3_DCP_KEY_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1,  4> IOMUXC_GPR_GPR3_DCP_KEY_SEL;
    // 0b0..Select [127:0] from SNVS Master Key as dcp key
    // 0b1..Select [255:128] from SNVS Master Key as dcp key
#undef IOMUXC_GPR_GPR3_OCRAM_CTL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4,  0> IOMUXC_GPR_GPR3_OCRAM_CTL;

// GPR4 General Purpose Register
#undef IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 31> IOMUXC_GPR_GPR4_FLEXSPI2_STOP_ACK;
    // 0b0..FLEXSPI2 stop acknowledge is not asserted
    // 0b1..FLEXSPI2 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 30> IOMUXC_GPR_GPR4_FLEXIO3_STOP_ACK;
    // 0b0..FLEXIO3 stop acknowledge is not asserted
    // 0b1..FLEXIO3 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 29> IOMUXC_GPR_GPR4_FLEXIO2_STOP_ACK;
    // 0b0..FLEXIO2 stop acknowledge is not asserted
    // 0b1..FLEXIO2 stop acknowledge is asserted (FLEXIO2 is in STOP mode)
#undef IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 28> IOMUXC_GPR_GPR4_FLEXIO1_STOP_ACK;
    // 0b0..FLEXIO1 stop acknowledge is not asserted
    // 0b1..FLEXIO1 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 27> IOMUXC_GPR_GPR4_FLEXSPI_STOP_ACK;
    // 0b0..FLEXSPI stop acknowledge is not asserted
    // 0b1..FLEXSPI stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_PIT_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 26> IOMUXC_GPR_GPR4_PIT_STOP_ACK;
    // 0b0..PIT stop acknowledge is not asserted
    // 0b1..PIT stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_SEMC_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 25> IOMUXC_GPR_GPR4_SEMC_STOP_ACK;
    // 0b0..SEMC stop acknowledge is not asserted
    // 0b1..SEMC stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_ENET2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 24> IOMUXC_GPR_GPR4_ENET2_STOP_ACK;
    // 0b0..ENET2 stop acknowledge is not asserted
    // 0b1..ENET2 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_SAI3_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 23> IOMUXC_GPR_GPR4_SAI3_STOP_ACK;
    // 0b0..SAI3 stop acknowledge is not asserted
    // 0b1..SAI3 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_SAI2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 22> IOMUXC_GPR_GPR4_SAI2_STOP_ACK;
    // 0b0..SAI2 stop acknowledge is not asserted
    // 0b1..SAI2 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_SAI1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 21> IOMUXC_GPR_GPR4_SAI1_STOP_ACK;
    // 0b0..SAI1 stop acknowledge is not asserted
    // 0b1..SAI1 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_ENET_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 20> IOMUXC_GPR_GPR4_ENET_STOP_ACK;
    // 0b0..ENET1 stop acknowledge is not asserted
    // 0b1..ENET1 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_TRNG_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 19> IOMUXC_GPR_GPR4_TRNG_STOP_ACK;
    // 0b0..TRNG stop acknowledge is not asserted
    // 0b1..TRNG stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_CAN2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 18> IOMUXC_GPR_GPR4_CAN2_STOP_ACK;
    // 0b0..CAN2 stop acknowledge is not asserted
    // 0b1..CAN2 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_CAN1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 17> IOMUXC_GPR_GPR4_CAN1_STOP_ACK;
    // 0b0..CAN1 stop acknowledge is not asserted
    // 0b1..CAN1 stop acknowledge is asserted
#undef IOMUXC_GPR_GPR4_EDMA_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 16> IOMUXC_GPR_GPR4_EDMA_STOP_ACK;
    // 0b0..EDMA stop acknowledge is not asserted
    // 0b1..EDMA stop acknowledge is asserted (EDMA is in STOP mode).
#undef IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 15> IOMUXC_GPR_GPR4_FLEXSPI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 14> IOMUXC_GPR_GPR4_FLEXIO3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 13> IOMUXC_GPR_GPR4_FLEXIO2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 12> IOMUXC_GPR_GPR4_FLEXIO1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 11> IOMUXC_GPR_GPR4_FLEXSPI_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_PIT_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 10> IOMUXC_GPR_GPR4_PIT_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_SEMC_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  9> IOMUXC_GPR_GPR4_SEMC_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_ENET2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  8> IOMUXC_GPR_GPR4_ENET2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_SAI3_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  7> IOMUXC_GPR_GPR4_SAI3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_SAI2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  6> IOMUXC_GPR_GPR4_SAI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_SAI1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  5> IOMUXC_GPR_GPR4_SAI1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_ENET_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  4> IOMUXC_GPR_GPR4_ENET_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_TRNG_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  3> IOMUXC_GPR_GPR4_TRNG_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_CAN2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  2> IOMUXC_GPR_GPR4_CAN2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_CAN1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  1> IOMUXC_GPR_GPR4_CAN1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR4_EDMA_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  0> IOMUXC_GPR_GPR4_EDMA_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on

// GPR5 General Purpose Register
#undef IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 29> IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT2;
    // 0b0..GPT2 ipg_clk_highfreq driven by IPG_PERCLK
    // 0b1..GPT2 ipg_clk_highfreq driven by anatop 1 MHz clock
#undef IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 28> IOMUXC_GPR_GPR5_VREF_1M_CLK_GPT1;
    // 0b0..GPT1 ipg_clk_highfreq driven by IPG_PERCLK
    // 0b1..GPT1 ipg_clk_highfreq driven by anatop 1 MHz clock
#undef IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 26> IOMUXC_GPR_GPR5_ENET2_EVENT3IN_SEL;
    // 0b0..event3 source input from ENET2_1588_EVENT3_IN
    // 0b1..event3 source input from GPT2.GPT_COMPARE2
#undef IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 25> IOMUXC_GPR_GPR5_ENET_EVENT3IN_SEL;
    // 0b0..event3 source input from ENET_1588_EVENT3_IN
    // 0b1..event3 source input from GPT2.GPT_COMPARE1
#undef IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 24> IOMUXC_GPR_GPR5_GPT2_CAPIN2_SEL;
    // 0b0..source from GPT2_CAPTURE2
    // 0b1..source from ENET2_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
#undef IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 23> IOMUXC_GPR_GPR5_GPT2_CAPIN1_SEL;
    // 0b0..source from GPT2_CAPTURE1
    // 0b1..source from ENET_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
#undef IOMUXC_GPR_GPR5_WDOG2_MASK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1,  7> IOMUXC_GPR_GPR5_WDOG2_MASK;
    // 0b0..WDOG2 Timeout behaves normally
    // 0b1..WDOG2 Timeout is masked
#undef IOMUXC_GPR_GPR5_WDOG1_MASK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1,  6> IOMUXC_GPR_GPR5_WDOG1_MASK;
    // 0b0..WDOG1 Timeout behaves normally
    // 0b1..WDOG1 Timeout is masked

// GPR6 General Purpose Register
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 31> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_19;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 30> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_18;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 29> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_17;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 28> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_16;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 27> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_15;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 26> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_14;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 25> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_13;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 24> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_12;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 23> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_11;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 22> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_10;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 21> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_9;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 20> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_8;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 19> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_7;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 18> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_6;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 17> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_5;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 16> IOMUXC_GPR_GPR6_IOMUXC_XBAR_DIR_SEL_4;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
#undef IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 15> IOMUXC_GPR_GPR6_QTIMER4_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 14> IOMUXC_GPR_GPR6_QTIMER4_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 13> IOMUXC_GPR_GPR6_QTIMER4_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 12> IOMUXC_GPR_GPR6_QTIMER4_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 11> IOMUXC_GPR_GPR6_QTIMER3_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 10> IOMUXC_GPR_GPR6_QTIMER3_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  9> IOMUXC_GPR_GPR6_QTIMER3_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  8> IOMUXC_GPR_GPR6_QTIMER3_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  7> IOMUXC_GPR_GPR6_QTIMER2_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  6> IOMUXC_GPR_GPR6_QTIMER2_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  5> IOMUXC_GPR_GPR6_QTIMER2_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  4> IOMUXC_GPR_GPR6_QTIMER2_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  3> IOMUXC_GPR_GPR6_QTIMER1_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  2> IOMUXC_GPR_GPR6_QTIMER1_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  1> IOMUXC_GPR_GPR6_QTIMER1_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
#undef IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  0> IOMUXC_GPR_GPR6_QTIMER1_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR

// GPR7 General Purpose Register
#undef IOMUXC_GPR_GPR7_LPUART8_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 31> IOMUXC_GPR_GPR7_LPUART8_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted (the module is in Stop mode)
#undef IOMUXC_GPR_GPR7_LPUART7_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 30> IOMUXC_GPR_GPR7_LPUART7_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART6_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 29> IOMUXC_GPR_GPR7_LPUART6_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART5_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 28> IOMUXC_GPR_GPR7_LPUART5_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART4_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 27> IOMUXC_GPR_GPR7_LPUART4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART3_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 26> IOMUXC_GPR_GPR7_LPUART3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 25> IOMUXC_GPR_GPR7_LPUART2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPUART1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 24> IOMUXC_GPR_GPR7_LPUART1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 23> IOMUXC_GPR_GPR7_LPSPI4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 22> IOMUXC_GPR_GPR7_LPSPI3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 21> IOMUXC_GPR_GPR7_LPSPI2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 20> IOMUXC_GPR_GPR7_LPSPI1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 19> IOMUXC_GPR_GPR7_LPI2C4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 18> IOMUXC_GPR_GPR7_LPI2C3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 17> IOMUXC_GPR_GPR7_LPI2C2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
#undef IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 16> IOMUXC_GPR_GPR7_LPI2C1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted (the module is in Stop mode)
#undef IOMUXC_GPR_GPR7_LPUART8_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 15> IOMUXC_GPR_GPR7_LPUART8_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART7_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 14> IOMUXC_GPR_GPR7_LPUART7_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART6_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 13> IOMUXC_GPR_GPR7_LPUART6_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART5_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 12> IOMUXC_GPR_GPR7_LPUART5_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART4_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 11> IOMUXC_GPR_GPR7_LPUART4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART3_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1, 10> IOMUXC_GPR_GPR7_LPUART3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  9> IOMUXC_GPR_GPR7_LPUART2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPUART1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  8> IOMUXC_GPR_GPR7_LPUART1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  7> IOMUXC_GPR_GPR7_LPSPI4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  6> IOMUXC_GPR_GPR7_LPSPI3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  5> IOMUXC_GPR_GPR7_LPSPI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  4> IOMUXC_GPR_GPR7_LPSPI1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  3> IOMUXC_GPR_GPR7_LPI2C4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  2> IOMUXC_GPR_GPR7_LPI2C3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  1> IOMUXC_GPR_GPR7_LPI2C2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7,  1,  0> IOMUXC_GPR_GPR7_LPI2C1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on

// GPR8 General Purpose Register
#undef IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 31> IOMUXC_GPR_GPR8_LPUART8_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 30> IOMUXC_GPR_GPR8_LPUART8_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 29> IOMUXC_GPR_GPR8_LPUART7_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 28> IOMUXC_GPR_GPR8_LPUART7_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 27> IOMUXC_GPR_GPR8_LPUART6_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 26> IOMUXC_GPR_GPR8_LPUART6_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 25> IOMUXC_GPR_GPR8_LPUART5_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 24> IOMUXC_GPR_GPR8_LPUART5_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 23> IOMUXC_GPR_GPR8_LPUART4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 22> IOMUXC_GPR_GPR8_LPUART4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 21> IOMUXC_GPR_GPR8_LPUART3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 20> IOMUXC_GPR_GPR8_LPUART3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 19> IOMUXC_GPR_GPR8_LPUART2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 18> IOMUXC_GPR_GPR8_LPUART2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 17> IOMUXC_GPR_GPR8_LPUART1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 16> IOMUXC_GPR_GPR8_LPUART1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 15> IOMUXC_GPR_GPR8_LPSPI4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 14> IOMUXC_GPR_GPR8_LPSPI4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 13> IOMUXC_GPR_GPR8_LPSPI3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 12> IOMUXC_GPR_GPR8_LPSPI3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 11> IOMUXC_GPR_GPR8_LPSPI2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1, 10> IOMUXC_GPR_GPR8_LPSPI2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  9> IOMUXC_GPR_GPR8_LPSPI1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  8> IOMUXC_GPR_GPR8_LPSPI1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  7> IOMUXC_GPR_GPR8_LPI2C4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  6> IOMUXC_GPR_GPR8_LPI2C4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  5> IOMUXC_GPR_GPR8_LPI2C3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  4> IOMUXC_GPR_GPR8_LPI2C3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  3> IOMUXC_GPR_GPR8_LPI2C2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  2> IOMUXC_GPR_GPR8_LPI2C2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
#undef IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  1> IOMUXC_GPR_GPR8_LPI2C1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
#undef IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8,  1,  0> IOMUXC_GPR_GPR8_LPI2C1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted

// GPR10 General Purpose Register
#undef IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  7, 25> IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_ADDR;
    // 0b0000000..Field is not locked
    // 0b0000001..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1, 24> IOMUXC_GPR_GPR10_LOCK_OCRAM_TZ_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1, 20> IOMUXC_GPR_GPR10_LOCK_DCPKEY_OCOTP_OR_KEYMUX;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1, 18> IOMUXC_GPR_GPR10_LOCK_SEC_ERR_RESP;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_LOCK_DBG_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1, 17> IOMUXC_GPR_GPR10_LOCK_DBG_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_LOCK_NIDEN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1, 16> IOMUXC_GPR_GPR10_LOCK_NIDEN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  7,  9> IOMUXC_GPR_GPR10_OCRAM_TZ_ADDR;
#undef IOMUXC_GPR_GPR10_OCRAM_TZ_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1,  8> IOMUXC_GPR_GPR10_OCRAM_TZ_EN;
    // 0b0..The TrustZone feature is disabled. Entire OCRAM space is available for all access types (secure/non-secure/user/supervisor).
    // 0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
    //      the execution mode access policy described in CSU chapter.
#undef IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1,  4> IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX;
    // 0b0..Select key from SNVS Master Key.
    // 0b1..Select key from OCOTP (SW_GP2).
#undef IOMUXC_GPR_GPR10_SEC_ERR_RESP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1,  2> IOMUXC_GPR_GPR10_SEC_ERR_RESP;
    // 0b0..OKEY response
    // 0b1..SLVError (default)
#undef IOMUXC_GPR_GPR10_DBG_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1,  1> IOMUXC_GPR_GPR10_DBG_EN;
    // 0b0..Debug turned off.
    // 0b1..Debug enabled (default).
#undef IOMUXC_GPR_GPR10_NIDEN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10,  1,  0> IOMUXC_GPR_GPR10_NIDEN;
    // 0b0..Debug turned off.
    // 0b1..Debug enabled (default).

// GPR11 General Purpose Register
#undef IOMUXC_GPR_GPR11_BEE_DE_RX_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11,  4,  8> IOMUXC_GPR_GPR11_BEE_DE_RX_EN;
#undef IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11,  2,  6> IOMUXC_GPR_GPR11_M7_APC_AC_R3_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
#undef IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11,  2,  4> IOMUXC_GPR_GPR11_M7_APC_AC_R2_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
#undef IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11,  2,  2> IOMUXC_GPR_GPR11_M7_APC_AC_R1_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
#undef IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11,  2,  0> IOMUXC_GPR_GPR11_M7_APC_AC_R0_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved

// GPR12 General Purpose Register
#undef IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  6> IOMUXC_GPR_GPR12_FLEXIO3_IPG_DOZE;
    // 0b0..FLEXIO3 is not in doze mode
    // 0b1..FLEXIO3 is in doze mode
#undef IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  5> IOMUXC_GPR_GPR12_FLEXIO3_IPG_STOP_MODE;
    // 0b0..FlexIO3 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO3 is not functional in Stop mode.
#undef IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  4> IOMUXC_GPR_GPR12_ACMP_IPG_STOP_MODE;
    // 0b0..ACMP is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, ACMP is not functional in Stop mode.
#undef IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  3> IOMUXC_GPR_GPR12_FLEXIO2_IPG_DOZE;
    // 0b0..FLEXIO2 is not in doze mode
    // 0b1..FLEXIO2 is in doze mode
#undef IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  2> IOMUXC_GPR_GPR12_FLEXIO2_IPG_STOP_MODE;
    // 0b0..FlexIO2 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO2 is not functional in Stop mode.
#undef IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  1> IOMUXC_GPR_GPR12_FLEXIO1_IPG_DOZE;
    // 0b0..FLEXIO1 is not in doze mode
    // 0b1..FLEXIO1 is in doze mode
#undef IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12,  1,  0> IOMUXC_GPR_GPR12_FLEXIO1_IPG_STOP_MODE;
    // 0b0..FlexIO1 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO1 is not functional in Stop mode.

// GPR13 General Purpose Register
#undef IOMUXC_GPR_GPR13_CANFD_STOP_ACK
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1, 20> IOMUXC_GPR_GPR13_CANFD_STOP_ACK;
    // 0b0..CANFD stop acknowledge is not asserted
    // 0b1..CANFD stop acknowledge is asserted
#undef IOMUXC_GPR_GPR13_CACHE_USB
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1, 13> IOMUXC_GPR_GPR13_CACHE_USB;
    // 0b0..Cacheable attribute is off for read/write transactions.
    // 0b1..Cacheable attribute is on for read/write transactions.
#undef IOMUXC_GPR_GPR13_CACHE_ENET
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1,  7> IOMUXC_GPR_GPR13_CACHE_ENET;
    // 0b0..Cacheable attribute is off for read/write transactions.
    // 0b1..Cacheable attribute is on for read/write transactions.
#undef IOMUXC_GPR_GPR13_CANFD_STOP_REQ
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1,  4> IOMUXC_GPR_GPR13_CANFD_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
#undef IOMUXC_GPR_GPR13_AWCACHE_USDHC
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1,  1> IOMUXC_GPR_GPR13_AWCACHE_USDHC;
    // 0b0..Cacheable attribute is off for write transactions.
    // 0b1..Cacheable attribute is on for write transactions.
#undef IOMUXC_GPR_GPR13_ARCACHE_USDHC
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13,  1,  0> IOMUXC_GPR_GPR13_ARCACHE_USDHC;
    // 0b0..Cacheable attribute is off for read transactions.
    // 0b1..Cacheable attribute is on for read transactions.

// GPR14 General Purpose Register
#undef IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1, 11> IOMUXC_GPR_GPR14_ACMP4_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
#undef IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1, 10> IOMUXC_GPR_GPR14_ACMP3_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
#undef IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  9> IOMUXC_GPR_GPR14_ACMP2_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
#undef IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  8> IOMUXC_GPR_GPR14_ACMP1_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
#undef IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  7> IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
#undef IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  6> IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
#undef IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  5> IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
#undef IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  4> IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
#undef IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  3> IOMUXC_GPR_GPR14_ACMP4_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
#undef IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  2> IOMUXC_GPR_GPR14_ACMP3_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
#undef IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  1> IOMUXC_GPR_GPR14_ACMP2_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
#undef IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14,  1,  0> IOMUXC_GPR_GPR14_ACMP1_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces

// GPR16 General Purpose Register
#undef IOMUXC_GPR_GPR16_CM7_INIT_VTOR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR16, 25,  7> IOMUXC_GPR_GPR16_CM7_INIT_VTOR;
#undef IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR16,  1,  2> IOMUXC_GPR_GPR16_FLEXRAM_BANK_CFG_SEL;
    // 0b0..use fuse value to config
    // 0b1..use FLEXRAM_BANK_CFG to config

// GPR17 General Purpose Register
#undef IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR17, 32,  0> IOMUXC_GPR_GPR17_FLEXRAM_BANK_CFG;  // FlexRAM bank config value

// GPR18 General Purpose Register
#undef IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR18, 29,  3> IOMUXC_GPR_GPR18_M7_APC_AC_R0_BOT;
#undef IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR18,  1,  0> IOMUXC_GPR_GPR18_LOCK_M7_APC_AC_R0_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR19 General Purpose Register
#undef IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR19, 29,  3> IOMUXC_GPR_GPR19_M7_APC_AC_R0_TOP;
#undef IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR19,  1,  0> IOMUXC_GPR_GPR19_LOCK_M7_APC_AC_R0_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR20 General Purpose Register
#undef IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR20, 29,  3> IOMUXC_GPR_GPR20_M7_APC_AC_R1_BOT;
#undef IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR20,  1,  0> IOMUXC_GPR_GPR20_LOCK_M7_APC_AC_R1_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR21 General Purpose Register
#undef IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR21, 29,  3> IOMUXC_GPR_GPR21_M7_APC_AC_R1_TOP;
#undef IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR21,  1,  0> IOMUXC_GPR_GPR21_LOCK_M7_APC_AC_R1_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR22 General Purpose Register
#undef IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR22, 29,  3> IOMUXC_GPR_GPR22_M7_APC_AC_R2_BOT;
#undef IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR22,  1,  0> IOMUXC_GPR_GPR22_LOCK_M7_APC_AC_R2_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR23 General Purpose Register
#undef IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR23, 29,  3> IOMUXC_GPR_GPR23_M7_APC_AC_R2_TOP;
#undef IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR23,  1,  0> IOMUXC_GPR_GPR23_LOCK_M7_APC_AC_R2_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR24 General Purpose Register
#undef IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR24, 29,  3> IOMUXC_GPR_GPR24_M7_APC_AC_R3_BOT;
#undef IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR24,  1,  0> IOMUXC_GPR_GPR24_LOCK_M7_APC_AC_R3_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)

// GPR25 General Purpose Register
#undef IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR25, 29,  3> IOMUXC_GPR_GPR25_M7_APC_AC_R3_TOP;
#undef IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR25,  1,  0> IOMUXC_GPR_GPR25_LOCK_M7_APC_AC_R3_TOP;
// 0b0..Register field [31:1] is not locked
// 0b1..Register field [31:1] is locked (read access only)

// GPR26 General Purpose Register
#undef IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR26, 32,  0> IOMUXC_GPR_GPR26_GPIO_MUX1_GPIO_SEL;  // GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function.

// GPR27 General Purpose Register
#undef IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR27, 32,  0> IOMUXC_GPR_GPR27_GPIO_MUX2_GPIO_SEL;  //  GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function.

// GPR28 General Purpose Register
#undef IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR28, 32,  0> IOMUXC_GPR_GPR28_GPIO_MUX3_GPIO_SEL;  // GPIO3 and GPIO8 share same IO MUX function, GPIO_MUX3 selects one GPIO function.

// GPR29 General Purpose Register
#undef IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR29, 32,  0> IOMUXC_GPR_GPR29_GPIO_MUX4_GPIO_SEL;  // GPIO4 and GPIO9 share same IO MUX function, GPIO_MUX4 selects one GPIO function.

// GPR30 General Purpose Register
#undef IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR30, 20, 12> IOMUXC_GPR_GPR30_FLEXSPI_REMAP_ADDR_START;

// GPR31 General Purpose Register
#undef IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR31, 20, 12> IOMUXC_GPR_GPR31_FLEXSPI_REMAP_ADDR_END;

// GPR32 General Purpose Register
#undef IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR32, 20, 12> IOMUXC_GPR_GPR32_FLEXSPI_REMAP_ADDR_OFFSET;

// GPR33 General Purpose Register
#undef IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33,  7, 17> IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_ADDR;
    // 0b0000000..Field is not locked
    // 0b0000001..Field is locked (read access only)
#undef IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33,  1, 16> IOMUXC_GPR_GPR33_LOCK_OCRAM2_TZ_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
#undef IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33,  7,  1> IOMUXC_GPR_GPR33_OCRAM2_TZ_ADDR;
#undef IOMUXC_GPR_GPR33_OCRAM2_TZ_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33,  1,  0> IOMUXC_GPR_GPR33_OCRAM2_TZ_EN;
    // 0b0..The TrustZone feature is disabled. Entire OCRAM2 space is available for all access types (secure/non-secure/user/supervisor).
    // 0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
    //      the execution mode access policy described in CSU chapter.

// GPR34 General Purpose Register
#undef IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR34,  1,  8> IOMUXC_GPR_GPR34_SIP_TEST_MUX_QSPI_SIP_EN;
    // 0b0..SIP_TEST_MUX is disabled
    // 0b1..SIP_TEST_MUX is enabled
#undef IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR34,  8,  0> IOMUXC_GPR_GPR34_SIP_TEST_MUX_BOOT_PIN_SEL;  // Boot Pin select in SIP_TEST_MUX

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
