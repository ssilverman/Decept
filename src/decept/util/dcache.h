// SPDX-FileCopyrightText: (c) 2022-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcache.h defines some utilities for working the ARM data cache.
// This file is part of the Decept library.

// Note: The cache works in multiples of 32.

#pragma once

// C++ includes
#include <cstddef>
#include <cstdint>
#include <cstring>

#include "decept/regs/SCB.h"

namespace decept {
namespace util {

static constexpr size_t kCacheLineSize = 32;

// Performs a dcache operation.
template <volatile uint32_t regs::SCB_Layout::* Member>
[[gnu::always_inline]]
static inline void dcacheOp(const void* const m, const size_t size) {
  if (size == 0) {
    return;
  }

  uint32_t a = reinterpret_cast<uint32_t>(m) & ~(kCacheLineSize - 1u);
  const uint32_t end = reinterpret_cast<uint32_t>(m) + size;

  asm volatile ("dsb 0xF":::"memory");

  do {
    reinterpret_cast<regs::SCB_Layout*>(regs::kSCB_base)->*Member = a;
    a += kCacheLineSize;
  } while (a < end);

  asm volatile ("dsb 0xF":::"memory");
  asm volatile ("isb 0xF":::"memory");
}

[[gnu::always_inline]]
inline void dcacheFlush(const void* const m, const size_t size) {
  dcacheOp<&regs::SCB_Layout::DCCMVAC>(m, size);
}

[[gnu::always_inline]]
inline void dcacheDelete(const void* const m, const size_t size) {
  dcacheOp<&regs::SCB_Layout::DCIMVAC>(m, size);
}

[[gnu::always_inline]]
inline void dcacheFlushDelete(const void* const m, const size_t size) {
  dcacheOp<&regs::SCB_Layout::DCCIMVAC>(m, size);
}

// Clears an object and then flushes and deletes the cache.
inline void reallyClear(void* const p, const size_t size) {
  (void)std::memset(p, 0, size);
  dcacheFlushDelete(p, size);
}

}  // namespace util
}  // namespace decept
