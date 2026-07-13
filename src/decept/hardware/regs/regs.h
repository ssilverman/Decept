// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// regs.h defines some useful register-related utilities.
// This file is part of the Decept library.

#pragma once

#include <cstddef>
#include <cstdint>
#include <limits>
#include <type_traits>
#include <utility>

namespace qindesign {
namespace hardware {
namespace regs {

// Defines a register group having the given layout, expected size, and base
// address. While it's possible to just utilize sizeof(Layout) instead of also
// passing a size, having the size provides an extra check.
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
// "SET" registers, where only the 1-assigned bits are set to something. Or, it
// could be used for write-1-to-clear bits, if all the bits in the register are
// write-1-to-clear (w1c).
template <uintptr_t Base, typename T, auto Member,  // Can be const or non-const
          size_t MemberOffset,  // If the member is an array, otherwise zero
          size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
struct Reg {
  // Only arrays can have a non-zero offset
  static_assert(
      ((MemberOffset != 0) &&
       std::is_array_v<
           std::remove_reference_t<decltype(std::declval<T&>().*Member)>>) ||
          (MemberOffset == 0),
      "Non-array members must use a zero offset");

  // The shift.
  static constexpr unsigned int kShift = Shift;

  // The number of consecutive bits.
  static constexpr size_t kBits = Bits;

  // The shifted mask.
  static constexpr uint32_t kMask =  // Add -1 using 32-bit modular arithmetic
      (((Bits < 32) ? (uint32_t{1} << Bits) : uint32_t{0}) +
       std::numeric_limits<uint32_t>::max())
      << Shift;
  // static constexpr uint32_t kMask = static_cast<uint32_t>(int32_t{-1}) >> (32 - Bits);
  // static constexpr uint32_t kMask = ((uint32_t{1} << Bits) - uint32_t{1});

  // Returns the masked and shifted version of the given field value.
  [[gnu::always_inline]]
  constexpr uint32_t operator()(const uint32_t val) const {
    return (val << Shift) & kMask;
  }

 private:
  [[gnu::always_inline]]
  static auto r() {
    auto& m = reinterpret_cast<T*>(Base)->*Member;
    if constexpr (std::is_array_v<std::remove_reference_t<decltype(m)>>) {
      return &m[MemberOffset];
    } else {
      return &m;
    }
  }

 public:
  [[gnu::always_inline]]
  const Reg& operator=(const uint32_t val) const {
    // Clear and then set the bits
    if constexpr (DirectAssign) {
      *r() = (*this)(val);
    } else {
      *r() = (*r() & ~kMask) | (*this)(val);
    }
    return *this;
  }

  [[gnu::always_inline]]
  explicit operator uint32_t() const {
    return (*r() & kMask) >> Shift;
  }

  // Converts the register to a uint32_t. This is useful for when an explicit
  // conversion isn't desired.
  [[gnu::always_inline]]
  uint32_t operator*() const {
    return static_cast<uint32_t>(*this);
  }

  [[gnu::always_inline]]
  const Reg& operator&=(const uint32_t val) const {
    *r() &= (*this)(val);
    return *this;
  }

  [[gnu::always_inline]]
  const Reg& operator|=(const uint32_t val) const {
    *r() |= (*this)(val);
    return *this;
  }

  [[gnu::always_inline]]
  const Reg& operator^=(const uint32_t val) const {
    *r() ^= (*this)(val);
    return *this;
  }

  [[gnu::always_inline]]
  uint32_t operator&(const uint32_t val) const {
    return ((*r() & (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  uint32_t operator|(const uint32_t val) const {
    return ((*r() | (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  uint32_t operator^(const uint32_t val) const {
    return ((*r() ^ (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  uint32_t operator~() const {
    return ((~(*r())) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  bool operator==(const uint32_t val) const {
    return (*r() & kMask) == (*this)(val);
  }

  [[gnu::always_inline]]
  bool operator!=(const uint32_t val) const {
    return !(*this == val);
  }
};

// RegValue defines an easier way to define register-part values. It is
// represented by a mask and shift. It's useful for when a specific register
// value may be used for more than one register, and that value always has the
// same size and is always at the same position.
template <size_t Bits, unsigned int Shift>
struct RegValue {
  // The shift.
  static constexpr unsigned int kShift = Shift;

  // The number of consecutive bits.
  static constexpr size_t kBits = Bits;

  // The shifted mask.
  static constexpr uint32_t kMask =  // Add -1 using 32-bit modular arithmetic
      (((Bits < 32) ? (uint32_t{1} << Bits) : uint32_t{0}) +
       std::numeric_limits<uint32_t>::max())
      << Shift;

  // Returns the masked and shifted version of the given field value.
  [[gnu::always_inline]]
  constexpr uint32_t operator()(const uint32_t val) const {
    return (val << Shift) & kMask;
  }
};

// Generate unique "_reserved" field names
#define HARDWARE_REGS_CAT2(a, b) a##b
#define HARDWARE_REGS_CAT(a, b) HARDWARE_REGS_CAT2(a, b)
#define HARDWARE_REGS_LAYOUT_MEMBER_RESERVED \
  HARDWARE_REGS_CAT(_reserved, __COUNTER__)

}  // namespace regs
}  // namespace hardware
}  // namespace qindesign
