#include "Engine.h"
#include <vector>
#include <list>
#include <algorithm>
#include <iostream>


//자료구조 - 프로그램 만들때 자주? 어쩌다 쓸까?
//진영이한테 만들라고 시킬까? 매번? 저놈을 어떻게 믿고?
//Library -> 도서관, 프로그램 도서관
//Standard Template Library -> STL
//[][][][][][][][] -> 상수시간에 접근(랜덤억세스)
//크기 변경 -> 자주 하지 않음.
//vector
//Container, vector, list, queue, stack, tree, deqeue, map, set ...

int main()
{
	//std::vector<int> Data;

	//Data.push_back(3);
	//Data.push_back(7);
	//Data.push_back(4);
	//Data.push_back(1);
	//Data.push_back(3);
	//Data.push_back(2);
	//Data.push_back(5);
	//Data.push_back(6);

	//std::cout << Data.size() << std::endl;
	//
	//Data.erase(std::find(Data.begin(), Data.end(), 3));
	//Data.insert(std::find(Data.begin(), Data.end(), 4), 20);
	//std::sort(Data.begin(), Data.end());

	////for (auto Iter = Data.rbegin(); Iter != Data.rend(); ++Iter)
	////{
	////	std::cout << *Iter << std::endl;
	////}


	//for (auto Value : Data)
	//{
	//	std::cout << Value << std::endl;
	//}
	//std::cout << Data.size() << std::endl;

	//std::list<int> List;

	//List.push_back(7);
	//List.push_back(4);
	//List.push_back(1);
	//List.push_back(3);
	//List.push_back(2);
	//List.push_back(5);
	//List.push_back(6);

	//List.erase(std::find(List.begin(), List.end(), 3));
	//List.insert(std::find(List.begin(), List.end(), 4), 20);
	////for (auto Iter = List.rbegin(); Iter != List.rend(); ++Iter)
	////{
	////	std::cout << *Iter << std::endl;
	////}

	//for (auto Value : List)
	//{
	//	std::cout << Value << std::endl;
	//}
	//

	


	UEngine* MyEngine = new UEngine();

	MyEngine->Init();

	MyEngine->Run();

	MyEngine->Exit();

	delete MyEngine;

	return 0;
}