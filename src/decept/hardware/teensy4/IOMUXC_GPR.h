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

namespace IOMUXC_GPR {
constexpr regs::RegGroup<IOMUXC_GPR_Layout, kIOMUXC_GPR_size, kIOMUXC_GPR_base>
    group;
}  // namespace IOMUXC_GPR

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using IOMUXC_GPR_Reg = regs::Reg32<kIOMUXC_GPR_base, IOMUXC_GPR_Layout, Member,
                                   0, Bits, Shift, DirectAssign>;

namespace IOMUXC_GPR {

// GPR1 General Purpose Register
namespace GPR1 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 31> CM7_FORCE_HCLK_EN;  // Arm CM7 platform AHB clock enable
    // 0b0..AHB clock is not running (gated) when CM7 is sleeping and TCM is not accessible.
    // 0b1..AHB clock is running (enabled) when CM7 is sleeping and TCM is accessible.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 23> ENET_IPG_CLK_S_EN;
    // 0b0..ipg_clk_s is gated when there is no IPS access
    // 0b1..ipg_clk_s is always on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 22> EXC_MON;            // Exclusive monitor response select of illegal command
    // 0b0..OKAY response
    // 0b1..SLVError response (default)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 21> SAI3_MCLK_DIR;      // sai3.MCLK signal direction control
    // 0b0..sai3.MCLK is input signal
    // 0b1..sai3.MCLK is output signal
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 20> SAI2_MCLK_DIR;      // sai2.MCLK signal direction control
    // 0b0..sai2.MCLK is input signal
    // 0b1..sai2.MCLK is output signal
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 19> SAI1_MCLK_DIR;      // sai1.MCLK signal direction control
    // 0b0..sai1.MCLK is input signal
    // 0b1..sai1.MCLK is output signal
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 18> ENET2_TX_CLK_DIR;
    // 0b0..ENET2_TX_CLK output driver is disabled
    // 0b1..ENET2_TX_CLK output driver is enabled
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 17> ENET1_TX_CLK_DIR;
    // 0b0..ENET1_TX_CLK output driver is disabled
    // 0b1..ENET1_TX_CLK output driver is enabled
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 14> ENET2_CLK_SEL;
    // 0b0..ENET2 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET2_REF_CLK function.
    // 0b1..Gets ENET2 TX reference clock from the ENET2_TX_CLK pin. In this use case, an external OSC provides the
    //      clock for both the external PHY and the internal controller.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 13> ENET1_CLK_SEL;
    // 0b0..ENET1 TX reference clock driven by ref_enetpll. This clock is also output to pins via the IOMUX. ENET_REF_CLK1 function.
    // 0b1..Gets ENET1 TX reference clock from the ENET1_TX_CLK pin. In this use case, an external OSC provides the
    //      clock for both the external PHY and the internal controller.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 1, 12> GINT;               // Global Interrupt
    // 0b0..Global interrupt request is not asserted.
    // 0b1..Global interrupt request is asserted.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2, 10> SAI3_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2,  8> SAI2_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 2,  6> SAI1_MCLK3_SEL;
    // 0b00..ccm.spdif0_clk_root
    // 0b01..iomux.spdif_tx_clk2
    // 0b10..spdif.spdif_srclk
    // 0b11..spdif.spdif_outclock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 3,  3> SAI1_MCLK2_SEL;
    // 0b000..ccm.ssi1_clk_root
    // 0b001..ccm.ssi2_clk_root
    // 0b010..ccm.ssi3_clk_root
    // 0b011..iomux.sai1_ipg_clk_sai_mclk
    // 0b100..iomux.sai2_ipg_clk_sai_mclk
    // 0b101..iomux.sai3_ipg_clk_sai_mclk
    // 0b110..Reserved
    // 0b111..Reserved
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR1, 3,  0> SAI1_MCLK1_SEL;
    // 0b000..ccm.ssi1_clk_root
    // 0b001..ccm.ssi2_clk_root
    // 0b010..ccm.ssi3_clk_root
    // 0b011..iomux.sai1_ipg_clk_sai_mclk
    // 0b100..iomux.sai2_ipg_clk_sai_mclk
    // 0b101..iomux.sai3_ipg_clk_sai_mclk
    // 0b110..Reserved
    // 0b111..Reserved
}  // namespace GPR1

