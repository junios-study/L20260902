#pragma once
#include "Object.h"
#include <string>
#include <SDL.h>

#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

class UWorld;
class FInputDevice;
class FRenderer;
class AActor;

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

	static bool Compare(AActor* A, AActor* B);

	virtual UWorld* GetWorld() const override;
	const FRenderer* GetRenderer();

	FInputDevice* GetInputDevice()
	{
		return InputDevice;
	}

	SDL_Window* MyWindow = nullptr;
	SDL_Event MyEvent;

protected:
	void Input();
	bool bIsRunning = true;
	FInputDevice* InputDevice = nullptr;
	FRenderer* Renderer = nullptr;

	Uint64 DeltaSeconds;
	Uint64 LastTick;

	Uint64 ElapsedTime = 0;
	Uint64 FrameTime = 166; //(1.0/60) 모니터가 60hz
};


#define GEngine		UEngine::GetInstance()

//extern UEngine* GEngine;

