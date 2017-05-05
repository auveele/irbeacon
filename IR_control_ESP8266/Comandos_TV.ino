

// =============
// BUTTON CODES
// =============

// TV codes
unsigned int code_power = 0x4C;
unsigned int code_volUp = 0x850;
unsigned int code_volDwn = 0x51;
unsigned int code_prgUp = 0x60;
unsigned int code_prgDwn = 0x861;
unsigned int code_mute = 0x4D;
unsigned int code_info = 0x852;

#define TV_DURATION 150

// =========
// FUNCIONES DE CADA BOTÓN
// =========

void TV_power(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_power);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_power);
}

void TV_volUp(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_volUp);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_volUp);
}

void TV_volDwn(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_volDwn);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_volDwn);
}

void TV_prgUp(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_prgUp);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_prgUp);
}

void TV_prgDwn(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_prgDwn);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_prgDwn);
}

void TV_mute(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_mute);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_mute);
}

void TV_info(){
  ++ir_pulse_count;
  ir_pulse_n = (TV_DURATION / sender_delay);
  if (ir_pulse_count < ir_pulse_n ) {
    flipper.attach(sender_delay, TV_info);
  } else {
    ir_pulse_count = 0;
    flipper.detach();
  }
  send_rc5_command(TV_DURATION, code_info);
}
