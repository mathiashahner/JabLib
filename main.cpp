#include <game.h>

int main(int argc, char *argv[])
{
  Uint32 frameStart;

  Game *game = new Game();
  game->init();

  while (game->running())
  {
    frameStart = SDL_GetTicks();

    game->handleEvents();
    game->update();
    game->render();
    game->delay(frameStart);
    // printf("FPS: %d\n", 1000 / (SDL_GetTicks() - frameStart));
  }

  game->clean();
  return 0;
}
