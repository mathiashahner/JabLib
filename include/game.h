#ifndef GAME_H
#define GAME_H

#include <maze.h>
#include <info.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Game
{
public:
  Game();

  Uint32 frameStart;

  void init();
  void render();
  void update();
  void clean();
  void handleEvents();
  void delay();

  bool running();

private:
  const int fps = 30;
  const int frameDelay = 1000 / fps;

  Maze *maze;
  Info *info;

  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Thread *thread;
};

#endif
