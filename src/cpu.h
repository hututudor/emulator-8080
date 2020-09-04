#pragma once

#include "definitions.h"

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  uint8_t c;
  uint8_t z;
  uint8_t s;
  uint8_t p;
  uint8_t ac;
} cpu_flags;

typedef struct {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t h;
  uint8_t l;

  uint32_t pc;
  uint32_t sp;

  uint8_t interrupt_enable;

  cpu_flags flags;
  uint8_t *memory;
} cpu_state;

uint16_t cpu_compose(uint8_t high_byte, uint8_t low_byte);
void cpu_split(uint16_t byte, uint8_t *high_byte, uint8_t *low_byte);

void cpu_handle_z_flag(cpu_state *state, uint16_t res);
void cpu_handle_s_flag(cpu_state *state, uint16_t res);
void cpu_handle_p_flag(cpu_state *state, uint16_t res);
void cpu_handle_c_flag(cpu_state *state, uint16_t res);
void cpu_handle_ac_flag(cpu_state *state, uint16_t res);

cpu_state cpu_init(char *file_data, uint32_t file_size);
void cpu_destroy(cpu_state *state);

void cpu_print_debug_info(cpu_state *state);
void cpu_print_disassembled_op_code(cpu_state *state, uint8_t op_code);

uint8_t cpu_fetch(cpu_state *state);
uint16_t cpu_fetch_address(cpu_state * state);

void cpu_start_emulation(cpu_state *state);
void cpu_emulate_op_code(cpu_state *state, uint8_t op_code);

void cpu_execute_lxi(cpu_state *state, uint8_t *high_register, uint8_t *low_register);
void cpu_execute_stax(cpu_state *state, uint8_t high_register, uint8_t low_register);
void cpu_execute_inx(uint8_t *high_register, uint8_t *low_register);
void cpu_execute_inr(cpu_state *state, uint8_t *reg);
void cpu_execute_dcr(cpu_state *state, uint8_t *reg);
void cpu_execute_mvi(cpu_state *state, uint8_t *reg);
void cpu_execute_rlc(cpu_state *state);
void cpu_execute_dad(cpu_state *state, uint8_t *high_register, uint8_t *low_register);
void cpu_execute_ldax(cpu_state* state, uint8_t high_register, uint8_t low_register);
void cpu_execute_dcx(uint8_t *high_register, uint8_t *low_register);
void cpu_execute_rrc(cpu_state *state);
void cpu_execute_ral(cpu_state *state);
void cpu_execute_rar(cpu_state *state);
void cpu_execute_shld(cpu_state *state);
void cpu_execute_lhld(cpu_state *state);
void cpu_execute_cma(cpu_state *state);
void cpu_execute_sta(cpu_state *state);
void cpu_execute_inr_m(cpu_state *state);
void cpu_execute_dcr_m(cpu_state *state);
void cpu_execute_mvi_m(cpu_state *state);
void cpu_execute_stc(cpu_state* state);
void cpu_execute_lda(cpu_state* state);
void cpu_execute_cmc(cpu_state* state);