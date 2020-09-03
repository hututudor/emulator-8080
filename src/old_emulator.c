#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *file_to_open = "../roms/test.rom";
char *file_buffer;
unsigned int file_size;

typedef struct {
  uint8_t z: 1;
  uint8_t s: 1;
  uint8_t p: 1;
  uint8_t c: 1;
  uint8_t ac: 1;
  uint8_t padding: 3;
} ConditionCodes;

typedef struct {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t h;
  uint8_t l;

  uint16_t pc;
  uint16_t sp;

  ConditionCodes cc;

  uint8_t *memory;
  uint8_t enable;
  uint8_t is_running;
} State;

State cpu_state;

void debug_print() {
  printf(
    "a: %02x | b: %02x | c: %02x | d: %02x | e: %02x | h: %02x | l: %02x | pc: %04x | sp: %04x | Z: %02x | S: %02x | P: %02x | C: %02x | AC: %02x \n",
    cpu_state.a, cpu_state.b, cpu_state.c, cpu_state.d, cpu_state.e, cpu_state.h, cpu_state.l, cpu_state.pc,
    cpu_state.sp, cpu_state.cc.z, cpu_state.cc.s, cpu_state.cc.p, cpu_state.cc.c, cpu_state.cc.ac);
}

void init_emulator(char *rom) {
  cpu_state.memory = malloc(sizeof(uint8_t) * 16 * 16 * 16 * 16);
  memcpy(cpu_state.memory, rom, file_size);

  cpu_state.is_running = 1;
}

void destroy_emulator() {
  free(cpu_state.memory);
}

uint8_t fetch_next() {
  return cpu_state.memory[cpu_state.pc++];
}

void emulate() {
  while (cpu_state.is_running) {
    debug_print();
    uint8_t op_code = fetch_next();
    printf("%02X \n", op_code);

    switch (op_code) {
      // INR instructions
      case 0x04:
        cpu_state.b++;
        break;

      case 0x0c:
        cpu_state.c++;
        break;

      case 0x14:
        cpu_state.d++;
        break;

      case 0x1c:
        cpu_state.e++;
        break;

      case 0x24:
        cpu_state.h++;
        break;

      case 0x2c:
        cpu_state.l++;
        break;

      case 0x34:
        uint16_t temp = 0;
        temp += cpu_state.h;
        temp <<= 8;
        temp += cpu_state.l;
        temp ++;
        cpu_state.h = (temp & 0xFF00) >> 8;
        cpu_state.l = temp & 0x00FF;
        break;

      case 0x3c:
        cpu_state.a++;
        break;

      case 0x76:
        cpu_state.is_running = 0;
        break;

      default:
        break;
    }

    getchar();
  }
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

  init_emulator(file_buffer);
  emulate();
  destroy_emulator();

  free(file_buffer);
  return 0;
}