#include <math.h>
#include <astar.h>
#include <float.h>
#include <string.h>

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
  int row, col;
  double gNew, hNew, fNew;

  bool closedList[maze->rows - 1][maze->columns - 1];
  memset(closedList, false, sizeof(closedList));

  initCellDetails();

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

    for (int dir = 0; dir < sizeof(enum Direction); dir++)
    {
      int newRow = row, newCol = col;
      Direction direction = (Direction)dir;

      switch (direction)
      {
      case UP:
        newRow--;
        break;
      case DOWN:
        newRow++;
        break;
      case LEFT:
        newCol--;
        break;
      case RIGHT:
        newCol++;
        break;
      }

      if (isValid(newRow, newCol) && isUnBlocked(row, col, direction))
      {
        if (isDestination(newRow, newCol, dest))
        {
          cellDetails[newRow][newCol].parentRow = row;
          cellDetails[newRow][newCol].parentCol = col;
          tracePath(dest);
          return;
        }
        else if (closedList[newRow][newCol] == false)
        {
          gNew = cellDetails[row][col].g + 1.0;
          hNew = calculateHValue(newRow, newCol, dest);
          fNew = gNew + hNew;

          if (cellDetails[newRow][newCol].f == FLT_MAX || cellDetails[newRow][newCol].f > fNew)
          {
            openList.insert(make_pair(fNew, make_pair(newRow, newCol)));

            cellDetails[newRow][newCol].f = fNew;
            cellDetails[newRow][newCol].g = gNew;
            cellDetails[newRow][newCol].h = hNew;
            cellDetails[newRow][newCol].parentRow = row;
            cellDetails[newRow][newCol].parentCol = col;
          }
        }
      }
    }
  }

  return;
}

void AStar::initCellDetails()
{
  int row, col;

  cellDetails = new Cell *[maze->rows - 1];

  for (row = 0; row < maze->rows - 1; row++)
  {
    cellDetails[row] = new Cell[maze->columns - 1];
  }

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
