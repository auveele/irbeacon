
// ==========
// Archivo para el respositorio, renombrar a 'config' para compilar.
// El archivo config.ino se ignorará al hacer un commit para no
// publicar las credenciales.
//
// Si este archivo es modificado,
// eliminar del .ignore para que se sincronice.
// ==========


// ===========
// WIFI CONFIG
// ===========
#define WIFI_SSID "WIFI_SSID"
#define WIFI_PASS "WIFI_PASS"

// ===========
// MQTT SERVER
// ===========
#define MQTT_SERVER "MQTT_SERVER"
#define MQTT_USER "MQTT_USER"
#define MQTT_PASS "MQTT_PASS"

// ===========
// MQTT CLIENT
// ===========
String mqtt_client_id = "ESP8266-";         // This text is concatenated with ChipId to get unique client_id
String mqtt_base_topic = "/IR_Beacon/";     // MQTT Topic configuration

// Perifericos
#define TV_topic "TV"
#define Chuwi_topic "CHUWI"
