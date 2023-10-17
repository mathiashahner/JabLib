#include <maze.h>

Maze::Maze(SDL_Renderer *renderer, int rows, int columns)
{
  this->rows = rows;
  this->columns = columns;
  this->renderer = renderer;

  srand(time(NULL));

  initPoints();
  initLines();
}

Maze::~Maze()
{
  for (int row = 0; row < rows; row++)
  {
    delete[] mazePoints[row];
  }

  delete[] mazePoints;
}

void Maze::initPoints()
{
  mazePoints = new MazePoint *[rows];

  for (int row = 0; row < rows; row++)
  {
    mazePoints[row] = new MazePoint[columns];
  }

  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      mazePoints[row][column].point = new Point(renderer, (column * pointDistance),
                                                (row * pointDistance), pointColor);
    }
  }
}

void Maze::initLines()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      Point *origin = mazePoints[row][column].point;

      if (column < columns - 1)
      {
        Point *xDestiny = mazePoints[row][column + 1].point;

        mazePoints[row][column].xLine = new Line(renderer, origin->x, origin->y,
                                                 xDestiny->x, xDestiny->y, lineColor);
      }
      else
      {
        mazePoints[row][column].xLine = NULL;
      }

      if (row < rows - 1)
      {
        Point *yDestiny = mazePoints[row + 1][column].point;

        mazePoints[row][column].yLine = new Line(renderer, origin->x, origin->y,
                                                 yDestiny->x, yDestiny->y, lineColor);
      }
      else
      {
        mazePoints[row][column].yLine = NULL;
      }
    }
  }
}

void Maze::update()
{
  // for (int row = 0; row < rows; row++)
  // {
  //   for (int column = 0; column < columns; column++)
  //   {
  //     MazePoint origin = mazePoints[row][column];

  //     int newRow = row;
  //     int newColumn = column;

  //     int random = getRandomNumber(8);

  //     switch (random)
  //     {
  //     case 0:
  //       newRow = row + 1;
  //       break;
  //     case 1:
  //       newRow = row - 1;
  //       break;
  //     case 2:
  //       newColumn = column + 1;
  //       break;
  //     case 3:
  //       newColumn = column - 1;
  //       break;
  //     case 4:
  //       newRow = row + 1;
  //       newColumn = column - 1;
  //       break;
  //     case 5:
  //       newRow = row + 1;
  //       newColumn = column + 1;
  //       break;
  //     case 6:
  //       newRow = row - 1;
  //       newColumn = column - 1;
  //       break;
  //     case 7:
  //       newRow = row - 1;
  //       newColumn = column + 1;
  //       break;
  //     }

  //     if (row == 0)
  //       newRow = row + 1;
  //     else if (row == rows - 1)
  //       newRow = row - 1;
  //     else if (column == 0)
  //       newColumn = column + 1;
  //     else if (column == columns - 1)
  //       newColumn = column - 1;

  //     MazePoint destiny = mazePoints[newRow][newColumn];
  //   }
  // }
}

void Maze::render()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      MazePoint point = mazePoints[row][column];

      point.point->render();

      if (point.xLine != NULL)
        point.xLine->render();

      if (point.yLine != NULL)
        point.yLine->render();
    }
  }
}

int Maze::getRandomNumber(int max)
{
  return rand() % max;
}