// GPR2 General Purpose Register
namespace GPR2 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 31> QTIMER4_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 30> QTIMER3_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 29> QTIMER2_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 28> QTIMER1_TMR_CNTS_FREEZE;
    // 0b0..timer counter work normally
    // 0b1..reset counter and ouput flags
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 26> MQS_OVERSAMPLE;
    // 0b0..32
    // 0b1..64
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 25> MQS_EN;
    // 0b0..Disable MQS
    // 0b1..Enable MQS
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 24> MQS_SW_RST;
    // 0b0..Exit software reset for MQS
    // 0b1..Enable software reset for MQS
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 8, 16> MQS_CLK_DIV;  // Divider ratio control for mclk from hmclk. mclk frequency = 1/(n+1) * hmclk frequency.
    // mclk frequency = 1/('value' + 1) * hmclk frequency
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 14> L2_MEM_DEEPSLEEP;
    // 0b0..no force sleep control supported, memory deep sleep mode only entered when whole system in stop mode
    // 0b1..force memory into deep sleep mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 13> RAM_AUTO_CLK_GATING_EN;
    // 0b0..disable automatically gate off RAM clock
    // 0b1..enable automatically gate off RAM clock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1, 12> L2_MEM_EN_POWERSAVING;
    // 0b0..none memory power saving features enabled, SHUTDOWN/DEEPSLEEP/LIGHTSLEEP will have no effect
    // 0b1..memory power saving features enabled, set SHUTDOWN/DEEPSLEEP/LIGHTSLEEP (priority high to low) to enable power saving levels
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  6> CANFD_FILTER_BYPASS;
    // 0b0..enable CANFD filter
    // 0b1..disable CANFD filter
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  5> AXBS_P_FORCE_ROUND_ROBIN;
    // 0b0..AXBS_P masters are not arbitored in round robin, depending on M0/M1 master priority settings.
    // 0b1..AXBS_P masters are arbitored in round robin
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  4> AXBS_P_M1_HIGH_PRIORITY;
    // 0b0..AXBS_P M1 master does not have high priority
    // 0b1..AXBS_P M1 master has high priority
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  3> AXBS_P_M0_HIGH_PRIORITY;
    // 0b0..AXBS_P M0 master doesn't have high priority
    // 0b1..AXBS_P M0 master has high priority
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  2> AXBS_L_FORCE_ROUND_ROBIN;
    // 0b0..AXBS_L masters are not arbitored in round robin, depending on DMA and AHBXL master priority settings.
    // 0b1..AXBS_L masters are arbitored in round robin
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  1> AXBS_L_DMA_HIGH_PRIORITY;
    // 0b0..AXBS_L DMA master does not have high priority
    // 0b1..AXBS_L DMA master has high priority
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR2, 1,  0> AXBS_L_AHBXL_HIGH_PRIORITY;
    // 0b0..AXBS_L AHBXL master does not have high priority
    // 0b1..AXBS_P AHBXL master has high priority
}  // namespace GPR2

// GPR3 General Purpose Register
namespace GPR3 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1, 31> AXBS_L_HALTED;
    // 0b0..axbs_l is not halted
    // 0b1..axbs_l is in halted status
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4, 24> OCRAM2_STATUS;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4, 16> OCRAM_STATUS;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1, 15> AXBS_L_HALT_REQ;
    // 0b0..axbs_l normal run
    // 0b1..request to halt axbs_l
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4,  8> OCRAM2_CTL;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 1,  4> DCP_KEY_SEL;
    // 0b0..Select [127:0] from SNVS Master Key as dcp key
    // 0b1..Select [255:128] from SNVS Master Key as dcp key
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR3, 4,  0> OCRAM_CTL;
}  // namespace GPR3

