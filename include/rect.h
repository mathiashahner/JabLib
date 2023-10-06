#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rect
{
public:
  Rect();
  Rect(SDL_Renderer *renderer, int x, int y, int w, int h, Uint32 color);

  int x, y;
  int w, h;

  void render();

private:
  SDL_Color color;
  SDL_Renderer *renderer;
};

#endif
