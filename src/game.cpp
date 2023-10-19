#include <game.h>

Game::Game()
{
  isRunning = false;
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Maze Builder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  maze = new Maze(renderer, 70, 105);
  isRunning = true;
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
  case SDL_KEYDOWN:
    if (event.key.keysym.sym == SDLK_s)
      maze->update();
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
