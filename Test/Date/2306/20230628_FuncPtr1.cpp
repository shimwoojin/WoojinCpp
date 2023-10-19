#include <iostream>
using namespace std;

void PrintHello()
{
	cout << "Hello!!" << endl;
}

int PrintHelloNumber(int num)
{
	cout << "Hello!! : " << num << endl;

	return num;
}

int PrintHelloHelloNumber(int num)
{
	cout << "Hello!!" << "Hello : " << num << endl;

	return num;
}

int main()
{
	//변수 선언 후 초기화
	void (*VoidNoParameter)();
	VoidNoParameter = PrintHello;

	//변수 선언과 동시에 초기화
	int (*IntOneParameter)(int) = PrintHelloNumber;

	VoidNoParameter();

	//return값을 담아둘 변수 선언 및 함수 실행
	auto FuncPtrReturnInt = IntOneParameter(10);

	//함수의 return값을 담은 변수 값 확인
	cout << "Return Result Of OneParam Function Pointer : " << FuncPtrReturnInt << endl << endl;

	//======================================

	IntOneParameter = PrintHelloHelloNumber;
	
	cout << "After Changing OneParam Function Pointer Binding" << endl;

	cout<<endl;
	
	FuncPtrReturnInt = IntOneParameter(1000);

	cout << "Return Result Of OneParam Function Pointer : " << FuncPtrReturnInt << endl;

	return 0;
}