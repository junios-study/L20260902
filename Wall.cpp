#include "Wall.h"

AWall::AWall()
{
	Shape = '*';
	Layer = 1;
	bIsCollisionEnable = true;
	R = 255;
	G = 255;
	B = 255;
	A = 0;
}

AWall::~AWall()
{
}
