#include <iostream>
using namespace std;

//�Լ� �����͸� ����ó�� �� �� �ְ� ���ִ� typedef
typedef int (*FuncPtrIntTwoParam)(int, int);
//�Լ� �����͸� ����ó�� �� �� �ְ� ���ִ� using
using FuncPtrVoidOneParam = void(*)(float&);

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

void FloatToZero(float& f)
{
	f = 0.0f;
}

int main()
{
	FuncPtrIntTwoParam funcptr1;
	funcptr1 = add;

	FuncPtrIntTwoParam funcptr2 = sub;

	FuncPtrVoidOneParam funcptr3 = FloatToZero;

	cout << "TwoParam Func Result : " << funcptr1(1, 9) << endl;
	cout << "Other TwoParam Func Result : " << funcptr2(1, 9) << endl;
	
	float TestFloat = 10.0f;

	cout << "Before TestFloat : " << TestFloat << endl;

	funcptr3(TestFloat);

	cout << "After TestFloat : " << TestFloat << endl;

	return 0;
}