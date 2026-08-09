// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// DCP.h defines all the DCP registers.
// This file is part of the imxrt1060-regs library.

#pragma once

#include <cstddef>
#include <cstdint>

#include "qindesign/hardware/regs/regs.h"

namespace qindesign {
namespace hardware {
namespace imxrt1060 {

// Structure type to access the DCP (DCP) registers.
//
// Comments are from BSD-3-licensed NXP SDK.
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
constexpr uintptr_t kDCP_base = 0x402F'C000;

namespace DCP {

constexpr regs::RegGroup<DCP_Layout, kDCP_size, kDCP_base> group;

template <auto Member, size_t Bits, unsigned int Shift,
          auto AssignMask = regs::shiftedMask32<Bits, Shift>()>
using DCP_Reg =
    regs::Reg32<kDCP_base, DCP_Layout, Member, 0, Bits, Shift, AssignMask>;

// DCP control register 0
namespace CTRL {
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 31> SFTRST;                          // Set this bit to zero to enable a normal DCP operation
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 30> CLKGATE;                         // This bit must be set to zero for a normal operation
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL), 1, 29> PRESENT_CRYPTO;  // Indicates whether the crypto (cipher/hash) functions are present.
    // 0b0..Absent
    // 0b1..Present
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL), 1, 28> PRESENT_SHA;     // Indicates whether the SHA1/SHA2 functions are present.
    // 0b0..Absent
    // 0b1..Present
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 23> GATHER_RESIDUAL_WRITES;          // The software must set this bit to enable the ragged writes to the unaligned buffers to be gathered between multiple write operations
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 22> ENABLE_CONTEXT_CACHING;          // The software must set this bit to enable the caching of contexts between the operations
constexpr DCP_Reg<&DCP_Layout::CTRL, 1, 21> ENABLE_CONTEXT_SWITCHING;        // Enable automatic context switching for the channels
constexpr DCP_Reg<&DCP_Layout::CTRL, 1,  8> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL, 8,  0> CHANNEL_INTERRUPT_ENABLE;        // Per-channel interrupt enable bit
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
}  // namespace CTRL

// DCP control register 0
namespace CTRL_SET {
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 31, 0x0> SFTRST;                     // Set this bit to zero to enable a normal DCP operation
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 30, 0x0> CLKGATE;                    // This bit must be set to zero for a normal operation
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_SET), 1, 29> PRESENT_CRYPTO;  // Indicates whether the crypto (cipher/hash) functions are present.
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_SET), 1, 28> PRESENT_SHA;     // Indicates whether the SHA1/SHA2 functions are present.
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 23, 0x0> GATHER_RESIDUAL_WRITES;     // The software must set this bit to enable the ragged writes to the unaligned buffers to be gathered between multiple write operations
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 22, 0x0> ENABLE_CONTEXT_CACHING;     // The software must set this bit to enable the caching of contexts between the operations
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1, 21, 0x0> ENABLE_CONTEXT_SWITCHING;   // Enable automatic context switching for the channels
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 1,  8, 0x0> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_SET, 8,  0, 0x0> CHANNEL_INTERRUPT_ENABLE;   // Per-channel interrupt enable bit
}  // namespace CTRL_SET

// DCP control register 0
namespace CTRL_CLR {
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 31, 0x0> SFTRST;                     // Set this bit to zero to enable a normal DCP operation
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 30, 0x0> CLKGATE;                    // This bit must be set to zero for a normal operation
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_CLR), 1, 29> PRESENT_CRYPTO;  // Indicates whether the crypto (cipher/hash) functions are present.
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_CLR), 1, 28> PRESENT_SHA;     // Indicates whether the SHA1/SHA2 functions are present.
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 23, 0x0> GATHER_RESIDUAL_WRITES;     // The software must set this bit to enable the ragged writes to the unaligned buffers to be gathered between multiple write operations
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 22, 0x0> ENABLE_CONTEXT_CACHING;     // The software must set this bit to enable the caching of contexts between the operations
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1, 21, 0x0> ENABLE_CONTEXT_SWITCHING;   // Enable automatic context switching for the channels
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 1,  8, 0x0> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_CLR, 8,  0, 0x0> CHANNEL_INTERRUPT_ENABLE;   // Per-channel interrupt enable bit
}  // namespace CTRL_CLR

