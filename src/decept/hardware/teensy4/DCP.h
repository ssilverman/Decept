// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DCP.h defines all the DCP registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace teensy4 {

// DCP layout. Comments are from BSD-3-licensed NXP SDK.
//
// See:
// * https://github.com/nxp-mcuxpresso/mcux-devices-rt/blob/main/RT1060/periph/PERI_DCP.h
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk/blob/main/devices/MIMXRT1062/MIMXRT1062.h
struct DCP_Layout {
  volatile uint32_t CTRL;                              /**< DCP control register 0, offset: 0x0 */
  volatile uint32_t CTRL_SET;                          /**< DCP control register 0, offset: 0x4 */
  volatile uint32_t CTRL_CLR;                          /**< DCP control register 0, offset: 0x8 */
  volatile uint32_t CTRL_TOG;                          /**< DCP control register 0, offset: 0xC */
  volatile uint32_t STAT;                              /**< DCP status register, offset: 0x10 */
  volatile uint32_t STAT_SET;                          /**< DCP status register, offset: 0x14 */
  volatile uint32_t STAT_CLR;                          /**< DCP status register, offset: 0x18 */
  volatile uint32_t STAT_TOG;                          /**< DCP status register, offset: 0x1C */
  volatile uint32_t CHANNELCTRL;                       /**< DCP channel control register, offset: 0x20 */
  volatile uint32_t CHANNELCTRL_SET;                   /**< DCP channel control register, offset: 0x24 */
  volatile uint32_t CHANNELCTRL_CLR;                   /**< DCP channel control register, offset: 0x28 */
  volatile uint32_t CHANNELCTRL_TOG;                   /**< DCP channel control register, offset: 0x2C */
  volatile uint32_t CAPABILITY0;                       /**< DCP capability 0 register, offset: 0x30 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t CAPABILITY1;                 /**< DCP capability 1 register, offset: 0x40 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CONTEXT;                           /**< DCP context buffer pointer, offset: 0x50 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEY;                               /**< DCP key index, offset: 0x60 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEYDATA;                           /**< DCP key data, offset: 0x70 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET0;                     /**< DCP work packet 0 status register, offset: 0x80 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET1;                     /**< DCP work packet 1 status register, offset: 0x90 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET2;                     /**< DCP work packet 2 status register, offset: 0xA0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET3;                     /**< DCP work packet 3 status register, offset: 0xB0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET4;                     /**< DCP work packet 4 status register, offset: 0xC0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET5;                     /**< DCP work packet 5 status register, offset: 0xD0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t PACKET6;                     /**< DCP work packet 6 status register, offset: 0xE0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t CH0CMDPTR;                         /**< DCP channel 0 command pointer address register, offset: 0x100 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0SEMA;                           /**< DCP channel 0 semaphore register, offset: 0x110 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0STAT;                           /**< DCP channel 0 status register, offset: 0x120 */
  volatile uint32_t CH0STAT_SET;                       /**< DCP channel 0 status register, offset: 0x124 */
  volatile uint32_t CH0STAT_CLR;                       /**< DCP channel 0 status register, offset: 0x128 */
  volatile uint32_t CH0STAT_TOG;                       /**< DCP channel 0 status register, offset: 0x12C */
  volatile uint32_t CH0OPTS;                           /**< DCP channel 0 options register, offset: 0x130 */
  volatile uint32_t CH0OPTS_SET;                       /**< DCP channel 0 options register, offset: 0x134 */
  volatile uint32_t CH0OPTS_CLR;                       /**< DCP channel 0 options register, offset: 0x138 */
  volatile uint32_t CH0OPTS_TOG;                       /**< DCP channel 0 options register, offset: 0x13C */
  volatile uint32_t CH1CMDPTR;                         /**< DCP channel 1 command pointer address register, offset: 0x140 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1SEMA;                           /**< DCP channel 1 semaphore register, offset: 0x150 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1STAT;                           /**< DCP channel 1 status register, offset: 0x160 */
  volatile uint32_t CH1STAT_SET;                       /**< DCP channel 1 status register, offset: 0x164 */
  volatile uint32_t CH1STAT_CLR;                       /**< DCP channel 1 status register, offset: 0x168 */
  volatile uint32_t CH1STAT_TOG;                       /**< DCP channel 1 status register, offset: 0x16C */
  volatile uint32_t CH1OPTS;                           /**< DCP channel 1 options register, offset: 0x170 */
  volatile uint32_t CH1OPTS_SET;                       /**< DCP channel 1 options register, offset: 0x174 */
  volatile uint32_t CH1OPTS_CLR;                       /**< DCP channel 1 options register, offset: 0x178 */
  volatile uint32_t CH1OPTS_TOG;                       /**< DCP channel 1 options register, offset: 0x17C */
  volatile uint32_t CH2CMDPTR;                         /**< DCP channel 2 command pointer address register, offset: 0x180 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2SEMA;                           /**< DCP channel 2 semaphore register, offset: 0x190 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2STAT;                           /**< DCP channel 2 status register, offset: 0x1A0 */
  volatile uint32_t CH2STAT_SET;                       /**< DCP channel 2 status register, offset: 0x1A4 */
  volatile uint32_t CH2STAT_CLR;                       /**< DCP channel 2 status register, offset: 0x1A8 */
  volatile uint32_t CH2STAT_TOG;                       /**< DCP channel 2 status register, offset: 0x1AC */
  volatile uint32_t CH2OPTS;                           /**< DCP channel 2 options register, offset: 0x1B0 */
  volatile uint32_t CH2OPTS_SET;                       /**< DCP channel 2 options register, offset: 0x1B4 */
  volatile uint32_t CH2OPTS_CLR;                       /**< DCP channel 2 options register, offset: 0x1B8 */
  volatile uint32_t CH2OPTS_TOG;                       /**< DCP channel 2 options register, offset: 0x1BC */
  volatile uint32_t CH3CMDPTR;                         /**< DCP channel 3 command pointer address register, offset: 0x1C0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3SEMA;                           /**< DCP channel 3 semaphore register, offset: 0x1D0 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3STAT;                           /**< DCP channel 3 status register, offset: 0x1E0 */
  volatile uint32_t CH3STAT_SET;                       /**< DCP channel 3 status register, offset: 0x1E4 */
  volatile uint32_t CH3STAT_CLR;                       /**< DCP channel 3 status register, offset: 0x1E8 */
  volatile uint32_t CH3STAT_TOG;                       /**< DCP channel 3 status register, offset: 0x1EC */
  volatile uint32_t CH3OPTS;                           /**< DCP channel 3 options register, offset: 0x1F0 */
  volatile uint32_t CH3OPTS_SET;                       /**< DCP channel 3 options register, offset: 0x1F4 */
  volatile uint32_t CH3OPTS_CLR;                       /**< DCP channel 3 options register, offset: 0x1F8 */
  volatile uint32_t CH3OPTS_TOG;                       /**< DCP channel 3 options register, offset: 0x1FC */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[128];
  volatile uint32_t DBGSELECT;                         /**< DCP debug select register, offset: 0x400 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t DBGDATA;                     /**< DCP debug data register, offset: 0x410 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PAGETABLE;                         /**< DCP page table register, offset: 0x420 */
  uint32_t HARDWARE_REGS_LAYOUT_MEMBER_RESERVED[3];
  const volatile uint32_t VERSION;                     /**< DCP version register, offset: 0x430 */
};

