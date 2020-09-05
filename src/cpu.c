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

  for (int i = 0; i < 8; i++) {
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
    "Registers: PC - 0x%04x | SP - 0x%04x | A - 0x%02x | B - 0x%02x | C - 0x%02x | D - 0x%02x | E - 0x%02x | H - 0x%02x | L - 0x%02x\n",
    state->pc, state->sp, state->a, state->b, state->c, state->d, state->e, state->h, state->l);
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

uint16_t cpu_fetch_address(cpu_state *state) {
  uint8_t low_register = cpu_fetch(state);
  uint8_t high_register = cpu_fetch(state);
  return cpu_compose(high_register, low_register);
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

//    getchar();
    printf("\n");
  }
}

void cpu_emulate_op_code(cpu_state *state, uint8_t op_code) {
  uint8_t high_byte, low_byte;

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

    case RLC:
      cpu_execute_rlc(state);
      break;

    case DAD_B:
      cpu_execute_dad(state, &state->b, &state->c);
      break;

    case LDAX_B:
      cpu_execute_ldax(state, state->b, state->c);
      break;

    case DCX_B:
      cpu_execute_dcx(&state->b, &state->c);
      break;

    case INR_C:
      cpu_execute_inr(state, &state->c);
      break;

    case DCR_C:
      cpu_execute_dcr(state, &state->c);
      break;

    case MVI_C_D8:
      cpu_execute_mvi(state, &state->c);
      break;

    case RRC:
      cpu_execute_rrc(state);
      break;

    case LXI_D:
      cpu_execute_lxi(state, &state->d, &state->e);
      break;

    case STAX_D:
      cpu_execute_stax(state, state->d, state->e);
      break;

    case INX_D:
      cpu_execute_inx(&state->d, &state->e);
      break;

    case INR_D:
      cpu_execute_inr(state, &state->d);
      break;

    case DCR_D:
      cpu_execute_dcr(state, &state->d);
      break;

    case MVI_D_D8:
      cpu_execute_mvi(state, &state->d);
      break;

    case RAL:
      cpu_execute_ral(state);
      break;

    case DAD_D:
      cpu_execute_dad(state, &state->d, &state->e);
      break;

    case LDAX_D:
      cpu_execute_ldax(state, state->d, state->e);
      break;

    case DCX_D:
      cpu_execute_dcx(&state->d, &state->e);
      break;

    case INR_E:
      cpu_execute_inr(state, &state->e);
      break;

    case DCR_E:
      cpu_execute_dcr(state, &state->e);
      break;

    case MVI_E_D8:
      cpu_execute_mvi(state, &state->e);
      break;

    case RAR:
      cpu_execute_rar(state);
      break;

    case LXI_H:
      cpu_execute_lxi(state, &state->h, &state->l);
      break;

    case SHLD:
      cpu_execute_shld(state);
      break;

    case INX_H:
      cpu_execute_inx(&state->h, &state->l);
      break;

    case INR_H:
      cpu_execute_inr(state, &state->h);
      break;

    case DCR_H:
      cpu_execute_dcr(state, &state->h);
      break;

    case MVI_H_D8:
      cpu_execute_mvi(state, &state->h);
      break;

    case DAA:
      // TODO: Implement this instruction
      break;

    case DAD_H:
      cpu_execute_dad(state, &state->h, &state->l);
      break;

    case LHLD:
      cpu_execute_lhld(state);
      break;

    case DCX_H:
      cpu_execute_dcx(&state->h, &state->l);
      break;

    case INR_L:
      cpu_execute_inr(state, &state->l);
      break;

    case DCR_L:
      cpu_execute_dcr(state, &state->l);
      break;

    case MVI_L_D8:
      cpu_execute_mvi(state, &state->l);
      break;

    case CMA:
      cpu_execute_cma(state);
      break;

    case LXI_SP:
      cpu_split(state->sp, &high_byte, &low_byte);
      cpu_execute_lxi(state, &high_byte, &low_byte);
      state->sp = cpu_compose(high_byte, low_byte);
      break;

    case STA:
      cpu_execute_sta(state);
      break;

    case INX_SP:
      cpu_split(state->sp, &high_byte, &low_byte);
      cpu_execute_inx(&high_byte, &low_byte);
      state->sp = cpu_compose(high_byte, low_byte);
      break;

    case INR_M:
      cpu_execute_inr_m(state);
      break;

    case DCR_M:
      cpu_execute_dcr_m(state);
      break;

    case MVI_M_D8:
      cpu_execute_mvi_m(state);
      break;

    case STC:
      cpu_execute_stc(state);
      break;

    case DAD_SP:
      cpu_split(state->sp, &high_byte, &low_byte);
      cpu_execute_dad(state, &high_byte, &low_byte);
      break;

    case LDA:
      cpu_execute_lda(state);
      break;

    case DCX_SP:
      cpu_split(state->sp, &high_byte, &low_byte);
      cpu_execute_dcx(&high_byte, &low_byte);
      state->sp = cpu_compose(high_byte, low_byte);
      break;

    case INR_A:
      cpu_execute_inr(state, &state->a);
      break;

    case DCR_A:
      cpu_execute_dcr(state, &state->a);
      break;

    case MVI_A_D8:
      cpu_execute_mvi(state, &state->a);
      break;

    case CMC:
      cpu_execute_cmc(state);
      break;

    case MOV_B_B:
      cpu_execute_mov_r_r(state, &state->b, &state->b);
      break;

    case MOV_B_C:
      cpu_execute_mov_r_r(state, &state->b, &state->c);
      break;

    case MOV_B_D:
      cpu_execute_mov_r_r(state, &state->b, &state->d);
      break;

    case MOV_B_E:
      cpu_execute_mov_r_r(state, &state->b, &state->e);
      break;

    case MOV_B_H:
      cpu_execute_mov_r_r(state, &state->b, &state->h);
      break;

    case MOV_B_L:
      cpu_execute_mov_r_r(state, &state->b, &state->l);
      break;

    case MOV_B_M:
      cpu_execute_mov_r_m(state, &state->b);
      break;

    case MOV_B_A:
      cpu_execute_mov_r_r(state, &state->b, &state->a);
      break;

    case MOV_C_B:
      cpu_execute_mov_r_r(state, &state->c, &state->b);
      break;

    case MOV_C_C:
      cpu_execute_mov_r_r(state, &state->c, &state->c);
      break;

    case MOV_C_D:
      cpu_execute_mov_r_r(state, &state->c, &state->d);
      break;

    case MOV_C_E:
      cpu_execute_mov_r_r(state, &state->c, &state->e);
      break;

    case MOV_C_H:
      cpu_execute_mov_r_r(state, &state->c, &state->h);
      break;

    case MOV_C_L:
      cpu_execute_mov_r_r(state, &state->c, &state->l);
      break;

    case MOV_C_M:
      cpu_execute_mov_r_m(state, &state->c);
      break;

    case MOV_C_A:
      cpu_execute_mov_r_r(state, &state->c, &state->a);
      break;

    case MOV_D_B:
      cpu_execute_mov_r_r(state, &state->d, &state->b);
      break;

    case MOV_D_C:
      cpu_execute_mov_r_r(state, &state->d, &state->c);
      break;

    case MOV_D_D:
      cpu_execute_mov_r_r(state, &state->d, &state->d);
      break;

    case MOV_D_E:
      cpu_execute_mov_r_r(state, &state->d, &state->e);
      break;

    case MOV_D_H:
      cpu_execute_mov_r_r(state, &state->d, &state->h);
      break;

    case MOV_D_L:
      cpu_execute_mov_r_r(state, &state->d, &state->l);
      break;

    case MOV_D_M:
      cpu_execute_mov_r_m(state, &state->d);
      break;

    case MOV_D_A:
      cpu_execute_mov_r_r(state, &state->e, &state->a);
      break;

    case MOV_E_B:
      cpu_execute_mov_r_r(state, &state->e, &state->b);
      break;

    case MOV_E_C:
      cpu_execute_mov_r_r(state, &state->e, &state->c);
      break;

    case MOV_E_D:
      cpu_execute_mov_r_r(state, &state->e, &state->d);
      break;

    case MOV_E_E:
      cpu_execute_mov_r_r(state, &state->e, &state->e);
      break;

    case MOV_E_H:
      cpu_execute_mov_r_r(state, &state->e, &state->h);
      break;

    case MOV_E_L:
      cpu_execute_mov_r_r(state, &state->e, &state->l);
      break;

    case MOV_E_M:
      cpu_execute_mov_r_m(state, &state->e);
      break;

    case MOV_E_A:
      cpu_execute_mov_r_r(state, &state->e, &state->a);
      break;

    case MOV_H_B:
      cpu_execute_mov_r_r(state, &state->h, &state->b);
      break;

    case MOV_H_C:
      cpu_execute_mov_r_r(state, &state->h, &state->c);
      break;

    case MOV_H_D:
      cpu_execute_mov_r_r(state, &state->h, &state->d);
      break;

    case MOV_H_E:
      cpu_execute_mov_r_r(state, &state->h, &state->e);
      break;

    case MOV_H_H:
      cpu_execute_mov_r_r(state, &state->h, &state->h);
      break;

    case MOV_H_L:
      cpu_execute_mov_r_r(state, &state->h, &state->l);
      break;

    case MOV_H_M:
      cpu_execute_mov_r_m(state, &state->h);
      break;

    case MOV_H_A:
      cpu_execute_mov_r_r(state, &state->h, &state->a);
      break;

    case MOV_L_B:
      cpu_execute_mov_r_r(state, &state->l, &state->b);
      break;

    case MOV_L_C:
      cpu_execute_mov_r_r(state, &state->l, &state->c);
      break;

    case MOV_L_D:
      cpu_execute_mov_r_r(state, &state->l, &state->d);
      break;

    case MOV_L_E:
      cpu_execute_mov_r_r(state, &state->l, &state->e);
      break;

    case MOV_L_H:
      cpu_execute_mov_r_r(state, &state->l, &state->h);
      break;

    case MOV_L_L:
      cpu_execute_mov_r_r(state, &state->l, &state->l);
      break;

    case MOV_L_M:
      cpu_execute_mov_r_m(state, &state->l);
      break;

    case MOV_L_A:
      cpu_execute_mov_r_r(state, &state->l, &state->a);
      break;

    case MOV_M_B:
      cpu_execute_mov_m_r(state, &state->b);
      break;

    case MOV_M_C:
      cpu_execute_mov_m_r(state, &state->c);
      break;

    case MOV_M_D:
      cpu_execute_mov_m_r(state, &state->d);
      break;

    case MOV_M_E:
      cpu_execute_mov_m_r(state, &state->e);
      break;

    case MOV_M_H:
      cpu_execute_mov_m_r(state, &state->h);
      break;

    case MOV_M_L:
      cpu_execute_mov_m_r(state, &state->l);
      break;

    case MOV_M_A:
      cpu_execute_mov_m_r(state, &state->a);
      break;

    case MOV_A_B:
      cpu_execute_mov_r_r(state, &state->a, &state->b);
      break;

    case MOV_A_C:
      cpu_execute_mov_r_r(state, &state->a, &state->c);
      break;

    case MOV_A_D:
      cpu_execute_mov_r_r(state, &state->a, &state->d);
      break;

    case MOV_A_E:
      cpu_execute_mov_r_r(state, &state->a, &state->e);
      break;

    case MOV_A_H:
      cpu_execute_mov_r_r(state, &state->a, &state->h);
      break;

    case MOV_A_L:
      cpu_execute_mov_r_r(state, &state->a, &state->l);
      break;

    case MOV_A_M:
      cpu_execute_mov_r_m(state, &state->a);
      break;

    case MOV_A_A:
      cpu_execute_mov_r_r(state, &state->a, &state->a);
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
  state->memory[location] = state->a;
}

