// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DCP.h defines all the DCP registers.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "decept/regs/regs.h"

namespace decept {
namespace regs {

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
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t CAPABILITY1;             /**< DCP capability 1 register, offset: 0x40 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CONTEXT;                           /**< DCP context buffer pointer, offset: 0x50 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEY;                               /**< DCP key index, offset: 0x60 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEYDATA;                           /**< DCP key data, offset: 0x70 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET0;                 /**< DCP work packet 0 status register, offset: 0x80 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET1;                 /**< DCP work packet 1 status register, offset: 0x90 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET2;                 /**< DCP work packet 2 status register, offset: 0xA0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET3;                 /**< DCP work packet 3 status register, offset: 0xB0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET4;                 /**< DCP work packet 4 status register, offset: 0xC0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET5;                 /**< DCP work packet 5 status register, offset: 0xD0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t PACKET6;                 /**< DCP work packet 6 status register, offset: 0xE0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t CH0CMDPTR;                         /**< DCP channel 0 command pointer address register, offset: 0x100 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0SEMA;                           /**< DCP channel 0 semaphore register, offset: 0x110 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0STAT;                           /**< DCP channel 0 status register, offset: 0x120 */
  volatile uint32_t CH0STAT_SET;                       /**< DCP channel 0 status register, offset: 0x124 */
  volatile uint32_t CH0STAT_CLR;                       /**< DCP channel 0 status register, offset: 0x128 */
  volatile uint32_t CH0STAT_TOG;                       /**< DCP channel 0 status register, offset: 0x12C */
  volatile uint32_t CH0OPTS;                           /**< DCP channel 0 options register, offset: 0x130 */
  volatile uint32_t CH0OPTS_SET;                       /**< DCP channel 0 options register, offset: 0x134 */
  volatile uint32_t CH0OPTS_CLR;                       /**< DCP channel 0 options register, offset: 0x138 */
  volatile uint32_t CH0OPTS_TOG;                       /**< DCP channel 0 options register, offset: 0x13C */
  volatile uint32_t CH1CMDPTR;                         /**< DCP channel 1 command pointer address register, offset: 0x140 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1SEMA;                           /**< DCP channel 1 semaphore register, offset: 0x150 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1STAT;                           /**< DCP channel 1 status register, offset: 0x160 */
  volatile uint32_t CH1STAT_SET;                       /**< DCP channel 1 status register, offset: 0x164 */
  volatile uint32_t CH1STAT_CLR;                       /**< DCP channel 1 status register, offset: 0x168 */
  volatile uint32_t CH1STAT_TOG;                       /**< DCP channel 1 status register, offset: 0x16C */
  volatile uint32_t CH1OPTS;                           /**< DCP channel 1 options register, offset: 0x170 */
  volatile uint32_t CH1OPTS_SET;                       /**< DCP channel 1 options register, offset: 0x174 */
  volatile uint32_t CH1OPTS_CLR;                       /**< DCP channel 1 options register, offset: 0x178 */
  volatile uint32_t CH1OPTS_TOG;                       /**< DCP channel 1 options register, offset: 0x17C */
  volatile uint32_t CH2CMDPTR;                         /**< DCP channel 2 command pointer address register, offset: 0x180 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2SEMA;                           /**< DCP channel 2 semaphore register, offset: 0x190 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2STAT;                           /**< DCP channel 2 status register, offset: 0x1A0 */
  volatile uint32_t CH2STAT_SET;                       /**< DCP channel 2 status register, offset: 0x1A4 */
  volatile uint32_t CH2STAT_CLR;                       /**< DCP channel 2 status register, offset: 0x1A8 */
  volatile uint32_t CH2STAT_TOG;                       /**< DCP channel 2 status register, offset: 0x1AC */
  volatile uint32_t CH2OPTS;                           /**< DCP channel 2 options register, offset: 0x1B0 */
  volatile uint32_t CH2OPTS_SET;                       /**< DCP channel 2 options register, offset: 0x1B4 */
  volatile uint32_t CH2OPTS_CLR;                       /**< DCP channel 2 options register, offset: 0x1B8 */
  volatile uint32_t CH2OPTS_TOG;                       /**< DCP channel 2 options register, offset: 0x1BC */
  volatile uint32_t CH3CMDPTR;                         /**< DCP channel 3 command pointer address register, offset: 0x1C0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3SEMA;                           /**< DCP channel 3 semaphore register, offset: 0x1D0 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3STAT;                           /**< DCP channel 3 status register, offset: 0x1E0 */
  volatile uint32_t CH3STAT_SET;                       /**< DCP channel 3 status register, offset: 0x1E4 */
  volatile uint32_t CH3STAT_CLR;                       /**< DCP channel 3 status register, offset: 0x1E8 */
  volatile uint32_t CH3STAT_TOG;                       /**< DCP channel 3 status register, offset: 0x1EC */
  volatile uint32_t CH3OPTS;                           /**< DCP channel 3 options register, offset: 0x1F0 */
  volatile uint32_t CH3OPTS_SET;                       /**< DCP channel 3 options register, offset: 0x1F4 */
  volatile uint32_t CH3OPTS_CLR;                       /**< DCP channel 3 options register, offset: 0x1F8 */
  volatile uint32_t CH3OPTS_TOG;                       /**< DCP channel 3 options register, offset: 0x1FC */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[128];
  volatile uint32_t DBGSELECT;                         /**< DCP debug select register, offset: 0x400 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t DBGDATA;                 /**< DCP debug data register, offset: 0x410 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PAGETABLE;                         /**< DCP page table register, offset: 0x420 */
  uint32_t DECEPT_REGS_LAYOUT_MEMBER_RESERVED[3];
  /*const*/ volatile uint32_t VERSION;                 /**< DCP version register, offset: 0x430 */
};

constexpr size_t    kDCP_size = 0x434;
constexpr uintptr_t kDCP_base = 0x402FC000;

constexpr RegGroup<DCP_Layout, kDCP_size, kDCP_base> DCP;

#define DECEPT_REGS_DCP_MEMBER(member) \
  (decept::regs::kDCP_base + offsetof(decept::regs::DCP_Layout, member))

// DCP control register 0
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 8,  0> DCP_CTRL_CHANNEL_INTERRUPT_ENABLE;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 21> DCP_CTRL_ENABLE_CONTEXT_SWITCHING;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 22> DCP_CTRL_ENABLE_CONTEXT_CACHING;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 23> DCP_CTRL_GATHER_RESIDUAL_WRITES;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 28> DCP_CTRL_PRESENT_SHA;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 29> DCP_CTRL_PRESENT_CRYPTO;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 30> DCP_CTRL_CLKGATE;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CTRL), 1, 31> DCP_CTRL_SFTRESET;

