#include "display.h"
#include "machine.h"
#include <SDL.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *texture = NULL;
uint32_t *color_buffer = NULL;

int previous_frame_time = 0;

#define FPS 60
#define FRAME_TARGET_TIME (1000 / FPS)

void display_init() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Error initializing SDL\n");
    exit(0);
  }

  window = SDL_CreateWindow("Space invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);

  if (!window) {
    printf("Error creating SDL Window\n");
    exit(0);
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

  if (!window) {
    printf("Error creating SDL Renderer\n");
    exit(0);
  }

  texture = SDL_CreateTexture(
    renderer,
    SDL_PIXELFORMAT_RGBA32,
    SDL_TEXTUREACCESS_STREAMING,
    256,
    224
  );

  if (!texture) {
    printf("Error creating SDL Texture\n");
    exit(0);
  }

  color_buffer = malloc(sizeof(uint32_t) * 256 * 224);
}

void display_destroy() {
  free(color_buffer);
  SDL_DestroyTexture(texture);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void display_process_events(cpu_state *state) {
  SDL_Event event;
  SDL_PollEvent(&event);
  switch (event.type) {
    case SDL_QUIT:
      is_running = 0;
      break;
    case SDL_KEYDOWN:
      if (event.key.keysym.sym == SDLK_c)
        machine_set_key(KEY_COIN, 1);

      if (event.key.keysym.sym == SDLK_1)
        machine_set_key(KEY_P1_START, 1);
      if (event.key.keysym.sym == SDLK_LEFT)
        machine_set_key(KEY_P1_LEFT, 1);
      if (event.key.keysym.sym == SDLK_RIGHT)
        machine_set_key(KEY_P1_RIGHT, 1);
      if (event.key.keysym.sym == SDLK_SPACE)
        machine_set_key(KEY_P1_FIRE, 1);

      if (event.key.keysym.sym == SDLK_2)
        machine_set_key(KEY_P2_START, 1);
      if (event.key.keysym.sym == SDLK_a)
        machine_set_key(KEY_P2_LEFT, 1);
      if (event.key.keysym.sym == SDLK_d)
        machine_set_key(KEY_P2_RIGHT, 1);
      if (event.key.keysym.sym == SDLK_w)
        machine_set_key(KEY_P2_FIRE, 1);
      break;

    case SDL_KEYUP:
      if (event.key.keysym.sym == SDLK_c)
        machine_set_key(KEY_COIN, 0);

      if (event.key.keysym.sym == SDLK_0)
        machine_set_key(KEY_P1_START, 0);
      if (event.key.keysym.sym == SDLK_LEFT)
        machine_set_key(KEY_P1_LEFT, 0);
      if (event.key.keysym.sym == SDLK_RIGHT)
        machine_set_key(KEY_P1_RIGHT, 0);
      if (event.key.keysym.sym == SDLK_SPACE)
        machine_set_key(KEY_P1_FIRE, 0);

      if (event.key.keysym.sym == SDLK_2)
        machine_set_key(KEY_P2_START, 0);
      if (event.key.keysym.sym == SDLK_a)
        machine_set_key(KEY_P2_LEFT, 0);
      if (event.key.keysym.sym == SDLK_d)
        machine_set_key(KEY_P2_RIGHT, 0);
      if (event.key.keysym.sym == SDLK_w)
        machine_set_key(KEY_P2_FIRE, 0);
      break;
  }
}

void display_render(cpu_state *state) {
  int time_to_wait = FRAME_TARGET_TIME - (SDL_GetTicks() - previous_frame_time);

  if (time_to_wait > 0 && time_to_wait <= FRAME_TARGET_TIME) {
    SDL_Delay(time_to_wait);
  }

  previous_frame_time = SDL_GetTicks();

  SDL_RenderClear(renderer);

  uint32_t black = 0xFF000000;
  uint32_t white = 0xFFFFFFFF;

  for (int i = 0; i < 32; i++) {
    for (int j = 0; j < 224; j++) {
      if (i == 0 && j == 97) {
        cpu_set_interrupt(state, RST_1);
      }

      uint8_t byte = state->memory[0x2400 + i + 32 * j];

      color_buffer[8 * i + 256 * j + 7] = (byte & (1 << 7)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 6] = (byte & (1 << 6)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 5] = (byte & (1 << 5)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 4] = (byte & (1 << 4)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 3] = (byte & (1 << 3)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 2] = (byte & (1 << 2)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 1] = (byte & (1 << 1)) != 0 ? white : black;
      color_buffer[8 * i + 256 * j + 0] = (byte & (1 << 0)) != 0 ? white : black;
    }
  }

  cpu_set_interrupt(state, RST_2);

//  exit(0);
  SDL_UpdateTexture(texture, NULL, color_buffer, (int) (256 * sizeof(uint32_t)));
  SDL_RenderSetScale(renderer, 2, 2);
  SDL_RenderCopyEx(renderer, texture, NULL, NULL, -90, NULL, 0);
  SDL_RenderPresent(renderer);
}
