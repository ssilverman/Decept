// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// CCM.h defines all the CCM registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_CCM.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct CCM_Layout {
  volatile uint32_t CCR;                               /**< CCM Control Register, offset: 0x0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t CSR;                               /**< CCM Status Register, offset: 0x8 */
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
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t CSCDR2;                            /**< CCM Serial Clock Divider Register 2, offset: 0x38 */
  volatile uint32_t CSCDR3;                            /**< CCM Serial Clock Divider Register 3, offset: 0x3C */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[2];
  volatile uint32_t CDHIPR;                            /**< CCM Divider Handshake In-Process Register, offset: 0x48 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[2];
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
} CCM_Type;

constexpr size_t    kCCM_size = 0x8C;
constexpr uintptr_t kCCM_base = 0x400FC000;

constexpr RegGroup<CCM_Layout, kCCM_size, kCCM_base> CCM;

#define CCM_MEMBER(member) (kCCM_base + offsetof(CCM_Layout, member))

// DCP control register 0
constexpr Reg<CCM_MEMBER(CCGR0), 2, 10> CCM_CCGR0_DCP;  // CG5

constexpr uint32_t kCCM_CCGR_OFF      = 0x00;
constexpr uint32_t kCCM_CCGR_RUN_ONLY = 0x01;
constexpr uint32_t kCCM_CCGR_ON       = 0x03;

#undef CCM_MEMBER

}  // namespace regs
}  // namespace decept
