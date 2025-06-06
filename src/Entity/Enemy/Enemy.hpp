#pragma once
#include "Entity/Entity.hpp"
#include "Entity/Player/Player.hpp"

class Enemy : public Entity {
public:
  Enemy(int x, int y, int w, int h, SDL_Color color, Player *target);
  void handleInput(const Uint8 *keystates) override;
  void update() override;

private:
  Player *target;
  float velocityX;
  float velocityY;
  float speed;
};
