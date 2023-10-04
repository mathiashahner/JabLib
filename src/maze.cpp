#include <maze.h>

Maze::Maze(SDL_Renderer *renderer, int rows, int columns)
{
  this->rows = rows;
  this->columns = columns;
  this->renderer = renderer;

  init();
}

Maze::~Maze()
{
  for (int row = 0; row < rows; row++)
  {
    delete[] rects[row];
  }

  delete[] rects;
}

void Maze::init()
{
  int row, column;

  rects = new Rect *[rows];

  for (row = 0; row < rows; row++)
  {
    rects[row] = new Rect[columns];
  }

  for (row = 0; row < rows; row++)
  {
    for (column = 0; column < columns; column++)
    {
      Rect *rect = new Rect(renderer, (column * rectDistance) + rectWidth, (row * rectDistance) + rectHeight,
                            rectWidth, rectHeight, rectColor);

      rects[row][column] = *rect;
    }
  }
}

void Maze::render()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      rects[row][column].render();
    }
  }
}
