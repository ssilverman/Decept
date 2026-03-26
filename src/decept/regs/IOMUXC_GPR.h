// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// IOMUXC_GPR.h defines all the IOMUXC_GPR registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

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

constexpr RegGroup<IOMUXC_GPR_Layout, kIOMUXC_GPR_size, kIOMUXC_GPR_base>
    IOMUXC_GPR;

#define IOMUXC_GPR_MEMBER(member) \
  (kIOMUXC_GPR_base + offsetof(IOMUXC_GPR_Layout, member))

constexpr Reg<IOMUXC_GPR_MEMBER(GPR1),  1, 23> IOMUXC_GPR_GPR1_ENET_IPG_CLK_S_EN;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR1),  1, 18> IOMUXC_GPR_GPR1_ENET2_TX_CLK_DIR;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR1),  1, 17> IOMUXC_GPR_GPR1_ENET1_TX_CLK_DIR;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR1),  1, 14> IOMUXC_GPR_GPR1_ENET2_CLK_SEL;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR1),  1, 13> IOMUXC_GPR_GPR1_ENET1_CLK_SEL;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR3),  1,  4> IOMUXC_GPR_GPR3_DCP_KEY_SEL;
constexpr Reg<IOMUXC_GPR_MEMBER(GPR10), 1,  4> IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX;

#undef IOMUXC_GPR_MEMBER

}  // namespace regs
}  // namespace decept
