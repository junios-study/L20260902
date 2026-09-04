#pragma once
#include "Object.h"
#include <vector>

class AActor;

class UWorld : public UObject
{
public:
	UWorld();

	virtual ~UWorld();

	void Tick();
	void Render();

	template<typename T>
	AActor* SpawnActor();


	std::vector<AActor*>& GetActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;
};

template<typename T>
inline AActor* UWorld::SpawnActor()
{
	AActor* NewActor = new T;
	Actors.push_back(NewActor);
	NewActor->SetWorld(this);

	return NewActor;
}