// DCP status register
constexpr Reg<DECEPT_REGS_DCP_MEMBER(STAT), 1, 28> DCP_STAT_OTP_KEY_READY;

// DCP channel control register
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CHANNELCTRL),  8,  0> DCP_CHANNELCTRL_ENABLE_CHANNEL;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(CHANNELCTRL), 15, 17> DCP_CHANNELCTRL_RSVD;

// DCP key index
constexpr Reg<DECEPT_REGS_DCP_MEMBER(KEY), 2, 0> DCP_KEY_SUBWORD;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(KEY), 2, 4> DCP_KEY_INDEX;

// DCP work packet 1 status register
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1,  1> DCP_PACKET1_DECR_SEMAPHORE;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1,  5> DCP_PACKET1_ENABLE_CIPHER;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1,  6> DCP_PACKET1_ENABLE_HASH;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1,  8> DCP_PACKET1_CIPHER_ENCRYPT;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1,  9> DCP_PACKET1_CIPHER_INIT;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1, 10> DCP_PACKET1_OTP_KEY;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1, 11> DCP_PACKET1_PAYLOAD_KEY;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1, 12> DCP_PACKET1_HASH_INIT;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 1, 13> DCP_PACKET1_HASH_TERM;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET1), 6, 18> DCP_PACKET1_SWAP;

// DCP work packet 2 status register
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET2), 4,  0> DCP_PACKET2_CIPHER_SELECT;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET2), 4,  4> DCP_PACKET2_CIPHER_MODE;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET2), 8,  8> DCP_PACKET2_KEY_SELECT;
constexpr Reg<DECEPT_REGS_DCP_MEMBER(PACKET2), 4, 16> DCP_PACKET2_HASH_SELECT;

// DCP work packet 2 status register cipher values
constexpr uint32_t kDCP_PACKET2_CIPHER_SELECT_AES128  = 0;
constexpr uint32_t kDCP_PACKET2_CIPHER_MODE_ECB       = 0;
constexpr uint32_t kDCP_PACKET2_CIPHER_MODE_CBC       = 1;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY0       = 0;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY1       = 1;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY2       = 2;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_KEY3       = 3;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_UNIQUE_KEY = 0xFE;
constexpr uint32_t kDCP_PACKET2_KEY_SELECT_OTP_KEY    = 0xFF;

// DCP work packet 2 status register hash values
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_SHA256 = 2;
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_SHA1   = 0;
constexpr uint32_t kDCP_PACKET2_HASH_SELECT_CRC32  = 1;

// DCP channel X registers

constexpr RegValue<8, 16> DCP_CHxSEMA_VALUE;
constexpr RegValue<8, 16> DCP_CHxSTAT_ERROR_CODE;

}  // namespace regs
}  // namespace decept
