#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "������" << endl; } // ������
	A(int a) { cout << "������ ������" << endl; }
	~A() { cout << "�Ҹ���" << endl; } // �Ҹ���
	A(const A& Rhs) { cout << "���� ������" << endl; } //���� ������
	A& operator=(const A& Rhs) { cout << "���� �̵� ������" << endl; return *this; } // ���� �̵� ������
	A(A&& Rhs) noexcept { a = Rhs.a; Rhs.a = 0; cout << "�̵� ������" << endl; } // �̵� ������
	A& operator=(A&& Rhs) noexcept { cout << "�̵� ���� ������" << endl; return *this; }// �̵� ���� ������

public:
	int a = 10;
};

int main()
{
	{
		A MyA; //������ �Ҹ�
		A MyOtherA(MyA); //���� ������ �Ҹ�
		MyOtherA = MyA; //���� ���� ������ �Ҹ�
		MyOtherA = std::move(MyA); //�̵� ���� ������ �Ҹ�
		MyOtherA.a = 20;
		A MyOtherB(std::move(MyOtherA)); //�̵� ������ �Ҹ�
		cout << MyOtherA.a << endl;
		cout << MyOtherB.a << endl;
		//�������� ����� ��������� A���� �Ҹ��ڰ� �Ҹ�
	}

	return 0;
}