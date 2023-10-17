#ifndef MAZE_H
#define MAZE_H

#include <line.h>
#include <time.h>
#include <point.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef struct MazePoint
{
  Line *xLine;
  Line *yLine;
  Point *point;
} MazePoint;

class Maze
{
public:
  Maze(SDL_Renderer *renderer, int rows, int columns);
  ~Maze();

  void update();
  void render();

private:
  const int pointDistance = 10;
  const int pointColor = 0xFF0000FF;
  const int lineColor = 0x00FF00FF;

  int rows;
  int columns;

  MazePoint **mazePoints;
  SDL_Renderer *renderer;

  void initPoints();
  void initLines();

  int getRandomNumber(int max);
};

#endif
