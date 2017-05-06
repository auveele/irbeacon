

// =========
// FUNCIÓN GENERAL SEGÚN PROTOCOLOS
// =========
// Enviamos una señales, con determinada duración en ms

void send_raw_command(unsigned int *code_to_send, int code_size){
  irsend.sendRaw(code_to_send, code_size, khz);
}

void send_rc5_command(const unsigned int code_to_send){
  irsend.sendRC5(code_to_send, 12);
}

// =========
// Para hacer bucle al enviar los IR, sin delays
// =========

// Este es para la TV, que tiene el tiempo fijo.
// No se pasa variables en la función
void ir_attacher(void (*fn)(), int duration){
  ++ir_pulse_count;
  ir_pulse_n = (duration / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, fn);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
}

// Este es para Chuwi, que tiene el tiempo como argumento.
// Se le pasa un int a la función
void ir_attacher_ms(void (*fn)(int), int duration){
  ++ir_pulse_count;
  ir_pulse_n = (duration / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, fn, duration);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
}
