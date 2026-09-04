#pragma once

#include <vector>

class UWorld;
class AActor;

class USystemLibrary
{
public:
	static bool CheckCollide(UWorld* InWorld, AActor* CollisionActor, std::vector<AActor*>& OutCollidedActor);
};

