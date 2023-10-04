#include <iostream>

class A
{
public:
	A()
		: a(1), b(2)
	{}

	A(int a, int b)
		: a(a), b(b)
	{
		std::cout << "인자 있는 생성자 호출" << std::endl;
	}

	A(const A& Rhs)
	{
		this->a = Rhs.a;
		this->b = Rhs.b;

		std::cout << "복사 생성자 호출" << std::endl;
	}

	A operator=(const A& Rhs)
	{
		this->a = Rhs.a;
		this->b = Rhs.b;

		std::cout << "복사 대입 연산자 호출" << std::endl;
	}

	A(A&& Rhs) noexcept
	{
		this->a = Rhs.a;
		this->b = Rhs.b;

		std::cout << "이동 생성자 호출" << std::endl;
	}

	A operator=(A&& Rhs) noexcept
	{
		this->a = Rhs.a;
		this->b = Rhs.b;

		std::cout << "이동 대입 연산자 호출" << std::endl;
	}

public:
	int a, b;
};

int main()
{
	A* MyA = new A[3]{A(1,2), A(3,4), A(5,6)};

	for (int i = 0; i < 3; i++)
	{
		std::cout << MyA[i].a << std::endl;
		std::cout << MyA[i].b << std::endl;
	}

	return 0;
}

//int main()
//{
//	A* MyA1 = new A;
//	A* MyA2 = (A*)malloc(sizeof(A));
//	if (MyA2)
//	{
//		*MyA2 = A();
//	}
//
//	if (MyA1)
//	{
//		std::cout << MyA1->a << std::endl;	//1
//	}
//
//	if (MyA2)
//	{
//		std::cout << MyA2->a << std::endl;	//1
//	}
//
//	return 0;
//}