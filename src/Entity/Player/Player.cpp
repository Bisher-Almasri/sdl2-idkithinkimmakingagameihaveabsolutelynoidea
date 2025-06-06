#include "Player.hpp"

Player::Player(int x, int y, int w, int h, SDL_Color color)
    : Entity(x, y, w, h, color) {}

void Player::handleInput(const Uint8 *keystates) {
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

SDL_Point Player::getPosition() const { return {rect.x, rect.y}; }
