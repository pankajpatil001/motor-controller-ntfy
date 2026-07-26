#ifndef controlMotor_h
#define controlMotor_h
#include "Arduino.h"

// extern WiFiClientSecure wificlientsecure;
// extern HTTPClient rpihttp; //HTTP client for RPI server
// extern bool serial, wifiConnected;
extern bool motorStatus;

void checkMotorSwitch();
void sendNtfyMessage(const String& topic, const String& message);
void publishMotorState();

#endif