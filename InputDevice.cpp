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
	KeyCode = _getch();

	return KeyCode;
}
