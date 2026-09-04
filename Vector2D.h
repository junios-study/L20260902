#pragma once
//struct // stack, 변수로만듬, 자주 자주 삭제
//class // heap, new, 오래 오래 삭제

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
