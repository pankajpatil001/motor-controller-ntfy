/*-------- WiFi Connection Settings -------------*/
// #define ssid1   "ModiInfonet_PKD"
// #define pwd1    "@##pankaj##@"

// #define ssid2    "Bajrangbali2"
// #define pwd2    "11JaiShreeRam11"

// #define ssid3   "Pankaj's iPhone"
// #define pwd3    "iPhone91"

// #define ssid4    "Bajrangbali5"
// #define pwd4    "11JaiShreeRam11"

// #define ssid7   "Redmi Note 4"
// #define pwd7    "ILPatil64"


/*-------- Important IOT Device Settings ---------*/
#define smsHost           "api.textlocal.in"

// #define SERVER            "io.adafruit.com"
#define SERVERPORT        1883
#define MQTT_USERNAME     "patilect"
#define MQTT_USERNAME_SIZE 8
#define MQTT_KEY          "d288fe61159d4fb084882b7de8a13ca6"
#define deviceName        "MotorController" //Specify the name to be seen on network

#define PREAMBLE          "patilect/"
#define MESSAGES          "feeds/messages" //for specific messages related to batches

#define ACCESS_POINT_NAME "Patilect-ESP-AP"
#define ACCESS_POINT_PWD  "PatilectPass" //Password for access point

#define OTA_USERNAME     "pp_admin" //OTA username
#define OTA_PASSWORD     "pp_ota_pass" //OTA password

// EEPROM Layout
#define EEPROM_SIZE       512 //Size of EEPROM in bytes
#define TEMP_PARAM_SIZE   32
#define TEST_PARAM_ADDR   0

#define NTFY_TOPIC        "patilect-motor-controller-2026"
#define STARTUP_NTFN      "Motor Controller is starting up..."
// #define LUMINOSITY        "sensor/luminosity"
// #define FAN               "fan"
// // #define BROODER           "device/brooder"
#define MOTOR             "feeds/motor"
#define MOTOR_FEED_SIZE  12
// #define HUMIDITY          "feeds/humidity"
// #define COOLER            "feeds/cooler"
// #define LIGHT1            "feeds/light1"
#define MAINTANK          "feeds/maintank"
#define MAINTANK_FEED_SIZE 14
// #define PORCHLIGHT        "device/porchlight"
// #define ALARM             "device/alarm"
// #define TEMP              "feeds/temperature"
// #define SECURITY          "device/security"
// #define GETLATEST         "/get"


#define LED                16
#define motorRelay         14
#define motorSwitch        2
// #define echoPin             16
// #define trigPin             4
// #define waterSensorTrigger  15
// #define waterSensor         5
// #define Fan          13
// #define M            15
// #define DHT11_PIN    16
// #define DOOR         5
// #define PIR          4
// #define trigP        1
// #define echoP        3

// #define LIGHTS            "device/lights"
// #define BIGTANKMOTOR      "device/bigtank"
// #define UNDERGROUNDMOTOR  "device/ugtank"
// #define BELL              "device/bell"
// #define LUMINOSITY        "sensor/luminosity"

// #define LED           2
// #define PIR           4
// #define R12           12 // bell
// #define R13           13 // outer lights
// #define R14           14 // big tank motor
// #define R15           15 // underground tank motor
