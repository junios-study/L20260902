#pragma once
#include "Actor.h"

// 옛날 스타일, 요새 스타일 
// 상속을 구현, 구성요소로 구현
//Component
//구성요소 -> 그 기능을 구성요소가 담당 하도록 한다.
//Actor 실질적으로 하는일은 자기의 의미가 있는일, Entity
//AActor -> 모든지 그린다.

//AActor -> ARenderActor  //무조건 정답이 아님.

#include <vector>

class APlayer : public AActor
{
public:
	APlayer();
	virtual ~APlayer();


	void IamPlayer() {}
};

