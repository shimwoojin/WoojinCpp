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
		std::cout << "�Ҹ��� ���� ȣ��" << std::endl;
		delete pa;
	}

	virtual void Print() {}	//virtual�� ������ �ʴ� ������ ������ ����, ���� ���̺� -> class�� size ����

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