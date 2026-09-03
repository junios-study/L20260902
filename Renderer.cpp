#include "Renderer.h"
#include "Actor.h"
#include <windows.h> 
#include <iostream>

FRenderer::FRenderer()
{
}

FRenderer::~FRenderer()
{
}

void FRenderer::Render(AActor* DrawActor) const
{
	COORD Position = { (SHORT)DrawActor->Location.X, (SHORT)DrawActor->Location.Y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Position);

	std::cout << DrawActor->Shape;
}
