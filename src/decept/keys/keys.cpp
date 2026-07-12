// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// keys.cpp implements the key helper functions.
// This file is part of the Decept library.

#include "decept/hardware/teensy4/IOMUXC_GPR.h"
#include "decept/hardware/teensy4/SNVS.h"

namespace decept {
namespace keys {

using namespace qindesign::hardware::teensy4;

// See:
// * https://github.com/nxp-mcuxpresso/mcuxsdk-examples/blob/main/driver_examples/snvs_hp/snvs_sw_zmk/snvs_sw_zmk.c
// * https://github.com/nxp-mcuxpresso/legacy-mcux-sdk-examples/blob/main/evkbmimxrt1060/driver_examples/snvs/snvs_sw_zmk/snvs_sw_zmk.c
void setSNVSZeroizableMasterKey(const uint32_t* const key) {
    // Disable the ZMK and ECC first
    SNVS_LPMKCR_ZMK_ECC_EN = false;  // SNVS_LP_EnableZeroizableMasterKeyECC
    SNVS_LPMKCR_ZMK_VAL    = false;  // SNVS_LP_SetZeroizableMasterKeyValid
    SNVS->HPSVSR = SNVS_HPSVSR_ZMK_ECC_FAIL(1);  // SNVS_HP_ClearSecurityViolationStatusFlags

    // Step 1: Set the ZMK key by software
    SNVS_LPMKCR_ZMK_HWP = kSNVS_LPMKCR_ZMK_HWP_SOFTWARE;  // SNVS_LP_SetZeroizableMasterKeyProgramMode
    for (size_t i = 0; i < kSNVS_LPZMKR_count; ++i) {
      SNVS->LPZMKR[i] = key[i];
    }  // SNVS_LP_WriteZeroizableMasterKey

    // Step 2: Enable the ZMK
    SNVS_LPMKCR_ZMK_VAL = true;  // SNVS_LP_SetZeroizableMasterKeyValid

    // Step 3: Enable the ECC
    SNVS_LPMKCR_ZMK_ECC_EN = true;  // SNVS_LP_EnableZeroizableMasterKeyECC
}

bool isSNVSZeroizableMasterKeyZero() {
  return (SNVS_HPSR_ZMK_ZERO_MASK != 0);
}

void selectSNVSZeroizableMasterKey() {
  // Enable master key selection
  SNVS_HPCOMR_MKS_EN = true;

  // Select the zeroizable master key
  SNVS_LPMKCR_MASTER_KEY_SEL = kSNVS_LPMKCR_MASTER_KEY_SEL_ZMK;
}

void selectSNVSKeyLow() {
  IOMUXC_GPR_GPR3_DCP_KEY_SEL             = 0;
  IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX = 0;
}

void selectSNVSKeyHigh() {
  IOMUXC_GPR_GPR3_DCP_KEY_SEL             = 1;
  IOMUXC_GPR_GPR10_DCPKEY_OCOTP_OR_KEYMUX = 0;
}

}  // namespace keys
}  // namespace decept
