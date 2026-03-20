// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// keys.h defines some key helper functions.
// This file is part of the Decept library.

#pragma once

#include <cstdint>

namespace decept {
namespace keys {

// Sets the "Zeroizable Master Key" in the SNVS. This assumes that there are at
// least 8 readable Dwords in the key. The parameter is a 32-bit pointer to
// help guarantee that the key is 4-byte aligned.
//
// This disables the ZMK and ECC, writes the key, and then reenables the ZMK
// and ECC. The caller should probably check validity and such.
void setSNVSZeroizableMasterKey(const uint32_t* key);

// Checks if the SNVS Zeroizable Master Key is zero.
bool isSNVSZeroizableMasterKeyZero();

// Enables the SNVS Zeroizable Master Key.
void selectSNVSZeroizableMasterKey();

}  // namespace keys
}  // namespace decept
