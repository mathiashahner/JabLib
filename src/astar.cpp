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
    maze->mazePoints[i][j].isExplored = true;

    if (maze->delay > 0)
      SDL_Delay(maze->delay);

    double gNew, hNew, fNew;

    if (isValid(i - 1, j) && isUnBlocked(i, j, UP))
    {
      if (isDestination(i - 1, j, dest))
      {
        cellDetails[i - 1][j].parent_i = i;
        cellDetails[i - 1][j].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i - 1][j] == false)
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

    if (isValid(i + 1, j) && isUnBlocked(i, j, DOWN))
    {
      if (isDestination(i + 1, j, dest))
      {
        cellDetails[i + 1][j].parent_i = i;
        cellDetails[i + 1][j].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i + 1][j] == false)
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

    if (isValid(i, j + 1) && isUnBlocked(i, j, RIGHT))
    {
      if (isDestination(i, j + 1, dest))
      {
        cellDetails[i][j + 1].parent_i = i;
        cellDetails[i][j + 1].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i][j + 1] == false)
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

    if (isValid(i, j - 1) && isUnBlocked(i, j, LEFT))
    {
      if (isDestination(i, j - 1, dest))
      {
        cellDetails[i][j - 1].parent_i = i;
        cellDetails[i][j - 1].parent_j = j;
        tracePath(dest);
        return;
      }
      else if (closedList[i][j - 1] == false)
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

  maze->mazePoints[0][0].isPath = true;

  while (!(cellDetails[row][col].parent_i == row &&
           cellDetails[row][col].parent_j == col))
  {
    maze->mazePoints[row][col].isPath = true;

    if (maze->delay > 0)
      SDL_Delay(maze->delay);

    int temp_row = cellDetails[row][col].parent_i;
    int temp_col = cellDetails[row][col].parent_j;
    row = temp_row;
    col = temp_col;
  }
}