void cpu_execute_inx(uint8_t *high_register, uint8_t *low_register) {
  uint16_t byte = cpu_compose(*high_register, *low_register);
  byte++;

  cpu_split(byte, high_register, low_register);
}

void cpu_execute_inr(cpu_state *state, uint8_t *reg) {
  uint16_t res = *reg;
  res++;
  *reg = res & 0x00FF;

  cpu_handle_z_flag(state, res);
  cpu_handle_s_flag(state, res);
  cpu_handle_p_flag(state, res);
  cpu_handle_ac_flag(state, res);
}

void cpu_execute_dcr(cpu_state *state, uint8_t *reg) {
  uint16_t res = *reg;
  res--;
  *reg = res & 0x00FF;

  cpu_handle_z_flag(state, res);
  cpu_handle_s_flag(state, res);
  cpu_handle_p_flag(state, res);
  cpu_handle_ac_flag(state, res);
}

void cpu_execute_mvi(cpu_state *state, uint8_t *reg) {
  *reg = cpu_fetch(state);
}

void cpu_execute_rlc(cpu_state *state) {
  state->flags.c = state->a >> 7 != 0;
  state->a = state->a << 1 | state->a >> 7;
}

void cpu_execute_dad(cpu_state *state, uint8_t *high_register, uint8_t *low_register) {
  uint16_t reg = cpu_compose(*high_register, *low_register);
  uint16_t hl = cpu_compose(state->h, state->l);

  uint32_t res = hl + reg;

  state->flags.c = (res & 0xFFFF0000) > 0;

  cpu_split((uint32_t) res, &state->h, &state->l);
}

