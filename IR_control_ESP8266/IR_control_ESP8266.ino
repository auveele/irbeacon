
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
#define wifi_ssid "........"
#define wifi_password "........"

// ===========
// MQTT CONFIG
// ===========
#define mqtt_server "192.168.1....."
#define mqtt_user "....."
#define mqtt_password "......"
String mqtt_client_id = "ESP8266-"; // This text is concatenated with ChipId to get unique client_id


// MQTT Topic configuration
String mqtt_base_topic = "/IR_Beacon/";

// Perifericos
#define TV_topic "TV"
#define Chuwi_topic "CHUWI"

// MQTT client
WiFiClient espClient;
PubSubClient mqtt_client(espClient);

// ======================
// NOTIFICACIÓN DE INICIO
// =====================
void led_notification() {
  digitalWrite(IR_Pin, HIGH);
  delay(200);
  digitalWrite(IR_Pin, LOW);
  delay(200);
  digitalWrite(IR_Pin, HIGH);
  delay(200);
  digitalWrite(IR_Pin, LOW);
  delay(200);
  digitalWrite(IR_Pin, HIGH);
  delay(200);
  digitalWrite(IR_Pin, LOW);
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
