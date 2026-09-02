#pragma once

struct FVector2D
{
//public:
	//FVector2D();

	//생성자 오버로딩
	FVector2D(int InX = 0, int InY = 0);
	FVector2D(const FVector2D& RHS);

	virtual ~FVector2D();
	//연산자 오버로딩
	FVector2D operator+(const FVector2D& RHS) const;

	int X;
	int Y;
};