void cpu_execute_ldax(cpu_state *state, uint8_t high_register, uint8_t low_register) {
  uint16_t location = cpu_compose(high_register, low_register);
  state->a = state->memory[location];
}

void cpu_execute_dcx(uint8_t *high_register, uint8_t *low_register) {
  uint16_t byte = cpu_compose(*high_register, *low_register);
  byte--;

  cpu_split(byte, high_register, low_register);
}

void cpu_execute_rrc(cpu_state *state) {
  state->a = state->a >> 1 | state->a << 7;
  state->flags.c = state->a >> 7 != 0;
}

void cpu_execute_ral(cpu_state *state) {
  uint8_t new_carry = state->a >> 7;
  state->a = (state->a << 1) | state->flags.c;
  state->flags.c = new_carry;
}

void cpu_execute_rar(cpu_state *state) {
  uint8_t new_carry = ((uint8_t) (state->a << 7)) >> 7;
  state->a = (state->a >> 1) | (state->flags.c << 7);
  state->flags.c = new_carry;
}

void cpu_execute_shld(cpu_state *state) {
  uint16_t address = cpu_fetch_address(state);
  state->memory[address] = state->l;
  state->memory[address + 1] = state->h;
}

void cpu_execute_lhld(cpu_state *state) {
  uint16_t address = cpu_fetch_address(state);
  state->l = state->memory[address];
  state->h = state->memory[address + 1];
}

