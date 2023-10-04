#include <game.h>

Game::Game()
{
  isRunning = false;
}

void Game::init()
{
  if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
  {
    fprintf(stderr, "Error on init SDL: %s\n", SDL_GetError());
  }
  else
  {
    window = SDL_CreateWindow("Maze Builder", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    if (window == NULL)
    {
      fprintf(stderr, "Error on create window: %s\n", SDL_GetError());
    }
    else
    {
      renderer = SDL_CreateRenderer(window, -1, 0);
      if (renderer == NULL)
      {
        fprintf(stderr, "Error on create renderer: %s\n", SDL_GetError());
      }
      else
      {
        maze = new Maze(renderer, 20, 30);
        isRunning = true;
      }
    }
  }
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  maze->render();

  SDL_RenderPresent(renderer);
}

void Game::update()
{
}

void Game::clean()
{
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::handleEvents()
{
  SDL_Event event;
  SDL_PollEvent(&event);

  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  default:
    break;
  }
}

bool Game::running()
{
  return isRunning;
}

void Game::delay(Uint32 frameStart)
{
  int frameTime = SDL_GetTicks() - frameStart;

  if (frameDelay > frameTime)
  {
    SDL_Delay(frameDelay - frameTime);
  }
}
