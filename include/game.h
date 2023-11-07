#ifndef GAME_H
#define GAME_H

#include <maze.h>
#include <info.h>
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
  const int fps = 60;
  const int frameDelay = 1000 / fps;

  Maze *maze;
  Info *info;

  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Thread *thread;
};

#endif
