#include "Engine.h"

#include <iostream>

using namespace std;

class Singleton
{
protected:
	Singleton()
	{
	}

public:
	static Singleton* GetInstance()
	{
		if (!Singleton::Instance)
		{
			Singleton::Instance = new Singleton();
		}

		return Singleton::Instance;
	}

protected:
	static Singleton* Instance;
};

Singleton* Singleton::Instance = nullptr;




int main()
{
	//UEngine::GetInstance();

	GEngine->Init();

	GEngine->Run();

	GEngine->Exit();


	return 0;
}
