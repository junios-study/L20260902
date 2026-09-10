#include "Goal.h"

AGoal::AGoal()
{
	Shape = 'G';
	Layer = 20;
	bIsCollisionEnable = false;
	R = 255;
	G = 255;
	B = 0;
	A = 0;

	Load(".\\data\\goal.bmp");

}

AGoal::~AGoal()
{
}
