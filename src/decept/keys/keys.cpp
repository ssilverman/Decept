// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// keys.cpp implements the key helper functions.
// This file is part of the Decept library.

#include "decept/regs/SNVS.h"

namespace decept {
namespace keys {

// See:
// * https://github.com/nxp-mcuxpresso/mcuxsdk-examples/blob/main/driver_examples/snvs_hp/snvs_sw_zmk/snvs_sw_zmk.c
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk-examples/blob/main/evkbmimxrt1060/driver_examples/snvs/snvs_sw_zmk/snvs_sw_zmk.c
void setSNVSZeroizableMasterKey(const uint32_t* const key) {
    // Disable the ZMK and ECC first
    regs::SNVS_LPMKCR_ZMK_ECC_EN = false;  // SNVS_LP_EnableZeroizableMasterKeyECC
    regs::SNVS_LPMKCR_ZMK_VAL    = false;  // SNVS_LP_SetZeroizableMasterKeyValid
    regs::SNVS->HPSVSR = regs::SNVS_HPSVSR_ZMK_ECC_FAIL.v(1);  // SNVS_HP_ClearSecurityViolationStatusFlags

    // Step 1: Set the ZMK key by software
    regs::SNVS_LPMKCR_ZMK_HWP = regs::kSNVS_LPMKCR_ZMK_HWP_SOFTWARE;  // SNVS_LP_SetZeroizableMasterKeyProgramMode
    for (size_t i = 0; i < regs::kSNVS_LPZMKR_count; ++i) {
      regs::SNVS->LPZMKR[i] = key[i];
    }  // SNVS_LP_WriteZeroizableMasterKey

    // Step 2: Enable the ZMK
    regs::SNVS_LPMKCR_ZMK_VAL = true;  // SNVS_LP_SetZeroizableMasterKeyValid

    // Step 3: Enable the ECC
    regs::SNVS_LPMKCR_ZMK_ECC_EN = true;  // SNVS_LP_EnableZeroizableMasterKeyECC
}

}  // namespace keys
}  // namespace decept
