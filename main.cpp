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

SDL_Window* MyWindow = nullptr;

SDL_Renderer* MyRenderer = nullptr;

SDL_Event MyEvent;

bool bIsRunning = true;

void Input();

void Tick();

void Render();


int SDL_main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);

	MyWindow = SDL_CreateWindow("Game", 100, 100, 800, 600, SDL_WINDOW_SHOWN);

	MyRenderer =  SDL_CreateRenderer(MyWindow, -1, SDL_RENDERER_ACCELERATED);

	MyEvent;

	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}

	SDL_Quit();

	return 0;
}

void Input()
{
	SDL_PollEvent(&MyEvent);


}

void Tick()
{
	if (MyEvent.type == SDL_QUIT)
	{
		bIsRunning = false;
		return;
	}
	else if (MyEvent.type == SDL_KEYDOWN)
	{
		if (MyEvent.key.keysym.sym == SDLK_ESCAPE)
		{
			bIsRunning = false;
			return;
		}
	}
}

void Render()
{
	//back buffer
	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);

	for (int i = 0; i < 60000; ++i)
	{
		SDL_Rect MyRect{ rand() % 800, rand() % 600, rand() % 400, rand() % 400 };
		SDL_SetRenderDrawColor(MyRenderer, rand() % 256, rand() % 256, rand() % 256, 0);

		if (rand() % 2 == 0)
		{
			SDL_RenderDrawRect(MyRenderer, &MyRect);
		}
		else
		{
			SDL_RenderFillRect(MyRenderer, &MyRect);
		}
	}

	SDL_RenderPresent(MyRenderer);
}
