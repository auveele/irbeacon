
#include <IRremoteESP8266.h>    // For manage the IR transmission with the ESP
#include <ESP8266WiFi.h>        // For ESP8266
#include <PubSubClient.h>       // For MQTT

/*
#include <ESP8266mDNS.h>        // For OTA
#include <WiFiUdp.h>            // For OTA
#include <ArduinoOTA.h>         // For OTA
*/

// IR led attached to the GPIO2
IRsend irsend(2);

// WIFI configuration
#define wifi_ssid "........"
#define wifi_password "........"

// ==========
// MQTT CONFIG
// ==========
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

// Necesario para hacer que ArduinoIDE autodetecte el servicio OTA
// WiFiServer TelnetServer(8266);

// ==========
// MQTT CALLBACK PRINCIPAL
// ==========
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Recibo: [");
  Serial.print(topic);
  Serial.print("] ");
  char comando = (char)payload[0];
  String rutaTopic = "";

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    rutaTopic = rutaTopic + payloa
  }

  Serial.println();
  Serial.print("topic = ");
  Serial.println(topic);
  Serial.print("comando = ");
  Serial.println(comando);
  Serial.println();

 //Una vez interpretado el mensaje, pasamos la orden por IR
  if ((comando == 'TV_POWER')&&(rutaTopic.equals("/IR_Beacon/TV"))) {
    TV_power(150);
    Serial.println("POWER EN TV");
  }
//-------------------------------------------------------------------------------

// ==========
// SETUP WIFI
// ==========
void setup_wifi() {
  delay(10);
  Serial.print("Conectando a ");
  Serial.print(wifi_ssid);
  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("OK");
  Serial.print("   IP: ");
  Serial.println(WiFi.localIP());
}

/*
void setup_ota() {
  Serial.print("Configurando servicio OTA...");
  TelnetServer.begin();   // Necesary to make Arduino Software autodetect OTA device

  ArduinoOTA.onStart([]() {
    Serial.println("Iniciando OTA...");
  });
  ArduinoOTA.onEnd([]() {
    Serial.println("OTA update finalizado!");
    Serial.println("Reiniciando...");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("OTA en progreso: %u%%\r\n", (progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
    else if (error == OTA_END_ERROR) Serial.println("End Failed");
  });
  ArduinoOTA.begin();
  // ArduinoOTA.setPassword((const char *)"123");
  Serial.println("OK");
}
*/

// ==========
// SETUP MQTT
// ==========
void setup_mqtt() {
  Serial.println("Configurando cliente MQTT...");
  mqtt_client_id = mqtt_client_id + ESP.getChipId();
  mqtt_base_topic = mqtt_base_topic + mqtt_client_id + "/";
  mqtt_client.setServer(mqtt_server, 1883);
  mqtt_client.setCallback(mqtt_callback);
  mqtt_client.subscribe("/IR_Beacon/#");
  Serial.printf("   Server IP: %s\r\n", mqtt_server);
  Serial.printf("   Username:  %s\r\n", mqtt_user);
  Serial.println("   Cliend Id: " + mqtt_client_id);
  Serial.println("   MQTT configurado!");
}

// Notificación led para asegurar visualmente el correcto arranque del programa.
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
// MQTT RECONNECT
// ==============
void mqtt_reconnect() {
  // Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print("Intentando conexion MQTT...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (mqtt_client.connect(mqtt_client_id.c_str(), mqtt_user, mqtt_password)) {
      Serial.println("conectado");
      mqtt_client.subscribe("/IR_BeaconN/#");
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" nuevo intento en 5 segundos");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

// ==============
// LOOP PRINCIPAL
// ==============
void loop() {
  // Controlador del OTA
  // ArduinoOTA.handle();
  
  // Comprobar conexión de MQTT o reconectar
  if (!mqtt_client.connected()) {
    mqtt_reconnect();
  }
  mqtt_client.loop();
}
