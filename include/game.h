#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

class Game
{
public:
  Game();

  void init();
  void render();
  void update();
  void clean();
  void handleEvents();

  bool running();

private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif
