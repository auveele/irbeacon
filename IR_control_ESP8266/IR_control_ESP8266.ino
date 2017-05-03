
#include <IRremoteESP8266.h>    // For manage the IR transmission with the ESP
#include <ESP8266WiFi.h>        // For ESP8266
#include <PubSubClient.h>       // For MQTT

// ==========
// DECLARAMOS
// ==========
IRsend irsend(2); // GPIO 2

// ===========
// WIFI CONFIG
// ===========
#define wifi_ssid "IOT"
#define wifi_password "C4ch4rr30!"

// ===========
// MQTT CONFIG
// ===========
#define mqtt_server "192.168.1.131"
#define mqtt_user "bas"
#define mqtt_password "1234"
String mqtt_client_id = "ESP8266-"; // This text is concatenated with ChipId to get unique client_id


// MQTT Topic configuration
String mqtt_base_topic = "/IR_Beacon/";

// Perifericos
#define TV_topic "TV"
#define Chuwi_topic "CHUWI"

// MQTT client
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

// ===============
// SETUP PRINCIPAL
// ===============
void setup() {
  irsend.begin();
  Serial.begin(115200);
  Serial.println("\r\nIniciando...");
  setup_wifi();
  // setup_ota();
  setup_mqtt();
  Serial.println("Setup completado! Iniciando modulo...");
}

// ==============
// LOOP PRINCIPAL
// ==============
void loop() {
  loop_mqtt();  
}
