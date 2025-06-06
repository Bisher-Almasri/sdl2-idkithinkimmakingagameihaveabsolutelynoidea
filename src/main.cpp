#include <SDL2/SDL.h>
#include <SDL2/SDL_error.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_keyboard.h>
#include <SDL2/SDL_keycode.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

class Player {
public:
  Player(int x, int y, int w, int h, SDL_Color color)
      : rect({x, y, w, h}), color(color) {};

  void handleInput(const Uint8 *keystates) {
    int speed = 5;

    if (keystates[SDL_SCANCODE_UP] || keystates[SDL_SCANCODE_W])
      rect.y -= speed;
    if (keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_S])
      rect.y += speed;
    if (keystates[SDL_SCANCODE_LEFT] || keystates[SDL_SCANCODE_A])
      rect.x -= speed;
    if (keystates[SDL_SCANCODE_RIGHT] || keystates[SDL_SCANCODE_D])
      rect.x += speed;
  }

  void render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, &rect);
  }

private:
  SDL_Rect rect;
  SDL_Color color;
};

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
          player = new Player(100, 100, 50, 50, {255, 0, 0, 255});
          isRunning = true;
        }
      }
    }
    return success;
  }

  void clean() {
    delete player;
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
  }

  void run() {
    while (isRunning) {
      handlePollEvents();
      update();
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
  Player *player;

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
    player->render(renderer);
    SDL_RenderPresent(renderer);
  }

  void update() {
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    player->handleInput(keystates);
  }
};

int main() {
  Window window;

  if (window.init("e", SCREEN_WIDTH, SCREEN_HEIGHT))
    window.run();
}
