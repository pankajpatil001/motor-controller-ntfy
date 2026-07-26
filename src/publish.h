#ifndef publish_h
#define publish_h
#include "Arduino.h"
#include <PubSubClient.h>
#include <ESP8266WiFi.h>
#include "ntfy.h"
#include "defines.h"
// #include "temperature.h"

extern unsigned long tkeepMainTankLevel, tkeepRssi;
extern unsigned long tkeepNtfy, ntfyTime;
extern unsigned int rssiTime, mainTankLevelTime, mainTankWaterLevel;
extern PubSubClient client;
extern char valueStr[100];
extern bool serial;
extern bool motorStatus;
extern unsigned int ntfyLowerThreshold, ntfyUpperThreshold;

void publishFeeds();
void publishMotorState();
void sendNtfyMessage(const String& topic, const String& message);

#endif