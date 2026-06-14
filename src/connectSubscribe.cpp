#include "connectSubscribe.h"

void connectSubscribe(){
  if (!client.connected() && millis() - tkeepConnect > connectTime) {
    if (WiFi.status() != WL_CONNECTED) {

      if (wifiConnected) {
        Serial.println("⚠️ WiFi lost!");
        wifiConnected = false;
        lastReconnectAttempt = millis();
      }

      // Try to reconnect every 10 seconds
      if (millis() - lastReconnectAttempt > 10000) {
        Serial.println("🔄 Attempting WiFi reconnect...");
        WiFi.reconnect();
        lastReconnectAttempt = millis();
      }
      // wifiMulti.run();
      // delay(1000);
      wifiReconnectAttemptCount++;
      if(wifiReconnectAttemptCount>5) {
        if (serial) Serial.println("WiFi reconnect failed. Restarting...");
        delay(1000);
        ESP.restart();
      }
    }
    else {
      wifiReconnectAttemptCount=0;
      if(serial) {
        Serial.println("Attempting MQTT connection...");
        Serial.print("MQTT Server: ");
        Serial.println(SERVER);
        Serial.print("MQTT Username: ");
        Serial.println(MQTT_USERNAME);
        Serial.print("MQTT Key: ");
        Serial.println(MQTT_KEY);
      }
      // Attempt to connect
      // if (client.connect("", ADA_USER_NAME, ADA_ACC_KEY)) {
      if (client.connect("", MQTT_USERNAME, MQTT_KEY)) {
        if(serial) Serial.println("connected");
        // ... and resubscribe
        // Serial.println(ON_TIME);
        // Serial.println(OFF_TIME);
        char motorSwitchTopic[MQTT_USERNAME_SIZE + MOTOR_FEED_SIZE + 2]; // +2 FOR / AND \0
        strcpy(motorSwitchTopic, MQTT_USERNAME);
        strcat(motorSwitchTopic, "/");
        strcat(motorSwitchTopic, MOTOR);
        Serial.print("Topic name: ");
        Serial.println(motorSwitchTopic);
        client.subscribe(motorSwitchTopic, 1);
        
        // char mainTankTopic[MQTT_USERNAME_SIZE + MAINTANK_FEED_SIZE + 2]; // +2 FOR / AND \0
        // strcpy(mainTankTopic, MQTT_USERNAME);
        // strcat(mainTankTopic, "/");
        // strcat(mainTankTopic, MAINTANK);
        // Serial.print("Topic name: ");
        // Serial.println(mainTankTopic);
        // client.subscribe(mainTankTopic, 1);
        // client.subscribe("Umeshp99/feeds/on-time", 1);
        // client.subscribe("Umeshp99/feeds/off-time", 1);
        // client.subscribe("patilect/feeds/+", 1);
  
        delay(1);
        connection = HIGH;
        // getFeedLatest(); //get latest values of feed
      } 
      else {
        if(serial) Serial.print("Failed, rc=");
        if(serial) Serial.print(client.state());
        if(serial) Serial.println(" Retrying soon...!!!");
      }
    }
    tkeepConnect = millis();
  }
}

void checkConnection(){
    //----Connection LED-----
  if(client.connected() && connection == LOW) {
    wifiReconnectAttemptCount=0;
    digitalWrite(LED, LOW); //Connected
    connection = HIGH;
  }
  else if(!client.connected() && connection == HIGH){
    digitalWrite(LED, HIGH); //Not Connected
    connection = LOW;
  }
  //-----------------------
}