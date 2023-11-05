#include <game.h>

Game::Game()
{
  isRunning = false;
}

void Game::init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  window = SDL_CreateWindow("Maze Builder", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1080, 720, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  maze = new Maze(renderer, 20, 30);
  info = new Info(renderer, maze);

  isRunning = true;
}

void Game::render()
{
  int w, h;
  SDL_GetWindowSize(window, &w, &h);

  SDL_SetRenderDrawColor(renderer, 30, 30, 30, 255);
  SDL_RenderClear(renderer);

  maze->render(w, h);
  info->render();

  SDL_RenderPresent(renderer);
}

void Game::update()
{
}

void Game::clean()
{
  SDL_WaitThread(thread, NULL);
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

int mazeSolveWrapper(void *param)
{
  Maze *maze = (Maze *)param;
  maze->solve();
  return 0;
}

int mazeGenerateWrapper(void *param)
{
  Maze *maze = (Maze *)param;
  maze->generate();
  return 0;
}

void Game::handleEvents()
{
  SDL_Event event;

  if (maze->isGenerating)
    SDL_PollEvent(&event);
  else
    SDL_WaitEvent(&event);

  switch (event.type)
  {
  case SDL_QUIT:
    isRunning = false;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case SDLK_f:
      thread = SDL_CreateThread(mazeSolveWrapper, "MazeThread", (void *)maze);
      break;
    case SDLK_g:
      thread = SDL_CreateThread(mazeGenerateWrapper, "MazeThread", (void *)maze);
      break;
    case SDLK_r:
      maze->reset();
      break;
    case SDLK_e:
      isRunning = false;
      break;
    case SDLK_h:
      maze->toggleHideExplored();
      break;
    case SDLK_1:
      maze->decreasePointDistance();
      break;
    case SDLK_2:
      maze->increasePointDistance();
      break;
    case SDLK_3:
      maze->increaseDelay();
      break;
    case SDLK_4:
      maze->decreaseDelay();
      break;
    case SDLK_w:
    case SDLK_UP:
      maze->resizeMaze(ADD_ROW);
      break;
    case SDLK_s:
    case SDLK_DOWN:
      maze->resizeMaze(REMOVE_ROW);
      break;
    case SDLK_a:
    case SDLK_LEFT:
      maze->resizeMaze(REMOVE_COLUMN);
      break;
    case SDLK_d:
    case SDLK_RIGHT:
      maze->resizeMaze(ADD_COLUMN);
      break;
    }
    break;
  }
}

bool Game::running()
{
  return isRunning;
}

void Game::setFrameStart()
{
  frameStart = SDL_GetTicks();
}

void Game::delay()
{
  int frameTime = SDL_GetTicks() - frameStart;

  if (frameDelay > frameTime)
  {
    SDL_Delay(frameDelay - frameTime);
  }
}
