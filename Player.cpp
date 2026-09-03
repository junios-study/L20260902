#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"

APlayer::APlayer()
{
	Shape = 'P';
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	int KeyCode = GEngine->GetInputDevice()->GetKeyCode();
	if (KeyCode == 'w')
	{
		Location.Y--;
	}
	if (KeyCode == 's')
	{
		Location.Y++;
	}
	if (KeyCode == 'a')
	{
		Location.X--;
	}
	if (KeyCode == 'd')
	{
		Location.X++;
	}
}