// DCP control register 0
namespace CTRL_TOG {
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 31, 0x0> SFTRST;                     // Set this bit to zero to enable a normal DCP operation
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 30, 0x0> CLKGATE;                    // This bit must be set to zero for a normal operation
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_TOG), 1, 29> PRESENT_CRYPTO;  // Indicates whether the crypto (cipher/hash) functions are present.
constexpr DCP_Reg<regs::constify(&DCP_Layout::CTRL_TOG), 1, 28> PRESENT_SHA;     // Indicates whether the SHA1/SHA2 functions are present.
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 23, 0x0> GATHER_RESIDUAL_WRITES;     // The software must set this bit to enable the ragged writes to the unaligned buffers to be gathered between multiple write operations
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 22, 0x0> ENABLE_CONTEXT_CACHING;     // The software must set this bit to enable the caching of contexts between the operations
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1, 21, 0x0> ENABLE_CONTEXT_SWITCHING;   // Enable automatic context switching for the channels
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 1,  8, 0x0> RSVD_CSC_INTERRUPT_ENABLE;
constexpr DCP_Reg<&DCP_Layout::CTRL_TOG, 8,  0, 0x0> CHANNEL_INTERRUPT_ENABLE;   // Per-channel interrupt enable bit
}  // namespace CTRL_TOG

// DCP status register
namespace STAT {
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT), 1, 28> OTP_KEY_READY;   // When set, it indicates that the OTP key is shifted from the fuse block and is ready for use.
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT), 4, 24> CUR_CHANNEL;     // Current (active) channel (encoded)
    // None: 0, Channel: channel + 1:
    // 0b0000..None
    // 0b0001..CH0
    // 0b0010..CH1
    // 0b0011..CH2
    // 0b0100..CH3
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT), 8, 16> READY_CHANNELS;  // Indicates which channels are ready to proceed with a transfer (the active channel is also included)
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
constexpr DCP_Reg<&DCP_Layout::STAT, 1,  8> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT, 4,  0> IRQ;                             // Indicates which channels have pending interrupt requests
}  // namespace STAT

// DCP status register
namespace STAT_SET {
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_SET), 1, 28> OTP_KEY_READY;   // When set, it indicates that the OTP key is shifted from the fuse block and is ready for use.
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_SET), 4, 24> CUR_CHANNEL;     // Current (active) channel (encoded)
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_SET), 8, 16> READY_CHANNELS;  // Indicates which channels are ready to proceed with a transfer (the active channel is also included)
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 1,  8, 0x0> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_SET, 4,  0, 0x0> IRQ;                        // Indicates which channels have pending interrupt requests
}  // namespace STAT_SET

// DCP status register
namespace STAT_CLR {
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_CLR), 1, 28> OTP_KEY_READY;   // When set, it indicates that the OTP key is shifted from the fuse block and is ready for use.
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_CLR), 4, 24> CUR_CHANNEL;     // Current (active) channel (encoded)
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_CLR), 8, 16> READY_CHANNELS;  // Indicates which channels are ready to proceed with a transfer (the active channel is also included)
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 1,  8, 0x0> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_CLR, 4,  0, 0x0> IRQ;                        // Indicates which channels have pending interrupt requests
}  // namespace STAT_CLR

// DCP status register
namespace STAT_TOG {
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_TOG), 1, 28> OTP_KEY_READY;   // When set, it indicates that the OTP key is shifted from the fuse block and is ready for use.
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_TOG), 4, 24> CUR_CHANNEL;     // Current (active) channel (encoded)
constexpr DCP_Reg<regs::constify(&DCP_Layout::STAT_TOG), 8, 16> READY_CHANNELS;  // Indicates which channels are ready to proceed with a transfer (the active channel is also included)
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 1,  8, 0x0> RSVD_IRQ;
constexpr DCP_Reg<&DCP_Layout::STAT_TOG, 4,  0, 0x0> IRQ;                        // Indicates which channels have pending interrupt requests
}  // namespace STAT_TOG

