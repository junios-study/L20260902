#include "Vector2D.h"


int main()
{
	FVector2D T(1, 1);
	FVector2D T2 = T; //복사 생성자, 깊은 복사, 얕은 복사.

	//FVector2D T3 = T2.operator+(T);
	FVector2D T3 = T2 + T;



	T.SetX(1); //10만번 호출 매 프레임마다.
	//T.X = -1001; //complie

	return 0;
}