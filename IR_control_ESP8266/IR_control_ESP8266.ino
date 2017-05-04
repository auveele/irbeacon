
#include <IRremoteESP8266.h>    // For manage the IR transmission with the ESP
#include <ESP8266WiFi.h>        // For ESP8266
#include <PubSubClient.h>       // For MQTT

// ==========
// DECLARAMOS
// ==========
IRsend irsend(2); // GPIO 2

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
