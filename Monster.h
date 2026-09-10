#pragma once
#include "Actor.h"
#include "SDL.h"

class AMonster : public AActor
{
public:
	AMonster();

	virtual ~AMonster();

	virtual void Tick(Uint64 DeltaSeconds) override;

	Uint64 ElapsedTime = 0; 
	Uint64 ExecuteTime = 250;
};

