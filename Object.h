#pragma once
class UWorld;

class UObject //메모리 관리, 언리얼 엔진은 모든 UObject 상속됨
{
public:
	UObject();

	virtual ~UObject();

	virtual UWorld* GetWorld() const;
	virtual void SetWorld(UWorld* NewWorld);

protected:
	UWorld* World;
};

