#include <astar.h>

AStar::AStar(Maze *maze)
{
  this->maze = maze;
}

void AStar::aStarSearch(Pair src, Pair dest)
{
  bool closedList[maze->rows - 1][maze->columns - 1];
  memset(closedList, false, sizeof(closedList));

  cellDetails = new Cell *[maze->rows - 1];

  for (int row = 0; row < maze->rows - 1; row++)
  {
    cellDetails[row] = new Cell[maze->columns - 1];
  }

  int i, j;

  for (i = 0; i < maze->rows - 1; i++)
  {
    for (j = 0; j < maze->columns - 1; j++)
    {
      cellDetails[i][j].f = FLT_MAX;
      cellDetails[i][j].g = FLT_MAX;
      cellDetails[i][j].h = FLT_MAX;
      cellDetails[i][j].parent_i = -1;
      cellDetails[i][j].parent_j = -1;
    }
  }

  i = src.first, j = src.second;
  cellDetails[i][j].f = 0.0;
  cellDetails[i][j].g = 0.0;
  cellDetails[i][j].h = 0.0;
  cellDetails[i][j].parent_i = i;
  cellDetails[i][j].parent_j = j;

  set<pPair> openList;
  openList.insert(make_pair(0.0, make_pair(i, j)));

  while (!openList.empty())
  {
    pPair p = *openList.begin();

    openList.erase(openList.begin());

    i = p.second.first;
    j = p.second.second;
    closedList[i][j] = true;

    double gNew, hNew, fNew;

    if (isValid(i - 1, j))
    {
      if (isDestination(i - 1, j, dest))
      {
        cellDetails[i - 1][j].parent_i = i;
        cellDetails[i - 1][j].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i - 1][j] == false && isUnBlocked(i, j, UP))
      {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calculateHValue(i - 1, j, dest);
        fNew = gNew + hNew;

        if (cellDetails[i - 1][j].f == FLT_MAX || cellDetails[i - 1][j].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(i - 1, j)));

          cellDetails[i - 1][j].f = fNew;
          cellDetails[i - 1][j].g = gNew;
          cellDetails[i - 1][j].h = hNew;
          cellDetails[i - 1][j].parent_i = i;
          cellDetails[i - 1][j].parent_j = j;
        }
      }
    }

    if (isValid(i + 1, j))
    {
      if (isDestination(i + 1, j, dest))
      {
        cellDetails[i + 1][j].parent_i = i;
        cellDetails[i + 1][j].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i + 1][j] == false && isUnBlocked(i, j, DOWN))
      {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calculateHValue(i + 1, j, dest);
        fNew = gNew + hNew;

        if (cellDetails[i + 1][j].f == FLT_MAX || cellDetails[i + 1][j].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(i + 1, j)));
          cellDetails[i + 1][j].f = fNew;
          cellDetails[i + 1][j].g = gNew;
          cellDetails[i + 1][j].h = hNew;
          cellDetails[i + 1][j].parent_i = i;
          cellDetails[i + 1][j].parent_j = j;
        }
      }
    }

    if (isValid(i, j + 1))
    {
      if (isDestination(i, j + 1, dest))
      {
        cellDetails[i][j + 1].parent_i = i;
        cellDetails[i][j + 1].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i][j + 1] == false && isUnBlocked(i, j, RIGHT))
      {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calculateHValue(i, j + 1, dest);
        fNew = gNew + hNew;

        if (cellDetails[i][j + 1].f == FLT_MAX || cellDetails[i][j + 1].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(i, j + 1)));

          cellDetails[i][j + 1].f = fNew;
          cellDetails[i][j + 1].g = gNew;
          cellDetails[i][j + 1].h = hNew;
          cellDetails[i][j + 1].parent_i = i;
          cellDetails[i][j + 1].parent_j = j;
        }
      }
    }

    if (isValid(i, j - 1))
    {
      if (isDestination(i, j - 1, dest))
      {
        cellDetails[i][j - 1].parent_i = i;
        cellDetails[i][j - 1].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i][j - 1] == false && isUnBlocked(i, j, LEFT))
      {
        gNew = cellDetails[i][j].g + 1.0;
        hNew = calculateHValue(i, j - 1, dest);
        fNew = gNew + hNew;

        if (cellDetails[i][j - 1].f == FLT_MAX || cellDetails[i][j - 1].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(i, j - 1)));

          cellDetails[i][j - 1].f = fNew;
          cellDetails[i][j - 1].g = gNew;
          cellDetails[i][j - 1].h = hNew;
          cellDetails[i][j - 1].parent_i = i;
          cellDetails[i][j - 1].parent_j = j;
        }
      }
    }
  }

  return;
}

bool AStar::isValid(int row, int col)
{
  return (row >= 0) && (row < maze->rows - 1) &&
         (col >= 0) && (col < maze->columns - 1);
}

bool AStar::isUnBlocked(int row, int col, Direction direction)
{
  switch (direction)
  {
  case UP:
    return !maze->mazePoints[row][col].xLine;
    break;
  case DOWN:
    return !maze->mazePoints[row + 1][col].xLine;
    break;
  case RIGHT:
    return !maze->mazePoints[row][col + 1].yLine;
    break;
  case LEFT:
    return !maze->mazePoints[row][col].yLine;
    break;
  default:
    return false;
  }
}

bool AStar::isDestination(int row, int col, Pair dest)
{
  if (row == dest.first && col == dest.second)
    return true;
  return false;
}

double AStar::calculateHValue(int row, int col, Pair dest)
{
  return (double)sqrt((row - dest.first) * (row - dest.first) +
                      (col - dest.second) * (col - dest.second));
}

void AStar::tracePath(Pair dest)
{
  int row = dest.first;
  int col = dest.second;

  stack<Pair> Path;

  while (!(cellDetails[row][col].parent_i == row &&
           cellDetails[row][col].parent_j == col))
  {
    Path.push(make_pair(row, col));
    maze->mazePoints[row][col].isPath = true;
    int temp_row = cellDetails[row][col].parent_i;
    int temp_col = cellDetails[row][col].parent_j;
    row = temp_row;
    col = temp_col;
  }

  Path.push(make_pair(row, col));
  while (!Path.empty())
  {
    pair<int, int> p = Path.top();
    Path.pop();
    printf("-> (%d,%d) ", p.first, p.second);
  }
}
