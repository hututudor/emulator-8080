#include "cpu.h"
#include <stdio.h>

char *file_to_open = "../roms/invaders.rom";

int main() {
  char *file_buffer;
  uint32_t file_size;

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

  cpu_state state = cpu_init(file_buffer, file_size);
  free(file_buffer);

  cpu_start_emulation(&state);
  cpu_print_dump(&state);
  cpu_destroy(&state);

  return 0;
}