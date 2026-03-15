// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// regs.h defines some useful register-related utilities.
// This file is part of the Decept library.

#include <cstdint>

namespace decept {
namespace util {

// Defines a register group having the given layout and base address.
template <typename Layout, uintptr_t Base>
struct RegGroup {
  static_assert((Base % alignof(Layout)) == 0, "Bad alignment");
  Layout* operator->() const { return reinterpret_cast<Layout*>(Base); }
};

// Generate unique "_reserved" field names
#define LAYOUT_CAT2(a, b) a##b
#define LAYOUT_CAT(a, b) LAYOUT_CAT2(a, b)
#define LAYOUT_MEMBER_RESERVED LAYOUT_CAT(_reserved, __COUNTER__)

}  // namespace util
}  // namespace decept
