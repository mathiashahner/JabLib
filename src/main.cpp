#include <game.h>

int main(int argc, char *argv[])
{
  Game *game = new Game();
  game->init();

  while (game->running())
  {
    game->frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();
    game->delay();
  }

  game->clean();
  return 0;
}
