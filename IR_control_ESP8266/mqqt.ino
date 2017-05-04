

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
  mqtt_base_topic = mqtt_base_topic + mqtt_client_id + "/";
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
  // Loop until we're reconnected
  while (!mqtt_client.connected()) {
    Serial.print("Intentando conexion MQTT...");
    // Attempt to connect
    // If you do not want to use a username and password, change next line to
    // if (client.connect("ESP8266Client")) {
    if (mqtt_client.connect(mqtt_client_id.c_str(), MQTT_USER, MQTT_PASS)) {
      Serial.println("conectado");
      mqtt_client.subscribe("/BROKER_CASA/SALON/IR_BEACON/#");
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

 //Una vez interpretado el mensaje, pasamos la orden por IR
 //==========
 //CONTROL TV
 //==========
  if ((mqtt_command.equals("TV_POWER"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_power(150);
    Serial.println("POWER EN TV");
  }
  
  if ((mqtt_command.equals("TV_VOL_UP"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_volUp(150);
    Serial.println("VOL+ EN TV");
  }
  
  if ((mqtt_command.equals("TV_VOL_DWN"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_volDwn(150);
    Serial.println("VOL- EN TV");
  }
  
  if ((mqtt_command.equals("TV_PRG_UP"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_prgUp(150);
    Serial.println("PROG+ EN TV");
  }
  
  if ((mqtt_command.equals("TV_PRG_DWN"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_prgDwn(150);
    Serial.println("PROG- EN TV");
  }
  
  if ((mqtt_command.equals("TV_MUTE"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_mute(150);
    Serial.println("MUTE EN TV");
  }
  
  if ((mqtt_command.equals("TV_INFO"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/TV"))) {
    TV_info(150);
    Serial.println("INFO EN TV");
  }

  //============
  //CONTROL CHUWI
  //============
 if ((mqtt_command.equals("CHUWI_CLEAN"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_clean(150);
    Serial.println("CLEAN EN CHUWI");
  }

 if ((mqtt_command.equals("CHUWI_HOME"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_home(150);
    Serial.println("HOME EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_UP"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_up(150);
    Serial.println("UP EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_DOWN"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_down(150);
    Serial.println("DOWN EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_LEFT"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_left(150);
    Serial.println("LEFT EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_RIGHT"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_right(150);
    Serial.println("RIGHT EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_CLOCK"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_clock(150);
    Serial.println("CLOCK EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_MAX"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_max(150);
    Serial.println("MAX EN CHUWI");
  }
  
 if ((mqtt_command.equals("CHUWI_EDGES"))&&(mqtt_topic.equals("/BROKER_CASA/SALON/IR_BEACON/CHUWI"))) {
    chuwi_edges(150);
    Serial.println("EDGES EN CHUWI");
  }
}
