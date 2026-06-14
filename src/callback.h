#ifndef callback_h
#define callback_h
#include "Arduino.h"
#include <EEPROM.h>
#include "defines.h"

extern bool serial, motorStatus;
extern String incoming[100];

void callback(char* topic, byte * data, unsigned int length);
void sendNtfyMessage(const String& topic, const String& message);

#endif