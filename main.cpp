#include <vector>
#include <iostream>

//생략은 생각도 하지마.
using namespace std;

class SuperParent
{
public:
	virtual void Play()
	{
		cout << "술을 마신다." << endl;
	}
};


class 유진영 : public SuperParent
{
public:
	virtual void Play() override
	{
		__super::Play();
		//SuperParent::Play();
		cout << "공룡을 가지고 논다." << endl;
	}

	void 나가()
	{
		cout << "쫓겨난다.." << endl;
	}
};

class Girl : public SuperParent
{
public:
	virtual void Play() override
	{
		SuperParent::Play();
		cout << "지구본 가지고 논다." << endl;
	}
};


int main()
{
	//다형성
	//상속 + 포인터
	//virtual, override
	vector<SuperParent*> House;

	House.push_back(new SuperParent);
	House.push_back(new Girl);
	House.push_back(new Girl);
	House.push_back(new Girl);
	House.push_back(new 유진영);

	for (auto Person : House)
	{
		//다운 캐스팅
		유진영* B = dynamic_cast<유진영*>(Person);
		if (B)
		{
			B->나가();
		}
	}
	//House[0]->Play();
	//House[1]->Play();
	//House[2]->Play();

	//다형성

	return 0;
}