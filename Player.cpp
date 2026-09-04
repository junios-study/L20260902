#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"
#include "World.h"
#include "SystemLibrary.h"
#include <vector>

APlayer::APlayer()
{
	Shape = 'P';
	Layer = 100;
	bIsCollisionEnable = true;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	std::vector<AActor*> CollideActors;
	int KeyCode = GEngine->GetInputDevice()->GetKeyCode();
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
