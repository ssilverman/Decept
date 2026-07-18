// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// SCB.h defines all the SCB registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the System Control Block (SCB).
//
// Comments are from BSD-3-licensed NXP SDK.
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
  volatile uint8_t  SHPR[12];               /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  volatile uint32_t SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  volatile uint32_t CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  volatile uint32_t HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  volatile uint32_t DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  volatile uint32_t MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  volatile uint32_t BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  volatile uint32_t AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  const volatile uint32_t ID_PFR[2];        /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  const volatile uint32_t ID_DFR;           /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  const volatile uint32_t ID_AFR;           /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  const volatile uint32_t ID_MMFR[4];       /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  const volatile uint32_t ID_ISAR[5];       /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  const volatile uint32_t CLIDR;            /*!< Offset: 0x078 (R/ )  Cache Level ID register */
  const volatile uint32_t CTR;              /*!< Offset: 0x07C (R/ )  Cache Type register */
  const volatile uint32_t CCSIDR;           /*!< Offset: 0x080 (R/ )  Cache Size ID Register */
  volatile uint32_t CSSELR;                 /*!< Offset: 0x084 (R/W)  Cache Size Selection Register */
  volatile uint32_t CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[93];
  volatile uint32_t STIR;                   /*!< Offset: 0x200 ( /W)  Software Triggered Interrupt Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[15];
  const volatile uint32_t MVFR0;            /*!< Offset: 0x240 (R/ )  Media and VFP Feature Register 0 */
  const volatile uint32_t MVFR1;            /*!< Offset: 0x244 (R/ )  Media and VFP Feature Register 1 */
  const volatile uint32_t MVFR2;            /*!< Offset: 0x248 (R/ )  Media and VFP Feature Register 2 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ICIALLU;                /*!< Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ICIMVAU;                /*!< Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU */
  volatile uint32_t DCIMVAC;                /*!< Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC */
  volatile uint32_t DCISW;                  /*!< Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way */
  volatile uint32_t DCCMVAU;                /*!< Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU */
  volatile uint32_t DCCMVAC;                /*!< Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC */
  volatile uint32_t DCCSW;                  /*!< Offset: 0x26C ( /W)  D-Cache Clean by Set-way */
  volatile uint32_t DCCIMVAC;               /*!< Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC */
  volatile uint32_t DCCISW;                 /*!< Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way */
  volatile uint32_t BPIALL;                 /*!< Offset: 0x278 ( /W)  Branch Predictor Invalidate All */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[5];
  volatile uint32_t ITCMCR;                 /*!< Offset: 0x290 (R/W)  Instruction Tightly-Coupled Memory Control Register */
  volatile uint32_t DTCMCR;                 /*!< Offset: 0x294 (R/W)  Data Tightly-Coupled Memory Control Registers */
  volatile uint32_t AHBPCR;                 /*!< Offset: 0x298 (R/W)  AHBP Control Register */
  volatile uint32_t CACR;                   /*!< Offset: 0x29C (R/W)  L1 Cache Control Register */
  volatile uint32_t AHBSCR;                 /*!< Offset: 0x2A0 (R/W)  AHB Slave Control Register */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[1];
  volatile uint32_t ABFSR;                  /*!< Offset: 0x2A8 (R/W)  Auxiliary Bus Fault Status Register */
};

constexpr size_t    kSCB_size = 0x2AC;
static constexpr uintptr_t kSCS_base = 0xE000E000;   /*!< System Control Space Base Address */
constexpr uintptr_t kSCB_base = kSCS_base + 0x0D00;  /*!< System Control Block Base Address */

