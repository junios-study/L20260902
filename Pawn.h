#pragma once
#include "Actor.h"

class UWorld;

class APawn :  public AActor
{
public:
	APawn();
	virtual ~APawn();

	virtual void Tick() override;

	virtual void Render() override;

	//virtual UWorld* GetWorld() const override;
};

