// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SCB.h defines all the SCB registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

// SCB layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcu-sdk-cmsis/blob/mcux_main/Core/Include/core_cm7.h
struct SCB_Layout {
  const volatile uint32_t CPUID;            /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  volatile uint32_t ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  volatile uint32_t VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  volatile uint32_t AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  volatile uint32_t SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  volatile uint32_t CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  volatile uint8_t  SHPR[12U];              /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  const volatile uint32_t ID_PFR[2U];       /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  const volatile uint32_t ID_DFR;           /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  const volatile uint32_t ID_AFR;           /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  const volatile uint32_t ID_MMFR[4U];      /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  const volatile uint32_t ID_ISAR[5U];      /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t CLIDR;            /*!< Offset: 0x078 (R/ )  Cache Level ID register */
  const volatile uint32_t CTR;              /*!< Offset: 0x07C (R/ )  Cache Type register */
  const volatile uint32_t CCSIDR;           /*!< Offset: 0x080 (R/ )  Cache Size ID Register */
  volatile uint32_t CSSELR;                 /*!< Offset: 0x084 (R/W)  Cache Size Selection Register */
  volatile uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[93];
  volatile uint32_t STIR;                   /*!< Offset: 0x200 ( /W)  Software Triggered Interrupt Register */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[15];
  const volatile uint32_t MVFR0;            /*!< Offset: 0x240 (R/ )  Media and VFP Feature Register 0 */
  const volatile uint32_t MVFR1;            /*!< Offset: 0x244 (R/ )  Media and VFP Feature Register 1 */
  const volatile uint32_t MVFR2;            /*!< Offset: 0x248 (R/ )  Media and VFP Feature Register 2 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ICIALLU;                /*!< Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ICIMVAU;                /*!< Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU */
  volatile uint32_t DCIMVAC;                /*!< Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC */
  volatile uint32_t DCISW;                  /*!< Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way */
  volatile uint32_t DCCMVAU;                /*!< Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU */
  volatile uint32_t DCCMVAC;                /*!< Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC */
  volatile uint32_t DCCSW;                  /*!< Offset: 0x26C ( /W)  D-Cache Clean by Set-way */
  volatile uint32_t DCCIMVAC;               /*!< Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC */
  volatile uint32_t DCCISW;                 /*!< Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way */
  volatile uint32_t BPIALL;                 /*!< Offset: 0x278 ( /W)  Branch Predictor Invalidate All */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t ITCMCR;                 /*!< Offset: 0x290 (R/W)  Instruction Tightly-Coupled Memory Control Register */
  volatile uint32_t DTCMCR;                 /*!< Offset: 0x294 (R/W)  Data Tightly-Coupled Memory Control Registers */
  volatile uint32_t AHBPCR;                 /*!< Offset: 0x298 (R/W)  AHBP Control Register */
  volatile uint32_t CACR;                   /*!< Offset: 0x29C (R/W)  L1 Cache Control Register */
  volatile uint32_t AHBSCR;                 /*!< Offset: 0x2A0 (R/W)  AHB Slave Control Register */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ABFSR;                  /*!< Offset: 0x2A8 (R/W)  Auxiliary Bus Fault Status Register */
};

constexpr size_t    kSCB_size = 0x2AC;
static constexpr uintptr_t kSCS_base = 0xE000E000;   /*!< System Control Space Base Address */
constexpr uintptr_t kSCB_base = kSCS_base + 0x0D00;  /*!< System Control Block Base Address */

constexpr RegGroup<SCB_Layout, kSCB_size, kSCB_base> SCB;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using SCB_Reg = Reg<kSCB_base, SCB_Layout, Member, Bits, Shift, DirectAssign>;

}  // namespace regs
}  // namespace decept
