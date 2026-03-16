#include <Arduino.h>

#include "decept/dcp/dcp.h"

#if !defined(PIO_UNIT_TESTING)

static uint32_t kStartupDelay = 1500;

// Main program setup.
void setup() {
  Serial.begin(115200);
  while (!Serial && (millis() < 4000)) {
    // Wait for Serial
  }
  delay(kStartupDelay);
  printf("Starting...\r\n");

  // Initialize the DCP module
  decept::dcp::init();
  printf("DCP initialized\r\n");
}

// Main program loop.
void loop() {
}

#endif  // !PIO_UNIT_TESTING
