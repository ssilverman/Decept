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
class RegGroup {
  static_assert(sizeof(Layout) == LayoutSize,
                "Bad size: Packing? Incorrect size?");
  static_assert((BaseAddr % alignof(Layout)) == 0, "Bad alignment");

 public:
  Layout* operator->() const { return reinterpret_cast<Layout*>(BaseAddr); }
};

// Reg defines an easier way to access parts of a register.
//
// The 'R' parameter is the unsigned type of each whole register, for example,
// uint32_t or uint16_t.
//
// The "direct assign" parameter means that assignment will not use the "read,
// clear, set, assign" approach. Instead, the given value is directly assigned
// to the register after shifting. This is appropriate for things like "CLR" and
// "SET" registers, where only the 1-assigned bits are set to something. Or, it
// could be used for write-1-to-clear bits, if all the bits in the register are
// write-1-to-clear (w1c).
template <typename R, uintptr_t Base, typename Layout,
          auto Member,          // Can be const or non-const
          size_t MemberOffset,  // If the member is an array, otherwise zero
          size_t Bits, unsigned int Shift,
          bool DirectAssign = false>
class Reg {
  using MemberExpr   = decltype(std::declval<Layout&>().*Member);
  using MemberType   = std::remove_reference_t<MemberExpr>;
  using RegType      = std::remove_extent_t<MemberType>;
  using RegValueType = std::remove_cv_t<RegType>;

  static constexpr bool kMemberIsWritable = !std::is_const_v<RegType>;
  static constexpr bool kMemberIsArray    = std::is_array_v<MemberType>;

  // Parameter shape checks
  static_assert(std::is_integral_v<R> && std::is_unsigned_v<R>,
                "Register type must be unsigned integral");
  static_assert(Bits != 0, "Bits shouldn't be zero");

  // Array checks
  static_assert(std::is_same_v<RegValueType, R>,
                "Array element type must match register type");
  static_assert(kMemberIsArray || (MemberOffset == 0),
                "Non-array members must use a zero offset");
  static_assert(!kMemberIsArray || (MemberOffset < std::extent_v<MemberType>),
                "Member offset out of range");

 public:
  // Number of bits in whole register.
  static constexpr size_t kWholeRegBits = std::numeric_limits<R>::digits;

  // More parameter shape checks
  static_assert(Bits <= kWholeRegBits, "Bit count exceeds register width");
  static_assert(Shift < kWholeRegBits, "Shift exceeds register width");
  static_assert((Bits <= kWholeRegBits) && (Shift <= kWholeRegBits - Bits),
                "Register extends past register bounds");

  // The shift.
  static constexpr unsigned int kShift = Shift;

  // The number of consecutive bits.
  static constexpr size_t kBits = Bits;

  // The shifted mask.
  static constexpr R kMask =  // Add -1 using R-bit modular arithmetic
      (((Bits < kWholeRegBits) ? (R{1} << Bits) : R{0}) +
       std::numeric_limits<R>::max())
      << Shift;
  // static constexpr R kMask =
  //     static_cast<R>(std::make_signed_t<R>{-1}) >> (kWholeRegBits - Bits);
  // static constexpr R kMask = ((R{1} << Bits) - R{1});

  // Returns the masked and shifted version of the given field value.
  [[gnu::always_inline]]
  constexpr R operator()(const R val) const {
    return (val << Shift) & kMask;
  }

 private:
  [[gnu::always_inline]]
  static auto r() {
    auto& m = reinterpret_cast<Layout*>(Base)->*Member;
    if constexpr (kMemberIsArray) {
      return &m[MemberOffset];
    } else {
      static_assert(MemberOffset == 0, "Not an array");
      return &m;
    }
  }

 public:
  template <bool Writable = kMemberIsWritable,
            typename = std::enable_if_t<Writable>>
  [[gnu::always_inline]]
  const Reg& operator=(const R val) const {
    // Clear and then set the bits
    if constexpr (DirectAssign || ((Bits == kWholeRegBits) && (Shift == 0))) {
      *r() = (*this)(val);
    } else {
      *r() = (*r() & ~kMask) | (*this)(val);
    }
    return *this;
  }

  [[gnu::always_inline]]
  explicit operator R() const {
    return (*r() & kMask) >> Shift;
  }

  // Converts the register to an R. This is useful for when an explicit
  // conversion isn't desired.
  [[gnu::always_inline]]
  R operator*() const {
    return static_cast<R>(*this);
  }

