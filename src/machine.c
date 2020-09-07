#include "machine.h"

uint8_t shift_offset;
uint8_t shift0;
uint8_t shift1;

void machine_in(uint8_t port, uint8_t *value) {
  switch (port) {
    case 0:
      *value = 1;
      break;

    case 1:
      *value = 0;
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
