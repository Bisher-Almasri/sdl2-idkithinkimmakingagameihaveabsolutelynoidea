#include "Enemy.hpp"
#include "Entity/Player/Player.hpp"
#include <cmath>

Enemy::Enemy(int x, int y, int w, int h, SDL_Color color, Player *target)
    : Entity(x, y, w, h, color), target(target), velocityX(0), velocityY(0),
      speed(2.5f) {}

void Enemy::handleInput(const Uint8 *) {}

void Enemy::update() {
  SDL_Point playerPos = target->getPosition();

  float dx = static_cast<float>(playerPos.x - rect.x);
  float dy = static_cast<float>(playerPos.y - rect.y);
  float distance = std::sqrt(dx * dx + dy * dy);

  if (distance > 0.1f) {
    dx /= distance;
    dy /= distance;

    velocityX = dx * speed;
    velocityY = dy * speed;

    rect.x += static_cast<int>(velocityX);
    rect.y += static_cast<int>(velocityY);
  }
}
