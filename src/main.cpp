#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Window {
public:
  Window() : window(nullptr), renderer(nullptr), isRunning(false) {};

  bool init(const char *title, int w, int h) {
    bool success = true;
    if (0 > SDL_Init(SDL_INIT_VIDEO)) {
      printf("err no init work me very zad, %s\n", SDL_GetError());
      success = false;
    } else {
      window =
          SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                           SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

      if (NULL == window) {
        printf("err no window work me very zad, %s\n", SDL_GetError());
        success = false;
      } else {
        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (NULL == renderer) {
          printf("err no renderer work me very zad, %s\n", SDL_GetError());
          success = false;
        } else {
          isRunning = true;
        }
      }
    }
    return success;
  }

  void clean() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  void run() {
    while (isRunning) {
      handlePollEvents();
      render();
      SDL_Delay(16);
    }
  }

  // NEW: DECONSTRUCTOR
  ~Window() { clean(); }

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;

  void handlePollEvents() {
    SDL_Event e;
    while (0 != SDL_PollEvent(&e)) {
      if (e.type == SDL_QUIT)
        isRunning = false;
    }
  }

  void render() {
    SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
  }

  void update() {
    // TODO: ADD STUFF
  }
};

int main() {
  Window window;

  if (window.init("e", SCREEN_WIDTH, SCREEN_HEIGHT))
    window.run();
}
