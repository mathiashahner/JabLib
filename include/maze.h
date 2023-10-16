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
  Line *line;
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
  bool hasConflicts;

  MazePoint **mazePoints;
  SDL_Renderer *renderer;

  void initPoints();
  void initLines();

  bool verifyConflicts(Line *line);
  bool onSegment(Point p, Point q, Point r);
  bool doIntersect(Point p1, Point q1, Point p2, Point q2);
  int orientation(Point p, Point q, Point r);
  int getRandomNumber(int max);
};

#endif
