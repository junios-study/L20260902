#pragma once
#include "Object.h"

class UWorld;
class FInputDevice;
class FRenderer;

class UEngine : public UObject
{
public:
	UEngine();

	virtual ~UEngine();

	void Init();
	void Run();
	void Exit();

	virtual UWorld* GetWorld() const override;
	const FRenderer* GetRenderer();

protected:
	bool bIsRunning = true;
	FInputDevice* InputDevice = nullptr;
	FRenderer* Renderer = nullptr;
};

