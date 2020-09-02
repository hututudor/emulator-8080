#include <stdio.h>
#include <stdlib.h>

char *file_to_open = "../roms/invaders.rom";
char *file_to_write = "../roms/invaders.asm";

unsigned char *file_buffer;
unsigned int file_size;

int disassembleBytes[256] = {
  1, 3, 1, 1, 1, 1, 2, 1,
  1, 1, 1, 1, 1, 1, 2, 1,
  1, 3, 1, 1, 1, 1, 3, 1,
  1, 1, 1, 1, 1, 1, 2, 1,
  1, 3, 3, 1, 1, 1, 2, 1,
  1, 1, 3, 1, 1, 1, 2, 1,
  1, 3, 3, 1, 1, 1, 2, 1,
  1, 1, 3, 1, 1, 1, 2, 1,

  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,

  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,
  1, 1, 1, 1, 1, 1, 1, 1,

  1, 1, 3, 3, 3, 1, 2, 1,
  1, 1, 3, 1, 3, 3, 2, 1,
  1, 1, 3, 2, 3, 1, 2, 1,
  1, 1, 3, 2, 3, 1, 2, 1,
  1, 1, 3, 1, 3, 1, 1, 1,
  1, 1, 3, 1, 3, 1, 2, 1,
  1, 1, 3, 1, 3, 1, 2, 1,
  1, 1, 3, 1, 3, 1, 2, 1
};

char disassembleTable[256][256] = {
  "NOP", "LXI B, 0x%02X%02X", "STAX B", "INX B", "INR B", "DCR B", "MVI B, 0x%02X", "RLC",
  "NOP", "DAD B", "LDAX B", "DCX B", "INR C", "DCR C", "MVI C, 0x%02X", "RRC",
  "NOP", "LXI D, 0x%02X%02X", "STAX D", "INX D", "INR D", "DCR D", "MVI D, 0x%02X", "RAL",
  "NOP", "DAD D", "LDAX D", "DCX D", "INR E", "DCR E", "MVI E, 0x%02X", "RAR",
  "NOP", "LXI H, 0x%02X%02X", "SHLD 0x%02X%02X", "INX H", "INR H", "DCR H", "MVI H, 0x%02X", "DAA",
  "NOP", "DAD H", "LHLD 0x%02X%02X", "DCX H", "INR L", "DCR L", "MVI L, 0x%02X", "CMA",
  "NOP", "LXI SP, 0x%02X%02X", "STA 0x%02X%02X", "INX SP", "INR M", "DCR M", "MVI M, 0x%02X", "STC",
  "NOP", "DAD SP", "LDA 0x%02X%02X", "DCX SP", "INR A", "DCR A", "MVI A, 0x%02X", "CMC",

  "MOV B,B", "MOV B,C", "MOV B,D", "MOV B,E", "MOV B,H", "MOV B,L", "MOV B,M", "MOV B,A",
  "MOV C,B", "MOV C,C", "MOV C,D", "MOV C,E", "MOV C,H", "MOV C,L", "MOV C,M", "MOV C,A",
  "MOV D,B", "MOV D,C", "MOV D,D", "MOV D,E", "MOV D,H", "MOV D,L", "MOV D,M", "MOV D,A",
  "MOV E,B", "MOV E,C", "MOV E,D", "MOV E,E", "MOV E,H", "MOV E,L", "MOV E,M", "MOV E,A",
  "MOV H,B", "MOV H,C", "MOV H,D", "MOV H,E", "MOV H,H", "MOV H,L", "MOV H,M", "MOV H,A",
  "MOV L,B", "MOV L,C", "MOV L,D", "MOV L,E", "MOV L,H", "MOV L,L", "MOV L,M", "MOV L,A",
  "MOV M,B", "MOV M,C", "MOV M,D", "MOV M,E", "MOV M,H", "MOV M,L", "HLT", "MOV M,A",
  "MOV A,B", "MOV A,C", "MOV A,D", "MOV A,E", "MOV A,H", "MOV A,L", "MOV A,M", "MOV A,A",

  "ADD B", "ADD C", "ADD D", "ADD E", "ADD H", "ADD L", "ADD M", "ADD A",
  "ADC B", "ADC C", "ADC D", "ADC E", "ADC H", "ADC L", "ADC M", "ADC A",
  "SUB B", "SUB C", "SUB D", "SUB E", "SUB H", "SUB L", "SUB M", "SUB A",
  "SBB B", "SBB C", "SBB D", "SBB E", "SBB H", "SBB L", "SBB M", "SBB A",
  "ANA B", "ANA C", "ANA D", "ANA E", "ANA H", "ANA L", "ANA M", "ANA A",
  "XRA B", "XRA C", "XRA D", "XRA E", "XRA H", "XRA L", "XRA M", "XRA A",
  "ORA B", "ORA C", "ORA D", "ORA E", "ORA H", "ORA L", "ORA M", "ORA A",
  "CMP B", "CMP C", "CMP D", "CMP E", "CMP H", "CMP L", "CMP M", "CMP A",

  "RNZ", "POP B", "JNZ 0x%02X%02X", "JMP 0x%02X%02X", "CNZ 0x%02X%02X", "PUSH B", "ADI 0x%02X", "RST 0",
  "RZ", "RET", "JZ 0x%02X%02X", "NOP", "CZ 0x%02X%02X", "CALL 0x%02X%02X", "ACI 0x%02X", "RST 1",
  "RNC", "POP D", "JNC 0x%02X%02X", "OUT 0x%02X", "CNC 0x%02X%02X", "PUSH D", "SUI 0x%02X", "RST 2",
  "RC", "NOP", "JC 0x%02X%02X", "IN  0x%02X", "CC 0x%02X%02X", "NOP", "SBI 0x%02X", "RST 3",
  "RPO", "POP H", "JPO 0x%02X%02X", "XTHL", "CPO 0x%02X%02X", "PUSH H", "ANI 0x%02X", "RST 4",
  "RPE", "PCHL", "JPE 0x%02X%02X", "XCHG", "CPE 0x%02X%02X", "NOP", "XRI 0x%02X", "RST 5",
  "RP", "POP PSW", "JP 0x%02X%02X", "DI", "CP 0x%02X%02X", "PUSH PSW", "ORI 0x%02X", "RST 6",
  "RM", "SPHL", "JM 0x%02X%02X", "EI", "CM 0x%02X%02X", "NOP", "CPI 0x%02X", "RST 7"
};

void disassemble() {
  FILE *out = fopen(file_to_write, "wb");
  unsigned char *pc = file_buffer;
  unsigned int byte_count = 0;

  while (file_size) {
    int op_bytes = disassembleBytes[*pc];

    if (!op_bytes) {
      op_bytes = 1;
    }

    fprintf(out, "0x%04X: ", byte_count);

    if (op_bytes == 3) {
      fprintf(out, disassembleTable[*pc], *(pc + 2), *(pc + 1));
    } else {
      fprintf(out, disassembleTable[*pc], *(pc + 1));
    }
    fprintf(out, "\n");

    file_size -= op_bytes;
    byte_count += op_bytes;
    pc += op_bytes;
  }

  fclose(out);
}

int main() {
  FILE *file = fopen(file_to_open, "rb");

  if (!file) {
    printf("FILE COULD NOT BE LOADED");
    return 1;
  }

  fseek(file, 0, SEEK_END);
  file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  file_buffer = malloc(file_size * sizeof(char));
  fread(file_buffer, 1, file_size, file);
  fclose(file);

  if (!file_buffer) {
    printf("FILE IS EMPTY");
    return 1;
  }

  disassemble();
  return 0;
}
