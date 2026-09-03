#include "Engine.h"

#include <iostream>

using namespace std;

class StaticClass
{
public:
	StaticClass()
	{
		StaticClass::Count++;
	}

	virtual ~StaticClass()
	{
		StaticClass::Count--;
	}

	static int Count;
};

int StaticClass::Count = 0;


int main()
{
	StaticClass* A = new StaticClass();
	delete A;
	StaticClass* B;
	std::cout << StaticClass::Count << std::endl;

	//UEngine* MyEngine = new UEngine();

	//MyEngine->Init();


	return 0;
}
