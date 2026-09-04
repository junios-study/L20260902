#include <algorithm>

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
		//system("cls");
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

			AActor* NewActor = World->SpawnActor<AFloor>();
			NewActor->Location = FVector2D(X, Y);
		}
	}

	//5, 3, 1, 2, 4
	//3, 5, 1, 2, 4
	//1, 5, 3, 2, 4
	//1, 3, 5, 2, 4
	//1, 2, 5, 3, 4
	// 
	//bubble sort, selection sort, quick sort, merge sort..
	//for (int i = 0; i < GetWorld()->GetActors().size(); ++i)
	//{
	//	for (int j = i + 1; j < GetWorld()->GetActors().size(); ++j)
	//	{
	//		if (GetWorld()->GetActors()[i]->Layer > GetWorld()->GetActors()[j]->Layer)
	//		{
	//			AActor* Temp = GetWorld()->GetActors()[i];
	//			GetWorld()->GetActors()[i] = GetWorld()->GetActors()[j];
	//			GetWorld()->GetActors()[j] = Temp;
	//		}
	//	}
	//}

	//무명 함수
	//람다 함수


	//std::sort(GetWorld()->GetActors().begin(), GetWorld()->GetActors().end(), UEngine::Compare);

	//AsyncLoadTexture([]() {};)

	std::sort(GetWorld()->GetActors().begin(), GetWorld()->GetActors().end(), 
		[&](AActor* A, AActor* B) {
			return (A->Layer < B->Layer);
		}
	);
}

bool UEngine::Compare(AActor* A, AActor* B)
{
	if (A->Layer > B->Layer)
	{
		return true;
	}
	else
	{
		return false;
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
