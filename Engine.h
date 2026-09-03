#pragma once
#include "Object.h"
#include <string>

class UWorld;
class FInputDevice;
class FRenderer;

class UEngine : public UObject
{
protected:
	UEngine();

	static UEngine* Instance;
public:
	virtual ~UEngine();

	static UEngine* GetInstance();

	void Init();
	void Run();
	void Exit();

	void OpenLevel(std::string MapName);

	virtual UWorld* GetWorld() const override;
	const FRenderer* GetRenderer();

protected:
	bool bIsRunning = true;
	FInputDevice* InputDevice = nullptr;
	FRenderer* Renderer = nullptr;
};


#define GEngine		UEngine::GetInstance()

//extern UEngine* GEngine;