// DCP channel control register
namespace CHANNELCTRL {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL, 15, 17> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  1, 16> CH0_IRQ_MERGED;         // Indicates that the interrupt for channel 0 must be merged with the other interrupts on the shared dcp_irq interrupt
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  8> HIGH_PRIORITY_CHANNEL;  // Setting a bit in this field causes the corresponding channel to have high-priority arbitration
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL,  8,  0> ENABLE_CHANNEL;         // Setting a bit in this field enables the DMA channel associated with it
    // Channel mask is (1 << channel):
    // 0b00000001..CH0
    // 0b00000010..CH1
    // 0b00000100..CH2
    // 0b00001000..CH3
}  // namespace CHANNELCTRL

// DCP channel control register
namespace CHANNELCTRL_SET {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET, 15, 17, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  1, 16, 0x0> CH0_IRQ_MERGED;         // Indicates that the interrupt for channel 0 must be merged with the other interrupts on the shared dcp_irq interrupt
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  8, 0x0> HIGH_PRIORITY_CHANNEL;  // Setting a bit in this field causes the corresponding channel to have high-priority arbitration
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_SET,  8,  0, 0x0> ENABLE_CHANNEL;         // Setting a bit in this field enables the DMA channel associated with it
}  // namespace CHANNELCTRL_SET

// DCP channel control register
namespace CHANNELCTRL_CLR {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR, 15, 17, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  1, 16, 0x0> CH0_IRQ_MERGED;         // Indicates that the interrupt for channel 0 must be merged with the other interrupts on the shared dcp_irq interrupt
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  8, 0x0> HIGH_PRIORITY_CHANNEL;  // Setting a bit in this field causes the corresponding channel to have high-priority arbitration
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_CLR,  8,  0, 0x0> ENABLE_CHANNEL;         // Setting a bit in this field enables the DMA channel associated with it
}  // namespace CHANNELCTRL_CLR

// DCP channel control register
namespace CHANNELCTRL_TOG {
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG, 15, 17, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  1, 16, 0x0> CH0_IRQ_MERGED;         // Indicates that the interrupt for channel 0 must be merged with the other interrupts on the shared dcp_irq interrupt
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  8, 0x0> HIGH_PRIORITY_CHANNEL;  // Setting a bit in this field causes the corresponding channel to have high-priority arbitration
constexpr DCP_Reg<&DCP_Layout::CHANNELCTRL_TOG,  8,  0, 0x0> ENABLE_CHANNEL;         // Setting a bit in this field enables the DMA channel associated with it
}  // namespace CHANNELCTRL_TOG

// DCP capability 0 register
namespace CAPABILITY0 {
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 31> DISABLE_DECRYPT;               // Write to 1 to disable the decryption
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0,  1, 29> DISABLE_UNIQUE_KEY;            // Write to a 1 to disable the per-device unique key
constexpr DCP_Reg<&DCP_Layout::CAPABILITY0, 17, 12> RSVD;
constexpr DCP_Reg<regs::constify(&DCP_Layout::CAPABILITY0),  4,  8> NUM_CHANNELS;  // Encoded value indicating the number of channels implemented in the design
constexpr DCP_Reg<regs::constify(&DCP_Layout::CAPABILITY0),  8,  0> NUM_KEYS;      // Encoded value indicating the number of key-storage locations implemented in the design
}  // namespace CAPABILITY0