namespace SCB {
constexpr regs::RegGroup<SCB_Layout, kSCB_size, kSCB_base> group;
}  // namespace SCB

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using SCB_Reg =
    regs::Reg32<kSCB_base, SCB_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace SCB {

// SCB CPUID Register Definitions
namespace CPUID {
constexpr SCB_Reg<&SCB_Layout::CPUID,  8, 24> IMPLEMENTER;
constexpr SCB_Reg<&SCB_Layout::CPUID,  4, 20> VARIANT;
constexpr SCB_Reg<&SCB_Layout::CPUID,  4, 16> ARCHITECTURE;
constexpr SCB_Reg<&SCB_Layout::CPUID, 12,  4> PARTNO;
constexpr SCB_Reg<&SCB_Layout::CPUID,  4,  0> REVISION;
}  // namespace CPUID

// SCB Interrupt Control State Register Definitions
namespace ICSR {
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 31> NMIPENDSET;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 28> PENDSVSET;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 27> PENDSVCLR;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 26> PENDSTSET;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 25> PENDSTCLR;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 23> ISRPREEMPT;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 22> ISRPENDING;
constexpr SCB_Reg<&SCB_Layout::ICSR, 9, 12> VECTPENDING;
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 11> RETTOBASE;
constexpr SCB_Reg<&SCB_Layout::ICSR, 9,  0> VECTACTIVE;
}  // namespace ICSR

// SCB Vector Table Offset Register Definitions
namespace VTOR {
constexpr SCB_Reg<&SCB_Layout::VTOR, 25, 7> TBLOFF;
}  // namespace VTOR

// SCB Application Interrupt and Reset Control Register Definitions
namespace AIRCR {
constexpr SCB_Reg<&SCB_Layout::AIRCR, 16, 16> VECTKEY;
constexpr SCB_Reg<&SCB_Layout::AIRCR, 16, 16> VECTKEYSTAT;
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1, 15> ENDIANNESS;
constexpr SCB_Reg<&SCB_Layout::AIRCR,  3,  8> PRIGROUP;
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  2> SYSRESETREQ;
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  1> VECTCLRACTIVE;
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  0> VECTRESET;
}  // namespace AIRCR

// SCB System Control Register Definitions
namespace SCR {
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 4> SEVONPEND;
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 2> SLEEPDEEP;
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 1> SLEEPONEXIT;
}  // namespace SCR

// SCB Configuration Control Register Definitions
namespace CCR {
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 18> BP;
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 17> IC;
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 16> DC;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  9> STKALIGN;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  8> BFHFNMIGN;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  4> DIV_0_TRP;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  3> UNALIGN_TRP;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  1> USERSETMPEND;
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  0> NONBASETHRDENA;
}  // namespace CCR

// SCB System Handler Control and State Register Definitions
namespace SHCSR {
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 18> USGFAULTENA;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 17> BUSFAULTENA;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 16> MEMFAULTENA;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 15> SVCALLPENDED;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 14> BUSFAULTPENDED;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 13> MEMFAULTPENDED;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 12> USGFAULTPENDED;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 11> SYSTICKACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 10> PENDSVACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  8> MONITORACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  7> SVCALLACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  3> USGFAULTACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  1> BUSFAULTACT;
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  0> MEMFAULTACT;
}  // namespace SHCSR

// SCB Configurable Fault Status Register Definitions
namespace CFSR {
constexpr SCB_Reg<&SCB_Layout::CFSR, 16, 16> USGFAULTSR;
constexpr SCB_Reg<&SCB_Layout::CFSR,  8,  8> BUSFAULTSR;
constexpr SCB_Reg<&SCB_Layout::CFSR,  8,  0> MEMFAULTSR;

// SCB MemManage Fault Status Register Definitions (part of SCB Configurable Fault Status Register)
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 7> MMARVALID;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 5> MLSPERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 4> MSTKERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 3> MUNSTKERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 1> DACCVIOL;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 0> IACCVIOL;

// SCB BusFault Status Register Definitions (part of SCB Configurable Fault Status Register)
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 15> BFARVALID;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 13> LSPERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 12> STKERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 11> UNSTKERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 10> IMPRECISERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1,  9> PRECISERR;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1,  8> IBUSERR;

// SCB UsageFault Status Register Definitions (part of SCB Configurable Fault Status Register)
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 25> DIVBYZERO;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 24> UNALIGNED;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 19> NOCP;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 18> INVPC;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 17> INVSTATE;
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 16> UNDEFINSTR;
}  // namespace CFSR

// SCB Hard Fault Status Register Definitions
namespace HFSR {
constexpr SCB_Reg<&SCB_Layout::HFSR, 1, 31> DEBUGEVT;
constexpr SCB_Reg<&SCB_Layout::HFSR, 1, 30> FORCED;
constexpr SCB_Reg<&SCB_Layout::HFSR, 1,  1> VECTTBL;
}  // namespace HFSR

// SCB Debug Fault Status Register Definitions
namespace DFSR {
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 4> EXTERNAL;
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 3> VCATCH;
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 2> DWTTRAP;
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 1> BKPT;
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 0> HALTED;
}  // namespace DFSR

// SCB Cache Level ID Register Definitions
namespace CLIDR {
constexpr SCB_Reg<&SCB_Layout::CLIDR, 3, 27> LOUU;
constexpr SCB_Reg<&SCB_Layout::CLIDR, 3, 24> LOC;
}  // namespace CLIDR

// SCB Cache Type Register Definitions
namespace CTR {
constexpr SCB_Reg<&SCB_Layout::CTR, 3, 29> FORMAT;
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 24> CWG;
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 20> ERG;
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 16> DMINLINE;
constexpr SCB_Reg<&SCB_Layout::CTR, 4,  0> IMINLINE;
}  // namespace CTR

// SCB Cache Size ID Register Definitions
namespace CCSIDR {
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 31> WT;
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 30> WB;
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 29> RA;
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 28> WA;
constexpr SCB_Reg<&SCB_Layout::CCSIDR, 15, 13> NUMSETS;
constexpr SCB_Reg<&SCB_Layout::CCSIDR, 10,  3> ASSOCIATIVITY;
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  3,  0> LINESIZE;
}  // namespace CCSIDR

// SCB Cache Size Selection Register Definitions
namespace CSSELR {
constexpr SCB_Reg<&SCB_Layout::CSSELR, 3, 1> LEVEL;
constexpr SCB_Reg<&SCB_Layout::CSSELR, 1, 0> IND;
}  // namespace CSSELR

// SCB Software Triggered Interrupt Register Definitions
namespace STIR {
constexpr SCB_Reg<&SCB_Layout::STIR, 9, 0> INTID;
}  // namespace STIR

// SCB D-Cache Invalidate by Set-way Register Definitions
namespace DCISW {
constexpr SCB_Reg<&SCB_Layout::DCISW, 2, 30> WAY;
constexpr SCB_Reg<&SCB_Layout::DCISW, 9,  5> SET;
}  // namespace DCISW

// SCB D-Cache Clean by Set-way Register Definitions
namespace DCCSW {
constexpr SCB_Reg<&SCB_Layout::DCCSW, 2, 30> WAY;
constexpr SCB_Reg<&SCB_Layout::DCCSW, 9,  5> SET;
}  // namespace DCCSW

// SCB D-Cache Clean and Invalidate by Set-way Register Definitions
namespace DCCISW {
constexpr SCB_Reg<&SCB_Layout::DCCISW, 2, 30> WAY;
constexpr SCB_Reg<&SCB_Layout::DCCISW, 9,  5> SET;
}  // namespace DCCISW

// SCB Instruction Tightly-Coupled Memory Control Register Definitions
namespace ITCMCR {
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 4, 3> SZ;
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 2> RETEN;
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 1> RMW;
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 0> EN;
}  // namespace ITCMCR

// SCB Data Tightly-Coupled Memory Control Register Definitions
namespace DTCMCR {
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 4, 3> SZ;
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 2> RETEN;
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 1> RMW;
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 0> EN;
}  // namespace DTCMCR

// SCB AHBP Control Register Definitions
namespace AHBPCR {
constexpr SCB_Reg<&SCB_Layout::AHBPCR, 3, 1> SZ;
constexpr SCB_Reg<&SCB_Layout::AHBPCR, 1, 0> EN;
}  // namespace AHBPCR

// SCB L1 Cache Control Register Definitions
namespace CACR {
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 2> FORCEWT;
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 1> ECCDIS;
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 0> SIWT;
}  // namespace CACR

// SCB AHBS Control Register Definitions
namespace AHBSCR {
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 5, 11> INITCOUNT;
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 9,  2> TPRI;
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 2,  0> CTL;
}  // namespace AHBSCR

// SCB Auxiliary Bus Fault Status Register Definitions
namespace ABFSR {
constexpr SCB_Reg<&SCB_Layout::ABFSR, 2, 8> AXIMTYPE;
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 4> EPPB;
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 3> AXIM;
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 2> AHBP;
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 1> DTCM;
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 0> ITCM;
}  // namespace ABFSR

}  // namespace SCB

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
