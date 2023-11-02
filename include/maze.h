#ifndef MAZE_H
#define MAZE_H

#include <line.h>
#include <point.h>
#include <SDL2/SDL.h>

typedef enum Direction
{
  UP,
  DOWN,
  LEFT,
  RIGHT
} Direction;

typedef enum ResizeOption
{
  ADD_ROW,
  ADD_COLUMN,
  REMOVE_ROW,
  REMOVE_COLUMN
} ResizeOption;

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
  int pointDistance;
  bool isGenerating;

  void update();
  void render(int screenWidth, int screenHeight);
  void reset();
  void decreaseDelay();
  void increaseDelay();
  void decreasePointDistance();
  void increasePointDistance();
  void resizeMaze(ResizeOption option);

private:
  const int xOffset = 240;
  const int yOffset = 0;
  const int pointColor = 0xAA00AAFF;
  const int lineColor = 0xAA00AAFF;

  MazePoint **mazePoints;
  SDL_Renderer *renderer;

  void initPoints();
  void initLines();
  void deleteMazePoints();
  void depthFirstSearch(MazePoint *point);

  MazePoint *getUnvisitedNeighbour(MazePoint *point);
  void removeWall(MazePoint *point, MazePoint *neighbour);
  Direction getRandomDirection(int *selectedValues, int numEnumValues);
};

#endif
