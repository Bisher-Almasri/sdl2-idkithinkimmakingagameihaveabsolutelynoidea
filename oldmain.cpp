#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

bool init();
bool loadbmp();
void close();

SDL_Window *window;
SDL_Surface *windowSurface;
SDL_Surface *helloWorld;

bool init() {
  bool success = true;

  if (0 > SDL_Init(SDL_INIT_VIDEO)) {
    success = false;
    printf("err init, sdl err: %s\n", SDL_GetError());
  } else {
    window = SDL_CreateWindow("Roar", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (NULL == window) {
      success = false;
      printf("Err with make window, sdl err: %s\n", SDL_GetError());
    } else {
      windowSurface = SDL_GetWindowSurface(window);
    }
  }

  return success;
}

bool loadbmp() {
  bool success = true;

  helloWorld = SDL_LoadBMP("/home/balma/dev/C++/sdl2/learn/hello_world.bmp");
  if (NULL == helloWorld) {
    success = false;
    printf("error with idk atp, sdl err: %s\n", SDL_GetError());
  }
  return success;
}

void close() {
  SDL_FreeSurface(helloWorld);
  helloWorld = NULL;
  SDL_DestroyWindow(window);
  window = NULL;
  SDL_Quit();
}

int main() {
  if (!init()) {
    printf("idkkddkdkdkd dkkill me");
    return -1;
  } else {
    if (!loadbmp()) {
      printf("roar eooro roro ");
      return -1;
    } else {
      SDL_BlitSurface(helloWorld, NULL, windowSurface, NULL);

      SDL_UpdateWindowSurface(window);

      SDL_Event e;
      bool quit;

      while (false == quit) {
        while (0 != SDL_PollEvent(&e)) {
          if (e.type == SDL_QUIT) {
            quit = true;
          } else if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
            case SDLK_ESCAPE:
              printf("press escape roofofwaenfj4rtrggrg");
              break;
            case SDLK_a:
              printf("gfdvdbtgvdgbvf you press a erfgbhgtr");
              break;
            }
          }
        }
      }
    }
  }

  close();
  return 0;
}
