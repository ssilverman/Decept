#include <Arduino.h>

#include "decept/dcp/dcp.h"

#if !defined(PIO_UNIT_TESTING)

// Main program setup.
void setup() {
  Serial.begin(115200);
  while (!Serial && (millis() < 4000)) {
    // Wait for Serial
  }

  // Initialize the DCP module
  decept::dcp::init();
}

// Main program loop.
void loop() {
}

#endif  // !PIO_UNIT_TESTING
