#include <rect.h>

Rect::Rect() {}

Rect::Rect(SDL_Renderer *renderer, int x, int y, int w, int h, Uint32 color)
{
  this->renderer = renderer;

  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;

  this->color.r = color >> 24;
  this->color.g = (color >> 16) & 0xFF;
  this->color.b = (color >> 8) & 0xFF;
  this->color.a = color & 0xFF;
}

void Rect::render()
{
  SDL_Rect rect = {x, y, w, h};

  SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
  SDL_RenderFillRect(renderer, &rect);
}
