#pragma once

extern char disassemble_table[256][256];
extern int disassemble_byte_length[256];

enum INSTRUCTIONS {
  NOP = 0x00,
  LXI_B = 0x01,
  STAX_B = 0x02,
  INX_B = 0x03,
  INR_B = 0x04,
  DCR_B = 0x05,
  MVI_B_D8 = 0x06,
  RLC = 0x07,

  HLT = 0x76
};