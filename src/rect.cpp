#include <rect.h>

Rect::Rect() {}

Rect::Rect(SDL_Renderer *renderer, int x, int y, int w, int h, Uint32 color)
{
  this->renderer = renderer;

  this->color.r = color >> 24;
  this->color.g = (color >> 16) & 0xFF;
  this->color.b = (color >> 8) & 0xFF;
  this->color.a = color & 0xFF;

  rect = {x, y, w, h};
}

void Rect::render()
{
  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}
