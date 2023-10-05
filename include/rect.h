#ifndef RECT_H
#define RECT_H

#include <SDL2/SDL.h>

class Rect
{
public:
  Rect();
  Rect(SDL_Renderer *renderer, int x, int y, int w, int h, Uint32 color);

  int x, y;

  void render();

private:
  SDL_Rect rect;
  SDL_Color color;
  SDL_Renderer *renderer;
};

#endif
