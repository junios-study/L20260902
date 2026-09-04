#include "Renderer.h"
#include "Actor.h"
#include <windows.h> 
#include <iostream>

FRenderer::FRenderer()
{
	BufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);
	BufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, nullptr, CONSOLE_TEXTMODE_BUFFER, nullptr);

	CONSOLE_CURSOR_INFO CursorInfo;
	CursorInfo.bVisible = false;
	CursorInfo.dwSize = 1;
	SetConsoleCursorInfo(BufferHandle[0], &CursorInfo);
	SetConsoleCursorInfo(BufferHandle[1], &CursorInfo);
}

FRenderer::~FRenderer()
{
	CloseHandle(BufferHandle[0]);
	CloseHandle(BufferHandle[1]);
}

void FRenderer::Render(AActor* DrawActor) const
{
	COORD Position = { (SHORT)DrawActor->Location.X, (SHORT)DrawActor->Location.Y };
	SetConsoleCursorPosition(BufferHandle[CurrentBufferIndex], Position);
	char Buffer[2] = { 0, }; //[P] [0]
	Buffer[0] = DrawActor->Shape;
	WriteConsole(BufferHandle[CurrentBufferIndex], Buffer, 1, nullptr, nullptr);

	//std::cout << DrawActor->Shape;
}

void FRenderer::Clear()
{
	COORD Coord{ 0, 0 };
	DWORD DW;
	FillConsoleOutputCharacter(BufferHandle[CurrentBufferIndex],
		' ', 80 * 25, Coord, &DW);
}

void FRenderer::Present()
{
	SetConsoleActiveScreenBuffer(BufferHandle[CurrentBufferIndex]);
	CurrentBufferIndex++;
	CurrentBufferIndex = CurrentBufferIndex % 2;
}
