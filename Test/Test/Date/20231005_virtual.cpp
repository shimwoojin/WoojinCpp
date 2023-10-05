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

	Parent* p = &P;	//������ �ڷ����� �´� �ν��Ͻ��� ���� ���
	p->PrintMyName();
	p = &C;	//�� ��Ȳ�� UpCasting�̶� �� �� ����, Child�� Parent�� �ڽ��̱� ������ �θ� �����ͷε� �ڽ��� ����ų �� ����
	p->PrintMyName();

	return 0;
}