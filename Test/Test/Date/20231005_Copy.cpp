#include <iostream>

class A
{
public:
	A()
	{
		pa = new int;
		*pa = 10;
	}

	A(const A& Rhs)
	{
		pa = new int;
		*pa = *Rhs.pa;
	}

	~A()
	{
		std::cout << "소멸자 정상 호출" << std::endl;
		delete pa;
	}

	virtual void Print() {}	//virtual은 보이지 않는 포인터 변수를 만듬, 가상 테이블 -> class의 size 증가

public:
	int* pa = nullptr;
};

class B : public A
{
public:
	virtual void Print() {}
};

int main()
{
	A MyA;
	A MyB(MyA);

	std::cout << MyA.pa << std::endl;
	std::cout << MyB.pa << std::endl;
	
	*(MyB.pa) = 20;
	
	std::cout << *(MyA.pa) << std::endl;
	std::cout << *(MyB.pa) << std::endl;

	std::cout << sizeof(MyA) << std::endl;
	std::cout << sizeof(B) << std::endl;

	return 0;
}