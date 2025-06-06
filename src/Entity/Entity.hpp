#pragma once
#include "SDL.h"

class Entity {
public:
  Entity(int x, int y, int w, int h, SDL_Color color);
  virtual ~Entity() = default;

  virtual void handleInput(const Uint8 *keystates);
  virtual void render(SDL_Renderer *renderer);
  virtual void update();

  SDL_Point getPosition() const;

  SDL_Rect getRect() const;

protected:
  SDL_Rect rect;
  SDL_Color color;
};
