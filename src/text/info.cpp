#include <info.h>

Info::Info(SDL_Renderer *renderer, Maze *maze)
{
  this->maze = maze;
  this->renderer = renderer;

  font = FC_CreateFont();
  divisionLine = new Line(renderer, 210, 0, 210, 1080, 0x888888FF);

  FC_LoadFont(font, renderer, fontName, fontSize, fontColor, TTF_STYLE_NORMAL);
}

Info::~Info()
{
  FC_FreeFont(font);
}

void Info::render()
{
  FC_Draw(font, renderer, 10, 10, "Rows: %d", maze->rows - 1);
  FC_Draw(font, renderer, 10, 30, "Columns: %d", maze->columns - 1);

  FC_Draw(font, renderer, 10, 60, "Generation speed: %d", 100 - maze->delay);

  FC_Draw(font, renderer, 10, 90, "(S)tart");
  FC_Draw(font, renderer, 10, 110, "(R)eset");

  FC_Draw(font, renderer, 10, 140, "(D) Decrease speed");
  FC_Draw(font, renderer, 10, 160, "(F) Increase speed");

  FC_Draw(font, renderer, 10, 190, "(UP) Remove row");
  FC_Draw(font, renderer, 10, 210, "(DOWN) Add row");
  FC_Draw(font, renderer, 10, 230, "(LEFT) Remove column");
  FC_Draw(font, renderer, 10, 250, "(RIGHT) Add column");

  FC_Draw(font, renderer, 10, 280, "(E)xit");

  divisionLine->render(0, 0);
}
