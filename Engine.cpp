#include "Engine.h"
#include "World.h"
#include <vector>
#include "Actor.h"
#include "Pawn.h"

UEngine::UEngine() : World(nullptr)
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
