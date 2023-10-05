#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "생성자" << endl; } // 생성자
	A(int a) { cout << "인자있 생성자" << endl; }
	~A() { cout << "소멸자" << endl; } // 소멸자
	A(const A& Rhs) { cout << "복사 생성자" << endl; } //복사 생성자
	A& operator=(const A& Rhs) { cout << "복사 이동 생성자" << endl; return *this; } // 복사 이동 생성자
	A(A&& Rhs) noexcept { a = Rhs.a; Rhs.a = 0; cout << "이동 생성자" << endl; } // 이동 생성자
	A& operator=(A&& Rhs) noexcept { cout << "이동 대입 연산자" << endl; return *this; }// 이동 대입 연산자

public:
	int a = 10;
};

int main()
{
	{
		A MyA; //생성자 불림
		A MyOtherA(MyA); //복사 생성자 불림
		MyOtherA = MyA; //복사 대입 연산자 불림
		MyOtherA = std::move(MyA); //이동 대입 연산자 불림
		MyOtherA.a = 20;
		A MyOtherB(std::move(MyOtherA)); //이동 생성자 불림
		cout << MyOtherA.a << endl;
		cout << MyOtherB.a << endl;
		//스코프를 벗어나면 만들어졌던 A들의 소멸자가 불림
	}

	return 0;
}