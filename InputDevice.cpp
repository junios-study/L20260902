#include "InputDevice.h"
#include <conio.h>
#include "SDL.h"
#include "Engine.h"

FInputDevice::FInputDevice()
{
}

FInputDevice::~FInputDevice()
{
}

int FInputDevice::Input()
{
	SDL_PollEvent(&GEngine->MyEvent);

	//if (_kbhit())
	//{
	//	KeyCode = _getch();
	//}
	//else
	//{
	//	KeyCode = 0;
	//}

	return 0;
}