// DCP capability 1 register
namespace CAPABILITY1 {
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16, 16> HASH_ALGORITHMS;    // One-hot field indicating which hashing features are implemented in the hardware
    // 0b0000000000000001..SHA1
    // 0b0000000000000010..CRC32
    // 0b0000000000000100..SHA256
constexpr DCP_Reg<&DCP_Layout::CAPABILITY1, 16,  0> CIPHER_ALGORITHMS;  // One-hot field indicating which cipher algorithms are available
    // 0b0000000000000001..AES128

// DCP capability 1 register values
constexpr uint32_t kCIPHER_ALGORITHMS_AES128 = 1;
constexpr uint32_t kHASH_ALGORITHMS_SHA1     = 1;
constexpr uint32_t kHASH_ALGORITHMS_CRC32    = 2;
constexpr uint32_t kHASH_ALGORITHMS_SHA256   = 4;
}  // namespace CAPABILITY1

// DCP context buffer pointer
namespace CONTEXT {
constexpr DCP_Reg<&DCP_Layout::CONTEXT, 32, 0> ADDR;  // Context pointer address
}  // namespace CONTEXT

// DCP key index
namespace KEY {
constexpr DCP_Reg<&DCP_Layout::KEY, 24, 8> RSVD;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 6> RSVD_INDEX;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 4> INDEX;         // Key index pointer.
    // The valid indices are 0-[number_keys].
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 2> RSVD_SUBWORD;
constexpr DCP_Reg<&DCP_Layout::KEY,  2, 0> SUBWORD;       // Key subword pointer
}  // namespace KEY

// DCP key data
namespace KEYDATA {
constexpr DCP_Reg<&DCP_Layout::KEYDATA, 32, 0> DATA;  // Word 0 data for the key.
    // This is the least-significant word.
}  // namespace KEYDATA

// DCP work packet 0 status register
namespace PACKET0 {
constexpr DCP_Reg<&DCP_Layout::PACKET0, 32, 0> ADDR;  // Next pointer register
}  // namespace PACKET0

// DCP work packet 1 status register
namespace PACKET1 {
constexpr DCP_Reg<&DCP_Layout::PACKET1, 8, 24> TAG;               // Packet Tag
constexpr DCP_Reg<&DCP_Layout::PACKET1, 6, 18> SWAP;              // Alias for 6 fields
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 23> OUTPUT_WORDSWAP;   // Reflects whether the DCP engine wordswaps the output data (big-endian data).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 22> OUTPUT_BYTESWAP;   // Reflects whether the DCP engine byteswaps the output data (big-endian data).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 21> INPUT_WORDSWAP;    // Reflects whether the DCP engine wordswaps the input data (big-endian data).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 20> INPUT_BYTESWAP;    // Reflects whether the DCP engine byteswaps the input data (big-endian data).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 19> KEY_WORDSWAP;      // Reflects whether the DCP engine swaps the key words (big-endian key).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 18> KEY_BYTESWAP;      // Reflects whether the DCP engine swaps the key bytes (big-endian key).
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 17> TEST_SEMA_IRQ;     // This bit is used to test the channel semaphore transition to 0.
    // FOR TEST USE ONLY!
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 16> CONSTANT_FILL;     // When this bit is set (MEMCOPY and BLIT modes only), the DCP simply fills the destination buffer with the value found in the source address field
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 15> HASH_OUTPUT;       // When the hashing is enabled, this bit controls whether the input or output data is hashed.
    // 0b0..INPUT
    // 0b1..OUTPUT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 14> CHECK_HASH;        // Reflects whether the calculated hash value must be compared to the hash provided in the payload.
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 13> HASH_TERM;         // Reflects whether the current hashing block is the final block in the hashing operation, so the hash padding must be applied by the hardware
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 12> HASH_INIT;         // Reflects whether the current hashing block is the initial block in the hashing operation, so the hash registers must be initialized before the operation
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 11> PAYLOAD_KEY;       // When set, it indicates the payload contains the key
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1, 10> OTP_KEY;           // Reflects whether a hardware-based key must be used
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  9> CIPHER_INIT;       // Reflects whether the cipher block must load the initialization vector from the payload for this operation
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  8> CIPHER_ENCRYPT;    // When the cipher block is enabled, this bit indicates whether the operation is encryption or decryption
    // 0b0..DECRYPT
    // 0b1..ENCRYPT
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  7> ENABLE_BLIT;       // Reflects whether the DCP must perform a blit operation
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  6> ENABLE_HASH;       // Reflects whether the selected hashing function must be enabled for this operation.
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  5> ENABLE_CIPHER;     // Reflects whether the selected cipher function must be enabled for this operation.
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  4> ENABLE_MEMCOPY;    // Reflects whether the selected memory-copy (memcopy) function should be enabled for this operation.
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  3> CHAIN_CONTIGUOUS;  // Reflects whether the next packet's address is located following this packet's payload.
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  2> CHAIN;             // Reflects whether the next command pointer register must be loaded into the channel's current descriptor pointer
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  1> DECR_SEMAPHORE;    // Reflects whether the channel's semaphore must be decremented at the end of the current operation
constexpr DCP_Reg<&DCP_Layout::PACKET1, 1,  0> INTERRUPT;         // Reflects whether the channel must issue an interrupt upon the completion of the packet.
}  // namespace PACKET1

