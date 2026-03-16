// SPDX-FileCopyrightText: (c) 2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// states.h defines API states.
// This file is part of the Decept library.

#pragma once

namespace decept {

// States contains the possible return values for the non-blocking API.
enum class States {
  kNotScheduled,
  kWaitingForSchedule,
  kScheduled,
  kComplete,
};

}  // namespace decept
