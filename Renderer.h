#pragma once
#include <windows.h>
#include <SDL.h>

class AActor;

class FRenderer
{
public:
	FRenderer();
	virtual ~FRenderer();

	void Render(AActor* DrawActor) const;
	void Clear();
	void Present();

	HANDLE BufferHandle[2];

	int CurrentBufferIndex = 0;

	SDL_Renderer* MyRenderer = nullptr;
};