// DCP work packet 2 status register
namespace PACKET2 {
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8, 24> CIPHER_CFG;     // Cipher configuration bits.
    // Optional configuration bits are required for the ciphers.
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 20> RSVD;
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4, 16> HASH_SELECT;    // Hash Selection Field
    // 0b0000..SHA1
    // 0b0001..CRC32
    // 0b0010..SHA256
constexpr DCP_Reg<&DCP_Layout::PACKET2, 8,  8> KEY_SELECT;     // Key selection field
    // 0b00000000..KEY0
    // 0b00000001..KEY1
    // 0b00000010..KEY2
    // 0b00000011..KEY3
    // 0b11111110..UNIQUE_KEY
    // 0b11111111..OTP_KEY
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  4> CIPHER_MODE;    // Cipher mode selection field.
    // Reflects the mode of operation for the cipher operations.
    // 0b0000..ECB
    // 0b0001..CBC
constexpr DCP_Reg<&DCP_Layout::PACKET2, 4,  0> CIPHER_SELECT;  // Cipher selection field
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

// DCP work packet 3 status register
namespace PACKET3 {
constexpr DCP_Reg<&DCP_Layout::PACKET3, 32, 0> ADDR;  // Source buffer address pointer
}  // namespace PACKET3

// DCP work packet 4 status register
namespace PACKET4 {
constexpr DCP_Reg<&DCP_Layout::PACKET4, 32, 0> ADDR;  // Destination buffer address pointer
}  // namespace PACKET4

// DCP work packet 5 status register
namespace PACKET5 {
constexpr DCP_Reg<&DCP_Layout::PACKET5, 32, 0> COUNT;  // Byte count register.
    // This value is the working value and updates as the operation proceeds.
}  // namespace PACKET5

// DCP work packet 6 status register
namespace PACKET6 {
constexpr DCP_Reg<&DCP_Layout::PACKET6, 32, 0> ADDR;  // This regiser reflects the payload pointer for the current control packet.
}  // namespace PACKET6

// DCP channel 0 command pointer address register
namespace CH0CMDPTR {
constexpr DCP_Reg<&DCP_Layout::CH0CMDPTR, 32, 0> ADDR;  // Pointer to the descriptor structure to be processed for channel 0.
}  // namespace CH0CMDPTR

// DCP channel 0 semaphore register
namespace CH0SEMA {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH0SEMA), 8, 16> VALUE;  // This read-only field shows the current (instantaneous) value of the semaphore counter.
constexpr DCP_Reg<&DCP_Layout::CH0SEMA, 8,  0> INCREMENT;              // The value written to this field is added to the semaphore count in an atomic way such that the simultaneous software adds and DCP hardware substracts happening on the same clock are protected
}  // namespace CH0SEMA

