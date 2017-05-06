

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
  ir_attacher(&TV_power, TV_DURATION);
  send_rc5_command(code_power);
}

void TV_volUp(){
  ir_attacher(&TV_volUp, TV_DURATION);
  send_rc5_command(code_volUp);
}

void TV_volDwn(){
  ir_attacher(&TV_volDwn, TV_DURATION);
  send_rc5_command(code_volDwn);
}

void TV_prgUp(){
  ir_attacher(&TV_prgUp, TV_DURATION);
  send_rc5_command(code_prgUp);
}

void TV_prgDwn(){
  ir_attacher(&TV_prgDwn, TV_DURATION);
  send_rc5_command(code_prgDwn);
}

void TV_mute(){
  ir_attacher(&TV_mute, TV_DURATION);
  send_rc5_command(code_mute);
}

void TV_info(){
  ir_attacher(&TV_info, TV_DURATION);
  send_rc5_command(code_info);
}
