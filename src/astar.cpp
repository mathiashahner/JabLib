#include <astar.h>

AStar::AStar(Maze *maze)
{
  this->maze = maze;
}

AStar::~AStar()
{
  for (int row = 0; row < maze->rows - 1; row++)
    delete[] cellDetails[row];
  delete[] cellDetails;
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

  int row, col;

  for (row = 0; row < maze->rows - 1; row++)
  {
    for (col = 0; col < maze->columns - 1; col++)
    {
      cellDetails[row][col].f = FLT_MAX;
      cellDetails[row][col].g = FLT_MAX;
      cellDetails[row][col].h = FLT_MAX;
      cellDetails[row][col].parentRow = -1;
      cellDetails[row][col].parentCol = -1;
    }
  }

  row = src.first, col = src.second;
  cellDetails[row][col].f = 0.0;
  cellDetails[row][col].g = 0.0;
  cellDetails[row][col].h = 0.0;
  cellDetails[row][col].parentRow = row;
  cellDetails[row][col].parentCol = col;

  set<pPair> openList;
  openList.insert(make_pair(0.0, make_pair(row, col)));

  while (!openList.empty())
  {
    pPair p = *openList.begin();

    openList.erase(openList.begin());

    row = p.second.first;
    col = p.second.second;

    closedList[row][col] = true;
    maze->buildExploredCircle(&maze->mazePoints[row][col]);

    if (maze->delay > 0)
      SDL_Delay(maze->delay);

    double gNew, hNew, fNew;

    if (isValid(row - 1, col) && isUnBlocked(row, col, UP))
    {
      if (isDestination(row - 1, col, dest))
      {
        cellDetails[row - 1][col].parentRow = row;
        cellDetails[row - 1][col].parentCol = col;
        tracePath(dest);
        return;
      }
      else if (closedList[row - 1][col] == false)
      {
        gNew = cellDetails[row][col].g + 1.0;
        hNew = calculateHValue(row - 1, col, dest);
        fNew = gNew + hNew;

        if (cellDetails[row - 1][col].f == FLT_MAX || cellDetails[row - 1][col].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(row - 1, col)));

          cellDetails[row - 1][col].f = fNew;
          cellDetails[row - 1][col].g = gNew;
          cellDetails[row - 1][col].h = hNew;
          cellDetails[row - 1][col].parentRow = row;
          cellDetails[row - 1][col].parentCol = col;
        }
      }
    }

    if (isValid(row + 1, col) && isUnBlocked(row, col, DOWN))
    {
      if (isDestination(row + 1, col, dest))
      {
        cellDetails[row + 1][col].parentRow = row;
        cellDetails[row + 1][col].parentCol = col;
        tracePath(dest);
        return;
      }
      else if (closedList[row + 1][col] == false)
      {
        gNew = cellDetails[row][col].g + 1.0;
        hNew = calculateHValue(row + 1, col, dest);
        fNew = gNew + hNew;

        if (cellDetails[row + 1][col].f == FLT_MAX || cellDetails[row + 1][col].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(row + 1, col)));
          cellDetails[row + 1][col].f = fNew;
          cellDetails[row + 1][col].g = gNew;
          cellDetails[row + 1][col].h = hNew;
          cellDetails[row + 1][col].parentRow = row;
          cellDetails[row + 1][col].parentCol = col;
        }
      }
    }

    if (isValid(row, col + 1) && isUnBlocked(row, col, RIGHT))
    {
      if (isDestination(row, col + 1, dest))
      {
        cellDetails[row][col + 1].parentRow = row;
        cellDetails[row][col + 1].parentCol = col;
        tracePath(dest);
        return;
      }
      else if (closedList[row][col + 1] == false)
      {
        gNew = cellDetails[row][col].g + 1.0;
        hNew = calculateHValue(row, col + 1, dest);
        fNew = gNew + hNew;

        if (cellDetails[row][col + 1].f == FLT_MAX || cellDetails[row][col + 1].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(row, col + 1)));

          cellDetails[row][col + 1].f = fNew;
          cellDetails[row][col + 1].g = gNew;
          cellDetails[row][col + 1].h = hNew;
          cellDetails[row][col + 1].parentRow = row;
          cellDetails[row][col + 1].parentCol = col;
        }
      }
    }

    if (isValid(row, col - 1) && isUnBlocked(row, col, LEFT))
    {
      if (isDestination(row, col - 1, dest))
      {
        cellDetails[row][col - 1].parentRow = row;
        cellDetails[row][col - 1].parentCol = col;
        tracePath(dest);
        return;
      }
      else if (closedList[row][col - 1] == false)
      {
        gNew = cellDetails[row][col].g + 1.0;
        hNew = calculateHValue(row, col - 1, dest);
        fNew = gNew + hNew;

        if (cellDetails[row][col - 1].f == FLT_MAX || cellDetails[row][col - 1].f > fNew)
        {
          openList.insert(make_pair(fNew, make_pair(row, col - 1)));

          cellDetails[row][col - 1].f = fNew;
          cellDetails[row][col - 1].g = gNew;
          cellDetails[row][col - 1].h = hNew;
          cellDetails[row][col - 1].parentRow = row;
          cellDetails[row][col - 1].parentCol = col;
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
  return sqrt((row - dest.first) * (row - dest.first) +
              (col - dest.second) * (col - dest.second));
}

void AStar::tracePath(Pair dest)
{
  int row = dest.first;
  int col = dest.second;

  while (!(cellDetails[row][col].parentRow == row &&
           cellDetails[row][col].parentCol == col))
  {
    maze->buildPathCircle(&maze->mazePoints[row][col]);

    if (maze->delay > 0)
      SDL_Delay(maze->delay);

    int temp_row = cellDetails[row][col].parentRow;
    int temp_col = cellDetails[row][col].parentCol;
    row = temp_row;
    col = temp_col;
  }
}
