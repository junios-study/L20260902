#include "World.h"
#include "Actor.h"

UWorld::UWorld()
{
}

UWorld::~UWorld()
{
}

void UWorld::Tick(Uint64 DeltaSeconds)
{
	for (auto Actor : Actors)
	{
		Actor->Tick(DeltaSeconds);
	}

}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}

}
