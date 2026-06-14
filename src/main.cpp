#include "definitions.h"

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(motorRelay, OUTPUT);
  pinMode(motorSwitch, INPUT);

  digitalWrite(motorRelay, LOW); // Ensure the motor relay is off at startup
  for (int i = 0; i < 6; i++) {
    digitalWrite(LED, HIGH); // Turn on the LED to indicate startup
    delay(200);
    digitalWrite(LED, LOW); // Turn off the LED to indicate startup
    delay(200);
  }
  
  if(serial) Serial.begin(115200);      
  delay(10);
  if(serial) Serial.println();
  delay(10);
  WiFi_httpStuff(); //handles everything wrt wifi and http server

  client.setServer(SERVER, SERVERPORT);
  client.setCallback(callback);

  setupHTTPRoutes();
  startHTTPServer(); // Start the HTTP server after WiFi connection
  sendNtfyMessage(NTFY_TOPIC, STARTUP_NTFN);
}

//
void loop() {
  httpServer.handleClient();
  // MDNS.update();

  checkConnection();
  connectSubscribe();
  publishFeeds();

  client.loop();  
  yield();
}