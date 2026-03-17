// SPDX-FileCopyrightText: (c) 2023 Shawn Silverman <shawn@pobox.com>
// SPDX-License-Identifier: AGPL-3.0-or-later

// dcp.c implements the DCP functions.
// This file is part of the Decept library.

#include "decept/dcp/dcp.h"

#include <array>

#include <arm_math.h>  // __DSB() & __ISB()
#include <imxrt.h>
#include <pgmspace.h>

#include "decept/dcp/regs.h"
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
    { (1u << 16), &dcp::regs->CH0CMDPTR, &dcp::regs->CH0SEMA, &dcp::regs->CH0STAT, &dcp::regs->CH0STAT_CLR },
    { (1u << 17), &dcp::regs->CH1CMDPTR, &dcp::regs->CH1SEMA, &dcp::regs->CH1STAT, &dcp::regs->CH1STAT_CLR },
    { (1u << 18), &dcp::regs->CH2CMDPTR, &dcp::regs->CH2SEMA, &dcp::regs->CH2STAT, &dcp::regs->CH2STAT_CLR },
    { (1u << 19), &dcp::regs->CH3CMDPTR, &dcp::regs->CH3SEMA, &dcp::regs->CH3STAT, &dcp::regs->CH3STAT_CLR },
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
  CCM_CCGR0 |= CCM_CCGR0_DCP(CCM_CCGR_ON);

  // CTRL:
  // Reset value:   0xF0800000
  // Default value: 0x30800000
  dcp::regs->CTRL = dcp::CTRL_SFTRESET(true)       |
                    dcp::CTRL_CLKGATE(true)        |
                    dcp::CTRL_PRESENT_CRYPTO(true) |
                    dcp::CTRL_PRESENT_SHA(true)    |
                    dcp::CTRL_GATHER_RESIDUAL_WRITES(true);  // Reset value
  dcp::regs->CTRL_CLR = dcp::CTRL_SFTRESET(true) |
                        dcp::CTRL_CLKGATE(true);  // Default value

  // Clear status
  dcp::regs->STAT_CLR = 0xFF;
  while ((dcp::regs->STAT & 0xFF) != 0) {
    // Wait for clear
  }

  // Clear all channels' status
  dcp::regs->CH0STAT_CLR = 0xFF;
  dcp::regs->CH1STAT_CLR = 0xFF;
  dcp::regs->CH2STAT_CLR = 0xFF;
  dcp::regs->CH3STAT_CLR = 0xFF;

  // Default config:
  // Gather residual writes: true
  // Enable context caching: false
  // Enable context switching: true
  // All channels enabled
  // All interrupts disabled

  dcp::regs->CTRL = dcp::CTRL_GATHER_RESIDUAL_WRITES(true)   |
                    dcp::CTRL_ENABLE_CONTEXT_CACHING(false)  |
                    dcp::CTRL_ENABLE_CONTEXT_SWITCHING(true) |
                    dcp::CTRL_CHANNEL_INTERRUPT_ENABLE(0);

  // Enable DCP channels
  dcp::regs->CHANNELCTRL = dcp::CHANNELCTRL_ENABLE_CHANNEL(0x0F);

  // Use context switching buffer
  dcp::regs->CONTEXT = reinterpret_cast<uint32_t>(s_contextSwitchingBuf);
}

FLASHMEM void deinit() {
  // CTRL reset value: 0xF0800000
  dcp::regs->CTRL = dcp::CTRL_SFTRESET(true)       |
                    dcp::CTRL_CLKGATE(true)        |
                    dcp::CTRL_PRESENT_CRYPTO(true) |
                    dcp::CTRL_PRESENT_SHA(true)    |
                    dcp::CTRL_GATHER_RESIDUAL_WRITES(true);

  // Turn off the clock
  CCM_CCGR0 &= ~CCM_CCGR0_DCP(CCM_CCGR_ON);
}

bool isStarted() {
  // Check only the run-only bit because that's always set when running
  return (CCM_CCGR0 & CCM_CCGR0_DCP(CCM_CCGR_ON_RUNONLY)) ==
         CCM_CCGR0_DCP(CCM_CCGR_ON_RUNONLY);
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

  if ((dcp::regs->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return false;
  }

  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    // Re-check channel
    if ((dcp::regs->STAT & kChannelInfo[channel].mask) ==
        kChannelInfo[channel].mask) {
      return false;
    }

    *kChannelInfo[channel].cmd = reinterpret_cast<uint32_t>(&workPacket);
    arm_dcache_flush(&workPacket, util::multipleOf32(sizeof(workPacket)));
    // util::dcacheFlush(&workPacket, sizeof(workPacket));

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

  if ((dcp::regs->STAT & kChannelInfo[channel].mask) ==
      kChannelInfo[channel].mask) {
    return States::kContinue;
  }

  static const auto clearStatus = []() {
    dcp::regs->STAT_CLR = 0xFF;
    while ((dcp::regs->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & dcp::CHxSEMA_VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & dcp::CHxSTAT_ERROR_CODE(0xFF)) != 0))) {
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
  while ((dcp::regs->STAT & kChannelInfo[channel].mask) ==
         kChannelInfo[channel].mask) {
    // Wait for clear
  }

  static const auto clearStatus = []() {
    dcp::regs->STAT_CLR = 0xFF;
    while ((dcp::regs->STAT & 0xFF) != 0) {
      // Wait for clear
    }
  };

  // Note: The code below could be simplified if clearStatus() was factored out.
  //       However, the NXP code clears the status before clearing the channel
  //       status, so that's what is done here.

  if ((((*kChannelInfo[channel].sema & dcp::CHxSEMA_VALUE(0xFF)) != 0) ||
       ((*kChannelInfo[channel].stat & dcp::CHxSTAT_ERROR_CODE(0xFF)) != 0))) {
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
