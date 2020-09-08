#include "machine.h"

uint8_t shift_offset;
uint8_t shift0;
uint8_t shift1;

uint8_t keys[10];

void machine_in(uint8_t port, uint8_t *value) {
  switch (port) {
    case 0:
      *value = 0;
      *value += 1 << 0;
      *value += 1 << 1;
      *value += 1 << 2;
      *value += 1 << 4;
      break;

    case 1:
      *value = 0;
      *value += keys[KEY_COIN] << 0;
      *value += keys[KEY_P2_START] << 1;
      *value += keys[KEY_P1_START] << 2;
      *value += 1 << 3;
      *value += keys[KEY_P1_FIRE] << 4;
      *value += keys[KEY_P1_LEFT] << 5;
      *value += keys[KEY_P1_RIGHT] << 6;
      break;

    case 2:
      *value = 0;
      *value += keys[KEY_P2_FIRE] << 4;
      *value += keys[KEY_P2_LEFT] << 5;
      *value += keys[KEY_P2_RIGHT] << 6;
      break;

    case 3:
      uint16_t v = (shift1 << 8) | shift0;
      *value = ((v >> (8 - shift_offset)) & 0xff);
      break;

    default:
      break;
  }
}

void machine_out(uint8_t port, uint8_t value) {
  switch (port) {
    case 2:
      shift_offset = value & 0x7;
      break;

    case 4:
      shift0 = shift1;
      shift1 = value;
      break;

    default:
      break;
  }
}

void machine_set_key(uint8_t key, uint8_t value) {
  keys[key] = value;
}

void machine_init() {
  for (int i = 0; i < 10; i++) {
    keys[i] = 0;
  }
}
