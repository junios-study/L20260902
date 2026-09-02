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
	void SpawnActor();


	std::vector<AActor*>& GetActors()
	{
		return Actors;
	}

protected:
	std::vector<AActor*> Actors;
};

template<typename T>
inline void UWorld::SpawnActor()
{
	Actors.push_back(new T);
}
