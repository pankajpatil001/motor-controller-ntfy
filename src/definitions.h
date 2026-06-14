#ifndef definitions_h
#define definitions_h

#include <Arduino.h>
#include "webupdater.h" //Add Web Update feature instead of OTA
#include "callback.h"
#include "publish.h"
#include "connectSubscribe.h"
#include "ntfy.h"
#include "defines.h"

//--------------------Ultrasonic---------------------
unsigned long duration, tkeepMainTankLevel=1000;
unsigned int mainTankWaterLevel=0, prevMainTankWaterLevel=0, mainTankLevelTime=10000, mainTankFullReading=15, mainTankEmptyReading=98, errorMargin=7;
//---------------------------------------------------

//-----------------------
unsigned long tkeepTemp=1000, tkeepRssi=6000, tkeepLight=2000, tkeepchkTemp = 3000, tkeepWaterLevel = 5000, waterLevelTime = 3000, waterLevelTimeHigh = 600000, waterLevelTimeLow = 10000;
unsigned int ntfyLowerThreshold = 21, ntfyUpperThreshold = 93;
unsigned long tkeepNtfy = 2000, ntfyTime = 12 * 60 * 1000; // notify every 30 minutes on crossing threshold
// unsigned long tkeepUS = 500, tkeepUSpub = 1500, tkeepHum = 4000, tBuzz = 0;
unsigned long tgetLight = 5000, tkeepConnect=0;//, tkeepDoor=1000, tkeepPIR=1500;
unsigned int rssiTime = 10000, tempTime = 120000;//, lightTime = 10000, humTime = 10000, lightinty = 0;
unsigned int connectTime = 5000, chkTempTime = 1000;//, dhtTime = 3000, getLight = 5000;
// unsigned int doorTime = 1000, pirTime = 1000, usTime = 2000, uspubTime = 10000, buzzTime = 5000;

uint8_t ti = 0;
int val = 0;
double t = 0;
double lmTemp = 0, t1 = 0;
double ts[20] = {0};

char valueStr[100];
String incoming[100];
uint8_t c=0;//, addr_L1=100, addr_L=101, addr_security=102, addr_M=103, minLight = 35, maxLight = 40;
// byte stat_L1, stat_L, security_state, stat_M;

// //-----------------------------------dht---------------------------------------------------------
// double Vcc = 3.33;
float temp = 0;//, hum = 0, prevTemp = 0, prevHum = 0;
// //-----------------------------------------------------------------------------------------------

// //--------------------------------------------------------------------------------
bool connection = LOW, firstTime = HIGH, smart = HIGH, waterLevel = LOW, motorStatus = LOW, coolerState = LOW;//, doorState = LOW, lightStatus = LOW;
//-----------------------------------------------------------------------------------------------
char SERVER[16] = "io.adafruit.com";
uint8_t wifiReconnectAttemptCount=0;
// const char* firmwareURL = "https://github.com/pankajpatil001/overhead-tank-ntfy/raw/refs/heads/master/firmwares/nodemcuv2.bin";
const char* firmwareURL = "https://raw.githubusercontent.com/pankajpatil001/overhead-tank-ntfy/master/firmwares/nodemcuv2.bin";

bool wifiConnected = LOW;
// Parameters from initial setup
char testParam[TEMP_PARAM_SIZE];
unsigned long lastReconnectAttempt=0;
bool configFreshlySaved;
//-----------------------------Webupdater---------------------------------

const char* loginIndex =
 "<form name='loginForm'>"
    "<table width='30%' bgcolor='A09F9F' align='center'>"
        "<tr>"
            "<td colspan=2>"
                "<center><font size=4><b>Patilect Smart Solutions</b></font></center>"
                "<center><font size=3><b>Motor Controller Device</b></font></center>"
                "<br>"
            "</td>"
            "<br>"
            "<br>"
        "</tr>"
        "<tr>"
             "<td>Username:</td>"
             "<td><input type='text' size=25 name='userid'><br></td>"
        "</tr>"
        "<br>"
        "<br>"
        "<tr>"
            "<td>Password:</td>"
            "<td><input type='Password' size=25 name='pwd'><br></td>"
            "<br>"
            "<br>"
        "</tr>"
        "<tr>"
            "<td><input type='submit' onclick='check(this.form)' value='Login'></td>"
        "</tr>"
    "</table>"
"</form>"
"<script>"
    "function check(form)"
    "{"
    "if(form.userid.value=='Patilect' && form.pwd.value=='SmartSolutions')"
    "{"
    "window.open('/serverIndex')"
    "}"
    "else"
    "{"
    " alert('Error Password or Username')/*displays error message*/"
    "}"
    "}"
"</script>";

/*
 * Server Index Page
 */

const char* serverIndex =
"<script src='https://ajax.googleapis.com/ajax/libs/jquery/3.2.1/jquery.min.js'></script>"
"<form method='POST' action='#' enctype='multipart/form-data' id='upload_form'>"
   "<input type='file' name='update'>"
        "<input type='submit' value='Update'>"
    "</form>"
 "<div id='prg'>progress: 0%</div>"
 "<script>"
  "$('form').submit(function(e){"
  "e.preventDefault();"
  "var form = $('#upload_form')[0];"
  "var data = new FormData(form);"
  " $.ajax({"
  "url: '/update',"
  "type: 'POST',"
  "data: data,"
  "contentType: false,"
  "processData:false,"
  "xhr: function() {"
  "var xhr = new window.XMLHttpRequest();"
  "xhr.upload.addEventListener('progress', function(evt) {"
  "if (evt.lengthComputable) {"
  "var per = evt.loaded / evt.total;"
  "$('#prg').html('progress: ' + Math.round(per*100) + '%');"
  "}"
  "}, false);"
  "return xhr;"
  "},"
  "success:function(d, s) {"
  "console.log('success!')"
 "},"
 "error: function (a, b, c) {"
 "}"
 "});"
 "});"
 "</script>";

WiFiClient wificlient;
WiFiClientSecure wificlientsecure;
HTTPClient rpihttp; //HTTP client for RPI server
// create MQTT object
PubSubClient client(wificlient);
const char* host = "test-device";
bool serial = HIGH;

// ESP8266WiFiMulti wifiMulti;
ESP8266WebServer httpServer(80); //Choose any number you want, just add this after your ip adrs
ESP8266HTTPUpdateServer httpUpdater; //http://<local-ip>:<any-number>/ as server address

//-------------------------------------------------------


#endif