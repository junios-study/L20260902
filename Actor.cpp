#include "Actor.h"

AActor::AActor() : Location(0, 0)
{
}

AActor::~AActor()
{
}

UWorld* AActor::GetWorld() const
{
	return World;
}