constexpr size_t    kDCP_size = 0x434;
constexpr uintptr_t kDCP_base = 0x402FC000;

constexpr regs::RegGroup<DCP_Layout, kDCP_size, kDCP_base> DCP;

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DCP_Reg =
    regs::Reg32<kDCP_base, DCP_Layout, Member, 0, Bits, Shift, DirectAssign>;

// Undefine anything defined by Teensyduino's imxrt.h

// DCP control register 0
#undef DCP_CTRL_SFTRESET
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 31> DCP_CTRL_SFTRESET;
#undef DCP_CTRL_CLKGATE
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 30> DCP_CTRL_CLKGATE;
#undef DCP_CTRL_PRESENT_CRYPTO
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 29> DCP_CTRL_PRESENT_CRYPTO;
    // 0b0..Absent
    // 0b1..Present
#undef DCP_CTRL_PRESENT_SHA
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 28> DCP_CTRL_PRESENT_SHA;
    // 0b0..Absent
    // 0b1..Present
#undef DCP_CTRL_GATHER_RESIDUAL_WRITES
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 23> DCP_CTRL_GATHER_RESIDUAL_WRITES;
#undef DCP_CTRL_ENABLE_CONTEXT_CACHING
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 22> DCP_CTRL_ENABLE_CONTEXT_CACHING;
#undef DCP_CTRL_ENABLE_CONTEXT_SWITCHING
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 21> DCP_CTRL_ENABLE_CONTEXT_SWITCHING;
#undef DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL, 1,  8> DCP_CTRL_RSVD_CSC_INTERRUPT_ENABLE;
#undef DCP_CTRL_CHANNEL_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL, 8,  0> DCP_CTRL_CHANNEL_INTERRUPT_ENABLE;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3

// DCP control register 0
#undef DCP_CTRL_SET_SFTRESET
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 31, true> DCP_CTRL_SET_SFTRESET;
#undef DCP_CTRL_SET_CLKGATE
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 30, true> DCP_CTRL_SET_CLKGATE;
#undef DCP_CTRL_SET_PRESENT_CRYPTO
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 29, true> DCP_CTRL_SET_PRESENT_CRYPTO;
#undef DCP_CTRL_SET_PRESENT_SHA
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 28, true> DCP_CTRL_SET_PRESENT_SHA;
#undef DCP_CTRL_SET_GATHER_RESIDUAL_WRITES
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 23, true> DCP_CTRL_SET_GATHER_RESIDUAL_WRITES;
#undef DCP_CTRL_SET_ENABLE_CONTEXT_CACHING
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 22, true> DCP_CTRL_SET_ENABLE_CONTEXT_CACHING;
#undef DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 21, true> DCP_CTRL_SET_ENABLE_CONTEXT_SWITCHING;
#undef DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1,  8, true> DCP_CTRL_SET_RSVD_CSC_INTERRUPT_ENABLE;
#undef DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 8,  0, true> DCP_CTRL_SET_CHANNEL_INTERRUPT_ENABLE;

// DCP control register 0
#undef DCP_CTRL_CLR_SFTRESET
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 31, true> DCP_CTRL_CLR_SFTRESET;
#undef DCP_CTRL_CLR_CLKGATE
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 30, true> DCP_CTRL_CLR_CLKGATE;
#undef DCP_CTRL_CLR_PRESENT_CRYPTO
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 29, true> DCP_CTRL_CLR_PRESENT_CRYPTO;
#undef DCP_CTRL_CLR_PRESENT_SHA
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 28, true> DCP_CTRL_CLR_PRESENT_SHA;
#undef DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 23, true> DCP_CTRL_CLR_GATHER_RESIDUAL_WRITES;
#undef DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 22, true> DCP_CTRL_CLR_ENABLE_CONTEXT_CACHING;
#undef DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 21, true> DCP_CTRL_CLR_ENABLE_CONTEXT_SWITCHING;
#undef DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1,  8, true> DCP_CTRL_CLR_RSVD_CSC_INTERRUPT_ENABLE;
#undef DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 8,  0, true> DCP_CTRL_CLR_CHANNEL_INTERRUPT_ENABLE;

// DCP control register 0
#undef DCP_CTRL_TOG_SFTRESET
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 31, true> DCP_CTRL_TOG_SFTRESET;
#undef DCP_CTRL_TOG_CLKGATE
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 30, true> DCP_CTRL_TOG_CLKGATE;
#undef DCP_CTRL_TOG_PRESENT_CRYPTO
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 29, true> DCP_CTRL_TOG_PRESENT_CRYPTO;
#undef DCP_CTRL_TOG_PRESENT_SHA
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 28, true> DCP_CTRL_TOG_PRESENT_SHA;
#undef DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 23, true> DCP_CTRL_TOG_GATHER_RESIDUAL_WRITES;
#undef DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 22, true> DCP_CTRL_TOG_ENABLE_CONTEXT_CACHING;
#undef DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 21, true> DCP_CTRL_TOG_ENABLE_CONTEXT_SWITCHING;
#undef DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1,  8, true> DCP_CTRL_TOG_RSVD_CSC_INTERRUPT_ENABLE;
#undef DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 8,  0, true> DCP_CTRL_TOG_CHANNEL_INTERRUPT_ENABLE;

// DCP status register
#undef DCP_STAT_OTP_KEY_READY
constexpr DCP_Reg<&DCP_Layout::STAT, 1, 28> DCP_STAT_OTP_KEY_READY;
#undef DCP_STAT_CUR_CHANNEL
constexpr DCP_Reg<&DCP_Layout::STAT, 4, 24> DCP_STAT_CUR_CHANNEL;
    // None: 0, Channel: channel + 1:
    // 0b0000..None
    // 0b0001..CH0
    // 0b0010..CH1
    // 0b0011..CH2
    // 0b0100..CH3