// DCP channel 0 status register
namespace CH0STAT {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH0STAT), 8, 24> TAG;  // Indicates the tag from the last completed packet in the command structure
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 8, 16> ERROR_CODE;           // Indicates the additional error codes for some of the error conditions
    // 0b00000001..Error signalled because the next pointer is 0x00000000
    // 0b00000010..Error signalled because the semaphore is non-zero and neither chain bit is set
    // 0b00000011..Error signalled because an error is reported reading/writing the context buffer
    // 0b00000100..Error signalled because an error is reported reading/writing the payload
    // 0b00000101..Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  6> ERROR_PAGEFAULT;      // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  5> ERROR_DST;            // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  4> ERROR_SRC;            // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  3> ERROR_PACKET;         // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet payload
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  2> ERROR_SETUP;          // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  1> HASH_MISMATCH;        // This bit indicates that a hashing check operation mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH0STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH0STAT

// DCP channel 0 status register
namespace CH0STAT_SET {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH0STAT_SET), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet payload
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH0STAT_SET, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH0STAT_SET

// DCP channel 0 status register
namespace CH0STAT_CLR {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH0STAT_CLR), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet payload
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH0STAT_CLR, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH0STAT_CLR

// DCP channel 0 status register
namespace CH0STAT_TOG {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH0STAT_TOG), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet payload
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH0STAT_TOG, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH0STAT_TOG

// DCP channel 0 options register
namespace CH0OPTS {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS, 16,  0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH0OPTS

// DCP channel 0 options register
namespace CH0OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_SET, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH0OPTS_SET

// DCP channel 0 options register
namespace CH0OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_CLR, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH0OPTS_CLR

// DCP channel 0 options register
namespace CH0OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH0OPTS_TOG, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH0OPTS_TOG

// DCP channel 1 command pointer address register
namespace CH1CMDPTR {
constexpr DCP_Reg<&DCP_Layout::CH1CMDPTR, 32, 0> ADDR;  // Pointer to the descriptor structure to be processed for channel 1.
}  // namespace CH1CMDPTR

// DCP channel 1 semaphore register
namespace CH1SEMA {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH1SEMA), 8, 16> VALUE;  // This read-only field shows the current (instantaneous) value of the semaphore counter.
constexpr DCP_Reg<&DCP_Layout::CH1SEMA, 8,  0> INCREMENT;              // The value written to this field is added to the semaphore count in an atomic way, such that the simultaneous software adds and the DCP hardware substracts happening on the same clock are protected
}  // namespace CH1SEMA

// DCP channel 1 status register
namespace CH1STAT {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH1STAT), 8, 24> TAG;  // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 8, 16> ERROR_CODE;           // Indicates the additional error codes for some of the error conditions.
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported when reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported when reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  6> ERROR_PAGEFAULT;      // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  5> ERROR_DST;            // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  4> ERROR_SRC;            // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  3> ERROR_PACKET;         // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  2> ERROR_SETUP;          // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  1> HASH_MISMATCH;        // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH1STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH1STAT

// DCP channel 1 status register
namespace CH1STAT_SET {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH1STAT_SET), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH1STAT_SET, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH1STAT_SET

// DCP channel 1 status register
namespace CH1STAT_CLR {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH1STAT_CLR), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH1STAT_CLR, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH1STAT_CLR

// DCP channel 1 status register
namespace CH1STAT_TOG {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH1STAT_TOG), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 8, 16, 0x0> ERROR_CODE;       // Indicates the additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH1STAT_TOG, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH1STAT_TOG

// DCP channel 1 options register
namespace CH1OPTS {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS, 16,  0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH1OPTS

// DCP channel 1 options register
namespace CH1OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_SET, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH1OPTS_SET

// DCP channel 1 options register
namespace CH1OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_CLR, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH1OPTS_CLR

// DCP channel 1 options register
namespace CH1OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH1OPTS_TOG, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH1OPTS_TOG

// DCP channel 2 command pointer address register
namespace CH2CMDPTR {
constexpr DCP_Reg<&DCP_Layout::CH2CMDPTR, 32, 0> ADDR;  // Pointer to the descriptor structure to be processed for channel 2.
}  // namespace CH2CMDPTR

// DCP channel 2 semaphore register
namespace CH2SEMA {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH2SEMA), 8, 16> VALUE;  // This read-only field shows the current (instantaneous) value of the semaphore counter.
constexpr DCP_Reg<&DCP_Layout::CH2SEMA, 8,  0> INCREMENT;              // The value written to this field is added to the semaphore count in an atomic way, such that the simultaneous software adds and DCP hardware substracts happening on the same clock are protected
}  // namespace CH2SEMA

