#include "Window.hpp"
#include "SDL_keyboard.h"
#include "Utils/collider.hpp"
#include <stdio.h>

Window::Window() : window(nullptr), renderer(nullptr), isRunning(false) {}

bool Window::init(const char *title, int w, int h) {
  if (0 > SDL_Init(SDL_INIT_VIDEO)) {
    printf("err no init work me very zad, %s\n", SDL_GetError());
    return false;
  };

  window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);

  if (!window) {
    printf("err no window work me very zad, %s\n", SDL_GetError());
    return false;
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  if (!renderer) {
    printf("err no renderer work me very zad, %s\n", SDL_GetError());
    return false;
  }

  player = new Player(100, 100, 50, 50, {255, 0, 0, 255});
  enemy = new Enemy(300, 300, 50, 50, {255, 0, 0, 255}, player);
  entities.push_back(enemy);
  isRunning = true;

  return true;
}

void Window::clean() {
  for (Entity *e : entities)
    delete e;
  entities.clear();
  delete player;

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Window::render() {
  SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
  SDL_RenderClear(renderer);

  player->render(renderer);
  for (Entity *e : entities)
    e->render(renderer);

  SDL_RenderPresent(renderer);
}

void Window::handlePollEvents() {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT)
      isRunning = false;
  }
}

void Window::update() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);
  player->handleInput(keystates);

  for (auto it = entities.begin(); it != entities.end();) {
    Entity *entity = *it;
    entity->update();

    if (checkCollision(player->getRect(), entity->getRect())) {
      printf("Entity deleted on collision!\n");
      delete entity;
      it = entities.erase(it);
    } else {
      ++it;
    }
  }
}

void Window::run() {
  while (isRunning) {
    handlePollEvents();
    update();
    render();
    SDL_Delay(16);
  }
}

Window::~Window() { clean(); }
