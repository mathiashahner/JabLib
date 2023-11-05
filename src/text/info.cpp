#include <info.h>

Info::Info(SDL_Renderer *renderer, Maze *maze)
{
  this->maze = maze;
  this->renderer = renderer;

  font = FC_CreateFont();

  FC_LoadFont(font, renderer, fontName, fontSize, fontColor, TTF_STYLE_NORMAL);
}

Info::~Info()
{
  FC_FreeFont(font);
}

int addLine(int *y, int lineHeight)
{
  *y += lineHeight;
  return *y;
}

void Info::render()
{
  int x = 10;
  int y = 10;

  SDL_Rect rect = {0, 0, 240, 1080};
  SDL_SetRenderDrawColor(renderer, 40, 40, 40, 255);
  SDL_RenderFillRect(renderer, &rect);

  FC_Draw(font, renderer, x, addLine(&y, 0), "Distance: %d", maze->pointDistance);
  FC_Draw(font, renderer, x, addLine(&y, 20), "Speed: %d", 100 - maze->delay);
  FC_Draw(font, renderer, x, addLine(&y, 20), "Rows: %d", maze->rows - 1);
  FC_Draw(font, renderer, x, addLine(&y, 20), "Columns: %d", maze->columns - 1);

  FC_Draw(font, renderer, x, addLine(&y, 40), "(1) - Distance");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(2) + Distance");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(3) - Speed");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(4) + Speed");

  FC_Draw(font, renderer, x, addLine(&y, 40), "(W) Add row");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(A) Remove row");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(S) Remove column");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(D) Add column");

  FC_Draw(font, renderer, x, addLine(&y, 40), "(G) Generate");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(F) Solve");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(H) Hide explored");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(R) Reset");
  FC_Draw(font, renderer, x, addLine(&y, 20), "(E) Exit");
}
