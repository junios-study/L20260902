#include "Object.h"
#include "World.h"

UObject::UObject() : World(nullptr)
{
}

UObject::~UObject()
{
}

UWorld* UObject::GetWorld() const
{
	return World;
}

void UObject::SetWorld(UWorld* NewWorld)
{
	World = NewWorld;
}
