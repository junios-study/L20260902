#include "Engine.h"


int SDL_main(int argc, char* argv[])
{
	GEngine->Init();

	GEngine->Run();

	GEngine->Exit();

	return 0;
}
