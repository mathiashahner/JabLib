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

void Info::render()
{
  FC_Draw(font, renderer, 510, 5, "Rows: %d", maze->rows - 1);
  FC_Draw(font, renderer, 510, 25, "Columns: %d", maze->columns - 1);

  FC_Draw(font, renderer, 510, 55, "Generation speed: %d", 100 - maze->delay);
}
