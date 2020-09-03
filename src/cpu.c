#include "cpu.h"

uint16_t cpu_compose(uint8_t high_byte, uint8_t low_byte) {
  uint16_t ret = 0;
  ret += high_byte;
  ret <<= 8;
  ret += low_byte;
  return ret;
}

void cpu_split(uint16_t byte, uint8_t *high_byte, uint8_t *low_byte) {
  *high_byte = (byte & 0xFF00) >> 8;
  *low_byte = byte & 0x00FF;
}

void cpu_handle_z_flag(cpu_state *state, uint16_t res) {
  state->flags.z = (res & 0xFF) == 0x00;
}

void cpu_handle_s_flag(cpu_state *state, uint16_t res) {
  state->flags.s = (res & 0x80) == 0x80;
}

void cpu_handle_p_flag(cpu_state *state, uint16_t res) {
  int32_t parity = 0;

  for(int i = 0; i < 8; i++) {
    parity += res & 1;
    res >>= 1;
  }

  state->flags.p = parity % 2 == 0;
}

void cpu_handle_c_flag(cpu_state *state, uint16_t res) {
  state->flags.ac = res > 0xFF;
}

void cpu_handle_ac_flag(cpu_state *state, uint16_t res) {
  state->flags.ac = res > 0x09;
}

cpu_state cpu_init(char *file_data, uint32_t file_size) {
  cpu_state state;

  state.a = 0;
  state.b = 0;
  state.c = 0;
  state.d = 0;
  state.e = 0;
  state.h = 0;
  state.l = 0;

  state.pc = 0;
  state.sp = 0; // TODO: The last memory address

  state.flags.ac = 0;
  state.flags.c = 0;
  state.flags.p = 0;
  state.flags.s = 0;
  state.flags.z = 0;

  state.interrupt_enable = 1;

  state.memory = malloc(16 * 16 * 16 * 16);

  memset(state.memory, 0, 16 * 16 * 16 * 16);
  memcpy(state.memory, file_data, file_size * sizeof(char));

  return state;
}

void cpu_destroy(cpu_state *state) {
  free(state->memory);
}

void cpu_print_debug_info(cpu_state *state) {
  printf(
    "Registers: PC - 0x%04x | A - 0x%02x | B - 0x%02x | C - 0x%02x | D - 0x%02x | E - 0x%02x | H - 0x%02x | L - 0x%02x\n",
    state->pc, state->a, state->b, state->c, state->d, state->e, state->h, state->l);
  printf("Flags: Z - %d | S - %d | P - %d | C - %d | AC - %d\n", state->flags.z, state->flags.s, state->flags.p,
         state->flags.c, state->flags.ac);
}

void cpu_print_disassembled_op_code(cpu_state *state, uint8_t op_code) {
  if (disassemble_byte_length[op_code] == 3) {
    printf(disassemble_table[op_code], *(state->memory + state->pc + 1), *(state->memory + state->pc));
  } else {
    printf(disassemble_table[op_code], *(state->memory + state->pc));
  }

  printf("\n");
}

uint8_t cpu_fetch(cpu_state *state) {
  return state->memory[state->pc++];
}

void cpu_start_emulation(cpu_state *state) {
  while (1) {
    uint8_t op_code = cpu_fetch(state);

    if (op_code == HLT) {
      break;
    }

    cpu_print_debug_info(state);
    cpu_print_disassembled_op_code(state, op_code);
    cpu_emulate_op_code(state, op_code);
    cpu_print_debug_info(state);

    getchar();
    printf("\n");
  }
}


void cpu_emulate_op_code(cpu_state *state, uint8_t op_code) {
  switch (op_code) {
    case NOP:
      break;

    case LXI_B:
      cpu_execute_lxi(state, &state->b, &state->c);
      break;

    case STAX_B:
      cpu_execute_stax(state, state->b, state->c);
      break;

    case INX_B:
      cpu_execute_inx(&state->b, &state->c);
      break;

    case INR_B:
      cpu_execute_inr(state, &state->b);
      break;

    case DCR_B:
      cpu_execute_dcr(state, &state->b);
      break;

    case MVI_B_D8:
      cpu_execute_mvi(state, &state->b);
      break;

    default:
      printf("UNIMPLEMENTED INSTRUCTION: 0x%02x", op_code);
      exit(1);
  }
}

void cpu_execute_lxi(cpu_state *state, uint8_t *high_register, uint8_t *low_register) {
  *low_register = cpu_fetch(state);
  *high_register = cpu_fetch(state);
}

void cpu_execute_stax(cpu_state *state, uint8_t high_register, uint8_t low_register) {
  uint16_t location = cpu_compose(high_register, low_register);
  printf("%04x", location);
  state->memory[location] = state->a;
}

void cpu_execute_inx(uint8_t *high_register, uint8_t *low_register) {
  uint16_t byte = cpu_compose(*high_register, *low_register);
  byte++;

  cpu_split(byte, high_register, low_register);
}

void cpu_execute_inr(cpu_state *state, uint8_t *reg) {
  uint16_t res = *reg;
  res ++;
  *reg = res & 0x00FF;

  cpu_handle_z_flag(state, res);
  cpu_handle_s_flag(state, res);
  cpu_handle_p_flag(state, res);
  cpu_handle_ac_flag(state, res);
}

void cpu_execute_dcr(cpu_state *state, uint8_t *reg) {
  uint16_t res = *reg;
  res --;
  *reg = res & 0x00FF;

  cpu_handle_z_flag(state, res);
  cpu_handle_s_flag(state, res);
  cpu_handle_p_flag(state, res);
  cpu_handle_ac_flag(state, res);
}

void cpu_execute_mvi(cpu_state *state, uint8_t *reg) {
  *reg = cpu_fetch(state);
}