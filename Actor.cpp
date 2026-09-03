#include "Actor.h"

AActor::AActor() : Location(0, 0), Shape(' ')
{
}

AActor::~AActor()
{
}

void AActor::Tick()
{
}


void AActor::Render()
{
}

UWorld* AActor::GetWorld() const
{
	return World;
}
