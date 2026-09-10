#include "Actor.h"
#include "Engine.h"
#include "Renderer.h"

AActor::AActor() : Location(0, 0), Shape(' ')
{
	BMPSurface = nullptr;
	BMPTexture = nullptr;
}

AActor::~AActor()
{
	if (BMPSurface)
	{
		SDL_FreeSurface(BMPSurface);
	}

	if (BMPTexture)
	{
		SDL_DestroyTexture(BMPTexture);
	}
}

void AActor::Load(std::string Path)
{
	BMPSurface = SDL_LoadBMP(Path.c_str());//CPU


	SDL_SetColorKey(BMPSurface, 1, SDL_MapRGB(BMPSurface->format, 255, 255, 255));


	//GPU
	BMPTexture = SDL_CreateTextureFromSurface(GEngine->GetRenderer()->MyRenderer, BMPSurface);
}

void AActor::Tick(Uint64 DeltaSeconds)
{
}

void AActor::Render()
{
	GEngine->GetRenderer()->Render(this);
}

UWorld* AActor::GetWorld() const
{
	return World;
}
