#include <iostream>
using namespace std;

//enum test
//{
//	t_1,
//	t_2,
//	t_3,
//	t_4,
//	t_5
//};
//
//class Parent
//{
//public:
//	virtual void print() {
//		cout << "parent" << endl;
//	}
//};
//
//class Child : public Parent
//{
//public:
//	void print() {
//		cout << "child" << endl;
//	}
//
//	void test()	//�θ����� ���� �Լ�
//	{
//		cout << "test" << endl;
//	}
//};
//
//class Child2 : public Parent
//{
//public:
//	void print() {
//		cout << "child2" << endl;
//	}
//};
//
////static		: �Ϲ���
////dynamic		: ��Ӱ��迡�� �ٿ�ĳ������ �� ��Ÿ���߿� Ȯ���� �� �ִ�
////reinterpret	: ������. ���� �������� ����ȯ���� ��. 1�� ������ -> 2����. �Ϲ��ڷ������� 2�� �����ͷ�. �̷� �� �� ����
////const			: const���� �ο�. Ȥ�� ����
//
//int main()
//{
//	//float f1 = 6.2f;
//	//
//	//int i1 = f1;		//�Ͻ��� ����ȯ
//	//int i2 = (int)f1;	//����� ����ȯ
//	//
//	//char c1 = (char)f1;		//c
//	//char c2 = char(f1);		//c++
//	//char c3 = static_cast<char>(f1);	//c++ ��Ÿ�Ͽ��� ����ȯ�� ���� 4������ �� ����
//	//
//	//cout << i1 << endl;
//	//cout << i2 << endl;
//	//cout << c1 << endl;
//
//	////�̷� ����ȯ�鿡 ���ؼ� static_cast��� ��
//	////int -> short
//	////float -> int
//	////enum -> int
//	////double ->float
//
//	////dynamic_cast
//	////�̰� �� ���� ?
//
//	Parent* parent = new Parent();
//	Parent* child = new Child();		//�Ͻ������� ��ĳ������ ��
//	//�и��� �ڽ��� ���� ������µ� ����Ű�� �����ʹ� �θ������ͷ� �ؼ� ������ ����ų�� �־�
//	
//	//��ĳ���� ������ ����
//	
//	Parent* parent_arr[2] = { parent, child };
//	
//	for (auto& p_arr : parent_arr)
//		p_arr->print();
//
//	static_cast<Child*>(child)->test();
//	dynamic_cast<Child*>(child)->test();
//	//child->test();
//
//	//Parent* parent = new Parent();
//	//Child* child = new Child();
//	//
//	////��ĳ���� ������ ����
//	//
//	//Parent* parent_arr[2] = { parent, child };
//	//
//	//for (auto& p_arr : parent_arr)
//	//	p_arr->print();
//
//	//reinterpret_cast
//	int test = 10;
//
//	int* test_p = &test;
//
//	//int** test_pp = &test_p;
//	int** test_pp = (test_p);
//	//���� ������ ��� ����
//	//������ ������ �ּҸ� ����ִ� ������
//
//	cout << "�������� ���� �� : " << test_p << endl;
//	cout << "������ ������ �ּ� : " << &test_p << endl;
//
//	//cout << *test_p << endl;
//	//
//	//cout << test_pp << endl;
//
//	int a = 10;
//
//	return 0;
//}



class Test
{
public:
	Test()
	{
		data = new char[10];
	}

	~Test()
	{
		delete[] data;
	}

	Test(const Test& other)
	{
	}


private:
	char* data;
};

int main()
{
	Test t;

	{
		Test t2(t);
	}

	return 0;
}