// GPR4 General Purpose Register
namespace GPR4 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 31> FLEXSPI2_STOP_ACK;
    // 0b0..FLEXSPI2 stop acknowledge is not asserted
    // 0b1..FLEXSPI2 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 30> FLEXIO3_STOP_ACK;
    // 0b0..FLEXIO3 stop acknowledge is not asserted
    // 0b1..FLEXIO3 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 29> FLEXIO2_STOP_ACK;
    // 0b0..FLEXIO2 stop acknowledge is not asserted
    // 0b1..FLEXIO2 stop acknowledge is asserted (FLEXIO2 is in STOP mode)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 28> FLEXIO1_STOP_ACK;
    // 0b0..FLEXIO1 stop acknowledge is not asserted
    // 0b1..FLEXIO1 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 27> FLEXSPI_STOP_ACK;
    // 0b0..FLEXSPI stop acknowledge is not asserted
    // 0b1..FLEXSPI stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 26> PIT_STOP_ACK;
    // 0b0..PIT stop acknowledge is not asserted
    // 0b1..PIT stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 25> SEMC_STOP_ACK;
    // 0b0..SEMC stop acknowledge is not asserted
    // 0b1..SEMC stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 24> ENET2_STOP_ACK;
    // 0b0..ENET2 stop acknowledge is not asserted
    // 0b1..ENET2 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 23> SAI3_STOP_ACK;
    // 0b0..SAI3 stop acknowledge is not asserted
    // 0b1..SAI3 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 22> SAI2_STOP_ACK;
    // 0b0..SAI2 stop acknowledge is not asserted
    // 0b1..SAI2 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 21> SAI1_STOP_ACK;
    // 0b0..SAI1 stop acknowledge is not asserted
    // 0b1..SAI1 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 20> ENET_STOP_ACK;
    // 0b0..ENET1 stop acknowledge is not asserted
    // 0b1..ENET1 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 19> TRNG_STOP_ACK;
    // 0b0..TRNG stop acknowledge is not asserted
    // 0b1..TRNG stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 18> CAN2_STOP_ACK;
    // 0b0..CAN2 stop acknowledge is not asserted
    // 0b1..CAN2 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 17> CAN1_STOP_ACK;
    // 0b0..CAN1 stop acknowledge is not asserted
    // 0b1..CAN1 stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 16> EDMA_STOP_ACK;
    // 0b0..EDMA stop acknowledge is not asserted
    // 0b1..EDMA stop acknowledge is asserted (EDMA is in STOP mode).
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 15> FLEXSPI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 14> FLEXIO3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 13> FLEXIO2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 12> FLEXIO1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 11> FLEXSPI_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1, 10> PIT_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  9> SEMC_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  8> ENET2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  7> SAI3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  6> SAI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  5> SAI1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  4> ENET_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  3> TRNG_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  2> CAN2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  1> CAN1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR4, 1,  0> EDMA_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
}  // namespace GPR4

// GPR5 General Purpose Register
namespace GPR5 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 29> VREF_1M_CLK_GPT2;
    // 0b0..GPT2 ipg_clk_highfreq driven by IPG_PERCLK
    // 0b1..GPT2 ipg_clk_highfreq driven by anatop 1 MHz clock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 28> VREF_1M_CLK_GPT1;
    // 0b0..GPT1 ipg_clk_highfreq driven by IPG_PERCLK
    // 0b1..GPT1 ipg_clk_highfreq driven by anatop 1 MHz clock
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 26> ENET2_EVENT3IN_SEL;
    // 0b0..event3 source input from ENET2_1588_EVENT3_IN
    // 0b1..event3 source input from GPT2.GPT_COMPARE2
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 25> ENET_EVENT3IN_SEL;
    // 0b0..event3 source input from ENET_1588_EVENT3_IN
    // 0b1..event3 source input from GPT2.GPT_COMPARE1
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 24> GPT2_CAPIN2_SEL;
    // 0b0..source from GPT2_CAPTURE2
    // 0b1..source from ENET2_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1, 23> GPT2_CAPIN1_SEL;
    // 0b0..source from GPT2_CAPTURE1
    // 0b1..source from ENET_1588_EVENT3_OUT (chnnal 3 of IEEE 1588 timer)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1,  7> WDOG2_MASK;
    // 0b0..WDOG2 Timeout behaves normally
    // 0b1..WDOG2 Timeout is masked
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR5, 1,  6> WDOG1_MASK;
    // 0b0..WDOG1 Timeout behaves normally
    // 0b1..WDOG1 Timeout is masked
}  // namespace GPR5

