#define DISPLAY 1
#define CPU_DEBUG 1

#include <SDL.h>
#include <stdio.h>

#include "cpu.h"
#include "display.h"
#include "machine.h"

char *file_to_open = "../roms/invaders.rom";
uint8_t is_running = 1;

int run_emulation(void *param) {
  cpu_state *state = (cpu_state *)param;
  cpu_start_emulation(state);
  cpu_print_dump(state);
  cpu_destroy(state);
  return 0;
}

int run_display(void *param) {
#if DISPLAY
  cpu_state *state = (cpu_state *)param;
  display_init();

  while (is_running) {
    display_process_events(state);
    display_render(state);
  }

  display_destroy();
#endif
  return 0;
}

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

  is_running = 1;

  machine_init();
  cpu_state state = cpu_init(file_buffer, file_size);
  free(file_buffer);

  SDL_Thread *emulation_thread =
      SDL_CreateThread(run_emulation, "emulation", &state);
  SDL_Thread *display_thread = SDL_CreateThread(run_display, "display", &state);

  if (!emulation_thread) {
    printf("Could not create emulation thread\n");
    exit(0);
  }

  if (!display_thread) {
    printf("Could not create display thread\n");
    exit(0);
  }

  SDL_WaitThread(emulation_thread, NULL);
  SDL_WaitThread(display_thread, NULL);

  return 0;
}