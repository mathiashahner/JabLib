#ifndef ASTAR_H
#define ASTAR_H

#include <set>
#include <stack>
#include <maze.h>
#include <point.h>

#define ROW 9
#define COL 10

struct Cell
{
  int parent_i, parent_j;
  double f, g, h;
};

using namespace std;

class AStar
{
public:
  AStar(Maze *maze);

  Maze *maze;

  void aStarSearch(int grid[][COL], Pair src, Pair dest);

private:
  bool isValid(int row, int col);
  bool isUnBlocked(int row, int col, Direction direction);
  bool isDestination(int row, int col, Pair dest);
  double calculateHValue(int row, int col, Pair dest);
  void tracePath(Cell cellDetails[][COL], Pair dest);
};

#endif