// GPR6 General Purpose Register
namespace GPR6 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 31> IOMUXC_XBAR_DIR_SEL_19;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 30> IOMUXC_XBAR_DIR_SEL_18;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 29> IOMUXC_XBAR_DIR_SEL_17;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 28> IOMUXC_XBAR_DIR_SEL_16;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 27> IOMUXC_XBAR_DIR_SEL_15;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 26> IOMUXC_XBAR_DIR_SEL_14;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 25> IOMUXC_XBAR_DIR_SEL_13;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 24> IOMUXC_XBAR_DIR_SEL_12;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 23> IOMUXC_XBAR_DIR_SEL_11;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 22> IOMUXC_XBAR_DIR_SEL_10;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 21> IOMUXC_XBAR_DIR_SEL_9;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 20> IOMUXC_XBAR_DIR_SEL_8;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 19> IOMUXC_XBAR_DIR_SEL_7;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 18> IOMUXC_XBAR_DIR_SEL_6;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 17> IOMUXC_XBAR_DIR_SEL_5;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 16> IOMUXC_XBAR_DIR_SEL_4;
    // 0b0..XBAR_INOUT as input
    // 0b1..XBAR_INOUT as output
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 15> QTIMER4_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 14> QTIMER4_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 13> QTIMER4_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 12> QTIMER4_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 11> QTIMER3_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1, 10> QTIMER3_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  9> QTIMER3_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  8> QTIMER3_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  7> QTIMER2_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  6> QTIMER2_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  5> QTIMER2_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  4> QTIMER2_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  3> QTIMER1_TRM3_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  2> QTIMER1_TRM2_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  1> QTIMER1_TRM1_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR6, 1,  0> QTIMER1_TRM0_INPUT_SEL;
    // 0b0..input from IOMUX
    // 0b1..input from XBAR
}  // namespace GPR6

// GPR7 General Purpose Register
namespace GPR7 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 31> LPUART8_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted (the module is in Stop mode)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 30> LPUART7_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 29> LPUART6_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 28> LPUART5_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 27> LPUART4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 26> LPUART3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 25> LPUART2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 24> LPUART1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 23> LPSPI4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 22> LPSPI3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 21> LPSPI2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 20> LPSPI1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 19> LPI2C4_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 18> LPI2C3_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 17> LPI2C2_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 16> LPI2C1_STOP_ACK;
    // 0b0..stop acknowledge is not asserted
    // 0b1..stop acknowledge is asserted (the module is in Stop mode)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 15> LPUART8_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 14> LPUART7_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 13> LPUART6_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 12> LPUART5_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 11> LPUART4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1, 10> LPUART3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  9> LPUART2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  8> LPUART1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  7> LPSPI4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  6> LPSPI3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  5> LPSPI2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  4> LPSPI1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  3> LPI2C4_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  2> LPI2C3_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  1> LPI2C2_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR7, 1,  0> LPI2C1_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
}  // namespace GPR7

// GPR8 General Purpose Register
namespace GPR8 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 31> LPUART8_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 30> LPUART8_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 29> LPUART7_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 28> LPUART7_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 27> LPUART6_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 26> LPUART6_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 25> LPUART5_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 24> LPUART5_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 23> LPUART4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 22> LPUART4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 21> LPUART3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 20> LPUART3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 19> LPUART2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 18> LPUART2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 17> LPUART1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 16> LPUART1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 15> LPSPI4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 14> LPSPI4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 13> LPSPI3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 12> LPSPI3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 11> LPSPI2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1, 10> LPSPI2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  9> LPSPI1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  8> LPSPI1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  7> LPI2C4_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  6> LPI2C4_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  5> LPI2C3_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  4> LPI2C3_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  3> LPI2C2_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  2> LPI2C2_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  1> LPI2C1_IPG_DOZE;
    // 0b0..not in doze mode
    // 0b1..in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR8, 1,  0> LPI2C1_IPG_STOP_MODE;
    // 0b0..the module is functional in Stop mode
    // 0b1..the module is NOT functional in Stop mode, when this bit is equal to 1 and ipg_stop is asserted
}  // namespace GPR8

// GPR10 General Purpose Register
namespace GPR10 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 7, 25> LOCK_OCRAM_TZ_ADDR;
    // 0b0000000..Field is not locked
    // 0b0000001..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1, 24> LOCK_OCRAM_TZ_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1, 20> LOCK_DCPKEY_OCOTP_OR_KEYMUX;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1, 18> LOCK_SEC_ERR_RESP;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1, 17> LOCK_DBG_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1, 16> LOCK_NIDEN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 7,  9> OCRAM_TZ_ADDR;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1,  8> OCRAM_TZ_EN;
    // 0b0..The TrustZone feature is disabled. Entire OCRAM space is available for all access types (secure/non-secure/user/supervisor).
    // 0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
    //      the execution mode access policy described in CSU chapter.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1,  4> DCPKEY_OCOTP_OR_KEYMUX;
    // 0b0..Select key from SNVS Master Key.
    // 0b1..Select key from OCOTP (SW_GP2).
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1,  2> SEC_ERR_RESP;
    // 0b0..OKEY response
    // 0b1..SLVError (default)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1,  1> DBG_EN;
    // 0b0..Debug turned off.
    // 0b1..Debug enabled (default).
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR10, 1,  0> NIDEN;
    // 0b0..Debug turned off.
    // 0b1..Debug enabled (default).
}  // namespace GPR10

