#include "Engine.h"
#include "World.h"
#include "Floor.h"
#include "Monster.h"
#include "Goal.h"
#include "Wall.h"
#include "Player.h"
#include "Actor.h"
#include "InputDevice.h"

UEngine* UEngine::Instance = nullptr;
//UEngine* GEngine = nullptr;

UEngine::UEngine()
{
}

UEngine* UEngine::GetInstance()
{
	if (!Instance)
	{
		Instance = new UEngine();
		//GEngine = Instance;
	}

	return Instance;
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
	InputDevice = new FInputDevice();

	//map loading
	World = new UWorld();

	OpenLevel("1.umap");

}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		World->Tick();
		system("cls");
		World->Render();
	}
}

void UEngine::Exit()
{

}

void UEngine::OpenLevel(std::string MapName)
{
	//OpenLevel
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

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (Map[Y][X] == 1)
			{
				AActor* NewActor = World->SpawnActor<AWall>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 0)
			{
				AActor* NewActor = World->SpawnActor<AFloor>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 2)
			{
				AActor* NewActor = World->SpawnActor<APlayer>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 3)
			{
				AActor* NewActor = World->SpawnActor<AMonster>();
				NewActor->Location = FVector2D(X, Y);
			}
			else if (Map[Y][X] == 4)
			{
				AActor* NewActor = World->SpawnActor<AGoal>();
				NewActor->Location = FVector2D(X, Y);
			}
		}
	}
}

UWorld* UEngine::GetWorld() const
{
	return World;
}

const FRenderer* UEngine::GetRenderer()
{
	return Renderer;
}

void UEngine::Input()
{
	InputDevice->Input();
}
