#include "Monster.h"
#include "World.h"
#include "SystemLibrary.h"
#include "Engine.h"
#include "InputDevice.h"
#include <vector>

AMonster::AMonster()
{
	Shape = 'M';
	Layer = 120;
	bIsCollisionEnable = false;
	R = 255;
	G = 0;
	B = 0;
	A = 0;
}

AMonster::~AMonster()
{
}

void AMonster::Tick(Uint64 DeltaSeconds)
{
	ElapsedTime += DeltaSeconds;
	if (ElapsedTime < ExecuteTime)
	{
		return;
	}

	ElapsedTime = 0;

	char VirtualKeyCode[4] = { 'w','s','a','d' };
	std::vector<AActor*> CollideActors;
	int KeyCode = VirtualKeyCode[rand() % 4];
	if (KeyCode == 'w')
	{
		//Predict
		Location.Y--;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y++;
		}

	}
	if (KeyCode == 's')
	{
		Location.Y++;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.Y--;
		}
	}
	if (KeyCode == 'a')
	{
		Location.X--;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X++;
		}
	}
	if (KeyCode == 'd')
	{
		Location.X++;
		if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
		{
			Location.X--;
		}
	}
}