// GPR11 General Purpose Register
namespace GPR11 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11, 4, 8> BEE_DE_RX_EN;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11, 2, 6> M7_APC_AC_R3_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11, 2, 4> M7_APC_AC_R2_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11, 2, 2> M7_APC_AC_R1_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR11, 2, 0> M7_APC_AC_R0_CTRL;
    // 0b00..No access protection
    // 0b01..M7 debug protection enabled
    // 0b10..Reserved
    // 0b11..Reserved
}  // namespace GPR11

// GPR12 General Purpose Register
namespace GPR12 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 6> FLEXIO3_IPG_DOZE;
    // 0b0..FLEXIO3 is not in doze mode
    // 0b1..FLEXIO3 is in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 5> FLEXIO3_IPG_STOP_MODE;
    // 0b0..FlexIO3 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO3 is not functional in Stop mode.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 4> ACMP_IPG_STOP_MODE;
    // 0b0..ACMP is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, ACMP is not functional in Stop mode.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 3> FLEXIO2_IPG_DOZE;
    // 0b0..FLEXIO2 is not in doze mode
    // 0b1..FLEXIO2 is in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 2> FLEXIO2_IPG_STOP_MODE;
    // 0b0..FlexIO2 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO2 is not functional in Stop mode.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 1> FLEXIO1_IPG_DOZE;
    // 0b0..FLEXIO1 is not in doze mode
    // 0b1..FLEXIO1 is in doze mode
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR12, 1, 0> FLEXIO1_IPG_STOP_MODE;
    // 0b0..FlexIO1 is functional in Stop mode.
    // 0b1..When this bit is equal to 1'b1 and ipg_stop is asserted, FlexIO1 is not functional in Stop mode.
}  // namespace GPR12

// GPR13 General Purpose Register
namespace GPR13 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1, 20> CANFD_STOP_ACK;
    // 0b0..CANFD stop acknowledge is not asserted
    // 0b1..CANFD stop acknowledge is asserted
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1, 13> CACHE_USB;
    // 0b0..Cacheable attribute is off for read/write transactions.
    // 0b1..Cacheable attribute is on for read/write transactions.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1,  7> CACHE_ENET;
    // 0b0..Cacheable attribute is off for read/write transactions.
    // 0b1..Cacheable attribute is on for read/write transactions.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1,  4> CANFD_STOP_REQ;
    // 0b0..stop request off
    // 0b1..stop request on
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1,  1> AWCACHE_USDHC;
    // 0b0..Cacheable attribute is off for write transactions.
    // 0b1..Cacheable attribute is on for write transactions.
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR13, 1,  0> ARCACHE_USDHC;
    // 0b0..Cacheable attribute is off for read transactions.
    // 0b1..Cacheable attribute is on for read transactions.
}  // namespace GPR13

// GPR14 General Purpose Register
namespace GPR14 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1, 11> ACMP4_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1, 10> ACMP3_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  9> ACMP2_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  8> ACMP1_SAMPLE_SYNC_EN;
    // 0b0..select XBAR output
    // 0b1..select synced sample_lv
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  7> ACMP4_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  6> ACMP3_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  5> ACMP2_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  4> ACMP1_CMP_IGEN_TRIM_UP;
    // 0b0..no increase
    // 0b1..increases
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  3> ACMP4_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  2> ACMP3_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  1> ACMP2_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR14, 1,  0> ACMP1_CMP_IGEN_TRIM_DN;
    // 0b0..no reduce
    // 0b1..reduces
}  // namespace GPR14

// GPR16 General Purpose Register
namespace GPR16 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR16, 25, 7> CM7_INIT_VTOR;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR16,  1, 2> FLEXRAM_BANK_CFG_SEL;
    // 0b0..use fuse value to config
    // 0b1..use FLEXRAM_BANK_CFG to config
}  // namespace GPR16

// GPR17 General Purpose Register
namespace GPR17 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR17, 32, 0> FLEXRAM_BANK_CFG;  // FlexRAM bank config value
}  // namespace GPR17

// GPR18 General Purpose Register
namespace GPR18 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR18, 29, 3> M7_APC_AC_R0_BOT;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR18,  1, 0> LOCK_M7_APC_AC_R0_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR18

