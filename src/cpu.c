#include "cpu.h"
#include "machine.h"

uint32_t debug_step_counter = 0;

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

uint8_t cpu_get_psw(cpu_state *state) {
  uint8_t res = 0;
  res += state->flags.s << 7;
  res += state->flags.z << 6;
  res += state->flags.ac << 4;
  res += state->flags.p << 2;
  res += 1 << 1;
  res += state->flags.c;

  return res;
}

void cpu_set_psw(cpu_state *state, uint8_t psw) {
  state->flags.s = psw >> 7 & 0x1;
  state->flags.z = psw >> 6 & 0x1;
  state->flags.ac = psw >> 4 & 0x1;
  state->flags.p = psw >> 2 & 0x1;
  state->flags.c = psw & 0x1;
}

void cpu_handle_z_flag(cpu_state *state, uint16_t res) {
  state->flags.z = (res & 0xFF) == 0x00;
}

void cpu_handle_s_flag(cpu_state *state, uint16_t res) {
  state->flags.s = (res & 0x80) == 0x80;
}

void cpu_handle_p_flag(cpu_state *state, uint16_t res) {
  int32_t parity = 0;

  res = (res & ((1 << 8) - 1));
  for (int i = 0; i < 8; i++) {

    if (res & 0x1) {
      parity++;
    }

    res = res >> 1;
  }

  state->flags.p = (parity & 0x1) == 0;
}

void cpu_handle_c_flag(cpu_state *state, uint16_t res) {
  state->flags.c = res > 0xFF;
}

void cpu_handle_ac_flag(cpu_state *state, uint16_t res) {
  state->flags.ac = res > 0x09;
}

