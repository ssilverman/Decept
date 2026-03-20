// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// regs.h defines some useful register-related utilities.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>

namespace decept {
namespace regs {

// Defines a register group having the given layout, expected size, and
// base address.
template <typename Layout, size_t LayoutSize, uintptr_t BaseAddr>
struct RegGroup {
  static_assert(sizeof(Layout) == LayoutSize,
                "Bad size: Packing? Incorrect size?");
  static_assert((BaseAddr % alignof(Layout)) == 0, "Bad alignment");

  Layout* operator->() const { return reinterpret_cast<Layout*>(BaseAddr); }
};

// Reg defines an easier way to access parts of a register.
//
// The "direct assign" parameter means that assignment will not use the "read,
// clear, set, assign" approach. Instead, the given value is directly assigned,
// after shifting. This is appropriate for things like "CLR" and "SET"
// registers, where only the 1-assigned bits are set to something.
template <uintptr_t R, uint32_t Bits, unsigned int Shift,
          bool DirectAssign = false>
struct Reg {
  // The shift.
  static constexpr unsigned int kShift = Shift;

  // The number of consecutive bits.
  static constexpr uint32_t kBits = Bits;

  // The shifted mask.
  static constexpr uint32_t kMask =  // Add -1 using 32-bit modular arithmetic
      ((uint32_t{1} << Bits) + std::numeric_limits<uint32_t>::max()) << Shift;
  // static constexpr uint32_t kMask = static_cast<uint32_t>(int32_t{-1}) >> (32 - Bits);
  // static constexpr uint32_t kMask = ((uint32_t{1} << Bits) - uint32_t{1});

  // Returns the masked and shifted version of the given field value.
  template <typename T>
  [[gnu::always_inline]]
  uint32_t v(const T val) const {
    return (static_cast<uint32_t>(val) << Shift) & kMask;
  }

  template <typename T>
  [[gnu::always_inline]]
  void operator=(const T val) const {
    // Clear and then set the bits
    const auto r = reinterpret_cast<volatile uint32_t*>(R);
    if constexpr (DirectAssign) {
      *r = v(val);
    } else {
      *r = (*r & ~kMask) | v(val);
    }
  }

  [[gnu::always_inline]]
  operator uint32_t() const {
    const auto r = reinterpret_cast<volatile uint32_t*>(R);
    return (*r & kMask) >> Shift;
  }

  template <typename T>
  [[gnu::always_inline]]
  void operator&=(const T val) const {
    const auto r = reinterpret_cast<volatile uint32_t*>(R);
    *r &= v(val);
  }

  template <typename T>
  [[gnu::always_inline]]
  void operator|=(const T val) const {
    const auto r = reinterpret_cast<volatile uint32_t*>(R);
    *r |= v(val);
  }

  template <typename T>
  [[gnu::always_inline]]
  bool operator==(const T val) const {
    const auto r = reinterpret_cast<volatile uint32_t*>(R);
    return (*r & kMask) == v(val);
  }

  template <typename T>
  [[gnu::always_inline]]
  bool operator!=(const T val) const {
    return !(*this == val);
  }
};

// Generate unique "_reserved" field names
#define DECEPT_REGS_CAT2(a, b) a##b
#define DECEPT_REGS_CAT(a, b) DECEPT_REGS_CAT2(a, b)
#define DECEPT_REGS_LAYOUT_MEMBER_RESERVED \
  DECEPT_REGS_CAT(_reserved, __COUNTER__)

}  // namespace regs
}  // namespace decept
