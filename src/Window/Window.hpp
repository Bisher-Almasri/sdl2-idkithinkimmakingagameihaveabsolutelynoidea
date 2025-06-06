#pragma once
#include "Entity/Enemy/Enemy.hpp"
#include "Entity/Player/Player.hpp"
#include <vector>

class Window {
public:
  Window();
  ~Window();

  bool init(const char *title, int w, int h);
  void run();
  void clean();

private:
  SDL_Window *window;
  SDL_Renderer *renderer;
  bool isRunning;
  Player *player;
  Enemy *enemy;
  std::vector<Entity *> entities;

  void handlePollEvents();
  void render();
  void update();
};
