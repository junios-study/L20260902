#pragma once
#include "Object.h"
#include "Vector2D.h"
#include "SDL.h"
#include <string>

class AActor : public UObject
{
public:
	AActor();
	virtual ~AActor();

	//inline FVector2D GetActorLocation() const
	//{
	//	return Location;
	//}

	//inline void SetActorLocation(const FVector2D InValue)
	//{
	//	//Location.SetX(InValue.GetX());
	//	//Location.SetY(InValue.GetY());

	//	Location = InValue;
	//}

	virtual void Load(std::string Path);

	virtual void Tick(Uint64 DeltaSeconds);
	virtual void Render();

	virtual UWorld* GetWorld() const override final;


//protected:
	FVector2D Location;
	char Shape = ' ';
	int Layer = 0;

	bool bIsCollisionEnable = false;

	int R = 255;
	int G = 255;
	int B = 255;
	int A = 0;


	//Surface 메모리 화면 공간 버퍼
	SDL_Surface* BMPSurface = nullptr;

	//VRAM에 잡는 공간
	SDL_Texture* BMPTexture = nullptr;

};