#undef DCP_STAT_READY_CHANNELS
constexpr DCP_Reg<&DCP_Layout::STAT, 8, 16> DCP_STAT_READY_CHANNELS;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
#undef DCP_STAT_RSVD_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT, 1,  8> DCP_STAT_RSVD_IRQ;
#undef DCP_STAT_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT, 4,  0> DCP_STAT_IRQ;

// DCP status register
#undef DCP_STAT_SET_OTP_KEY_READY
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 1, 28, true> DCP_STAT_SET_OTP_KEY_READY;
#undef DCP_STAT_SET_CUR_CHANNEL
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 4, 24, true> DCP_STAT_SET_CUR_CHANNEL;
#undef DCP_STAT_SET_READY_CHANNELS
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 8, 16, true> DCP_STAT_SET_READY_CHANNELS;
#undef DCP_STAT_SET_RSVD_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 1,  8, true> DCP_STAT_SET_RSVD_IRQ;
#undef DCP_STAT_SET_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 4,  0, true> DCP_STAT_SET_IRQ;

// DCP status register
#undef DCP_STAT_CLR_OTP_KEY_READY
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 1, 28, true> DCP_STAT_CLR_OTP_KEY_READY;
#undef DCP_STAT_CLR_CUR_CHANNEL
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 4, 24, true> DCP_STAT_CLR_CUR_CHANNEL;
#undef DCP_STAT_CLR_READY_CHANNELS
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 8, 16, true> DCP_STAT_CLR_READY_CHANNELS;
#undef DCP_STAT_CLR_RSVD_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 1,  8, true> DCP_STAT_CLR_RSVD_IRQ;
#undef DCP_STAT_CLR_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 4,  0, true> DCP_STAT_CLR_IRQ;

// DCP status register
#undef DCP_STAT_TOG_OTP_KEY_READY
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 1, 28, true> DCP_STAT_TOG_OTP_KEY_READY;
#undef DCP_STAT_TOG_CUR_CHANNEL
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 4, 24, true> DCP_STAT_TOG_CUR_CHANNEL;
#undef DCP_STAT_TOG_READY_CHANNELS
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 8, 16, true> DCP_STAT_TOG_READY_CHANNELS;
#undef DCP_STAT_TOG_RSVD_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 1,  8, true> DCP_STAT_TOG_RSVD_IRQ;
#undef DCP_STAT_TOG_IRQ
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 4,  0, true> DCP_STAT_TOG_IRQ;

// DCP channel control register
#undef DCP_CHANNELCTRL_RSVD
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL, 15, 17> DCP_CHANNELCTRL_RSVD;
#undef DCP_CHANNELCTRL_CH0_IRQ_MERGED
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  1, 16> DCP_CHANNELCTRL_CH0_IRQ_MERGED;
#undef DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  8> DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
#undef DCP_CHANNELCTRL_ENABLE_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  0> DCP_CHANNELCTRL_ENABLE_CHANNEL;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3

// DCP channel control register
#undef DCP_CHANNELCTRL_SET_RSVD
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET, 15, 17, true> DCP_CHANNELCTRL_SET_RSVD;
#undef DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  1, 16, true> DCP_CHANNELCTRL_SET_CH0_IRQ_MERGED;
#undef DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  8, true> DCP_CHANNELCTRL_SET_HIGH_PRIORITY_CHANNEL;
#undef DCP_CHANNELCTRL_SET_ENABLE_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  0, true> DCP_CHANNELCTRL_SET_ENABLE_CHANNEL;

// DCP channel control register
#undef DCP_CHANNELCTRL_CLR_RSVD
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR, 15, 17, true> DCP_CHANNELCTRL_CLR_RSVD;
#undef DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  1, 16, true> DCP_CHANNELCTRL_CLR_CH0_IRQ_MERGED;
#undef DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  8, true> DCP_CHANNELCTRL_CLR_HIGH_PRIORITY_CHANNEL;
#undef DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  0, true> DCP_CHANNELCTRL_CLR_ENABLE_CHANNEL;

// DCP channel control register
#undef DCP_CHANNELCTRL_TOG_RSVD
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG, 15, 17, true> DCP_CHANNELCTRL_TOG_RSVD;
#undef DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  1, 16, true> DCP_CHANNELCTRL_TOG_CH0_IRQ_MERGED;
#undef DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  8, true> DCP_CHANNELCTRL_TOG_HIGH_PRIORITY_CHANNEL;
#undef DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  0, true> DCP_CHANNELCTRL_TOG_ENABLE_CHANNEL;

// DCP capability 0 register
#undef DCP_CAPABILITY0_DISABLE_DECRYPT
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 31> DCP_CAPABILITY0_DISABLE_DECRYPT;
#undef DCP_CAPABILITY0_DISABLE_UNIQUE_KEY
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 29> DCP_CAPABILITY0_DISABLE_UNIQUE_KEY;
#undef DCP_CAPABILITY0_RSVD
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0, 17, 12> DCP_CAPABILITY0_RSVD;
#undef DCP_CAPABILITY0_NUM_CHANNELS
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  4,  8> DCP_CAPABILITY0_NUM_CHANNELS;
#undef DCP_CAPABILITY0_NUM_KEYS
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  8,  0> DCP_CAPABILITY0_NUM_KEYS;

// DCP capability 1 register
#undef DCP_CAPABILITY1_HASH_ALGORITHMS
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16, 16> DCP_CAPABILITY1_HASH_ALGORITHMS;
    // 0b0000000000000001..SHA1
    // 0b0000000000000010..CRC32
    // 0b0000000000000100..SHA256
#undef DCP_CAPABILITY1_CIPHER_ALGORITHMS
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16,  0> DCP_CAPABILITY1_CIPHER_ALGORITHMS;
    // 0b0000000000000001..AES128

// DCP key index
#undef DCP_KEY_RSVD
constexpr DCP_Reg<&DCP_Layout::KEY, 24, 8> DCP_KEY_RSVD;
#undef DCP_KEY_RSVD_INDEX
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 6> DCP_KEY_RSVD_INDEX;
#undef DCP_KEY_INDEX
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 4> DCP_KEY_INDEX;
#undef DCP_KEY_RSVD_SUBWORD
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 2> DCP_KEY_RSVD_SUBWORD;
#undef DCP_KEY_SUBWORD
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 0> DCP_KEY_SUBWORD;