void cpu_handle_all_flags(cpu_state *state, uint16_t res) {
  cpu_handle_z_flag(state, res);
  cpu_handle_s_flag(state, res);
  cpu_handle_p_flag(state, res);
  cpu_handle_c_flag(state, res);
  cpu_handle_ac_flag(state, res);
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
  state.interrupt = 0;

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

void cpu_print_dump(cpu_state *state) {
  FILE *dump = fopen("../dump", "wb");
  fwrite(state->memory, 1, 16 * 16 * 16 * 16, dump);
  fclose(dump);
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

void cpu_set_interrupt(cpu_state *state, uint8_t op_code) {
  if (state->interrupt_enable) {
    state->interrupt = op_code;
  }
}

void cpu_start_emulation(cpu_state *state) {
  while (is_running) {
    uint8_t op_code = 0;

    if (state->interrupt) {
      op_code = state->interrupt;
      state->interrupt = 0;
    } else {
      op_code = cpu_fetch(state);
    }

    if (op_code == HLT) {
      break;
    }

#if CPU_DEBUG
    cpu_print_debug_info(state);
    cpu_print_disassembled_op_code(state, op_code);
#endif

    cpu_emulate_op_code(state, op_code);

#if CPU_DEBUG
    cpu_print_debug_info(state);

    if (debug_step_counter == 0) {
      char c = getchar();
      if (c == 'd') {
        cpu_print_dump(state);
      } else if (c == '1') {
        cpu_set_interrupt(state, RST_1);
      } else if (c == '2') {
        cpu_set_interrupt(state, RST_2);
      } else if (c == 's') {
        debug_step_counter = 100;
      } else if (c == 'm') {
        debug_step_counter = 1000;
      } else if(c == 'z') {
        debug_step_counter = 10000;
      }
    } else {
      debug_step_counter --;
    }

    printf("\n");
#endif
  }

  is_running = 0;
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
      cpu_execute_daa(state);
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

    case ADD_B:
      cpu_execute_add_r(state, state->b);
      break;

    case ADD_C:
      cpu_execute_add_r(state, state->c);
      break;

    case ADD_D:
      cpu_execute_add_r(state, state->d);
      break;

    case ADD_E:
      cpu_execute_add_r(state, state->e);
      break;

    case ADD_H:
      cpu_execute_add_r(state, state->h);
      break;

    case ADD_L:
      cpu_execute_add_r(state, state->l);
      break;

    case ADD_M:
      cpu_execute_add_m(state);
      break;

    case ADD_A:
      cpu_execute_add_r(state, state->a);
      break;

    case ADC_B:
      cpu_execute_adc_r(state, state->b);
      break;

    case ADC_C:
      cpu_execute_adc_r(state, state->c);
      break;

    case ADC_D:
      cpu_execute_adc_r(state, state->d);
      break;

    case ADC_E:
      cpu_execute_adc_r(state, state->e);
      break;

    case ADC_H:
      cpu_execute_adc_r(state, state->h);
      break;

    case ADC_L:
      cpu_execute_adc_r(state, state->l);
      break;

    case ADC_M:
      cpu_execute_adc_m(state);
      break;

    case ADC_A:
      cpu_execute_adc_r(state, state->a);
      break;

    case SUB_B:
      cpu_execute_sub_r(state, state->b);
      break;

    case SUB_C:
      cpu_execute_sub_r(state, state->c);
      break;

    case SUB_D:
      cpu_execute_sub_r(state, state->d);
      break;

    case SUB_E:
      cpu_execute_sub_r(state, state->e);
      break;

    case SUB_H:
      cpu_execute_sub_r(state, state->h);
      break;

    case SUB_L:
      cpu_execute_sub_r(state, state->l);
      break;

    case SUB_M:
      cpu_execute_sub_m(state);
      break;

    case SUB_A:
      cpu_execute_sub_r(state, state->a);
      break;

    case SBB_B:
      cpu_execute_sbb_r(state, state->b);
      break;

    case SBB_C:
      cpu_execute_sbb_r(state, state->c);
      break;

    case SBB_D:
      cpu_execute_sbb_r(state, state->d);
      break;

    case SBB_E:
      cpu_execute_sbb_r(state, state->e);
      break;

    case SBB_H:
      cpu_execute_sbb_r(state, state->h);
      break;

    case SBB_L:
      cpu_execute_sbb_r(state, state->l);
      break;

    case SBB_M:
      cpu_execute_sbb_m(state);
      break;

    case SBB_A:
      cpu_execute_sbb_r(state, state->a);
      break;

    case ANA_B:
      cpu_execute_ana_r(state, state->b);
      break;

    case ANA_C:
      cpu_execute_ana_r(state, state->c);
      break;

    case ANA_D:
      cpu_execute_ana_r(state, state->d);
      break;

    case ANA_E:
      cpu_execute_ana_r(state, state->e);
      break;

    case ANA_H:
      cpu_execute_ana_r(state, state->h);
      break;

    case ANA_L:
      cpu_execute_ana_r(state, state->l);
      break;

    case ANA_M:
      cpu_execute_ana_m(state);
      break;

    case ANA_A:
      cpu_execute_ana_r(state, state->a);
      break;

    case XRA_B:
      cpu_execute_xra_r(state, state->b);
      break;

    case XRA_C:
      cpu_execute_xra_r(state, state->c);
      break;

    case XRA_D:
      cpu_execute_xra_r(state, state->d);
      break;

    case XRA_E:
      cpu_execute_xra_r(state, state->e);
      break;

    case XRA_H:
      cpu_execute_xra_r(state, state->h);
      break;

    case XRA_L:
      cpu_execute_xra_r(state, state->l);
      break;

    case XRA_M:
      cpu_execute_xra_m(state);
      break;

    case XRA_A:
      cpu_execute_xra_r(state, state->a);
      break;

    case ORA_B:
      cpu_execute_ora_r(state, state->b);
      break;

    case ORA_C:
      cpu_execute_ora_r(state, state->c);
      break;

    case ORA_D:
      cpu_execute_ora_r(state, state->d);
      break;

    case ORA_E:
      cpu_execute_ora_r(state, state->e);
      break;

    case ORA_H:
      cpu_execute_ora_r(state, state->h);
      break;

    case ORA_L:
      cpu_execute_ora_r(state, state->l);
      break;

    case ORA_M:
      cpu_execute_ora_m(state);
      break;

    case ORA_A:
      cpu_execute_ora_r(state, state->a);
      break;

    case CMP_B:
      cpu_execute_cmp_r(state, state->b);
      break;

    case CMP_C:
      cpu_execute_cmp_r(state, state->c);
      break;

    case CMP_D:
      cpu_execute_cmp_r(state, state->d);
      break;

    case CMP_E:
      cpu_execute_cmp_r(state, state->e);
      break;

    case CMP_H:
      cpu_execute_cmp_r(state, state->h);
      break;

    case CMP_L:
      cpu_execute_cmp_r(state, state->l);
      break;

    case CMP_M:
      cpu_execute_cmp_m(state);
      break;

    case CMP_A:
      cpu_execute_ora_r(state, state->a);
      break;

    case RNZ:
      cpu_execute_ret(state, !state->flags.z);
      break;

    case POP_B:
      cpu_execute_pop(state, &state->b, &state->c);
      break;

    case JNZ:
      cpu_execute_jmp(state, !state->flags.z);
      break;

    case JMP:
      cpu_execute_jmp(state, 1);
      break;

    case CNZ:
      cpu_execute_call(state, !state->flags.z);
      break;

    case PUSH_B:
      cpu_execute_push(state, state->b, state->c);
      break;

    case ADI_D8:
      cpu_execute_adi(state);
      break;

    case RST_0:
      cpu_execute_rst(state, 0x00);
      break;

    case RZ:
      cpu_execute_ret(state, state->flags.z);
      break;

    case RET:
      cpu_execute_ret(state, 1);
      break;

    case JZ:
      cpu_execute_jmp(state, state->flags.z);
      break;

    case CZ:
      cpu_execute_call(state, state->flags.z);
      break;

    case CALL:
      cpu_execute_call(state, 1);
      break;

    case ACI_D8:
      cpu_execute_aci(state);
      break;

    case RST_1:
      cpu_execute_rst(state, 0x08);
      break;

    case RNC:
      cpu_execute_ret(state, !state->flags.c);
      break;

    case POP_D:
      cpu_execute_pop(state, &state->d, &state->e);
      break;

    case JNC:
      cpu_execute_jmp(state, !state->flags.c);
      break;

    case CNC:
      cpu_execute_call(state, !state->flags.c);
      break;

    case PUSH_D:
      cpu_execute_push(state, state->d, state->e);
      break;

    case SUI_D8:
      cpu_execute_sui(state);
      break;

    case RST_2:
      cpu_execute_rst(state, 0x10);
      break;

    case RC:
      cpu_execute_ret(state, state->flags.c);
      break;

    case JC:
      cpu_execute_jmp(state, state->flags.c);
      break;

    case CC:
      cpu_execute_call(state, state->flags.c);
      break;

    case SBI_D8:
      cpu_execute_sbi(state);
      break;

    case RST_3:
      cpu_execute_rst(state, 0x18);
      break;

    case RPO:
      cpu_execute_ret(state, !state->flags.p);
      break;

    case POP_H:
      cpu_execute_pop(state, &state->h, &state->l);
      break;

    case JPO:
      cpu_execute_jmp(state, !state->flags.p);
      break;

    case XTHL:
      cpu_execute_xthl(state);
      break;

    case CPO:
      cpu_execute_call(state, !state->flags.p);
      break;

    case PUSH_H:
      cpu_execute_push(state, state->h, state->l);
      break;

    case ANI_D8:
      cpu_execute_ani(state);
      break;

    case RST_4:
      cpu_execute_rst(state, 0x20);
      break;

    case RPE:
      cpu_execute_ret(state, state->flags.p);
      break;

    case PCHL:
      cpu_execute_pchl(state);
      break;

    case JPE:
      cpu_execute_jmp(state, state->flags.p);
      break;

    case XCHG:
      cpu_execute_xchg(state);
      break;

    case CPE:
      cpu_execute_call(state, state->flags.p);
      break;

    case XRI_D8:
      cpu_execute_xri(state);
      break;

    case RST_5:
      cpu_execute_rst(state, 0x28);
      break;

    case RP:
      cpu_execute_ret(state, !state->flags.s);
      break;

    case POP_PSW:
      uint8_t psw = 0;
      cpu_execute_pop(state, &state->a, &psw);
      cpu_set_psw(state, psw);
      break;

    case JP:
      cpu_execute_jmp(state, !state->flags.s);
      break;

    case DI:
      cpu_execute_di(state);
      break;

    case CP:
      cpu_execute_call(state, !state->flags.s);
      break;

    case PUSH_PSW:
      cpu_execute_push(state, state->a, cpu_get_psw(state));
      break;

    case ORI_D8:
      cpu_execute_ori(state);
      break;

    case RST_6:
      cpu_execute_rst(state, 0x30);
      break;

    case RM:
      cpu_execute_ret(state, state->flags.s);
      break;

    case SPHL:
      cpu_execute_sphl(state);
      break;

    case JM:
      cpu_execute_jmp(state, state->flags.s);
      break;

    case EI:
      cpu_execute_ei(state);
      break;

    case CM:
      cpu_execute_call(state, state->flags.s);
      break;

    case CPI_D8:
      cpu_execute_cpi(state);
      break;

    case RST_7:
      cpu_execute_rst(state, 0x38);
      break;

    case OUT:
      machine_out(cpu_fetch(state), state->a);
      break;

    case IN:
      machine_in(cpu_fetch(state), &state->a);
      break;

    default:
      cpu_print_debug_info(state);
      cpu_print_dump(state);
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

void cpu_execute_add_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a + target_register;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_add_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a + state->memory[address];
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_adc_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a + target_register + state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_adc_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a + state->memory[address] + state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sub_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a - target_register;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sub_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a - state->memory[address];
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sbb_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a - target_register - state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sbb_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a - state->memory[address] - state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ana_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a & target_register;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ana_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a & state->memory[address];
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_xra_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a ^target_register;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_xra_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a ^state->memory[address];
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ora_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a | target_register;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ora_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a | state->memory[address];
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_cmp_r(cpu_state *state, uint8_t target_register) {
  uint16_t res = state->a - target_register;
  cpu_handle_all_flags(state, res);
}

void cpu_execute_cmp_m(cpu_state *state) {
  uint16_t address = cpu_compose(state->h, state->l);
  uint16_t res = state->a - state->memory[address];
  cpu_handle_all_flags(state, res);
}

void cpu_execute_jmp(cpu_state *state, uint8_t condition) {
  uint16_t address = cpu_fetch_address(state);

  if (condition) {
    state->pc = address;
  }
}

void cpu_execute_ei(cpu_state *state) {
  state->interrupt_enable = 1;
}

void cpu_execute_di(cpu_state *state) {
  state->interrupt_enable = 0;
}

void cpu_execute_call(cpu_state *state, uint8_t condition) {
  uint16_t address = cpu_fetch_address(state);
  uint8_t high_byte, low_byte;
  cpu_split(state->pc, &high_byte, &low_byte);

  if (condition) {
    state->memory[state->sp - 1] = high_byte;
    state->memory[state->sp - 2] = low_byte;
    state->sp -= 2;
    state->pc = address;
  }
}

void cpu_execute_ret(cpu_state *state, uint8_t condition) {
  if (condition) {
    uint16_t address = cpu_compose(state->memory[state->sp + 1], state->memory[state->sp]);
    state->sp += 2;
    state->pc = address;
  }
}

void cpu_execute_rst(cpu_state *state, uint8_t address) {
  uint8_t high_byte, low_byte;
  cpu_split(state->pc, &high_byte, &low_byte);

  state->memory[state->sp - 1] = high_byte;
  state->memory[state->sp - 2] = low_byte;
  state->sp -= 2;
  state->pc = address;
}

void cpu_execute_push(cpu_state *state, uint8_t high_register, uint8_t low_register) {
  state->memory[state->sp - 1] = high_register;
  state->memory[state->sp - 2] = low_register;
  state->sp -= 2;
}

void cpu_execute_pop(cpu_state *state, uint8_t *high_register, uint8_t *low_register) {
  *high_register = state->memory[state->sp + 1];
  *low_register = state->memory[state->sp];
  state->sp += 2;
}

void cpu_execute_pchl(cpu_state *state) {
  state->pc = cpu_compose(state->h, state->l);
}

void cpu_execute_sphl(cpu_state *state) {
  state->sp = cpu_compose(state->h, state->l);
}

void cpu_execute_xthl(cpu_state *state) {
  uint8_t temp;
  temp = state->memory[state->sp + 1];
  state->memory[state->sp + 1] = state->h;
  state->h = temp;

  temp = state->memory[state->sp];
  state->memory[state->sp] = state->l;
  state->l = temp;
}

void cpu_execute_xchg(cpu_state *state) {
  uint8_t temp;
  temp = state->d;
  state->d = state->h;
  state->h = temp;

  temp = state->e;
  state->e = state->l;
  state->l = temp;
}

void cpu_execute_adi(cpu_state *state) {
  uint16_t res = state->a + cpu_fetch(state);
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_aci(cpu_state *state) {
  uint16_t res = state->a + cpu_fetch(state) + state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sui(cpu_state *state) {
  uint16_t res = state->a - cpu_fetch(state);
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_sbi(cpu_state *state) {
  uint16_t res = state->a - cpu_fetch(state) - state->flags.c;
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ani(cpu_state *state) {
  uint16_t res = state->a & cpu_fetch(state);
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_xri(cpu_state *state) {
  uint16_t res = state->a ^cpu_fetch(state);
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_ori(cpu_state *state) {
  uint16_t res = state->a | cpu_fetch(state);
  cpu_handle_all_flags(state, res);
  state->a = res & 0xFF;
}

void cpu_execute_cpi(cpu_state *state) {
  uint16_t res = state->a - cpu_fetch(state);
  cpu_handle_all_flags(state, res);
}

void cpu_execute_daa(cpu_state *state) {
  if ((state->a & 0xf) > 0x9) {
    state->a += 0x6;
  }

  if ((state->a & 0xf0) > 0x90) {
    uint16_t res = (uint16_t) state->a + 0x60;
    state->a = res & 0xff;
    cpu_handle_all_flags(state, res);
  }
}

