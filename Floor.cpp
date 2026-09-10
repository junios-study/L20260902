#include "Floor.h"

AFloor::AFloor()
{
	Shape = ' ';
	Layer = 0;
	bIsCollisionEnable = false;
	R = 0;
	G = 0;
	B = 0;
	A = 0;

	Load(".\\data\\floor.bmp");
}

AFloor::~AFloor()
{
}
