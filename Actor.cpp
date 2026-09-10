#include "Actor.h"
#include "Engine.h"
#include "Renderer.h"

AActor::AActor() : Location(0, 0), Shape(' ')
{
}

AActor::~AActor()
{
}

void AActor::Tick(Uint64 DeltaSeconds)
{
}

void AActor::Render()
{
	GEngine->GetRenderer()->Render(this);
}

UWorld* AActor::GetWorld() const
{
	return World;
}
