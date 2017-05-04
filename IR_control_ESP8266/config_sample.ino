
// ==========
// Archivo para el respositorio, renombrar a 'config' para compilar.
// El archivo config.ino se ignorará al hacer un commit para no
// publicar las credenciales.
//
// Ignorar manualmente el config_sample.ino al hacer el commit para que
// no elimine el archivo actual de ejemplo.
// ==========


// ===========
// WIFI CONFIG
// ===========
#define wifi_ssid "wifi_ssid"
#define wifi_password "wifi_pass"

// ===========
// MQTT SERVER
// ===========
#define mqtt_server "mqtt_ip"
#define mqtt_user "mqtt_user"
#define mqtt_password "mqtt_pass"

// ===========
// MQTT CLIENT
// ===========
String mqtt_client_id = "ESP8266-";         // This text is concatenated with ChipId to get unique client_id
String mqtt_base_topic = "/IR_Beacon/";     // MQTT Topic configuration

// Perifericos
#define TV_topic "TV"
#define Chuwi_topic "CHUWI"
