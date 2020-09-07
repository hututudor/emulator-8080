#pragma once

#include <stdint.h>

void machine_out(uint8_t port, uint8_t value);
void machine_in(uint8_t port, uint8_t *value);