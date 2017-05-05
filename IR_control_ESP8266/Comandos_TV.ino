

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
  send_rc5_command(TV_DURATION, code_power);
}

void TV_volUp(){
  send_rc5_command(TV_DURATION, code_volUp);
}

void TV_volDwn(){
  send_rc5_command(TV_DURATION, code_volDwn);
}

void TV_prgUp(){
  send_rc5_command(TV_DURATION, code_prgUp);
}

void TV_prgDwn(){
  send_rc5_command(TV_DURATION, code_prgDwn);
}

void TV_mute(){
  send_rc5_command(TV_DURATION, code_mute);
}

void TV_info(){
  send_rc5_command(TV_DURATION, code_info);
}