void cpu_execute_cma(cpu_state *state) {
  state->a = ~state->a;
}

void cpu_execute_sta(cpu_state *state) {
  uint16_t address = cpu_fetch_address(state);
  state->memory[address] = state->a;
}

void cpu_execute_inr_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  state->memory[address]++;

  cpu_handle_z_flag(state, state->memory[address]);
  cpu_handle_s_flag(state, state->memory[address]);
  cpu_handle_p_flag(state, state->memory[address]);
  cpu_handle_ac_flag(state, state->memory[address]);
}

void cpu_execute_dcr_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  state->memory[address]--;

  cpu_handle_z_flag(state, state->memory[address]);
  cpu_handle_s_flag(state, state->memory[address]);
  cpu_handle_p_flag(state, state->memory[address]);
  cpu_handle_ac_flag(state, state->memory[address]);
}

void cpu_execute_mvi_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  state->memory[address] = cpu_fetch(state);
}

void cpu_execute_stc(cpu_state *state) {
  state->flags.c = 1;
}

void cpu_execute_lda(cpu_state *state) {
  uint16_t address = cpu_fetch_address(state);
  state->a = state->memory[address];
}

void cpu_execute_cmc(cpu_state *state) {
  state->flags.c = !state->flags.c;
}

void cpu_execute_mov_r_r(cpu_state *state, uint8_t *src_register, uint8_t *dest_register) {
  *src_register = *dest_register;
}

void cpu_execute_mov_r_m(cpu_state *state, uint8_t *src_register) {
  uint16_t address = cpu_compose(state->h, state->l);
  *src_register = state->memory[address];
}

void cpu_execute_mov_m_r(cpu_state *state, uint8_t *src_register) {
  uint16_t address = cpu_compose(state->h, state->l);
  state->memory[address] = *src_register;
}
