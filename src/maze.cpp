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

  rects = new SDL_Rect *[rows];

  for (row = 0; row < rows; row++)
  {
    rects[row] = new SDL_Rect[columns];
  }

  for (row = 0; row < rows; row++)
  {
    for (column = 0; column < columns; column++)
    {
      rects[row][column] = {(column * 20) + 3, (row * 20) + 3, 3, 3};
    }
  }
}

void Maze::render()
{
  for (int row = 0; row < rows; row++)
  {
    for (int column = 0; column < columns; column++)
    {
      SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
      SDL_RenderFillRect(renderer, &rects[row][column]);
    }
  }
}
