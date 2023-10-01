#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    fprintf(stderr, "Erro ao inicializar a SDL: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Window *janela = SDL_CreateWindow("Minha Janela SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
  if (janela == NULL)
  {
    fprintf(stderr, "Erro ao criar a janela: %s\n", SDL_GetError());
    return 1;
  }

  SDL_Renderer *renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
  if (renderizador == NULL)
  {
    fprintf(stderr, "Erro ao criar o renderizador: %s\n", SDL_GetError());
    return 1;
  }

  SDL_SetRenderDrawColor(renderizador, 0, 0, 0, 255);

  int rodando = 1;
  while (rodando)
  {
    SDL_Event evento;
    while (SDL_PollEvent(&evento))
    {
      if (evento.type == SDL_QUIT)
      {
        rodando = 0;
      }
    }

    SDL_RenderClear(renderizador);

    // Desenhe algo aqui

    SDL_RenderPresent(renderizador);

    SDL_Delay(16);
  }

  SDL_DestroyRenderer(renderizador);
  SDL_DestroyWindow(janela);
  SDL_Quit();

  return 0;
}