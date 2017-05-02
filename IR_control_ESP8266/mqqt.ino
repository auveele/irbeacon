

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

// =========
// LOOP MQTT
// =========
void loop_mqtt(){
  // Comprobar conexión de MQTT o reconectar
  if (!mqtt_client.connected()) { mqtt_reconnect(); }
  mqtt_client.loop();
}

// =======================
// MQTT CALLBACK PRINCIPAL
// =======================
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Recibo: [");
  Serial.print(topic);
  Serial.print("] ");
  char comando = (char)payload[0];
  String rutaTopic = "";

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    rutaTopic = rutaTopic + payload[i];
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
  
}