// DCP work packet 1 status register
#undef DCP_PACKET1_TAG
constexpr DCP_Reg<&DCP_Layout::PACKET1, 8, 24> DCP_PACKET1_TAG;
#undef DCP_PACKET1_SWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 6, 18> DCP_PACKET1_SWAP;  // Alias for 6 fields
#undef DCP_PACKET1_OUTPUT_WORDSWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 23> DCP_PACKET1_OUTPUT_WORDSWAP;
#undef DCP_PACKET1_OUTPUT_BYTESWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 22> DCP_PACKET1_OUTPUT_BYTESWAP;
#undef DCP_PACKET1_INPUT_WORDSWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 21> DCP_PACKET1_INPUT_WORDSWAP;
#undef DCP_PACKET1_INPUT_BYTESWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 20> DCP_PACKET1_INPUT_BYTESWAP;
#undef DCP_PACKET1_KEY_WORDSWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 19> DCP_PACKET1_KEY_WORDSWAP;
#undef DCP_PACKET1_KEY_BYTESWAP
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 18> DCP_PACKET1_KEY_BYTESWAP;
#undef DCP_PACKET1_TEST_SEMA_IRQ
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 17> DCP_PACKET1_TEST_SEMA_IRQ;
#undef DCP_PACKET1_CONSTANT_FILL
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 16> DCP_PACKET1_CONSTANT_FILL;
#undef DCP_PACKET1_HASH_OUTPUT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 15> DCP_PACKET1_HASH_OUTPUT;
    // 0b0..INPUT
    // 0b1..OUTPUT
#undef DCP_PACKET1_CHECK_HASH
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 14> DCP_PACKET1_CHECK_HASH;
#undef DCP_PACKET1_HASH_TERM
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 13> DCP_PACKET1_HASH_TERM;
#undef DCP_PACKET1_HASH_INIT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 12> DCP_PACKET1_HASH_INIT;
#undef DCP_PACKET1_PAYLOAD_KEY
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 11> DCP_PACKET1_PAYLOAD_KEY;
#undef DCP_PACKET1_OTP_KEY
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 10> DCP_PACKET1_OTP_KEY;
#undef DCP_PACKET1_CIPHER_INIT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  9> DCP_PACKET1_CIPHER_INIT;
#undef DCP_PACKET1_CIPHER_ENCRYPT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  8> DCP_PACKET1_CIPHER_ENCRYPT;
    // 0b0..DECRYPT
    // 0b1..ENCRYPT
#undef DCP_PACKET1_ENABLE_BLIT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  7> DCP_PACKET1_ENABLE_BLIT;
#undef DCP_PACKET1_ENABLE_HASH
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  6> DCP_PACKET1_ENABLE_HASH;
#undef DCP_PACKET1_ENABLE_CIPHER
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  5> DCP_PACKET1_ENABLE_CIPHER;
#undef DCP_PACKET1_ENABLE_MEMCOPY
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  4> DCP_PACKET1_ENABLE_MEMCOPY;
#undef DCP_PACKET1_CHAIN_CONTIGUOUS
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  3> DCP_PACKET1_CHAIN_CONTIGUOUS;
#undef DCP_PACKET1_CHAIN
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  2> DCP_PACKET1_CHAIN;
#undef DCP_PACKET1_DECR_SEMAPHORE
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  1> DCP_PACKET1_DECR_SEMAPHORE;
#undef DCP_PACKET1_INTERRUPT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  0> DCP_PACKET1_INTERRUPT;

// DCP work packet 2 status register
#undef DCP_PACKET2_CIPHER_CFG
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8, 24> DCP_PACKET2_CIPHER_CFG;
#undef DCP_PACKET2_RSVD
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 20> DCP_PACKET2_RSVD;
#undef DCP_PACKET2_HASH_SELECT
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 16> DCP_PACKET2_HASH_SELECT;
    // 0b0000..SHA1
    // 0b0001..CRC32
    // 0b0010..SHA256
#undef DCP_PACKET2_KEY_SELECT
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8,  8> DCP_PACKET2_KEY_SELECT;
    // 0b00000000..KEY0
    // 0b00000001..KEY1
    // 0b00000010..KEY2
    // 0b00000011..KEY3
    // 0b11111110..UNIQUE_KEY
    // 0b11111111..OTP_KEY
#undef DCP_PACKET2_CIPHER_MODE
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  4> DCP_PACKET2_CIPHER_MODE;
    // 0b0000..ECB
    // 0b0001..CBC
#undef DCP_PACKET2_CIPHER_SELECT
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  0> DCP_PACKET2_CIPHER_SELECT;
    // 0b0000..AES128

// DCP channel 0 semaphore register
#undef DCP_CH0SEMA_VALUE
constexpr DCP_Reg<&DCP_Layout::CH0SEMA, 8, 16> DCP_CH0SEMA_VALUE;
#undef DCP_CH0SEMA_INCREMENT
constexpr DCP_Reg<&DCP_Layout::CH0SEMA, 8,  0> DCP_CH0SEMA_INCREMENT;

// DCP channel 0 status register
#undef DCP_CH0STAT_TAG
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 8, 24> DCP_CH0STAT_TAG;
#undef DCP_CH0STAT_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 8, 16> DCP_CH0STAT_ERROR_CODE;
    // 0b00000001..Error signalled because the next pointer is 0x00000000
    // 0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
    // 0b00000011..Error signalled because an error is reported reading/writing the context buffer
    // 0b00000100..Error signalled because an error is reported reading/writing the payload
    // 0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
#undef DCP_CH0STAT_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  6> DCP_CH0STAT_ERROR_PAGEFAULT;
#undef DCP_CH0STAT_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  5> DCP_CH0STAT_ERROR_DST;
#undef DCP_CH0STAT_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  4> DCP_CH0STAT_ERROR_SRC;
#undef DCP_CH0STAT_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  3> DCP_CH0STAT_ERROR_PACKET;
#undef DCP_CH0STAT_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  2> DCP_CH0STAT_ERROR_SETUP;
#undef DCP_CH0STAT_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  1> DCP_CH0STAT_HASH_MISMATCH;
#undef DCP_CH0STAT_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  0> DCP_CH0STAT_RSVD_COMPLETE;

