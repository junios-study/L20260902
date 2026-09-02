#include "Engine.h"
#include "World.h"

UEngine::UEngine() : World(nullptr)
{
}

UEngine::~UEngine()
{
}

void UEngine::Init()
{
}

void UEngine::Run()
{
}

void UEngine::Exit()
{
}

UWorld* UEngine::GetWorld() const
{
	return World;
}
