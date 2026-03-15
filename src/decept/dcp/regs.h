// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// regs.h defines all the DCP registers.
// This file is part of the Decept library.

#pragma once

#include <cstdint>

namespace decept {
namespace dcp {

constexpr uint32_t kDCPBase = 0x402FC000;

const auto kCTRL            = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x000);
const auto kCTRL_SET        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x004);
const auto kCTRL_CLR        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x008);
const auto kCTRL_TOG        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x00C);
const auto kSTAT            = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x010);
const auto kSTAT_SET        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x014);
const auto kSTAT_CLR        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x018);
const auto kSTAT_TOG        = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x01C);
const auto kCHANNELCTRL     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x020);
const auto kCHANNELCTRL_SET = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x024);
const auto kCHANNELCTRL_CLR = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x028);
const auto kCHANNELCTRL_TOG = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x02C);
const auto kCAPABILITY0     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x030);
const auto kCAPABILITY1     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x040);
const auto kCONTEXT         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x050);
const auto kKEY             = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x060);
const auto kKEYDATA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x070);
const auto kPACKET0         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x080);
const auto kPACKET1         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x090);
const auto kPACKET2         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x0A0);
const auto kPACKET3         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x0B0);
const auto kPACKET4         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x0C0);
const auto kPACKET5         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x0D0);
const auto kPACKET6         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x0E0);
const auto kCH0CMDPTR       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x100);
const auto kCH0SEMA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x110);
const auto kCH0STAT         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x120);
const auto kCH0STAT_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x124);
const auto kCH0STAT_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x128);
const auto kCH0STAT_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x12C);
const auto kCH0OPTS         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x130);
const auto kCH0OPTS_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x134);
const auto kCH0OPTS_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x138);
const auto kCH0OPTS_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x13C);
const auto kCH1CMDPTR       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x140);
const auto kCH1SEMA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x150);
const auto kCH1STAT         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x160);
const auto kCH1STAT_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x164);
const auto kCH1STAT_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x168);
const auto kCH1STAT_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x16C);
const auto kCH1OPTS         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x170);
const auto kCH1OPTS_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x174);
const auto kCH1OPTS_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x178);
const auto kCH1OPTS_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x17C);
const auto kCH2CMDPTR       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x180);
const auto kCH2SEMA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x190);
const auto kCH2STAT         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1A0);
const auto kCH2STAT_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1A4);
const auto kCH2STAT_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1A8);
const auto kCH2STAT_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1AC);
const auto kCH2OPTS         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1B0);
const auto kCH2OPTS_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1B4);
const auto kCH2OPTS_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1B8);
const auto kCH2OPTS_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1BC);
const auto kCH3CMDPTR       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1C0);
const auto kCH3SEMA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1D0);
const auto kCH3STAT         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1E0);
const auto kCH3STAT_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1E4);
const auto kCH3STAT_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1E8);
const auto kCH3STAT_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1EC);
const auto kCH3OPTS         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1F0);
const auto kCH3OPTS_SET     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1F4);
const auto kCH3OPTS_CLR     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1F8);
const auto kCH3OPTS_TOG     = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x1FC);
const auto kDBGSELECT       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x400);
const auto kDBGDATA         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x410);
const auto kPAGETABLE       = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x420);
const auto kVERSION         = reinterpret_cast<volatile uint32_t*>(kDCPBase + 0x430);

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