// DCP channel 0 status register
#undef DCP_CH0STAT_SET_TAG
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 8, 24, true> DCP_CH0STAT_SET_TAG;
#undef DCP_CH0STAT_SET_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 8, 16, true> DCP_CH0STAT_SET_ERROR_CODE;
#undef DCP_CH0STAT_SET_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  6, true> DCP_CH0STAT_SET_ERROR_PAGEFAULT;
#undef DCP_CH0STAT_SET_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  5, true> DCP_CH0STAT_SET_ERROR_DST;
#undef DCP_CH0STAT_SET_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  4, true> DCP_CH0STAT_SET_ERROR_SRC;
#undef DCP_CH0STAT_SET_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  3, true> DCP_CH0STAT_SET_ERROR_PACKET;
#undef DCP_CH0STAT_SET_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  2, true> DCP_CH0STAT_SET_ERROR_SETUP;
#undef DCP_CH0STAT_SET_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  1, true> DCP_CH0STAT_SET_HASH_MISMATCH;
#undef DCP_CH0STAT_SET_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  0, true> DCP_CH0STAT_SET_RSVD_COMPLETE;

// DCP channel 0 status register
#undef DCP_CH0STAT_CLR_TAG
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 8, 24, true> DCP_CH0STAT_CLR_TAG;
#undef DCP_CH0STAT_CLR_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 8, 16, true> DCP_CH0STAT_CLR_ERROR_CODE;
#undef DCP_CH0STAT_CLR_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  6, true> DCP_CH0STAT_CLR_ERROR_PAGEFAULT;
#undef DCP_CH0STAT_CLR_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  5, true> DCP_CH0STAT_CLR_ERROR_DST;
#undef DCP_CH0STAT_CLR_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  4, true> DCP_CH0STAT_CLR_ERROR_SRC;
#undef DCP_CH0STAT_CLR_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  3, true> DCP_CH0STAT_CLR_ERROR_PACKET;
#undef DCP_CH0STAT_CLR_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  2, true> DCP_CH0STAT_CLR_ERROR_SETUP;
#undef DCP_CH0STAT_CLR_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  1, true> DCP_CH0STAT_CLR_HASH_MISMATCH;
#undef DCP_CH0STAT_CLR_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  0, true> DCP_CH0STAT_CLR_RSVD_COMPLETE;

// DCP channel 0 status register
#undef DCP_CH0STAT_TOG_TAG
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 8, 24, true> DCP_CH0STAT_TOG_TAG;
#undef DCP_CH0STAT_TOG_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 8, 16, true> DCP_CH0STAT_TOG_ERROR_CODE;
#undef DCP_CH0STAT_TOG_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  6, true> DCP_CH0STAT_TOG_ERROR_PAGEFAULT;
#undef DCP_CH0STAT_TOG_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  5, true> DCP_CH0STAT_TOG_ERROR_DST;
#undef DCP_CH0STAT_TOG_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  4, true> DCP_CH0STAT_TOG_ERROR_SRC;
#undef DCP_CH0STAT_TOG_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  3, true> DCP_CH0STAT_TOG_ERROR_PACKET;
#undef DCP_CH0STAT_TOG_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  2, true> DCP_CH0STAT_TOG_ERROR_SETUP;
#undef DCP_CH0STAT_TOG_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  1, true> DCP_CH0STAT_TOG_HASH_MISMATCH;
#undef DCP_CH0STAT_TOG_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  0, true> DCP_CH0STAT_TOG_RSVD_COMPLETE;

// DCP channel 0 options register
#undef DCP_CH0OPTS_RSVD
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16, 16> DCP_CH0OPTS_RSVD;
#undef DCP_CH0OPTS_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16,  0> DCP_CH0OPTS_RECOVERY_TIMER;

// DCP channel 0 options register
#undef DCP_CH0OPTS_SET_RSVD
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16, 16, true> DCP_CH0OPTS_SET_RSVD;
#undef DCP_CH0OPTS_SET_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16,  0, true> DCP_CH0OPTS_SET_RECOVERY_TIMER;

// DCP channel 0 options register
#undef DCP_CH0OPTS_CLR_RSVD
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16, 16, true> DCP_CH0OPTS_CLR_RSVD;
#undef DCP_CH0OPTS_CLR_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16,  0, true> DCP_CH0OPTS_CLR_RECOVERY_TIMER;

// DCP channel 0 options register
#undef DCP_CH0OPTS_TOG_RSVD
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16, 16, true> DCP_CH0OPTS_TOG_RSVD;
#undef DCP_CH0OPTS_TOG_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16,  0, true> DCP_CH0OPTS_TOG_RECOVERY_TIMER;

// DCP channel 1 semaphore register
#undef DCP_CH1SEMA_VALUE
constexpr DCP_Reg<&DCP_Layout::CH1SEMA, 8, 16> DCP_CH1SEMA_VALUE;
#undef DCP_CH1SEMA_INCREMENT
constexpr DCP_Reg<&DCP_Layout::CH1SEMA, 8,  0> DCP_CH1SEMA_INCREMENT;

// DCP channel 1 status register
#undef DCP_CH1STAT_TAG
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 8, 24> DCP_CH1STAT_TAG;
#undef DCP_CH1STAT_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 8, 16> DCP_CH1STAT_ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported when reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
#undef DCP_CH1STAT_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  6> DCP_CH1STAT_ERROR_PAGEFAULT;
#undef DCP_CH1STAT_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  5> DCP_CH1STAT_ERROR_DST;
#undef DCP_CH1STAT_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  4> DCP_CH1STAT_ERROR_SRC;
#undef DCP_CH1STAT_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  3> DCP_CH1STAT_ERROR_PACKET;
#undef DCP_CH1STAT_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  2> DCP_CH1STAT_ERROR_SETUP;
#undef DCP_CH1STAT_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  1> DCP_CH1STAT_HASH_MISMATCH;
#undef DCP_CH1STAT_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  0> DCP_CH1STAT_RSVD_COMPLETE;

// DCP channel 1 status register
#undef DCP_CH1STAT_SET_TAG
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 8, 24, true> DCP_CH1STAT_SET_TAG;
#undef DCP_CH1STAT_SET_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 8, 16, true> DCP_CH1STAT_SET_ERROR_CODE;
#undef DCP_CH1STAT_SET_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  6, true> DCP_CH1STAT_SET_ERROR_PAGEFAULT;
#undef DCP_CH1STAT_SET_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  5, true> DCP_CH1STAT_SET_ERROR_DST;
#undef DCP_CH1STAT_SET_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  4, true> DCP_CH1STAT_SET_ERROR_SRC;
#undef DCP_CH1STAT_SET_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  3, true> DCP_CH1STAT_SET_ERROR_PACKET;
#undef DCP_CH1STAT_SET_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  2, true> DCP_CH1STAT_SET_ERROR_SETUP;
#undef DCP_CH1STAT_SET_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  1, true> DCP_CH1STAT_SET_HASH_MISMATCH;
#undef DCP_CH1STAT_SET_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  0, true> DCP_CH1STAT_SET_RSVD_COMPLETE;

