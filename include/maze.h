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
  const int rectWidth = 2;
  const int rectHeight = 2;
  const int rectDistance = 12;
  const int rectColor = 0xFF0000FF;

  int rows;
  int columns;

  Rect **rects;
  SDL_Renderer *renderer;

  void init();
};

#endif
