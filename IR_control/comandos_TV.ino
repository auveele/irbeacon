

// =============
// BUTTON CODES
// =============

// TV codes
const unsigned int code_power = 0x4C;
const unsigned int code_volUp = 0x850;
const unsigned int code_volDwn = 0x51;
const unsigned int code_prgUp = 0x60;
const unsigned int code_prgDwn = 0x861;
const unsigned int code_mute = 0x4D;
const unsigned int code_info = 0x852;

// =========
// FUNCIONES DE CADA BOTÓN
// =========

void TV_power(int duration){
  send_rc5_command(duration, code_power, 12);
}

void TV_volUp(int duration){
  send_rc5_command(duration, code_volUp, 12);
}

void TV_volDwn(int duration){
  send_rc5_command(duration, code_volDwn, 12);
}

void TV_prgUp(int duration){
  send_rc5_command(duration, code_prgUp, 12);
}

void TV_prgDwn(int duration){
  send_rc5_command(duration, code_prgDwn, 12);
}

void TV_muter(int duration){
  send_rc5_command(duration, code_mute, 12);
}

void TV_info(int duration){
  send_rc5_command(duration, code_info, 12);
}

