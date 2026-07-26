#include "publish.h"

// Publish the current motor state to the MQTT feed so the Adafruit IO
// dashboard stays in sync when the motor is toggled locally (button).
// Published retained so the feed reflects the latest state to new clients.
void publishMotorState(){
  if (!client.connected()) return;
  const char* state = motorStatus ? "ON" : "OFF";
  client.publish(PREAMBLE MOTOR, state, true);
  if (serial) {
    Serial.print("Published motor state to MQTT: ");
    Serial.println(state);
  }
}

void publishFeeds(){
    
  //------------------------RSSI-----------------------------
  if (millis() - tkeepRssi > rssiTime && client.connected()) {
    String str = "Motor Controller Device IP "; 
    str+= WiFi.localIP().toString();
    str+= ", RSSI ";
    str+= (String)WiFi.RSSI();
    str+= " dBm\n";
    str.toCharArray(valueStr, 80);
    Serial.println(str);
    client.publish(PREAMBLE MESSAGES, valueStr);
    tkeepRssi = millis();
  }
  //------------------------RSSI-----------------------------

  // if (millis() - tkeepMainTankLevel > mainTankLevelTime && client.connected()) {
  //   String str = (String)mainTankWaterLevel;
  //   str.toCharArray(valueStr, 70);
  //   Serial.println(str);
  //   if (mainTankWaterLevel != 0) client.publish(PREAMBLE MAINTANK, valueStr);
  //   tkeepMainTankLevel = millis();
  // }

  // if (millis() - tkeepNtfy > ntfyTime && client.connected() && ((mainTankWaterLevel < ntfyLowerThreshold) || (mainTankWaterLevel > ntfyUpperThreshold))) {
  //   String str = "";
  //   str += "Tank level is " + (String)mainTankWaterLevel + "%.";
  //   if (mainTankWaterLevel < ntfyLowerThreshold) {
  //     str += "\nPlease turn motor ON.";
  //   } else if (mainTankWaterLevel > ntfyUpperThreshold) {
  //     str += "\nPlease turn motor OFF.";
  //   }
  //   // String str = (String)mainTankWaterLevel;
  //   str.toCharArray(valueStr, 120);
  //   Serial.println(str);
  //   sendNtfyMessage(NTFY_TOPIC, valueStr);
  //   tkeepNtfy = millis();
  // }
  // if (client.connected() && firstTime && coolerState) {
  //   String str = "ON";
  //   str.toCharArray(valueStr, 10);
  //   client.publish(PREAMBLE COOLER, valueStr);
  //   firstTime = LOW;
  // }
}