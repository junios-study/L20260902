#pragma once

class AActor;

class FRenderer
{
public:
	FRenderer();
	virtual ~FRenderer();

	void Render(AActor* DrawActor);
};

