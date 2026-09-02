#pragma once
#include "Actor.h"

class UWorld;

class APawn :  public AActor
{
public:
	APawn();
	virtual ~APawn();

	virtual UWorld* GetWorld() const override;
};

