#pragma once

#include <stdint.h>

enum Keys {
  KEY_COIN = 0x0,
  KEY_P1_LEFT = 0x1,
  KEY_P1_RIGHT = 0x2,
  KEY_P1_FIRE = 0x3,
  KEY_P1_START = 0x4,
  KEY_P2_LEFT = 0x5,
  KEY_P2_RIGHT = 0x6,
  KEY_P2_FIRE = 0x7,
  KEY_P2_START = 0x8,
};

void machine_init();
void machine_out(uint8_t port, uint8_t value);
void machine_in(uint8_t port, uint8_t *value);
void machine_set_key(uint8_t key, uint8_t value);