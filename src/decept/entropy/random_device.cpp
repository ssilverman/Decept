// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// random_device.cpp implements random_device.
// This file is part of the Decept library.

#include "decept/entropy/random_device.h"

#include <stdexcept>

#include "decept/entropy/entropy.h"

namespace decept {
namespace entropy {

static void ensureInitialized() {
  // static std::once_flag flag;
  // std::call_once(flag, []() { trng_init(); });

  // This is a lightweight alternative to std::call_once
  [[maybe_unused]] static bool initialized = []() {
    if (!trng_is_started()) {
      trng_init();
    }
    return true;
  }();
}

random_device::random_device() : random_device("default") {}

random_device::random_device(const std::string& token) {
  ensureInitialized();
}

random_device::result_type random_device::operator()() {
  result_type r;
  (*this)(&r, sizeof(r));
  return r;
}

void random_device::operator()(void* const buf, const size_t size) {
  if (trng_data(buf, size) != size) {
#if defined(__cpp_exceptions)
    throw std::runtime_error("generation");
#else
    std::__throw_runtime_error("generation");
#endif  // __cpp_exceptions
  }
}

size_t random_device::available() {
  return trng_available();
}

}  // namespace entropy
}  // namespace decept
