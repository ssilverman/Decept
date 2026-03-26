// SPDX-FileCopyrightText: (c) 2023-2026 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcp.c implements the DCP functions.
// This file is part of the Decept library.

#include "decept/dcp/dcp.h"

#include <array>

#include <arm_math.h>  // __DSB() & __ISB()
#include <pgmspace.h>

#include "decept/regs/CCM.h"
#include "decept/regs/DCP.h"
#include "decept/util/dcache.h"
#include "util/atomic.h"

namespace decept {
namespace dcp {

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
    { (1u << 16), &regs::DCP->CH0CMDPTR, &regs::DCP->CH0SEMA, &regs::DCP->CH0STAT, &regs::DCP->CH0STAT_CLR },
    { (1u << 17), &regs::DCP->CH1CMDPTR, &regs::DCP->CH1SEMA, &regs::DCP->CH1STAT, &regs::DCP->CH1STAT_CLR },
    { (1u << 18), &regs::DCP->CH2CMDPTR, &regs::DCP->CH2SEMA, &regs::DCP->CH2STAT, &regs::DCP->CH2STAT_CLR },
    { (1u << 19), &regs::DCP->CH3CMDPTR, &regs::DCP->CH3SEMA, &regs::DCP->CH3STAT, &regs::DCP->CH3STAT_CLR },
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
  regs::CCM_CCGR0_DCP = regs::kCCM_CCGR_ON;

  // CTRL:
  // Reset value:   0xF0800000
  // Default value: 0x30800000
  regs::DCP->CTRL = regs::DCP_CTRL_SFTRESET(1)       |
                    regs::DCP_CTRL_CLKGATE(1)        |
                    regs::DCP_CTRL_PRESENT_CRYPTO(1) |
                    regs::DCP_CTRL_PRESENT_SHA(1)    |
                    regs::DCP_CTRL_GATHER_RESIDUAL_WRITES(1);  // Reset value
  regs::DCP->CTRL_CLR = regs::DCP_CTRL_SFTRESET(1) |
                        regs::DCP_CTRL_CLKGATE(1);  // Default value

  // Clear status
  regs::DCP->STAT_CLR = 0xFF;
  while ((regs::DCP->STAT & 0xFF) != 0) {
    // Wait for clear
  }

  // Clear all channels' status
  regs::DCP->CH0STAT_CLR = 0xFF;
  regs::DCP->CH1STAT_CLR = 0xFF;
  regs::DCP->CH2STAT_CLR = 0xFF;
  regs::DCP->CH3STAT_CLR = 0xFF;

  // Default config:
  // Gather residual writes: true
  // Enable context caching: false
  // Enable context switching: true
  // All channels enabled
  // All interrupts disabled

  regs::DCP->CTRL = regs::DCP_CTRL_GATHER_RESIDUAL_WRITES(1)   |
                    regs::DCP_CTRL_ENABLE_CONTEXT_CACHING(0)   |
                    regs::DCP_CTRL_ENABLE_CONTEXT_SWITCHING(1) |
                    regs::DCP_CTRL_CHANNEL_INTERRUPT_ENABLE(0);

  // Enable DCP channels
  regs::DCP->CHANNELCTRL = regs::DCP_CHANNELCTRL_ENABLE_CHANNEL(0x0F);

  // Use context switching buffer
  regs::DCP->CONTEXT = reinterpret_cast<uint32_t>(s_contextSwitchingBuf);
}

FLASHMEM void deinit() {
  // Disallow register access if off
  if (!isStarted()) {
    return;
  }

  // CTRL reset value: 0xF0800000
  regs::DCP->CTRL = regs::DCP_CTRL_SFTRESET(1)       |
                    regs::DCP_CTRL_CLKGATE(1)        |
                    regs::DCP_CTRL_PRESENT_CRYPTO(1) |
                    regs::DCP_CTRL_PRESENT_SHA(1)    |
                    regs::DCP_CTRL_GATHER_RESIDUAL_WRITES(1);

  // Turn off the clock
  regs::CCM_CCGR0_DCP = regs::kCCM_CCGR_OFF;
}

bool isStarted() {
  // Check only the run-only bit because that's always set when running
  return (regs::CCM_CCGR0_DCP & regs::kCCM_CCGR_RUN_ONLY) ==
         regs::kCCM_CCGR_RUN_ONLY;
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

  if ((regs::DCP->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return false;
  }

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    // Re-check channel
    if ((regs::DCP->STAT & kChannelInfo[channel].mask) ==
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

  if ((regs::DCP->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return States::kContinue;
  }

  static const auto clearStatus = []() {
    regs::DCP->STAT_CLR = 0xFF;
    while ((regs::DCP->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & regs::DCP_CHxSEMA_VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & regs::DCP_CHxSTAT_ERROR_CODE(0xFF)) !=
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
  while ((regs::DCP->STAT & kChannelInfo[channel].mask) ==
         kChannelInfo[channel].mask) {
    // Wait for clear
  }

  static const auto clearStatus = []() {
    regs::DCP->STAT_CLR = 0xFF;
    while ((regs::DCP->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & regs::DCP_CHxSEMA_VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & regs::DCP_CHxSTAT_ERROR_CODE(0xFF)) !=
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
