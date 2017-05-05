
// ==========
// SETUP WIFI
// ==========
void setup_wifi() {
  delay(10);
  Serial.print("Conectando a ");
  Serial.print(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);
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
  // mqtt_base_topic = mqtt_base_topic + mqtt_client_id + "/";
  mqtt_client.setServer(MQTT_SERVER, 1883);
  mqtt_client.setCallback(mqtt_callback);
  mqtt_client.subscribe("/BROKER_CASA/SALON/IR_BEACON/#");
  Serial.printf("   Server IP: %s\r\n", MQTT_SERVER);
  Serial.printf("   Username:  %s\r\n", MQTT_USER);
  Serial.println("   Cliend Id: " + mqtt_client_id);
  Serial.println("   MQTT configurado!");
}

// ==============
// MQTT RECONNECT
// ==============
void mqtt_reconnect() {
  // Loop hasta que reconecte
  while (!mqtt_client.connected()) {
    Serial.print("Intentando conexion MQTT...");
    // Intentamos conexión con user y pass
    if (mqtt_client.connect(mqtt_client_id.c_str(), MQTT_USER, MQTT_PASS)) {
      Serial.println("Conectado!");
      mqtt_client.subscribe(mqtt_base_topic.c_str());
    } else {
      Serial.print("failed, rc=");
      Serial.print(mqtt_client.state());
      Serial.println(" nuevo intento en 5 segundos...");
      // Esperamos 5 segundos para reintento
      delay(5000);
    }
  }
}

// =========
// LOOP MQTT
// =========
void loop_mqtt(){
  // Comprobar conexión de MQTT o reconectar
  if (!mqtt_client.connected()) {
    mqtt_reconnect();
  }
  mqtt_client.loop();
}

// =======================
// MQTT CALLBACK PRINCIPAL
// =======================
void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Recibo: [");
  Serial.print(topic);
  Serial.print("] ");

  String mqtt_command = "";
  String mqtt_topic = (char*)topic;

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    mqtt_command = mqtt_command + (char)payload[i];
  }

  Serial.println();
  Serial.print("topic = ");
  Serial.println(mqtt_topic);
  Serial.print("comando = ");
  Serial.println(mqtt_command);
  Serial.println();

  // ==========
  // CONTROL TV
  // ==========
  if (mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV")) {
    if (mqtt_command.equals("TV_POWER")) {
      TV_power();
    } else if (mqtt_command.equals("TV_VOL_UP")) {
      TV_volUp();
    } else if (mqtt_command.equals("TV_VOL_DWN")) {
      TV_volDwn();
    } else if (mqtt_command.equals("TV_PRG_UP")) {
      TV_prgUp();
    } else if (mqtt_command.equals("TV_PRG_DWN")) {
      TV_prgDwn();
    } else if (mqtt_command.equals("TV_MUTE")) {
      TV_mute();
    } else if (mqtt_command.equals("TV_INFO")) {
      TV_info();
    }
    Serial.println(mqtt_command);
  }

  // =============
  // CONTROL CHUWI
  // =============
  if (mqtt_topic.equals("/BROKER_CASA/TEST/IR_BEACON/CHUWI")) {
    if (mqtt_command.equals("CHUWI_CLEAN")) {
      chuwi_clean(150);
    } else if (mqtt_command.equals("CHUWI_HOME")) {
      chuwi_home(150);
    } else if (mqtt_command.equals("CHUWI_UP")) {
      chuwi_up(150);
    } else if (mqtt_command.equals("CHUWI_DOWN")) {
      chuwi_down(150);
    } else if (mqtt_command.equals("CHUWI_LEFT")) {
      chuwi_left(150);
    } else if (mqtt_command.equals("CHUWI_RIGHT")) {
      chuwi_right(150);
    } else if (mqtt_command.equals("CHUWI_CLOCK")) {
      chuwi_clock(150);
    } else if (mqtt_command.equals("CHUWI_MAX")) {
      chuwi_max(150);
    } else if (mqtt_command.equals("CHUWI_EDGES")) {
      chuwi_edges(150);
    }
    Serial.println(mqtt_command);
  }
}
