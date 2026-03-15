// SPDX-FileCopyrightText: (c) 2022-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcache.h defines some utilities for working the ARM data cache.
// This file is part of the Decept library.

// Note: The cache works in multiples of 32.

#pragma once

// C++ includes
#include <cstdint>
#include <cstring>

#include <imxrt.h>

namespace decept {
namespace util {

[[nodiscard]] [[gnu::always_inline]]
inline uint32_t multipleOf32(const uint32_t x) {
  return (x + 31u) & ~31u;
}

// Calls a DCache function on the given address and size. This also handles
// non-aligned addresses and sizes that are not a multiple of 32.
[[gnu::always_inline]]
inline void dcacheArgs(void (*fn)(void* addr, uint32_t size),
                              const void* const addr, const size_t size) {
  fn((void*)((uintptr_t)addr & ~((uintptr_t)31)),
     multipleOf32(size + ((uintptr_t)addr & (uintptr_t)31)));
}

[[gnu::always_inline]]
inline void dcacheFlush(const void* const addr, const size_t size) {
  dcacheArgs(&arm_dcache_flush, addr, size);
}

[[gnu::always_inline]]
inline void dcacheFlushDelete(const void* const addr,
                                     const size_t size) {
  dcacheArgs(&arm_dcache_flush_delete, addr, size);
}

[[gnu::always_inline]]
inline void dcacheDelete(const void* const addr, const size_t size) {
  dcacheArgs(&arm_dcache_delete, addr, size);
}

// Clears an object and then flushes and deletes the cache.
[[gnu::always_inline]]
inline void reallyClear(void* const p, const size_t size) {
  std::memset(p, 0, size);
  dcacheFlushDelete(p, size);
}

}  // namespace util
}  // namespace decept
