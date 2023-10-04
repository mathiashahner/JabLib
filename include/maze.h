#ifndef MAZE_H
#define MAZE_H

#include <rect.h>
#include <SDL2/SDL.h>

class Maze
{
public:
  Maze(SDL_Renderer *renderer, int rows, int columns);
  ~Maze();

  void render();

private:
  int rows;
  int columns;

  SDL_Rect **rects;
  SDL_Renderer *renderer;

  void init();
};

#endif
