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
namespace teensy4 {

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

constexpr regs::RegGroup<SCB_Layout, kSCB_size, kSCB_base> SCB;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using SCB_Reg =
    regs::Reg32<kSCB_base, SCB_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// SCB CPUID Register Definitions
#undef SCB_CPUID_IMPLEMENTER
constexpr SCB_Reg<&SCB_Layout::CPUID,  8, 24> SCB_CPUID_IMPLEMENTER;
#undef SCB_CPUID_VARIANT
constexpr SCB_Reg<&SCB_Layout::CPUID,  4, 20> SCB_CPUID_VARIANT;
#undef SCB_CPUID_ARCHITECTURE
constexpr SCB_Reg<&SCB_Layout::CPUID,  4, 16> SCB_CPUID_ARCHITECTURE;
#undef SCB_CPUID_PARTNO
constexpr SCB_Reg<&SCB_Layout::CPUID, 12,  4> SCB_CPUID_PARTNO;
#undef SCB_CPUID_REVISION
constexpr SCB_Reg<&SCB_Layout::CPUID,  4,  0> SCB_CPUID_REVISION;

// SCB Interrupt Control State Register Definitions
#undef SCB_ICSR_NMIPENDSET
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 31> SCB_ICSR_NMIPENDSET;
#undef SCB_ICSR_PENDSVSET
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 28> SCB_ICSR_PENDSVSET;
#undef SCB_ICSR_PENDSVCLR
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 27> SCB_ICSR_PENDSVCLR;
#undef SCB_ICSR_PENDSTSET
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 26> SCB_ICSR_PENDSTSET;
#undef SCB_ICSR_PENDSTCLR
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 25> SCB_ICSR_PENDSTCLR;
#undef SCB_ICSR_ISRPREEMPT
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 23> SCB_ICSR_ISRPREEMPT;
#undef SCB_ICSR_ISRPENDING
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 22> SCB_ICSR_ISRPENDING;
#undef SCB_ICSR_VECTPENDING
constexpr SCB_Reg<&SCB_Layout::ICSR, 9, 12> SCB_ICSR_VECTPENDING;
#undef SCB_ICSR_RETTOBASE
constexpr SCB_Reg<&SCB_Layout::ICSR, 1, 11> SCB_ICSR_RETTOBASE;
#undef SCB_ICSR_VECTACTIVE
constexpr SCB_Reg<&SCB_Layout::ICSR, 9,  0> SCB_ICSR_VECTACTIVE;

// SCB Vector Table Offset Register Definitions
#undef SCB_VTOR_TBLOFF
constexpr SCB_Reg<&SCB_Layout::VTOR, 25, 7> SCB_VTOR_TBLOFF;

// SCB Application Interrupt and Reset Control Register Definitions
#undef SCB_AIRCR_VECTKEY
constexpr SCB_Reg<&SCB_Layout::AIRCR, 16, 16> SCB_AIRCR_VECTKEY;
#undef SCB_AIRCR_VECTKEYSTAT
constexpr SCB_Reg<&SCB_Layout::AIRCR, 16, 16> SCB_AIRCR_VECTKEYSTAT;
#undef SCB_AIRCR_ENDIANNESS
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1, 15> SCB_AIRCR_ENDIANNESS;
#undef SCB_AIRCR_PRIGROUP
constexpr SCB_Reg<&SCB_Layout::AIRCR,  3,  8> SCB_AIRCR_PRIGROUP;
#undef SCB_AIRCR_SYSRESETREQ
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  2> SCB_AIRCR_SYSRESETREQ;
#undef SCB_AIRCR_VECTCLRACTIVE
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  1> SCB_AIRCR_VECTCLRACTIVE;
#undef SCB_AIRCR_VECTRESET
constexpr SCB_Reg<&SCB_Layout::AIRCR,  1,  0> SCB_AIRCR_VECTRESET;

// SCB System Control Register Definitions
#undef SCB_SCR_SEVONPEND
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 4> SCB_SCR_SEVONPEND;
#undef SCB_SCR_SLEEPDEEP
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 2> SCB_SCR_SLEEPDEEP;
#undef SCB_SCR_SLEEPONEXIT
constexpr SCB_Reg<&SCB_Layout::SCR, 1, 1> SCB_SCR_SLEEPONEXIT;

// SCB Configuration Control Register Definitions
#undef SCB_CCR_BP
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 18> SCB_CCR_BP;
#undef SCB_CCR_IC
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 17> SCB_CCR_IC;
#undef SCB_CCR_DC
constexpr SCB_Reg<&SCB_Layout::CCR, 1, 16> SCB_CCR_DC;
#undef SCB_CCR_STKALIGN
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  9> SCB_CCR_STKALIGN;
#undef SCB_CCR_BFHFNMIGN
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  8> SCB_CCR_BFHFNMIGN;
#undef SCB_CCR_DIV_0_TRP
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  4> SCB_CCR_DIV_0_TRP;
#undef SCB_CCR_UNALIGN_TRP
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  3> SCB_CCR_UNALIGN_TRP;
#undef SCB_CCR_USERSETMPEND
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  1> SCB_CCR_USERSETMPEND;
#undef SCB_CCR_NONBASETHRDENA
constexpr SCB_Reg<&SCB_Layout::CCR, 1,  0> SCB_CCR_NONBASETHRDENA;

// SCB System Handler Control and State Register Definitions
#undef SCB_SHCSR_USGFAULTENA
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 18> SCB_SHCSR_USGFAULTENA;
#undef SCB_SHCSR_BUSFAULTENA
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 17> SCB_SHCSR_BUSFAULTENA;
#undef SCB_SHCSR_MEMFAULTENA
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 16> SCB_SHCSR_MEMFAULTENA;
#undef SCB_SHCSR_SVCALLPENDED
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 15> SCB_SHCSR_SVCALLPENDED;
#undef SCB_SHCSR_BUSFAULTPENDED
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 14> SCB_SHCSR_BUSFAULTPENDED;
#undef SCB_SHCSR_MEMFAULTPENDED
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 13> SCB_SHCSR_MEMFAULTPENDED;
#undef SCB_SHCSR_USGFAULTPENDED
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 12> SCB_SHCSR_USGFAULTPENDED;
#undef SCB_SHCSR_SYSTICKACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 11> SCB_SHCSR_SYSTICKACT;
#undef SCB_SHCSR_PENDSVACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1, 10> SCB_SHCSR_PENDSVACT;
#undef SCB_SHCSR_MONITORACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  8> SCB_SHCSR_MONITORACT;
#undef SCB_SHCSR_SVCALLACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  7> SCB_SHCSR_SVCALLACT;
#undef SCB_SHCSR_USGFAULTACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  3> SCB_SHCSR_USGFAULTACT;
#undef SCB_SHCSR_BUSFAULTACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  1> SCB_SHCSR_BUSFAULTACT;
#undef SCB_SHCSR_MEMFAULTACT
constexpr SCB_Reg<&SCB_Layout::SHCSR, 1,  0> SCB_SHCSR_MEMFAULTACT;

// SCB Configurable Fault Status Register Definitions
#undef SCB_CFSR_USGFAULTSR
constexpr SCB_Reg<&SCB_Layout::CFSR, 16, 16> SCB_CFSR_USGFAULTSR;
#undef SCB_CFSR_BUSFAULTSR
constexpr SCB_Reg<&SCB_Layout::CFSR,  8,  8> SCB_CFSR_BUSFAULTSR;
#undef SCB_CFSR_MEMFAULTSR
constexpr SCB_Reg<&SCB_Layout::CFSR,  8,  0> SCB_CFSR_MEMFAULTSR;

// SCB MemManage Fault Status Register Definitions (part of SCB Configurable Fault Status Register)
#undef SCB_CFSR_MMARVALID
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 7> SCB_CFSR_MMARVALID;
#undef SCB_CFSR_MLSPERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 5> SCB_CFSR_MLSPERR;
#undef SCB_CFSR_MSTKERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 4> SCB_CFSR_MSTKERR;
#undef SCB_CFSR_MUNSTKERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 3> SCB_CFSR_MUNSTKERR;
#undef SCB_CFSR_DACCVIOL
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 1> SCB_CFSR_DACCVIOL;
#undef SCB_CFSR_IACCVIOL
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 0> SCB_CFSR_IACCVIOL;

// SCB BusFault Status Register Definitions (part of SCB Configurable Fault Status Register)
#undef SCB_CFSR_BFARVALID
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 15> SCB_CFSR_BFARVALID;
#undef SCB_CFSR_LSPERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 13> SCB_CFSR_LSPERR;
#undef SCB_CFSR_STKERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 12> SCB_CFSR_STKERR;
#undef SCB_CFSR_UNSTKERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 11> SCB_CFSR_UNSTKERR;
#undef SCB_CFSR_IMPRECISERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 10> SCB_CFSR_IMPRECISERR;
#undef SCB_CFSR_PRECISERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1,  9> SCB_CFSR_PRECISERR;
#undef SCB_CFSR_IBUSERR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1,  8> SCB_CFSR_IBUSERR;

// SCB UsageFault Status Register Definitions (part of SCB Configurable Fault Status Register)
#undef SCB_CFSR_DIVBYZERO
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 25> SCB_CFSR_DIVBYZERO;
#undef SCB_CFSR_UNALIGNED
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 24> SCB_CFSR_UNALIGNED;
#undef SCB_CFSR_NOCP
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 19> SCB_CFSR_NOCP;
#undef SCB_CFSR_INVPC
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 18> SCB_CFSR_INVPC;
#undef SCB_CFSR_INVSTATE
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 17> SCB_CFSR_INVSTATE;
#undef SCB_CFSR_UNDEFINSTR
constexpr SCB_Reg<&SCB_Layout::CFSR, 1, 16> SCB_CFSR_UNDEFINSTR;

// SCB Hard Fault Status Register Definitions
#undef SCB_HFSR_DEBUGEVT
constexpr SCB_Reg<&SCB_Layout::HFSR, 1, 31> SCB_HFSR_DEBUGEVT;
#undef SCB_HFSR_FORCED
constexpr SCB_Reg<&SCB_Layout::HFSR, 1, 30> SCB_HFSR_FORCED;
#undef SCB_HFSR_VECTTBL
constexpr SCB_Reg<&SCB_Layout::HFSR, 1,  1> SCB_HFSR_VECTTBL;

// SCB Debug Fault Status Register Definitions
#undef SCB_DFSR_EXTERNAL
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 4> SCB_DFSR_EXTERNAL;
#undef SCB_DFSR_VCATCH
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 3> SCB_DFSR_VCATCH;
#undef SCB_DFSR_DWTTRAP
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 2> SCB_DFSR_DWTTRAP;
#undef SCB_DFSR_BKPT
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 1> SCB_DFSR_BKPT;
#undef SCB_DFSR_HALTED
constexpr SCB_Reg<&SCB_Layout::DFSR, 1, 0> SCB_DFSR_HALTED;

// SCB Cache Level ID Register Definitions
#undef SCB_CLIDR_LOUU
constexpr SCB_Reg<&SCB_Layout::CLIDR, 3, 27> SCB_CLIDR_LOUU;
#undef SCB_CLIDR_LOC
constexpr SCB_Reg<&SCB_Layout::CLIDR, 3, 24> SCB_CLIDR_LOC;

// SCB Cache Type Register Definitions
#undef SCB_CTR_FORMAT
constexpr SCB_Reg<&SCB_Layout::CTR, 3, 29> SCB_CTR_FORMAT;
#undef SCB_CTR_CWG
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 24> SCB_CTR_CWG;
#undef SCB_CTR_ERG
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 20> SCB_CTR_ERG;
#undef SCB_CTR_DMINLINE
constexpr SCB_Reg<&SCB_Layout::CTR, 4, 16> SCB_CTR_DMINLINE;
#undef SCB_CTR_IMINLINE
constexpr SCB_Reg<&SCB_Layout::CTR, 4,  0> SCB_CTR_IMINLINE;

// SCB Cache Size ID Register Definitions
#undef SCB_CCSIDR_WT
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 31> SCB_CCSIDR_WT;
#undef SCB_CCSIDR_WB
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 30> SCB_CCSIDR_WB;
#undef SCB_CCSIDR_RA
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 29> SCB_CCSIDR_RA;
#undef SCB_CCSIDR_WA
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  1, 28> SCB_CCSIDR_WA;
#undef SCB_CCSIDR_NUMSETS
constexpr SCB_Reg<&SCB_Layout::CCSIDR, 15, 13> SCB_CCSIDR_NUMSETS;
#undef SCB_CCSIDR_ASSOCIATIVITY
constexpr SCB_Reg<&SCB_Layout::CCSIDR, 10,  3> SCB_CCSIDR_ASSOCIATIVITY;
#undef SCB_CCSIDR_LINESIZE
constexpr SCB_Reg<&SCB_Layout::CCSIDR,  3,  0> SCB_CCSIDR_LINESIZE;

// SCB Cache Size Selection Register Definitions
#undef SCB_CSSELR_LEVEL
constexpr SCB_Reg<&SCB_Layout::CSSELR, 3, 1> SCB_CSSELR_LEVEL;
#undef SCB_CSSELR_IND
constexpr SCB_Reg<&SCB_Layout::CSSELR, 1, 0> SCB_CSSELR_IND;

// SCB Software Triggered Interrupt Register Definitions
#undef SCB_STIR_INTID
constexpr SCB_Reg<&SCB_Layout::STIR, 9, 0> SCB_STIR_INTID;

// SCB D-Cache Invalidate by Set-way Register Definitions
#undef SCB_DCISW_WAY
constexpr SCB_Reg<&SCB_Layout::DCISW, 2, 30> SCB_DCISW_WAY;
#undef SCB_DCISW_SET
constexpr SCB_Reg<&SCB_Layout::DCISW, 9,  5> SCB_DCISW_SET;

// SCB D-Cache Clean by Set-way Register Definitions
#undef SCB_DCCSW_WAY
constexpr SCB_Reg<&SCB_Layout::DCCSW, 2, 30> SCB_DCCSW_WAY;
#undef SCB_DCCSW_SET
constexpr SCB_Reg<&SCB_Layout::DCCSW, 9,  5> SCB_DCCSW_SET;

// SCB D-Cache Clean and Invalidate by Set-way Register Definitions
#undef SCB_DCCISW_WAY
constexpr SCB_Reg<&SCB_Layout::DCCISW, 2, 30> SCB_DCCISW_WAY;
#undef SCB_DCCISW_SET
constexpr SCB_Reg<&SCB_Layout::DCCISW, 9,  5> SCB_DCCISW_SET;

// SCB Instruction Tightly-Coupled Memory Control Register Definitions
#undef SCB_ITCMCR_SZ
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 4, 3> SCB_ITCMCR_SZ;
#undef SCB_ITCMCR_RETEN
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 2> SCB_ITCMCR_RETEN;
#undef SCB_ITCMCR_RMW
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 1> SCB_ITCMCR_RMW;
#undef SCB_ITCMCR_EN
constexpr SCB_Reg<&SCB_Layout::ITCMCR, 1, 0> SCB_ITCMCR_EN;

// SCB Data Tightly-Coupled Memory Control Register Definitions
#undef SCB_DTCMCR_SZ
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 4, 3> SCB_DTCMCR_SZ;
#undef SCB_DTCMCR_RETEN
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 2> SCB_DTCMCR_RETEN;
#undef SCB_DTCMCR_RMW
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 1> SCB_DTCMCR_RMW;
#undef SCB_DTCMCR_EN
constexpr SCB_Reg<&SCB_Layout::DTCMCR, 1, 0> SCB_DTCMCR_EN;

// SCB AHBP Control Register Definitions
#undef SCB_AHBPCR_SZ
constexpr SCB_Reg<&SCB_Layout::AHBPCR, 3, 1> SCB_AHBPCR_SZ;
#undef SCB_AHBPCR_EN
constexpr SCB_Reg<&SCB_Layout::AHBPCR, 1, 0> SCB_AHBPCR_EN;

// SCB L1 Cache Control Register Definitions
#undef SCB_CACR_FORCEWT
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 2> SCB_CACR_FORCEWT;
#undef SCB_CACR_ECCDIS
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 1> SCB_CACR_ECCDIS;
#undef SCB_CACR_SIWT
constexpr SCB_Reg<&SCB_Layout::CACR, 1, 0> SCB_CACR_SIWT;

// SCB AHBS Control Register Definitions
#undef SCB_AHBSCR_INITCOUNT
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 5, 11> SCB_AHBSCR_INITCOUNT;
#undef SCB_AHBSCR_TPRI
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 9,  2> SCB_AHBSCR_TPRI;
#undef SCB_AHBSCR_CTL
constexpr SCB_Reg<&SCB_Layout::AHBSCR, 2,  0> SCB_AHBSCR_CTL;

// SCB Auxiliary Bus Fault Status Register Definitions
#undef SCB_ABFSR_AXIMTYPE
constexpr SCB_Reg<&SCB_Layout::ABFSR, 2, 8> SCB_ABFSR_AXIMTYPE;
#undef SCB_ABFSR_EPPB
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 4> SCB_ABFSR_EPPB;
#undef SCB_ABFSR_AXIM
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 3> SCB_ABFSR_AXIM;
#undef SCB_ABFSR_AHBP
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 2> SCB_ABFSR_AHBP;
#undef SCB_ABFSR_DTCM
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 1> SCB_ABFSR_DTCM;
#undef SCB_ABFSR_ITCM
constexpr SCB_Reg<&SCB_Layout::ABFSR, 1, 0> SCB_ABFSR_ITCM;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
