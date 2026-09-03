#include "InputDevice.h"
#include <conio.h>

FInputDevice::FInputDevice()
{
}

FInputDevice::~FInputDevice()
{
}

int FInputDevice::Input()
{
	if (_kbhit())
	{
		KeyCode = _getch();
	}
	else
	{
		KeyCode = 0;
	}

	return KeyCode;
}
