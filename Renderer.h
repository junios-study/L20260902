#pragma once
#include <windows.h>

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
};