// DCP channel 1 status register
#undef DCP_CH1STAT_CLR_TAG
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 8, 24, true> DCP_CH1STAT_CLR_TAG;
#undef DCP_CH1STAT_CLR_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 8, 16, true> DCP_CH1STAT_CLR_ERROR_CODE;
#undef DCP_CH1STAT_CLR_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  6, true> DCP_CH1STAT_CLR_ERROR_PAGEFAULT;
#undef DCP_CH1STAT_CLR_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  5, true> DCP_CH1STAT_CLR_ERROR_DST;
#undef DCP_CH1STAT_CLR_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  4, true> DCP_CH1STAT_CLR_ERROR_SRC;
#undef DCP_CH1STAT_CLR_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  3, true> DCP_CH1STAT_CLR_ERROR_PACKET;
#undef DCP_CH1STAT_CLR_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  2, true> DCP_CH1STAT_CLR_ERROR_SETUP;
#undef DCP_CH1STAT_CLR_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  1, true> DCP_CH1STAT_CLR_HASH_MISMATCH;
#undef DCP_CH1STAT_CLR_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  0, true> DCP_CH1STAT_CLR_RSVD_COMPLETE;

// DCP channel 1 status register
#undef DCP_CH1STAT_TOG_TAG
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 8, 24, true> DCP_CH1STAT_TOG_TAG;
#undef DCP_CH1STAT_TOG_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 8, 16, true> DCP_CH1STAT_TOG_ERROR_CODE;
#undef DCP_CH1STAT_TOG_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  6, true> DCP_CH1STAT_TOG_ERROR_PAGEFAULT;
#undef DCP_CH1STAT_TOG_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  5, true> DCP_CH1STAT_TOG_ERROR_DST;
#undef DCP_CH1STAT_TOG_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  4, true> DCP_CH1STAT_TOG_ERROR_SRC;
#undef DCP_CH1STAT_TOG_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  3, true> DCP_CH1STAT_TOG_ERROR_PACKET;
#undef DCP_CH1STAT_TOG_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  2, true> DCP_CH1STAT_TOG_ERROR_SETUP;
#undef DCP_CH1STAT_TOG_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  1, true> DCP_CH1STAT_TOG_HASH_MISMATCH;
#undef DCP_CH1STAT_TOG_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  0, true> DCP_CH1STAT_TOG_RSVD_COMPLETE;

// DCP channel 1 options register
#undef DCP_CH1OPTS_RSVD
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16, 16> DCP_CH1OPTS_RSVD;
#undef DCP_CH1OPTS_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16,  0> DCP_CH1OPTS_RECOVERY_TIMER;

// DCP channel 1 options register
#undef DCP_CH1OPTS_SET_RSVD
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16, 16, true> DCP_CH1OPTS_SET_RSVD;
#undef DCP_CH1OPTS_SET_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16,  0, true> DCP_CH1OPTS_SET_RECOVERY_TIMER;

// DCP channel 1 options register
#undef DCP_CH1OPTS_CLR_RSVD
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16, 16, true> DCP_CH1OPTS_CLR_RSVD;
#undef DCP_CH1OPTS_CLR_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16,  0, true> DCP_CH1OPTS_CLR_RECOVERY_TIMER;

// DCP channel 1 options register
#undef DCP_CH1OPTS_TOG_RSVD
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16, 16, true> DCP_CH1OPTS_TOG_RSVD;
#undef DCP_CH1OPTS_TOG_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16,  0, true> DCP_CH1OPTS_TOG_RECOVERY_TIMER;

// DCP channel 2 semaphore register
#undef DCP_CH2SEMA_VALUE
constexpr DCP_Reg<&DCP_Layout::CH2SEMA, 8, 16> DCP_CH2SEMA_VALUE;
#undef DCP_CH2SEMA_INCREMENT
constexpr DCP_Reg<&DCP_Layout::CH2SEMA, 8,  0> DCP_CH2SEMA_INCREMENT;

// DCP channel 2 status register
#undef DCP_CH2STAT_TAG
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 8, 24> DCP_CH2STAT_TAG;
#undef DCP_CH2STAT_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 8, 16> DCP_CH2STAT_ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
#undef DCP_CH2STAT_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  6> DCP_CH2STAT_ERROR_PAGEFAULT;
#undef DCP_CH2STAT_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  5> DCP_CH2STAT_ERROR_DST;
#undef DCP_CH2STAT_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  4> DCP_CH2STAT_ERROR_SRC;
#undef DCP_CH2STAT_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  3> DCP_CH2STAT_ERROR_PACKET;
#undef DCP_CH2STAT_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  2> DCP_CH2STAT_ERROR_SETUP;
#undef DCP_CH2STAT_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  1> DCP_CH2STAT_HASH_MISMATCH;
#undef DCP_CH2STAT_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  0> DCP_CH2STAT_RSVD_COMPLETE;

// DCP channel 2 status register
#undef DCP_CH2STAT_SET_TAG
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 8, 24, true> DCP_CH2STAT_SET_TAG;
#undef DCP_CH2STAT_SET_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 8, 16, true> DCP_CH2STAT_SET_ERROR_CODE;
#undef DCP_CH2STAT_SET_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  6, true> DCP_CH2STAT_SET_ERROR_PAGEFAULT;
#undef DCP_CH2STAT_SET_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  5, true> DCP_CH2STAT_SET_ERROR_DST;
#undef DCP_CH2STAT_SET_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  4, true> DCP_CH2STAT_SET_ERROR_SRC;
#undef DCP_CH2STAT_SET_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  3, true> DCP_CH2STAT_SET_ERROR_PACKET;
#undef DCP_CH2STAT_SET_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  2, true> DCP_CH2STAT_SET_ERROR_SETUP;
#undef DCP_CH2STAT_SET_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  1, true> DCP_CH2STAT_SET_HASH_MISMATCH;
#undef DCP_CH2STAT_SET_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  0, true> DCP_CH2STAT_SET_RSVD_COMPLETE;

