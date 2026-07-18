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

namespace DCP {
constexpr regs::RegGroup<DCP_Layout, kDCP_size, kDCP_base> group;
}  // namespace DCP

template <auto Member, size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
using DCP_Reg =
    regs::Reg32<kDCP_base, DCP_Layout, Member, 0, Bits, Shift, DirectAssign>;

namespace DCP {

// DCP control register 0
namespace CTRL {
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 31> SFTRESET;
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 30> CLKGATE;
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 29> PRESENT_CRYPTO;
    // 0b0..Absent
    // 0b1..Present
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 28> PRESENT_SHA;
    // 0b0..Absent
    // 0b1..Present
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 23> GATHER_RESIDUAL_WRITES;
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 22> ENABLE_CONTEXT_CACHING;
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 21> ENABLE_CONTEXT_SWITCHING;
constexpr DCP_Reg<&DCP_Layout::CTRL, 1,  8> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL, 8,  0> CHANNEL_INTERRUPT_ENABLE;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
}  // namespace CTRL

// DCP control register 0
namespace CTRL_SET {
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 31, true> SFTRESET;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 30, true> CLKGATE;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 29, true> PRESENT_CRYPTO;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 28, true> PRESENT_SHA;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 23, true> GATHER_RESIDUAL_WRITES;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 22, true> ENABLE_CONTEXT_CACHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 21, true> ENABLE_CONTEXT_SWITCHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1,  8, true> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 8,  0, true> CHANNEL_INTERRUPT_ENABLE;
}  // namespace CTRL_SET

// DCP control register 0
namespace CTRL_CLR {
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 31, true> SFTRESET;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 30, true> CLKGATE;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 29, true> PRESENT_CRYPTO;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 28, true> PRESENT_SHA;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 23, true> GATHER_RESIDUAL_WRITES;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 22, true> ENABLE_CONTEXT_CACHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 21, true> ENABLE_CONTEXT_SWITCHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1,  8, true> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 8,  0, true> CHANNEL_INTERRUPT_ENABLE;
}  // namespace CTRL_CLR

// DCP control register 0
namespace CTRL_TOG {
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 31, true> SFTRESET;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 30, true> CLKGATE;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 29, true> PRESENT_CRYPTO;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 28, true> PRESENT_SHA;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 23, true> GATHER_RESIDUAL_WRITES;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 22, true> ENABLE_CONTEXT_CACHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 21, true> ENABLE_CONTEXT_SWITCHING;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1,  8, true> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 8,  0, true> CHANNEL_INTERRUPT_ENABLE;
}  // namespace CTRL_TOG

// DCP status register
namespace STAT {
constexpr DCP_Reg<&DCP_Layout::STAT, 1, 28> OTP_KEY_READY;
constexpr DCP_Reg<&DCP_Layout::STAT, 4, 24> CUR_CHANNEL;
    // None: 0, Channel: channel + 1:
    // 0b0000..None
    // 0b0001..CH0
    // 0b0010..CH1
    // 0b0011..CH2
    // 0b0100..CH3
constexpr DCP_Reg<&DCP_Layout::STAT, 8, 16> READY_CHANNELS;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
constexpr DCP_Reg<&DCP_Layout::STAT, 1,  8> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT, 4,  0> IRQ;
}  // namespace STAT

// DCP status register
namespace STAT_SET {
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 1, 28, true> OTP_KEY_READY;
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 4, 24, true> CUR_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 8, 16, true> READY_CHANNELS;
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 1,  8, true> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 4,  0, true> IRQ;
}  // namespace STAT_SET

// DCP status register
namespace STAT_CLR {
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 1, 28, true> OTP_KEY_READY;
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 4, 24, true> CUR_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 8, 16, true> READY_CHANNELS;
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 1,  8, true> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 4,  0, true> IRQ;
}  // namespace STAT_CLR

// DCP status register
namespace STAT_TOG {
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 1, 28, true> OTP_KEY_READY;
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 4, 24, true> CUR_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 8, 16, true> READY_CHANNELS;
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 1,  8, true> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 4,  0, true> IRQ;
}  // namespace STAT_TOG

// DCP channel control register
namespace CHANNELCTRL {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL, 15, 17> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  1, 16> CH0_IRQ_MERGED;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  8> HIGH_PRIORITY_CHANNEL;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  0> ENABLE_CHANNEL;
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
}  // namespace CHANNELCTRL

// DCP channel control register
namespace CHANNELCTRL_SET {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET, 15, 17, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  1, 16, true> CH0_IRQ_MERGED;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  8, true> HIGH_PRIORITY_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  0, true> ENABLE_CHANNEL;
}  // namespace CHANNELCTRL_SET

// DCP channel control register
namespace CHANNELCTRL_CLR {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR, 15, 17, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  1, 16, true> CH0_IRQ_MERGED;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  8, true> HIGH_PRIORITY_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  0, true> ENABLE_CHANNEL;
}  // namespace CHANNELCTRL_CLR

// DCP channel control register
namespace CHANNELCTRL_TOG {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG, 15, 17, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  1, 16, true> CH0_IRQ_MERGED;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  8, true> HIGH_PRIORITY_CHANNEL;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  0, true> ENABLE_CHANNEL;
}  // namespace CHANNELCTRL_TOG

// DCP capability 0 register
namespace CAPABILITY0 {
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 31> DISABLE_DECRYPT;
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 29> DISABLE_UNIQUE_KEY;
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0, 17, 12> RSVD;
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  4,  8> NUM_CHANNELS;
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  8,  0> NUM_KEYS;
}  // namespace CAPABILITY0

// DCP capability 1 register
namespace CAPABILITY1 {
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16, 16> HASH_ALGORITHMS;
    // 0b0000000000000001..SHA1
    // 0b0000000000000010..CRC32
    // 0b0000000000000100..SHA256
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16,  0> CIPHER_ALGORITHMS;
    // 0b0000000000000001..AES128

// DCP capability 1 register values
constexpr uint32_t kCIPHER_ALGORITHMS_AES128 = 1;
constexpr uint32_t kHASH_ALGORITHMS_SHA1     = 1;
constexpr uint32_t kHASH_ALGORITHMS_CRC32    = 2;
constexpr uint32_t kHASH_ALGORITHMS_SHA256   = 4;
}  // namespace CAPABILITY1

// DCP key index
namespace KEY {
constexpr DCP_Reg<&DCP_Layout::KEY, 24, 8> RSVD;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 6> RSVD_INDEX;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 4> INDEX;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 2> RSVD_SUBWORD;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 0> SUBWORD;
}  // namespace KEY

// DCP work packet 1 status register
namespace PACKET1 {
constexpr DCP_Reg<&DCP_Layout::PACKET1, 8, 24> TAG;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 6, 18> SWAP;  // Alias for 6 fields
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 23> OUTPUT_WORDSWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 22> OUTPUT_BYTESWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 21> INPUT_WORDSWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 20> INPUT_BYTESWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 19> KEY_WORDSWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 18> KEY_BYTESWAP;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 17> TEST_SEMA_IRQ;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 16> CONSTANT_FILL;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 15> HASH_OUTPUT;
    // 0b0..INPUT
    // 0b1..OUTPUT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 14> CHECK_HASH;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 13> HASH_TERM;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 12> HASH_INIT;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 11> PAYLOAD_KEY;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 10> OTP_KEY;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  9> CIPHER_INIT;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  8> CIPHER_ENCRYPT;
    // 0b0..DECRYPT
    // 0b1..ENCRYPT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  7> ENABLE_BLIT;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  6> ENABLE_HASH;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  5> ENABLE_CIPHER;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  4> ENABLE_MEMCOPY;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  3> CHAIN_CONTIGUOUS;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  2> CHAIN;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  1> DECR_SEMAPHORE;
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  0> INTERRUPT;
}  // namespace PACKET1

// DCP work packet 2 status register
namespace PACKET2 {
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8, 24> CIPHER_CFG;
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 20> RSVD;
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 16> HASH_SELECT;
    // 0b0000..SHA1
    // 0b0001..CRC32
    // 0b0010..SHA256
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8,  8> KEY_SELECT;
    // 0b00000000..KEY0
    // 0b00000001..KEY1
    // 0b00000010..KEY2
    // 0b00000011..KEY3
    // 0b11111110..UNIQUE_KEY
    // 0b11111111..OTP_KEY
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  4> CIPHER_MODE;
    // 0b0000..ECB
    // 0b0001..CBC
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  0> CIPHER_SELECT;
    // 0b0000..AES128

// DCP work packet 2 status register values
constexpr uint32_t kCIPHER_SELECT_AES128  = 0;
constexpr uint32_t kCIPHER_MODE_ECB       = 0;
constexpr uint32_t kCIPHER_MODE_CBC       = 1;
constexpr uint32_t kKEY_SELECT_KEY0       = 0;
constexpr uint32_t kKEY_SELECT_KEY1       = 1;
constexpr uint32_t kKEY_SELECT_KEY2       = 2;
constexpr uint32_t kKEY_SELECT_KEY3       = 3;
constexpr uint32_t kKEY_SELECT_UNIQUE_KEY = 0xFE;
constexpr uint32_t kKEY_SELECT_OTP_KEY    = 0xFF;
constexpr uint32_t kHASH_SELECT_SHA1      = 0;
constexpr uint32_t kHASH_SELECT_CRC32     = 1;
constexpr uint32_t kHASH_SELECT_SHA256    = 2;
}  // namespace PACKET2

// DCP channel 0 semaphore register
namespace CH0SEMA {
constexpr DCP_Reg<&DCP_Layout::CH0SEMA, 8, 16> VALUE;
constexpr DCP_Reg<&DCP_Layout::CH0SEMA, 8,  0> INCREMENT;
}  // namespace CH0SEMA

// DCP channel 0 status register
namespace CH0STAT {
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 8, 24> TAG;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 8, 16> ERROR_CODE;
    // 0b00000001..Error signalled because the next pointer is 0x00000000
    // 0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
    // 0b00000011..Error signalled because an error is reported reading/writing the context buffer
    // 0b00000100..Error signalled because an error is reported reading/writing the payload
    // 0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  6> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  5> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  4> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  3> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  2> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  1> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH0STAT

// DCP channel 0 status register
namespace CH0STAT_SET {
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH0STAT_SET

// DCP channel 0 status register
namespace CH0STAT_CLR {
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH0STAT_CLR

// DCP channel 0 status register
namespace CH0STAT_TOG {
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH0STAT_TOG

// DCP channel 0 options register
namespace CH0OPTS {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16,  0> RECOVERY_TIMER;
}  // namespace CH0OPTS

// DCP channel 0 options register
namespace CH0OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH0OPTS_SET

// DCP channel 0 options register
namespace CH0OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH0OPTS_CLR

// DCP channel 0 options register
namespace CH0OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH0OPTS_TOG

// DCP channel 1 semaphore register
namespace CH1SEMA {
constexpr DCP_Reg<&DCP_Layout::CH1SEMA, 8, 16> VALUE;
constexpr DCP_Reg<&DCP_Layout::CH1SEMA, 8,  0> INCREMENT;
}  // namespace CH1SEMA

// DCP channel 1 status register
namespace CH1STAT {
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 8, 24> TAG;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 8, 16> ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported when reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  6> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  5> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  4> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  3> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  2> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  1> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH1STAT

// DCP channel 1 status register
namespace CH1STAT_SET {
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH1STAT_SET

// DCP channel 1 status register
namespace CH1STAT_CLR {
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH1STAT_CLR

// DCP channel 1 status register
namespace CH1STAT_TOG {
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH1STAT_TOG

// DCP channel 1 options register
namespace CH1OPTS {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16,  0> RECOVERY_TIMER;
}  // namespace CH1OPTS

// DCP channel 1 options register
namespace CH1OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH1OPTS_SET

// DCP channel 1 options register
namespace CH1OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH1OPTS_CLR

// DCP channel 1 options register
namespace CH1OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH1OPTS_TOG

// DCP channel 2 semaphore register
namespace CH2SEMA {
constexpr DCP_Reg<&DCP_Layout::CH2SEMA, 8, 16> VALUE;
constexpr DCP_Reg<&DCP_Layout::CH2SEMA, 8,  0> INCREMENT;
}  // namespace CH2SEMA

// DCP channel 2 status register
namespace CH2STAT {
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 8, 24> TAG;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 8, 16> ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  6> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  5> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  4> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  3> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  2> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  1> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH2STAT

// DCP channel 2 status register
namespace CH2STAT_SET {
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH2STAT_SET

// DCP channel 2 status register
namespace CH2STAT_CLR {
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH2STAT_CLR

// DCP channel 2 status register
namespace CH2STAT_TOG {
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH2STAT_TOG

// DCP channel 2 options register
namespace CH2OPTS {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16,  0> RECOVERY_TIMER;
}  // namespace CH2OPTS

// DCP channel 2 options register
namespace CH2OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH2OPTS_SET

// DCP channel 2 options register
namespace CH2OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH2OPTS_CLR

// DCP channel 2 options register
namespace CH2OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH2OPTS_TOG

// DCP channel 3 semaphore register
namespace CH3SEMA {
constexpr DCP_Reg<&DCP_Layout::CH3SEMA, 8, 16> VALUE;
constexpr DCP_Reg<&DCP_Layout::CH3SEMA, 8,  0> INCREMENT;
}  // namespace CH3SEMA

// DCP channel 3 status register
namespace CH3STAT {
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 8, 24> TAG;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 8, 16> ERROR_CODE;
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  6> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  5> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  4> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  3> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  2> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  1> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH3STAT

// DCP channel 3 status register
namespace CH3STAT_SET {
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH3STAT_SET

// DCP channel 3 status register
namespace CH3STAT_CLR {
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH3STAT_CLR

// DCP channel 3 status register
namespace CH3STAT_TOG {
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 8, 24, true> TAG;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 8, 16, true> ERROR_CODE;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  6, true> ERROR_PAGEFAULT;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  5, true> ERROR_DST;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  4, true> ERROR_SRC;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  3, true> ERROR_PACKET;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  2, true> ERROR_SETUP;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  1, true> HASH_MISMATCH;
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  0, true> RSVD_COMPLETE;
}  // namespace CH3STAT_TOG

// DCP channel 3 options register
namespace CH3OPTS {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16,  0> RECOVERY_TIMER;
}  // namespace CH3OPTS

// DCP channel 3 options register
namespace CH3OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH3OPTS_SET

// DCP channel 3 options register
namespace CH3OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH3OPTS_CLR

// DCP channel 3 options register
namespace CH3OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16, 16, true> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16,  0, true> RECOVERY_TIMER;
}  // namespace CH3OPTS_TOG

// DCP debug select register
namespace DBGSELECT {
constexpr DCP_Reg<&DCP_Layout::DBGSELECT, 24, 8> RSVD;
constexpr DCP_Reg<&DCP_Layout::DBGSELECT,  8, 0> INDEX;
    // 0b00000001..CONTROL
    // 0b00010000..OTPKEY0
    // 0b00010001..OTPKEY1
    // 0b00010010..OTPKEY2
    // 0b00010011..OTPKEY3

// DCP debug select register values
constexpr uint32_t kINDEX_CONTROL = (1u << 0);
constexpr uint32_t kINDEX_OTPKEY0 = (1u << 4) + 0u;
constexpr uint32_t kINDEX_OTPKEY1 = (1u << 4) + 1u;
constexpr uint32_t kINDEX_OTPKEY2 = (1u << 4) + 2u;
constexpr uint32_t kINDEX_OTPKEY3 = (1u << 4) + 3u;
}  // namespace DBGSELECT

// DCP page table register
namespace PAGETABLE {
constexpr DCP_Reg<&DCP_Layout::PAGETABLE, 30, 2> BASE;
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 1> FLUSH;
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 0> ENABLE;
}  // namespace PAGETABLE

// DCP version register
namespace VERSION {
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 24> MAJOR;
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 16> MINOR;
constexpr DCP_Reg<&DCP_Layout::VERSION, 16,  0> STEP;
}  // namespace VERSION

namespace CHxSEMA {
// DCP channel X register values
constexpr regs::RegValue32<8, 16> VALUE;
}  // namespace CHxSEMA

namespace CHxSTAT {
constexpr regs::RegValue32<8, 16> ERROR_CODE;
}  // namespace CHxSTAT

}  // namespace DCP

}  // namespace teensy4
}  // namespace hardware
}  // namespace qindesign
