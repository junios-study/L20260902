#include "Renderer.h"
#include "Actor.h"
#include <windows.h> 
#include <iostream>
#include "Engine.h"
#include "Player.h"


FRenderer::FRenderer()
{
	//BufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	//BufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	//CONSOLE_CURSOR_INFO CursorInfo;
	//CursorInfo.bVisible = false;
	//CursorInfo.dwSize = 1;
	//SetConsoleCursorInfo(BufferHandle[0], &CursorInfo);
	//SetConsoleCursorInfo(BufferHandle[1], &CursorInfo);


	MyRenderer = SDL_CreateRenderer(GEngine->MyWindow, -1, SDL_RENDERER_ACCELERATED);

}

FRenderer::~FRenderer()
{
	CloseHandle(BufferHandle[0]);
	CloseHandle(BufferHandle[1]);

	SDL_DestroyRenderer(MyRenderer);
}

void FRenderer::Render(AActor* DrawActor) const
{
	//COORD Position = { (SHORT)DrawActor->Location.X, (SHORT)DrawActor->Location.Y };
	//SetConsoleCursorPosition(BufferHandle[CurrentBufferIndex], Position);
	//char Buffer[2] = { 0, }; //[P] [0]
	//Buffer[0] = DrawActor->Shape;
	//WriteConsole(BufferHandle[CurrentBufferIndex], Buffer, 1, nullptr, nullptr);


	int SizeX = 60;
	int SizeY = 60;
	//SDL_SetRenderDrawColor(MyRenderer, DrawActor->R, DrawActor->G, DrawActor->B, DrawActor->A);
	//SDL_Rect MyRect{ DrawActor->Location.X * SizeX , DrawActor->Location.Y * SizeY, SizeX, SizeY };
	//SDL_RenderFillRect(MyRenderer, &MyRect);

	APlayer* MyPlayer = dynamic_cast<APlayer*>(DrawActor);

	if (MyPlayer)
	{
		int SpriteSizeX = MyPlayer->BMPSurface->w / 5;
		int SpriteSizeY = MyPlayer->BMPSurface->h / 5;
		SDL_Rect DestRect{ MyPlayer->Location.X * SizeX , MyPlayer->Location.Y * SizeY, SizeX, SizeY };
		SDL_Rect SrcRect{ SpriteSizeX * MyPlayer->Index, SpriteSizeY * MyPlayer->Direction,  SpriteSizeX , SpriteSizeY };

		SDL_RenderCopy(MyRenderer, MyPlayer->BMPTexture, &SrcRect, &DestRect);
		MyPlayer->NextFrame();
	}
	else
	{
		SDL_Rect DestRect{ DrawActor->Location.X * SizeX , DrawActor->Location.Y * SizeY, SizeX, SizeY };
		SDL_RenderCopy(MyRenderer, DrawActor->BMPTexture, nullptr, &DestRect);
	}
}

void FRenderer::Clear()
{
	//COORD Coord{ 0, 0 };
	//DWORD DW;
	//FillConsoleOutputCharacter(BufferHandle[CurrentBufferIndex],
	//	' ', 80 * 25, Coord, &DW);

	SDL_SetRenderDrawColor(MyRenderer, 0, 0, 0, 0);
	SDL_RenderClear(MyRenderer);
}

void FRenderer::Present()
{
	//SetConsoleActiveScreenBuffer(BufferHandle[CurrentBufferIndex]);
	//CurrentBufferIndex++;
	//CurrentBufferIndex = CurrentBufferIndex % 2;

	SDL_RenderPresent(MyRenderer);
}