// DCP channel 2 status register
#undef DCP_CH2STAT_CLR_TAG
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 8, 24, true> DCP_CH2STAT_CLR_TAG;
#undef DCP_CH2STAT_CLR_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 8, 16, true> DCP_CH2STAT_CLR_ERROR_CODE;
#undef DCP_CH2STAT_CLR_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  6, true> DCP_CH2STAT_CLR_ERROR_PAGEFAULT;
#undef DCP_CH2STAT_CLR_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  5, true> DCP_CH2STAT_CLR_ERROR_DST;
#undef DCP_CH2STAT_CLR_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  4, true> DCP_CH2STAT_CLR_ERROR_SRC;
#undef DCP_CH2STAT_CLR_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  3, true> DCP_CH2STAT_CLR_ERROR_PACKET;
#undef DCP_CH2STAT_CLR_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  2, true> DCP_CH2STAT_CLR_ERROR_SETUP;
#undef DCP_CH2STAT_CLR_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  1, true> DCP_CH2STAT_CLR_HASH_MISMATCH;
#undef DCP_CH2STAT_CLR_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  0, true> DCP_CH2STAT_CLR_RSVD_COMPLETE;

// DCP channel 2 status register
#undef DCP_CH2STAT_TOG_TAG
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 8, 24, true> DCP_CH2STAT_TOG_TAG;
#undef DCP_CH2STAT_TOG_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 8, 16, true> DCP_CH2STAT_TOG_ERROR_CODE;
#undef DCP_CH2STAT_TOG_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  6, true> DCP_CH2STAT_TOG_ERROR_PAGEFAULT;
#undef DCP_CH2STAT_TOG_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  5, true> DCP_CH2STAT_TOG_ERROR_DST;
#undef DCP_CH2STAT_TOG_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  4, true> DCP_CH2STAT_TOG_ERROR_SRC;
#undef DCP_CH2STAT_TOG_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  3, true> DCP_CH2STAT_TOG_ERROR_PACKET;
#undef DCP_CH2STAT_TOG_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  2, true> DCP_CH2STAT_TOG_ERROR_SETUP;
#undef DCP_CH2STAT_TOG_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  1, true> DCP_CH2STAT_TOG_HASH_MISMATCH;
#undef DCP_CH2STAT_TOG_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  0, true> DCP_CH2STAT_TOG_RSVD_COMPLETE;

// DCP channel 2 options register
#undef DCP_CH2OPTS_RSVD
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16, 16> DCP_CH2OPTS_RSVD;
#undef DCP_CH2OPTS_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16,  0> DCP_CH2OPTS_RECOVERY_TIMER;

// DCP channel 2 options register
#undef DCP_CH2OPTS_SET_RSVD
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16, 16, true> DCP_CH2OPTS_SET_RSVD;
#undef DCP_CH2OPTS_SET_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16,  0, true> DCP_CH2OPTS_SET_RECOVERY_TIMER;

// DCP channel 2 options register
#undef DCP_CH2OPTS_CLR_RSVD
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16, 16, true> DCP_CH2OPTS_CLR_RSVD;
#undef DCP_CH2OPTS_CLR_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16,  0, true> DCP_CH2OPTS_CLR_RECOVERY_TIMER;

// DCP channel 2 options register
#undef DCP_CH2OPTS_TOG_RSVD
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16, 16, true> DCP_CH2OPTS_TOG_RSVD;
#undef DCP_CH2OPTS_TOG_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16,  0, true> DCP_CH2OPTS_TOG_RECOVERY_TIMER;

// DCP channel 3 semaphore register
#undef DCP_CH3SEMA_VALUE
constexpr DCP_Reg<&DCP_Layout::CH3SEMA, 8, 16> DCP_CH3SEMA_VALUE;
#undef DCP_CH3SEMA_INCREMENT
constexpr DCP_Reg<&DCP_Layout::CH3SEMA, 8,  0> DCP_CH3SEMA_INCREMENT;

// DCP channel 3 status register
#undef DCP_CH3STAT_TAG
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 8, 24> DCP_CH3STAT_TAG;
#undef DCP_CH3STAT_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 8, 16> DCP_CH3STAT_ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
#undef DCP_CH3STAT_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  6> DCP_CH3STAT_ERROR_PAGEFAULT;
#undef DCP_CH3STAT_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  5> DCP_CH3STAT_ERROR_DST;
#undef DCP_CH3STAT_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  4> DCP_CH3STAT_ERROR_SRC;
#undef DCP_CH3STAT_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  3> DCP_CH3STAT_ERROR_PACKET;
#undef DCP_CH3STAT_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  2> DCP_CH3STAT_ERROR_SETUP;
#undef DCP_CH3STAT_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  1> DCP_CH3STAT_HASH_MISMATCH;
#undef DCP_CH3STAT_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  0> DCP_CH3STAT_RSVD_COMPLETE;

// DCP channel 3 status register
#undef DCP_CH3STAT_SET_TAG
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 8, 24, true> DCP_CH3STAT_SET_TAG;
#undef DCP_CH3STAT_SET_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 8, 16, true> DCP_CH3STAT_SET_ERROR_CODE;
#undef DCP_CH3STAT_SET_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  6, true> DCP_CH3STAT_SET_ERROR_PAGEFAULT;
#undef DCP_CH3STAT_SET_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  5, true> DCP_CH3STAT_SET_ERROR_DST;
#undef DCP_CH3STAT_SET_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  4, true> DCP_CH3STAT_SET_ERROR_SRC;
#undef DCP_CH3STAT_SET_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  3, true> DCP_CH3STAT_SET_ERROR_PACKET;
#undef DCP_CH3STAT_SET_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  2, true> DCP_CH3STAT_SET_ERROR_SETUP;
#undef DCP_CH3STAT_SET_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  1, true> DCP_CH3STAT_SET_HASH_MISMATCH;
#undef DCP_CH3STAT_SET_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  0, true> DCP_CH3STAT_SET_RSVD_COMPLETE;