// GPR19 General Purpose Register
namespace GPR19 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR19, 29, 3> M7_APC_AC_R0_TOP;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR19,  1, 0> LOCK_M7_APC_AC_R0_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR19

// GPR20 General Purpose Register
namespace GPR20 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR20, 29, 3> M7_APC_AC_R1_BOT;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR20,  1, 0> LOCK_M7_APC_AC_R1_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR20

// GPR21 General Purpose Register
namespace GPR21 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR21, 29, 3> M7_APC_AC_R1_TOP;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR21,  1, 0> LOCK_M7_APC_AC_R1_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR21

// GPR22 General Purpose Register
namespace GPR22 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR22, 29, 3> M7_APC_AC_R2_BOT;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR22,  1, 0> LOCK_M7_APC_AC_R2_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR22

// GPR23 General Purpose Register
namespace GPR23 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR23, 29, 3> M7_APC_AC_R2_TOP;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR23,  1, 0> LOCK_M7_APC_AC_R2_TOP;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR23

// GPR24 General Purpose Register
namespace GPR24 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR24, 29, 3> M7_APC_AC_R3_BOT;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR24,  1, 0> LOCK_M7_APC_AC_R3_BOT;
    // 0b0..Register field [31:1] is not locked
    // 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR24

// GPR25 General Purpose Register
namespace GPR25 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR25, 29, 3> M7_APC_AC_R3_TOP;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR25,  1, 0> LOCK_M7_APC_AC_R3_TOP;
// 0b0..Register field [31:1] is not locked
// 0b1..Register field [31:1] is locked (read access only)
}  // namespace GPR25

// GPR26 General Purpose Register
namespace GPR26 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR26, 32, 0> GPIO_MUX1_GPIO_SEL;  // GPIO1 and GPIO6 share same IO MUX function, GPIO_MUX1 selects one GPIO function.
}  // namespace GPR26

// GPR27 General Purpose Register
namespace GPR27 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR27, 32, 0> GPIO_MUX2_GPIO_SEL;  //  GPIO2 and GPIO7 share same IO MUX function, GPIO_MUX2 selects one GPIO function.
}  // namespace GPR27

// GPR28 General Purpose Register
namespace GPR28 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR28, 32, 0> GPIO_MUX3_GPIO_SEL;  // GPIO3 and GPIO8 share same IO MUX function, GPIO_MUX3 selects one GPIO function.
}  // namespace GPR28

// GPR29 General Purpose Register
namespace GPR29 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR29, 32, 0> GPIO_MUX4_GPIO_SEL;  // GPIO4 and GPIO9 share same IO MUX function, GPIO_MUX4 selects one GPIO function.
}  // namespace GPR29

// GPR30 General Purpose Register
namespace GPR30 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR30, 20, 12> FLEXSPI_REMAP_ADDR_START;
}  // namespace GPR30

// GPR31 General Purpose Register
namespace GPR31 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR31, 20, 12> FLEXSPI_REMAP_ADDR_END;
}  // namespace GPR31

// GPR32 General Purpose Register
namespace GPR32 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR32, 20, 12> FLEXSPI_REMAP_ADDR_OFFSET;
}  // namespace GPR32

// GPR33 General Purpose Register
namespace GPR33 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33, 7, 17> LOCK_OCRAM2_TZ_ADDR;
    // 0b0000000..Field is not locked
    // 0b0000001..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33, 1, 16> LOCK_OCRAM2_TZ_EN;
    // 0b0..Field is not locked
    // 0b1..Field is locked (read access only)
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33, 7,  1> OCRAM2_TZ_ADDR;
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR33, 1,  0> OCRAM2_TZ_EN;
    // 0b0..The TrustZone feature is disabled. Entire OCRAM2 space is available for all access types (secure/non-secure/user/supervisor).
    // 0b1..The TrustZone feature is enabled. Access to address in the range specified by [ENDADDR:STARTADDR] follows
    //      the execution mode access policy described in CSU chapter.
}  // namespace GPR33

// GPR34 General Purpose Register
namespace GPR34 {
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR34, 1, 8> SIP_TEST_MUX_QSPI_SIP_EN;
    // 0b0..SIP_TEST_MUX is disabled
    // 0b1..SIP_TEST_MUX is enabled
constexpr IOMUXC_GPR_Reg<&IOMUXC_GPR_Layout::GPR34, 8, 0> SIP_TEST_MUX_BOOT_PIN_SEL;  // Boot Pin select in SIP_TEST_MUX
}  // namespace GPR34

}  // namespace IOMUXC_GPR

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
