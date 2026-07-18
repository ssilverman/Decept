// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcp.c implements the DCP functions.
// This file is part of the Decept library.

#include "decept/dcp/dcp.h"

#include <array>

#include <arm_math.h>  // __DSB() & __ISB()
#include <pgmspace.h>

#include "decept/hardware/imxrt1060/CCM.h"
#include "decept/hardware/imxrt1060/DCP.h"
#include "decept/util/dcache.h"
#include "util/atomic.h"

namespace decept {
namespace dcp {

using namespace qindesign::hardware::imxrt1060;

// --------------------------------------------------------------------------
//  Internal
// --------------------------------------------------------------------------

namespace {

  // Channel information.
const struct {
  uint32_t mask;
  volatile uint32_t* cmd;
  volatile uint32_t* sema;
  volatile uint32_t* stat;
  volatile uint32_t* statClr;
} kChannelInfo[4] = {
    { (1u << 16), &DCP::group->CH0CMDPTR, &DCP::group->CH0SEMA, &DCP::group->CH0STAT, &DCP::group->CH0STAT_CLR },
    { (1u << 17), &DCP::group->CH1CMDPTR, &DCP::group->CH1SEMA, &DCP::group->CH1STAT, &DCP::group->CH1STAT_CLR },
    { (1u << 18), &DCP::group->CH2CMDPTR, &DCP::group->CH2SEMA, &DCP::group->CH2STAT, &DCP::group->CH2STAT_CLR },
    { (1u << 19), &DCP::group->CH3CMDPTR, &DCP::group->CH3SEMA, &DCP::group->CH3STAT, &DCP::group->CH3STAT_CLR },
};

constexpr size_t kNumChannels = std::size(kChannelInfo);

}  // namespace

// --------------------------------------------------------------------------
//  Implementation
// --------------------------------------------------------------------------

// DCP context switching buffer. Shouldn't be cacheable.
alignas(32) static uint32_t s_contextSwitchingBuf[208 / sizeof(uint32_t)];

FLASHMEM void init() {
  // Enable the clock
  CCM::CCGR0::DCP = CCM::CCGR::kON;

  // CTRL:
  // Reset value:   0xF0800000
  // Default value: 0x30800000
  DCP::group->CTRL = DCP::CTRL::SFTRESET(1)       |
                     DCP::CTRL::CLKGATE(1)        |
                     DCP::CTRL::PRESENT_CRYPTO(1) |
                     DCP::CTRL::PRESENT_SHA(1)    |
                     DCP::CTRL::GATHER_RESIDUAL_WRITES(1);  // Reset value
  DCP::group->CTRL_CLR = DCP::CTRL::SFTRESET(1) |
                         DCP::CTRL::CLKGATE(1);  // Default value

  // Clear status
  DCP::group->STAT_CLR = 0xFF;
  while ((DCP::group->STAT & 0xFF) != 0) {
    // Wait for clear
  }

  // Clear all channels' status
  DCP::group->CH0STAT_CLR = 0xFF;
  DCP::group->CH1STAT_CLR = 0xFF;
  DCP::group->CH2STAT_CLR = 0xFF;
  DCP::group->CH3STAT_CLR = 0xFF;

  // Default config:
  // Gather residual writes: true
  // Enable context caching: false
  // Enable context switching: true
  // All channels enabled
  // All interrupts disabled

  DCP::group->CTRL = DCP::CTRL::GATHER_RESIDUAL_WRITES(1)   |
                     DCP::CTRL::ENABLE_CONTEXT_CACHING(0)   |
                     DCP::CTRL::ENABLE_CONTEXT_SWITCHING(1) |
                     DCP::CTRL::CHANNEL_INTERRUPT_ENABLE(0);

  // Enable DCP channels
  DCP::group->CHANNELCTRL = DCP::CHANNELCTRL::ENABLE_CHANNEL(0x0F);

  // Use context switching buffer
  DCP::group->CONTEXT = reinterpret_cast<uint32_t>(s_contextSwitchingBuf);
}

FLASHMEM void deinit() {
  // Disallow register access if off
  if (!isStarted()) {
    return;
  }

  // CTRL reset value: 0xF0800000
  DCP::group->CTRL = DCP::CTRL::SFTRESET(1)       |
                     DCP::CTRL::CLKGATE(1)        |
                     DCP::CTRL::PRESENT_CRYPTO(1) |
                     DCP::CTRL::PRESENT_SHA(1)    |
                     DCP::CTRL::GATHER_RESIDUAL_WRITES(1);

  // Turn off the clock
  CCM::CCGR0::DCP = CCM::CCGR::kOFF;
}

bool isStarted() {
  // Check only the run-only bit because that's always set when running
  return (CCM::CCGR0::DCP & CCM::CCGR::kRUN_ONLY) == CCM::CCGR::kRUN_ONLY;
}

// Disable optimizations for GCC to prevent instruction reordering
#if defined(__GNUC__)
#pragma GCC push_options
#pragma GCC optimize("O0")
#endif
bool scheduleWork(size_t channel, WorkPacket& workPacket) {
  if (channel >= kNumChannels) {
    return false;
  }

  if ((DCP::group->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return false;
  }

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    // Re-check channel
    if ((DCP::group->STAT & kChannelInfo[channel].mask) ==
        kChannelInfo[channel].mask) {
      return false;
    }

    *kChannelInfo[channel].cmd = reinterpret_cast<uint32_t>(&workPacket);
    util::dcacheFlush(&workPacket, sizeof(workPacket));

    // Call these here because that's what the NXP SDK does
    // (They synchronize stuff)
    __DSB();
    __ISB();

    *kChannelInfo[channel].sema = 1;  // Start the job
  }

  return true;
}
#if defined(__GNUC__)
#pragma GCC pop_options
#endif

States isChannelComplete(const size_t channel) {
  if (channel >= kNumChannels) {
    return States::kNotScheduled;
  }

  if ((DCP::group->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return States::kContinue;
  }

  static const auto clearStatus = []() {
    DCP::group->STAT_CLR = 0xFF;
    while ((DCP::group->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & DCP::CHxSEMA::VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & DCP::CHxSTAT::ERROR_CODE(0xFF)) !=
        0))) {
    clearStatus();

    // Clear channel status
    *kChannelInfo[channel].statClr = 0xFF;

    return States::kNotScheduled;
  }

  clearStatus();
  return States::kComplete;
}

bool waitForChannelComplete(const size_t channel) {
  if (channel >= kNumChannels) {
    return false;
  }

  // Wait while the channel is still active
  while ((DCP::group->STAT & kChannelInfo[channel].mask) ==
         kChannelInfo[channel].mask) {
    // Wait for clear
  }

  static const auto clearStatus = []() {
    DCP::group->STAT_CLR = 0xFF;
    while ((DCP::group->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & DCP::CHxSEMA::VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & DCP::CHxSTAT::ERROR_CODE(0xFF)) !=
        0))) {
    clearStatus();

    // Clear channel status
    *kChannelInfo[channel].statClr = 0xFF;

    return false;
  }

  clearStatus();
  return true;
}

}  // namespace dcp
}  // namespace decept