// DCP channel 3 status register
#undef DCP_CH3STAT_CLR_TAG
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 8, 24, true> DCP_CH3STAT_CLR_TAG;
#undef DCP_CH3STAT_CLR_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 8, 16, true> DCP_CH3STAT_CLR_ERROR_CODE;
#undef DCP_CH3STAT_CLR_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  6, true> DCP_CH3STAT_CLR_ERROR_PAGEFAULT;
#undef DCP_CH3STAT_CLR_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  5, true> DCP_CH3STAT_CLR_ERROR_DST;
#undef DCP_CH3STAT_CLR_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  4, true> DCP_CH3STAT_CLR_ERROR_SRC;
#undef DCP_CH3STAT_CLR_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  3, true> DCP_CH3STAT_CLR_ERROR_PACKET;
#undef DCP_CH3STAT_CLR_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  2, true> DCP_CH3STAT_CLR_ERROR_SETUP;
#undef DCP_CH3STAT_CLR_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  1, true> DCP_CH3STAT_CLR_HASH_MISMATCH;
#undef DCP_CH3STAT_CLR_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  0, true> DCP_CH3STAT_CLR_RSVD_COMPLETE;

// DCP channel 3 status register
#undef DCP_CH3STAT_TOG_TAG
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 8, 24, true> DCP_CH3STAT_TOG_TAG;
#undef DCP_CH3STAT_TOG_ERROR_CODE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 8, 16, true> DCP_CH3STAT_TOG_ERROR_CODE;
#undef DCP_CH3STAT_TOG_ERROR_PAGEFAULT
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  6, true> DCP_CH3STAT_TOG_ERROR_PAGEFAULT;
#undef DCP_CH3STAT_TOG_ERROR_DST
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  5, true> DCP_CH3STAT_TOG_ERROR_DST;
#undef DCP_CH3STAT_TOG_ERROR_SRC
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  4, true> DCP_CH3STAT_TOG_ERROR_SRC;
#undef DCP_CH3STAT_TOG_ERROR_PACKET
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  3, true> DCP_CH3STAT_TOG_ERROR_PACKET;
#undef DCP_CH3STAT_TOG_ERROR_SETUP
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  2, true> DCP_CH3STAT_TOG_ERROR_SETUP;
#undef DCP_CH3STAT_TOG_HASH_MISMATCH
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  1, true> DCP_CH3STAT_TOG_HASH_MISMATCH;
#undef DCP_CH3STAT_TOG_RSVD_COMPLETE
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  0, true> DCP_CH3STAT_TOG_RSVD_COMPLETE;

// DCP channel 3 options register
#undef DCP_CH3OPTS_RSVD
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16, 16> DCP_CH3OPTS_RSVD;
#undef DCP_CH3OPTS_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16,  0> DCP_CH3OPTS_RECOVERY_TIMER;

// DCP channel 3 options register
#undef DCP_CH3OPTS_SET_RSVD
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16, 16, true> DCP_CH3OPTS_SET_RSVD;
#undef DCP_CH3OPTS_SET_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16,  0, true> DCP_CH3OPTS_SET_RECOVERY_TIMER;

// DCP channel 3 options register
#undef DCP_CH3OPTS_CLR_RSVD
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16, 16, true> DCP_CH3OPTS_CLR_RSVD;
#undef DCP_CH3OPTS_CLR_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16,  0, true> DCP_CH3OPTS_CLR_RECOVERY_TIMER;

// DCP channel 3 options register
#undef DCP_CH3OPTS_TOG_RSVD
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16, 16, true> DCP_CH3OPTS_TOG_RSVD;
#undef DCP_CH3OPTS_TOG_RECOVERY_TIMER
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16,  0, true> DCP_CH3OPTS_TOG_RECOVERY_TIMER;

// DCP debug select register
#undef DCP_DBGSELECT_RSVD
constexpr DCP_Reg<&DCP_Layout::DBGSELECT, 24, 8> DCP_DBGSELECT_RSVD;
#undef DCP_DBGSELECT_INDEX
constexpr DCP_Reg<&DCP_Layout::DBGSELECT,  8, 0> DCP_DBGSELECT_INDEX;
    // 0b00000001..CONTROL
    // 0b00010000..OTPKEY0
    // 0b00010001..OTPKEY1
    // 0b00010010..OTPKEY2
    // 0b00010011..OTPKEY3

// DCP page table register
#undef DCP_PAGETABLE_BASE
constexpr DCP_Reg<&DCP_Layout::PAGETABLE, 30, 2> DCP_PAGETABLE_BASE;
#undef DCP_PAGETABLE_FLUSH
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 1> DCP_PAGETABLE_FLUSH;
#undef DCP_PAGETABLE_ENABLE
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 0> DCP_PAGETABLE_ENABLE;

// DCP version register
#undef DCP_VERSION_MAJOR
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 24> DCP_VERSION_MAJOR;
#undef DCP_VERSION_MINOR
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 16> DCP_VERSION_MINOR;
#undef DCP_VERSION_STEP
constexpr DCP_Reg<&DCP_Layout::VERSION, 16,  0> DCP_VERSION_STEP;

// DCP capability 1 register values
constexpr uint32_t kDCP_CAPABILITY1_CIPHER_ALGORITHMS_AES128 = 1;
constexpr uint32_t kDCP_CAPABILITY1_HASH_ALGORITHMS_SHA1     = 1;
constexpr uint32_t kDCP_CAPABILITY1_HASH_ALGORITHMS_CRC32    = 2;
constexpr uint32_t kDCP_CAPABILITY1_HASH_ALGORITHMS_SHA256   = 4;

// DCP work packet 2 status register values
constexpr uint32_t kDCP_PACKET2_CIPHER_SELECT_AES128  = 0;
constexpr uint32_t kDCP_PACKET2_CIPHER_MODE_ECB       = 0;
constexpr uint32_t kDCP_PACKET2_CIPHER_MODE_CBC       = 1;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY0       = 0;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY1       = 1;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY2       = 2;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY3       = 3;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_UNIQUE_KEY = 0xFE;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_OTP_KEY    = 0xFF;
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_SHA1      = 0;
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_CRC32     = 1;
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_SHA256    = 2;

// DCP debug select register values
constexpr uint32_t kDCP_DBGSELECT_INDEX_CONTROL = (1u << 0);
constexpr uint32_t kDCP_DBGSELECT_INDEX_OTPKEY0 = (1u << 4) + 0u;
constexpr uint32_t kDCP_DBGSELECT_INDEX_OTPKEY1 = (1u << 4) + 1u;
constexpr uint32_t kDCP_DBGSELECT_INDEX_OTPKEY2 = (1u << 4) + 2u;
constexpr uint32_t kDCP_DBGSELECT_INDEX_OTPKEY3 = (1u << 4) + 3u;

// DCP channel X register values
constexpr regs::RegValue32<8, 16> DCP_CHxSEMA_VALUE;
constexpr regs::RegValue32<8, 16> DCP_CHxSTAT_ERROR_CODE;

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
