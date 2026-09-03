#pragma once
#include "Object.h"

class UWorld;
class FInputDevice;

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
	bool bIsRunning = true;
	FInputDevice* InputDevice = nullptr;
};

