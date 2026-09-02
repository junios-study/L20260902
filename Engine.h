#pragma once
#include "Object.h"

class UWorld;

class UEngine : public UObject
{
public:
	UEngine();

	virtual ~UEngine();

	void Init();
	void Run();
	void Exit();

	virtual UWorld* GetWorld() const override;


protected:
	//class UWorld* World;
	UWorld* World;
};

