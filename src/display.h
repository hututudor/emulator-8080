#pragma once

#include "cpu.h"

void display_init();
void display_destroy();

void display_process_events(cpu_state *state);
void display_render(cpu_state *state);