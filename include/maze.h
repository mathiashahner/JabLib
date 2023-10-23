#ifndef MAZE_H
#define MAZE_H

#include <line.h>
#include <time.h>
#include <point.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

typedef enum Direction
{
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

typedef struct MazePoint
{
  Line *xLine;
  Line *yLine;
  Point *point;
  bool isVisited;
} MazePoint;

class Maze
{
public:
  Maze(SDL_Renderer *renderer, int rows, int columns);
  ~Maze();

  int rows;
  int columns;
  int delay;

  void update();
  void render();
  void reset();
  void decreaseDelay();
  void increaseDelay();

private:
  const int pointDistance = 10;
  const int pointColor = 0xAA00AAFF;
  const int lineColor = 0xAA00AAFF;

  MazePoint **mazePoints;
  SDL_Renderer *renderer;

  void initPoints();
  void initLines();
  void depthFirstSearch(MazePoint *point);

  MazePoint *getUnvisitedNeighbour(MazePoint *point);
  void removeWall(MazePoint *point, MazePoint *neighbour);
  Direction getRandomDirection(int *selectedValues, int numEnumValues);
};

#endif