// DCP channel 2 status register
namespace CH2STAT {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH2STAT), 8, 24> TAG;  // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 8, 16> ERROR_CODE;           // Indicates additional error codes for some of the error conditions.
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for instance, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  6> ERROR_PAGEFAULT;      // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  5> ERROR_DST;            // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  4> ERROR_SRC;            // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  3> ERROR_PACKET;         // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  2> ERROR_SETUP;          // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  1> HASH_MISMATCH;        // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH2STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH2STAT

// DCP channel 2 status register
namespace CH2STAT_SET {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH2STAT_SET), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH2STAT_SET, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH2STAT_SET

// DCP channel 2 status register
namespace CH2STAT_CLR {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH2STAT_CLR), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH2STAT_CLR, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH2STAT_CLR

// DCP channel 2 status register
namespace CH2STAT_TOG {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH2STAT_TOG), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload, or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH2STAT_TOG, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH2STAT_TOG

// DCP channel 2 options register
namespace CH2OPTS {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS, 16,  0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH2OPTS

// DCP channel 2 options register
namespace CH2OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_SET, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH2OPTS_SET

// DCP channel 2 options register
namespace CH2OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_CLR, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH2OPTS_CLR

// DCP channel 2 options register
namespace CH2OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH2OPTS_TOG, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH2OPTS_TOG

// DCP channel 3 command pointer address register
namespace CH3CMDPTR {
constexpr DCP_Reg<&DCP_Layout::CH3CMDPTR, 32, 0> ADDR;  // Pointer to the descriptor structure to be processed for channel 3.
}  // namespace CH3CMDPTR

// DCP channel 3 semaphore register
namespace CH3SEMA {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH3SEMA), 8, 16> VALUE;  // This read-only field shows the current (instantaneous) value of the semaphore counter.
constexpr DCP_Reg<&DCP_Layout::CH3SEMA, 8,  0> INCREMENT;              // The value written to this field is added to the semaphore count in an atomic way, such that the simultaneous software adds and DCP hardware substracts happening on the same clock are protected
}  // namespace CH3SEMA

// DCP channel 3 status register
namespace CH3STAT {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH3STAT), 8, 24> TAG;  // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 8, 16> ERROR_CODE;           // Indicates additional error codes for some of the error conditions.
    // 0b00000001..Error is signalled because the next pointer is 0x00000000.
    // 0b00000010..Error is signalled because the semaphore is of a non-zero value and neither of the chain bits is set.
    // 0b00000011..Error is signalled because an error was reported while reading/writing the context buffer.
    // 0b00000100..Error is signalled because an error was reported while reading/writing the payload.
    // 0b00000101..Error is signalled because the control packet specifies an invalid mode select (for example, blit + hash).
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  6> ERROR_PAGEFAULT;      // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  5> ERROR_DST;            // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  4> ERROR_SRC;            // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  3> ERROR_PACKET;         // This bit indicates that a bus error occurred when reading the packet or payload or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  2> ERROR_SETUP;          // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  1> HASH_MISMATCH;        // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH3STAT, 1,  0> RSVD_COMPLETE;
}  // namespace CH3STAT

// DCP channel 3 status register
namespace CH3STAT_SET {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH3STAT_SET), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH3STAT_SET, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH3STAT_SET

// DCP channel 3 status register
namespace CH3STAT_CLR {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH3STAT_CLR), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH3STAT_CLR, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH3STAT_CLR

