// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// regs.h defines all the DCP registers.
// This file is part of the Decept library.

#pragma once

#include <cstdint>

#include "decept/util/regs.h"

namespace decept {
namespace dcp {

constexpr uintptr_t kDCPBase = 0x402FC000;  // This comment is less useful than the statement

struct DCPLayout {
  volatile uint32_t CTRL;             // 0x000
  volatile uint32_t CTRL_SET;         // 0x004
  volatile uint32_t CTRL_CLR;         // 0x008
  volatile uint32_t CTRL_TOG;         // 0x00C
  volatile uint32_t STAT;             // 0x010
  volatile uint32_t STAT_SET;         // 0x014
  volatile uint32_t STAT_CLR;         // 0x018
  volatile uint32_t STAT_TOG;         // 0x01C
  volatile uint32_t CHANNELCTRL;      // 0x020
  volatile uint32_t CHANNELCTRL_SET;  // 0x024
  volatile uint32_t CHANNELCTRL_CLR;  // 0x028
  volatile uint32_t CHANNELCTRL_TOG;  // 0x02C
  volatile uint32_t CAPABILITY0;      // 0x030
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CAPABILITY1;      // 0x040
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CONTEXT;          // 0x050
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEY;              // 0x060
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t KEYDATA;          // 0x070
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET0;          // 0x080
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET1;          // 0x090
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET2;          // 0x0A0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET3;          // 0x0B0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET4;          // 0x0C0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET5;          // 0x0D0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PACKET6;          // 0x0E0
  uint32_t LAYOUT_MEMBER_RESERVED[7];
  volatile uint32_t CH0CMDPTR;        // 0x100
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0SEMA;          // 0x110
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH0STAT;          // 0x120
  volatile uint32_t CH0STAT_SET;      // 0x124
  volatile uint32_t CH0STAT_CLR;      // 0x128
  volatile uint32_t CH0STAT_TOG;      // 0x12C
  volatile uint32_t CH0OPTS;          // 0x130
  volatile uint32_t CH0OPTS_SET;      // 0x134
  volatile uint32_t CH0OPTS_CLR;      // 0x138
  volatile uint32_t CH0OPTS_TOG;      // 0x13C
  volatile uint32_t CH1CMDPTR;        // 0x140
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1SEMA;          // 0x150
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH1STAT;          // 0x160
  volatile uint32_t CH1STAT_SET;      // 0x164
  volatile uint32_t CH1STAT_CLR;      // 0x168
  volatile uint32_t CH1STAT_TOG;      // 0x16C
  volatile uint32_t CH1OPTS;          // 0x170
  volatile uint32_t CH1OPTS_SET;      // 0x174
  volatile uint32_t CH1OPTS_CLR;      // 0x178
  volatile uint32_t CH1OPTS_TOG;      // 0x17C
  volatile uint32_t CH2CMDPTR;        // 0x180
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2SEMA;          // 0x190
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH2STAT;          // 0x1A0
  volatile uint32_t CH2STAT_SET;      // 0x1A4
  volatile uint32_t CH2STAT_CLR;      // 0x1A8
  volatile uint32_t CH2STAT_TOG;      // 0x1AC
  volatile uint32_t CH2OPTS;          // 0x1B0
  volatile uint32_t CH2OPTS_SET;      // 0x1B4
  volatile uint32_t CH2OPTS_CLR;      // 0x1B8
  volatile uint32_t CH2OPTS_TOG;      // 0x1BC
  volatile uint32_t CH3CMDPTR;        // 0x1C0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3SEMA;          // 0x1D0
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t CH3STAT;          // 0x1E0
  volatile uint32_t CH3STAT_SET;      // 0x1E4
  volatile uint32_t CH3STAT_CLR;      // 0x1E8
  volatile uint32_t CH3STAT_TOG;      // 0x1EC
  volatile uint32_t CH3OPTS;          // 0x1F0
  volatile uint32_t CH3OPTS_SET;      // 0x1F4
  volatile uint32_t CH3OPTS_CLR;      // 0x1F8
  volatile uint32_t CH3OPTS_TOG;      // 0x1FC
  uint32_t LAYOUT_MEMBER_RESERVED[128];
  volatile uint32_t DBGSELECT;        // 0x400
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t DBGDATA;          // 0x410
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t PAGETABLE;        // 0x420
  uint32_t LAYOUT_MEMBER_RESERVED[3];
  volatile uint32_t VERSION;          // 0x430
};

constexpr util::RegGroup<DCPLayout, kDCPBase> regs;

// DCP control register 0

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_CHANNEL_INTERRUPT_ENABLE(const uint32_t x) {
  return ((x & 0xFF) << 0);  // CH(x) = (1 << x)
}

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t CTRL_RSVD_CSC_INTERRUPT_ENABLE(
//     const bool flag) {
//   return (static_cast<uint32_t>(flag) << 8);
// }

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_ENABLE_CONTEXT_SWITCHING(
    const bool flag) {
  return (static_cast<uint32_t>(flag) << 21);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_ENABLE_CONTEXT_CACHING(const bool flag) {
  return (static_cast<uint32_t>(flag) << 22);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_GATHER_RESIDUAL_WRITES(const bool flag) {
  return (static_cast<uint32_t>(flag) << 23);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_PRESENT_SHA(const bool flag) {
  return (static_cast<uint32_t>(flag) << 28);  // Present(1), Absent(0)
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_PRESENT_CRYPTO(const bool flag) {
  return (static_cast<uint32_t>(flag) << 29);  // Present(1), Absent(0)
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_CLKGATE(const bool flag) {
  return (static_cast<uint32_t>(flag) << 30);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CTRL_SFTRESET(const bool flag) {
  return (static_cast<uint32_t>(flag) << 31);
}

// DCP status register

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t STAT_IRQ(const uint32_t x) {
//   return ((x & 0x0F) << 0);
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t STAT_RSVD_IRQ(const bool flag) {
//   return (static_cast<uint32_t>(flag) << 8);
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t STAT_READY_CHANNELS(const uint32_t x) {
//   return ((x & 0xFF) << 16);  // CH(x) = (1 << x)
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t STAT_CUR_CHANNEL(const uint32_t x) {
//   return ((x & 0x0F) << 24);  // CH(x) = (1 << x)
// }

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t STAT_OTP_KEY_READY(const bool flag) {
  return (static_cast<uint32_t>(flag) << 28);
}

// DCP channel control register

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CHANNELCTRL_ENABLE_CHANNEL(const uint32_t x) {
  return ((x & 0x00FF) << 0);  // CH(x) = (1 << x)
}

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t CHANNELCTRL_HIGH_PRIORITY_CHANNEL(
//     const uint32_t x) {
//   return ((x & 0x00FF) << 8);  // CH(x) = (1 << x)
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t CHANNELCTRL_CH0_IRQ_MERGED(const bool flag) {
//   return (static_cast<uint32_t>(flag) << 16);
// }

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CHANNELCTRL_RSVD(const uint32_t x) {
  return ((x & 0x7FFF) << 17);
}

// DCP key index

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t KEY_SUBWORD(const uint32_t x) {
  return ((x & 0x000003) << 0);
}

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t KEY_RSVD_SUBWORD(const uint32_t x) {
//   return ((x & 0x000003) << 2);
// }

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t KEY_INDEX(const uint32_t x) {
  return ((x & 0x000003) << 4);
}

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t KEY_RSVD_INDEX(const uint32_t x) {
//   return ((x & 0x000003) << 6);
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t KEY_RSVD(const uint32_t x) {
//   return ((x & 0xFFFFFF) << 8);
// }

// DCP work packet 1 status register

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_DECR_SEMAPHORE(const bool flag) {
  return (static_cast<uint32_t>(flag) << 1);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_ENABLE_CIPHER(const bool flag) {
  return (static_cast<uint32_t>(flag) << 5);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_ENABLE_HASH(const bool flag) {
  return (static_cast<uint32_t>(flag) << 6);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_CIPHER_ENCRYPT(const bool flag) {
  return (static_cast<uint32_t>(flag) << 8);  // Encrypt(1), Decrypt(0)
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_CIPHER_INIT(const bool flag) {
  return (static_cast<uint32_t>(flag) << 9);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_OTP_KEY(const bool flag) {
  return (static_cast<uint32_t>(flag) << 10);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_PAYLOAD_KEY(const bool flag) {
  return (static_cast<uint32_t>(flag) << 11);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_HASH_INIT(const bool flag) {
  return (static_cast<uint32_t>(flag) << 12);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_HASH_TERM(const bool flag) {
  return (static_cast<uint32_t>(flag) << 13);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET1_SWAP(const uint32_t x) {
  return ((x & 0x3F) << 18);
}

// // DCP work packet 1 status register values
// constexpr bool kPACKET1_CIPHER_ENCRYPT_ENCRYPT = true;
// constexpr bool kPACKET1_CIPHER_ENCRYPT_DECRYPT = false;
// constexpr bool kPACKET1_HASH_OUTPUT_INPUT      = false;
// constexpr bool kPACKET1_HASH_OUTPUT_OUTPUT     = true;

// DCP work packet 2 status register

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t PACKET2_CIPHER_SELECT(const uint32_t x) {
//   return ((x & 0x0F) << 0);  // AES128(0)
// }

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET2_CIPHER_MODE(const uint32_t x) {
  return ((x & 0x0F) << 4);  // ECB(0), CBC(1)
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET2_KEY_SELECT(const uint32_t x) {
  return ((x & 0xFF) << 8);  // KEY0(0), KEY1(1), KEY2(2), KEY3(3), UNIQUE_KEY(0xFE), OTP_KEY(0xFF)
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t PACKET2_HASH_SELECT(const uint32_t x) {
  return ((x & 0x0F) << 16);  // SHA1(0), CRC32(1), SHA256(2)
}

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t PACKET2_RSVD(const uint32_t x) {
//   return ((x & 0x0F) << 20);
// }

// [[nodiscard]] [[gnu::always_inline]]
// inline constexpr uint32_t PACKET2_CIPHER_CFG(const uint32_t x) {
//   return ((x & 0xFF) << 24);
// }

// DCP work packet 2 status register values
// constexpr uint32_t kPACKET2_CIPHER_SELECT_AES128  = 0;
constexpr uint32_t kPACKET2_CIPHER_MODE_ECB       = 0;
constexpr uint32_t kPACKET2_CIPHER_MODE_CBC       = 1;
// constexpr uint32_t kPACKET2_KEY_SELECT_KEY0       = 0;
// constexpr uint32_t kPACKET2_KEY_SELECT_KEY1       = 1;
// constexpr uint32_t kPACKET2_KEY_SELECT_KEY2       = 2;
// constexpr uint32_t kPACKET2_KEY_SELECT_KEY3       = 3;
constexpr uint32_t kPACKET2_KEY_SELECT_UNIQUE_KEY = 0xFE;
constexpr uint32_t kPACKET2_KEY_SELECT_OTP_KEY    = 0xFF;
// constexpr uint32_t kPACKET2_HASH_SELECT_SHA1      = 0;
// constexpr uint32_t kPACKET2_HASH_SELECT_CRC32     = 1;
// constexpr uint32_t kPACKET2_HASH_SELECT_SHA256    = 2;

// DCP work control 1 values
constexpr uint32_t kCONTROL1_HASH_SELECT_SHA256 = 2;
constexpr uint32_t kCONTROL1_HASH_SELECT_SHA1   = 0;
constexpr uint32_t kCONTROL1_HASH_SELECT_CRC32  = 1;

// DCP channel X registers

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CHxSEMA_VALUE(const uint32_t x) {
  return ((x & 0xFF) << 16);
}

[[nodiscard]] [[gnu::always_inline]]
inline constexpr uint32_t CHxSTAT_ERROR_CODE(const uint32_t x) {
  return ((x & 0xFF) << 16);
}

}  // namespace dcp
}  // namespace decept
