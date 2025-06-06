#pragma once
#include "Entity/Entity.hpp"

class Player : public Entity {
public:
  Player(int x, int y, int w, int h, SDL_Color color);
  void handleInput(const Uint8 *keystates) override;
  SDL_Point getPosition() const;
};
