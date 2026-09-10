#include "Player.h"
#include "Engine.h"
#include "InputDevice.h"
#include "World.h"
#include "SystemLibrary.h"
#include <vector>
#include "Renderer.h"

APlayer::APlayer()
{
	Shape = 'P';
	Layer = 100;
	bIsCollisionEnable = true;
	R = 0;
	G = 0;
	B = 255;
	A = 0;

	Load(".\\data\\player.bmp");

}

APlayer::~APlayer()
{
}

void APlayer::Load(std::string Path)
{
	BMPSurface = SDL_LoadBMP(Path.c_str());//CPU


	SDL_SetColorKey(BMPSurface, 1, SDL_MapRGB(BMPSurface->format, 255, 0, 255));

	//GPU
	BMPTexture = SDL_CreateTextureFromSurface(GEngine->GetRenderer()->MyRenderer, BMPSurface);
}

void APlayer::Tick(Uint64 DeltaSeconds)
{
	if (GEngine->MyEvent.type == SDL_KEYDOWN)
	{
		std::vector<AActor*> CollideActors;

		SDL_Keycode KeyCode = GEngine->MyEvent.key.keysym.sym;
		if (KeyCode == SDLK_w)
		{
			//Predict
			Location.Y--;
			if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
			{
				Location.Y++;
			}

		}
		if (KeyCode == SDLK_s)
		{
			Location.Y++;
			if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
			{
				Location.Y--;
			}
		}
		if (KeyCode == SDLK_a)
		{
			Location.X--;
			if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
			{
				Location.X++;
			}
		}
		if (KeyCode == SDLK_d)
		{
			Location.X++;
			if (USystemLibrary::CheckCollide(GetWorld(), this, CollideActors))
			{
				Location.X--;
			}
		}
	}
}

void APlayer::NextFrame()
{
	Index++;
	Index = Index % 5;
}
