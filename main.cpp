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


	for (int i = 0; i < 5000; ++i)
	{
		SDL_SetRenderDrawColor(MyRenderer, rand() % 255, rand() % 255, rand() % 255, 0);

		int Polygon = 20;
		int Radius = rand() % 290 + 10;
		int CenterX = rand() % 600;
		int CenterY = rand() % 400;

		for (float Theta = 0; Theta < 360; Theta += Polygon)
		{
			double StartRadian = Theta * ((3.14) / 180);
			double EndRadian = (Theta + Polygon) * ((3.14) / 180);
			int StartX = Radius * cos(StartRadian) + CenterX;
			int StartY = Radius * sin(StartRadian) + CenterY;
			int EndX = Radius * cos(EndRadian) + CenterX;
			int EndY = Radius * sin(EndRadian) + CenterY;

			SDL_RenderDrawLine(MyRenderer, StartX, StartY, EndX, EndY);
		}
	}


	SDL_RenderPresent(MyRenderer);
}
