

// =========
// FUNCIÓN GENERAL SEGÚN PROTOCOLOS
// =========
// Enviamos una señales, con determinada duración en ms

void send_raw_command(int duration, unsigned int *code_to_send, int code_size){
  unsigned long actual_time = millis();
  while ((millis() - actual_time) < duration) {
    irsend.sendRaw(code_to_send, code_size, khz);
    delay(sender_delay);
  }
  delay(end_delay);
}

void send_rc5_command(int duration, const unsigned int code_to_send){
unsigned long actual_time = millis();
  while ((millis() - actual_time) < duration) {
    irsend.sendRC5(code_to_send, 12);
    delay(sender_delay);
  }
  delay(end_delay);
}