  template <bool Writable = kMemberIsWritable,
            typename = std::enable_if_t<Writable>>
  [[gnu::always_inline]]
  const Reg& operator&=(const R val) const {
    // Preserve bits outside the range
    *r() &= static_cast<R>(~kMask) | (*this)(val);
    return *this;
  }

  template <bool Writable = kMemberIsWritable,
            typename = std::enable_if_t<Writable>>
  [[gnu::always_inline]]
  const Reg& operator|=(const R val) const {
    *r() |= (*this)(val);
    return *this;
  }

  template <bool Writable = kMemberIsWritable,
            typename = std::enable_if_t<Writable>>
  [[gnu::always_inline]]
  const Reg& operator^=(const R val) const {
    *r() ^= (*this)(val);
    return *this;
  }

  [[gnu::always_inline]]
  R operator&(const R val) const {
    return ((*r() & (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  R operator|(const R val) const {
    return ((*r() | (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  R operator^(const R val) const {
    return ((*r() ^ (*this)(val)) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  R operator~() const {
    return ((~(*r())) & kMask) >> Shift;
  }

  [[gnu::always_inline]]
  bool operator==(const R val) const {
    return (*r() & kMask) == (*this)(val);
  }

  [[gnu::always_inline]]
  bool operator!=(const R val) const {
    return !(*this == val);
  }
};

// RegValue defines an easier way to define register-part values. It is
// represented by a mask and shift. It's useful for when a specific register
// value may be used for more than one register, and that value always has the
// same size and is always at the same position. It's also useful when the
// shifted value is used with regular R variables.
template <typename R, size_t Bits, unsigned int Shift>
class RegValue {
  // Parameter shape checks
  static_assert(std::is_integral_v<R> && std::is_unsigned_v<R>,
                "Register type must be unsigned integral");
  static_assert(Bits != 0, "Bits shouldn't be zero");

 public:
  // Number of bits in whole register.
  static constexpr size_t kWholeRegBits = std::numeric_limits<R>::digits;

  // More parameter shape checks
  static_assert(Bits <= kWholeRegBits, "Bit count exceeds register width");
  static_assert(Shift < kWholeRegBits, "Shift exceeds register width");
  static_assert((Bits <= kWholeRegBits) && (Shift <= kWholeRegBits - Bits),
                "Register extends past register bounds");

  // The shift.
  static constexpr unsigned int kShift = Shift;

  // The number of consecutive bits.
  static constexpr size_t kBits = Bits;

  // The shifted mask.
  static constexpr R kMask =  // Add -1 using R-bit modular arithmetic
      (((Bits < kWholeRegBits) ? (R{1} << Bits) : R{0}) +
       std::numeric_limits<R>::max())
      << Shift;

  // Returns the masked and shifted version of the given field value.
  [[gnu::always_inline]]
  constexpr R operator()(const R val) const {
    return (val << Shift) & kMask;
  }
};

template <uintptr_t Base, typename Layout,
          auto Member,          // Can be const or non-const
          size_t MemberOffset,  // If the member is an array, otherwise zero
          size_t Bits, unsigned int Shift, bool DirectAssign = false>
using Reg32 = Reg<uint32_t, Base, Layout, Member, MemberOffset, Bits, Shift,
                  DirectAssign>;

template <size_t Bits, unsigned int Shift>
using RegValue32 = RegValue<uint32_t, Bits, Shift>;

template <uintptr_t Base, typename Layout,
          auto Member,          // Can be const or non-const
          size_t MemberOffset,  // If the member is an array, otherwise zero
          size_t Bits, unsigned int Shift, bool DirectAssign = false>
using Reg16 = Reg<uint16_t, Base, Layout, Member, MemberOffset, Bits, Shift,
                  DirectAssign>;

template <size_t Bits, unsigned int Shift>
using RegValue16 = RegValue<uint16_t, Bits, Shift>;

// Generate unique "_reserved" field names
#define HARDWARE_REGS_CAT2(a, b) a##b
#define HARDWARE_REGS_CAT(a, b) HARDWARE_REGS_CAT2(a, b)
#define HARDWARE_REGS_LAYOUT_MEMBER_RESERVED \
  HARDWARE_REGS_CAT(_reserved, __COUNTER__)

}  // namespace regs
}  // namespace hardware
}  // namespace qindesign
