#include "Entity.hpp"

Entity::Entity(int x, int y, int w, int h, SDL_Color color)
    : rect({x, y, w, h}), color(color) {}

void Entity::handleInput(const Uint8 *) {}

void Entity::render(SDL_Renderer *renderer) {
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}

void Entity::update() {}

SDL_Point Entity::getPosition() const { return {rect.x, rect.y}; }
SDL_Rect Entity::getRect() const { return rect; }
