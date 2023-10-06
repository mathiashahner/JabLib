#ifndef GAME_H
#define GAME_H

#include <maze.h>
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
  void delay(Uint32 frameStart);

  bool running();

private:
  const int fps = 60;
  const int frameDelay = 1000 / fps;

  Maze *maze;

  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
};

#endif