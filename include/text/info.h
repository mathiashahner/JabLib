#ifndef INFO_H
#define INFO_H

#include <maze.h>
#include <SDL_FontCache.h>

class Info
{
public:
  Info(SDL_Renderer *renderer, Maze *maze);
  ~Info();

  void render();

private:
  const int fontSize = 16;
  const char *fontName = "../assets/montserrat.ttf";
  const SDL_Color fontColor = FC_MakeColor(255, 255, 255, 255);

  Maze *maze;
  FC_Font *font;
  Line *divisionLine;
  SDL_Renderer *renderer;
};

#endif
