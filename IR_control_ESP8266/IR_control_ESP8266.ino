
#include <IRremoteESP8266.h>    // For manage the IR transmission with the ESP
#include <ESP8266WiFi.h>        // For ESP8266
#include <PubSubClient.h>       // For MQTT
#include <Ticker.h>             // For avoid blockin functions


// ==========
// DECLARAMOS
// ==========
#define PIN_IR 2
#define PIN_NOTIFY 3
IRsend irsend(PIN_IR); // GPIO 2
Ticker flipper;

// MQTT client
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

//=========
//PIN SETUP
//=========
void setup_pins() {
   pinMode(PIN_NOTIFY, OUTPUT);
}

// ===============
// SETUP PRINCIPAL
// ===============
void setup() {
  irsend.begin();
  Serial.begin(115200);
  Serial.println("\r\nIniciando...");
  setup_pins();
  setup_wifi();
  // setup_ota();
  setup_mqtt();
  Serial.println("Setup completado! Iniciando modulo...");
  led_notification();
}

// ==============
// LOOP PRINCIPAL
// ==============
void loop() {
  loop_mqtt();
}
