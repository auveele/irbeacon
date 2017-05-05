

// =========
// FUNCIÓN GENERAL SEGÚN PROTOCOLOS
// =========
// Enviamos una señales, con determinada duración en ms

void send_raw_command(int duration, unsigned int *code_to_send, int code_size){
  irsend.sendRaw(code_to_send, code_size, khz);
}

void send_rc5_command(int duration, const unsigned int code_to_send){
  irsend.sendRC5(code_to_send, 12);
}
