#include "Vector2D.h"

//FVector2D::FVector2D()
//{
//	X = 0;
//	Y = 0;
//}

FVector2D::FVector2D(int InX, int InY) : X(InX), Y(InY)
{
	//X = InX;
	//Y = InY;
}

FVector2D::FVector2D(const FVector2D& RHS)
{
	X = RHS.X;
	Y = RHS.Y;
}

FVector2D::~FVector2D()
{
}


FVector2D FVector2D::operator+(const FVector2D& RHS) const
{
	return FVector2D(X + RHS.X, Y + RHS.Y);
}
