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
      mazePoints[row][column].rect = new Rect(renderer, (column * rectDistance) + rectWidth,
                                              (row * rectDistance) + rectHeight,
                                              rectWidth, rectHeight, rectColor);
    }
  }
}

void Maze::initLines()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      int randomRow = getRandomNumber(rows - 1);
      int randomColumn = getRandomNumber(columns - 1);

      mazePoints[row][column].line = new Line(renderer,
                                              mazePoints[row][column].rect->x,
                                              mazePoints[row][column].rect->y,
                                              mazePoints[randomRow][randomColumn].rect->x,
                                              mazePoints[randomRow][randomColumn].rect->y,
                                              lineColor);
    }
  }
}

void Maze::render()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      mazePoints[row][column].rect->render();
      mazePoints[row][column].line->render();
    }
  }
}

int Maze::getRandomNumber(int max)
{
  return rand() % max;
}