#include "Engine.h"
#include "SDL.h"

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

//int main()
//{
//	GEngine->Init();
//
//	GEngine->Run();
//
//	GEngine->Exit();
//
//	return 0;
//}

int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	SDL_Renderer* MyRenderer =  SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED);

	SDL_Event MyEvent;

	while (true)
	{
		SDL_PollEvent(&MyEvent);
	}

	SDL_Quit();

	return 0;
}