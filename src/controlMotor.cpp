#include "controlMotor.h"
#include "defines.h"

void checkMotorSwitch() {
  // Momentary push button wired to GND with INPUT_PULLUP:
  //   not pressed -> HIGH, pressed -> LOW.
  // Each completed press toggles the motor (press once = ON and stays ON,
  // press again = OFF), using millis()-based debouncing so we don't block.
  static bool lastReading = HIGH;      // last raw reading of the pin
  static bool stableState = HIGH;      // debounced button state
  static unsigned long lastChangeTime = 0;
  const unsigned long debounceDelay = 50; // ms

  bool reading = digitalRead(motorSwitch);

  // Reset the debounce timer whenever the raw reading changes (bounce/noise).
  if (reading != lastReading) {
    lastChangeTime = millis();
    lastReading = reading;
  }

  // Accept the reading as stable only after it has held for debounceDelay.
  if ((millis() - lastChangeTime) > debounceDelay && reading != stableState) {
    stableState = reading;

    // Falling edge (HIGH -> LOW) means the button was just pressed.
    if (stableState == LOW) {
      motorStatus = !motorStatus; // Toggle the motor state

      if (motorStatus == HIGH) {
        digitalWrite(motorRelay, HIGH);
        digitalWrite(LED, HIGH);
        Serial.println("Motor turned ON");
        sendNtfyMessage(NTFY_TOPIC, "Motor turned ON");
      } else {
        digitalWrite(motorRelay, LOW);
        digitalWrite(LED, LOW);
        Serial.println("Motor turned OFF");
        sendNtfyMessage(NTFY_TOPIC, "Motor turned OFF");
      }

      // Reflect the new state back to the MQTT feed so the dashboard updates.
      publishMotorState();
    }
  }
}