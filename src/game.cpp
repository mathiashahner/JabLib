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

  TTF_Init();

  TTF_Font *font = TTF_OpenFont("/home/mathiashahner/dev/maze-builder/assets/arial.ttf", 24);
  SDL_Color color = {255, 255, 255, 255};
  SDL_Surface *surface = TTF_RenderText_Solid(font, "text test", color);
  texture = SDL_CreateTextureFromSurface(renderer, surface);
  fontRect = {200, 200, 100, 24};
  SDL_FreeSurface(surface);

  isRunning = true;
}

void Game::render()
{
  SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
  SDL_RenderClear(renderer);

  maze->render();
  SDL_RenderCopy(renderer, texture, NULL, &fontRect);

  SDL_RenderPresent(renderer);
}

void Game::update()
{
}

void Game::clean()
{
  SDL_DestroyTexture(texture);

  SDL_WaitThread(thread, NULL);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int mazeUpdateWrapper(void *param)
{
  Maze *maze = (Maze *)param;
  maze->update();
  return 0;
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
    switch (event.key.keysym.sym)
    {
    case SDLK_s:
      thread = SDL_CreateThread(mazeUpdateWrapper, "MazeThread", (void *)maze);
      break;
    case SDLK_r:
      maze->reset();
      break;
    case SDLK_DOWN:
      maze->increaseDelay();
      break;
    case SDLK_UP:
      maze->decreaseDelay();
      break;
    }
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
