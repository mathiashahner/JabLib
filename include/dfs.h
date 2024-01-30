#ifndef DFS_H
#define DFS_H

#include <maze.h>

class DFS
{
public:
  DFS(Maze *maze);

  Maze *maze;

  void depthFirstSearch(MazePoint *point);

private:
  MazePoint *getUnvisitedNeighbour(MazePoint *point);
  Direction getRandomDirection(int *selectedValues, int numEnumValues);
};

#endif
