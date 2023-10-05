#include <iostream>

class Parent
{
public:
	virtual void PrintMyName()
	{
		std::cout << "Parent" << std::endl;
	}
};

class Child : public Parent
{
public:
	virtual void PrintMyName()
	{
		std::cout << "Child" << std::endl;
	}
};

int main()
{
	Parent P;
	Child C;

	Parent* p = &P;	//본인의 자료형에 맞는 인스턴스를 갖는 경우
	p->PrintMyName();
	p = &C;	//이 상황을 UpCasting이라 할 수 있음, Child는 Parent의 자식이기 때문에 부모 포인터로도 자식을 가리킬 수 있음
	p->PrintMyName();

	return 0;
}