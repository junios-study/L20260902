#include "Engine.h"
#include "World.h"
#include <vector>
#include "Actor.h"
#include "Pawn.h"

UEngine::UEngine()
{
}

UEngine::~UEngine()
{
	if (World)
	{
		delete World;
		World = nullptr;
	}
}

void UEngine::Init()
{
	//map loading
	World = new UWorld();


	char Map[10][10] =
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 3, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 4, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};

	//openLevel
	World->SpawnActor<AActor>();
	World->SpawnActor<APawn>();
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		//Input();
		World->Tick();
		World->Render();
	}
}

void UEngine::Exit()
{

}

UWorld* UEngine::GetWorld() const
{
	return World;
}

const FRenderer* UEngine::GetRenderer()
{
	return Renderer;
}