// DCP channel 3 status register
namespace CH3STAT_TOG {
constexpr DCP_Reg<regs::constify(&DCP_Layout::CH3STAT_TOG), 8, 24> TAG;   // Indicates the tag from the last completed packet in the command structure.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 8, 16, 0x0> ERROR_CODE;       // Indicates additional error codes for some of the error conditions.
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  6, 0x0> ERROR_PAGEFAULT;  // This bit indicates that a page fault occurred while converting a virtual address to a physical address
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  5, 0x0> ERROR_DST;        // This bit indicates that a bus error occurred when storing to the destination buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  4, 0x0> ERROR_SRC;        // This bit indicates that a bus error occurred when reading from the source buffer
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  3, 0x0> ERROR_PACKET;     // This bit indicates that a bus error occurred when reading the packet or payload or when writing the status back to the packet paylaod
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  2, 0x0> ERROR_SETUP;      // This bit indicates that the hardware detected an invalid programming configuration (such as a buffer length that is not a multiple of the natural data size for the operation)
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  1, 0x0> HASH_MISMATCH;    // This bit indicates that a hashing check operation is mismatched for the control packets that enable the HASH_CHECK bit
constexpr DCP_Reg<&DCP_Layout::CH3STAT_TOG, 1,  0, 0x0> RSVD_COMPLETE;
}  // namespace CH3STAT_TOG

// DCP channel 3 options register
namespace CH3OPTS {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16, 16> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS, 16,  0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH3OPTS

// DCP channel 3 options register
namespace CH3OPTS_SET {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_SET, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH3OPTS_SET

// DCP channel 3 options register
namespace CH3OPTS_CLR {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_CLR, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH3OPTS_CLR

// DCP channel 3 options register
namespace CH3OPTS_TOG {
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16, 16, 0x0> RSVD;
constexpr DCP_Reg<&DCP_Layout::CH3OPTS_TOG, 16,  0, 0x0> RECOVERY_TIMER;  // This field indicates the recovery time for the channel
}  // namespace CH3OPTS_TOG

// DCP debug select register
namespace DBGSELECT {
constexpr DCP_Reg<&DCP_Layout::DBGSELECT, 24, 8> RSVD;
constexpr DCP_Reg<&DCP_Layout::DBGSELECT,  8, 0> INDEX;  // Selects a value to read via the debug data register.
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

// DCP debug data register
namespace DBGDATA {
constexpr DCP_Reg<&DCP_Layout::DBGDATA, 32, 0> DATA;  // Debug data
}  // namespace DBGDATA

// DCP page table register
namespace PAGETABLE {
constexpr DCP_Reg<&DCP_Layout::PAGETABLE, 30, 2> BASE;    // Page table base address
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 1> FLUSH;   // Page table flush control.
    // To flush the TLB, write this bit to 1 and then back to 0.
constexpr DCP_Reg<&DCP_Layout::PAGETABLE,  1, 0> ENABLE;  // Page table enable control
}  // namespace PAGETABLE

// DCP version register
namespace VERSION {
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 24> MAJOR;  // Fixed read-only value reflecting the MAJOR version of the design implementation.
constexpr DCP_Reg<&DCP_Layout::VERSION,  8, 16> MINOR;  // Fixed read-only value reflecting the MINOR version of the design implementation.
constexpr DCP_Reg<&DCP_Layout::VERSION, 16,  0> STEP;   // Fixed read-only value reflecting the stepping of the version of the design implementation.
}  // namespace VERSION

// CHxSEMA values
namespace CHANNEL_SEMA {
namespace vals {
// DCP channel X register values
constexpr regs::RegValue32<8, 16> VALUE;
}  // namespace vals
}  // namespace CHANNEL_SEMA

// CHxSTAT values
namespace CHANNEL_STAT {
namespace vals {
constexpr regs::RegValue32<8, 16> ERROR_CODE;
}  // namespace vals
}  // namespace CHANNEL_STAT

}  // namespace DCP

}  // namespace imxrt1060
}  // namespace hardware
}  // namespace qindesign
