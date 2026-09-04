#include "SystemLibrary.h"
#include "World.h"
#include "Actor.h"


bool USystemLibrary::CheckCollide(UWorld* InWorld, AActor* CollisionActor, std::vector<AActor*>& OutCollidedActor)
{
    if (!InWorld)
    {
        return false;
    }

    bool Result = false;
    for (auto Actor : InWorld->GetActors())
    {
        if (Actor == CollisionActor)
        {
            continue;
        }

        if (Actor->bIsCollisionEnable && Actor->Location == CollisionActor->Location)
        {
            OutCollidedActor.push_back(Actor);
            Result = true;
        }
    }

    return Result;
}
