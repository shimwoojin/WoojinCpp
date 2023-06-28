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
	//���� ���� �� �ʱ�ȭ
	void (*VoidNoParameter)();
	VoidNoParameter = PrintHello;

	//���� ����� ���ÿ� �ʱ�ȭ
	int (*IntOneParameter)(int) = PrintHelloNumber;

	VoidNoParameter();

	//return���� ��Ƶ� ���� ���� �� �Լ� ����
	auto FuncPtrReturnInt = IntOneParameter(10);

	//�Լ��� return���� ���� ���� �� Ȯ��
	cout << "Return Result Of OneParam Function Pointer : " << FuncPtrReturnInt << endl << endl;

	//======================================

	IntOneParameter = PrintHelloHelloNumber;
	
	cout << "After Changing OneParam Function Pointer Binding" << endl;

	cout<<endl;
	
	FuncPtrReturnInt = IntOneParameter(1000);

	cout << "Return Result Of OneParam Function Pointer : " << FuncPtrReturnInt << endl;

	return 0;
}