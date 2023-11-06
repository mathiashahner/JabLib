#ifndef ASTAR_H
#define ASTAR_H

#include <set>
#include <stack>
#include <maze.h>
#include <iostream>

using namespace std;

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct Cell
{
  int parent_i;
  int parent_j;
  double f, g, h;
};

class AStar
{
public:
  AStar(Maze *maze);

  void aStarSearch(Pair src, Pair dest);

private:
  Maze *maze;
  Cell **cellDetails;

  bool isValid(int row, int col);
  bool isUnBlocked(int row, int col, Direction direction);
  bool isDestination(int row, int col, Pair dest);
  double calculateHValue(int row, int col, Pair dest);
  void tracePath(Pair dest);
};

#endif
