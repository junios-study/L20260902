#pragma once

struct FVector2D
{
	//public:
		//FVector2D();

	//생성자 오버로딩
	FVector2D(int InX = 0, int InY = 0);
	FVector2D(const FVector2D& RHS);

	//A(Left Hand Side) = B (Right Hand Side)

	virtual ~FVector2D();

	//encapsulation
	inline void SetX(int NewValue)
	{
		if (NewValue > 0)
		{
			return;
		}

		X = NewValue;
	}
	inline int GetX() const
	{
		return X;
	}

	inline void SetY(int NewValue)
	{
		Y = NewValue;
	}
	inline int GetY() const
	{
		return Y;
	}

	//__forceinline void SetVector2D(int NewValueX, int NewValueY)
	//{
	//	X = NewValueX;
	//	Y = NewValueY;
	//}
	//inline FVector2D GetVector2D() const
	//{
	//	//FVector2D Value;
	//	//Value.SetVector2D(this->X, this->Y);

	//	return *this;
	//}

	//연산자 오버로딩
	FVector2D operator+(const FVector2D& RHS) const;

protected:
	int X;
	int Y;
};
