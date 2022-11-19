#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
	Test() = default;
	explicit Test(int data) : int_data(data), float_data(0) { cout << "�Ű����� 1���� ������ ȣ��" << endl; }
	Test(int intdata, float floatdata) : int_data(intdata), float_data(floatdata) { cout << "�Ű����� 2���� ������ ȣ��" << endl; }
	void print()
	{
		cout << "int�� data : " << int_data << endl;
		cout << "float�� data : " << float_data << endl;
	}
	//Test(const Test& test) = delete;
	Test(const Test& test)
	{
		int_data = 10;
		float_data = 10.5;
		cout << "��������� ȣ��" << endl;
	}
private:
	int int_data;
	float float_data;
};

int main()
{
	vector<Test> t1;

	t1.assign(5, { 1,2.5 });
	t1.push_back(Test(1, 2.5));	//��������ڰ� delete�� ��� ����
	cout << "##############" << endl;
	t1.push_back(Test());
	cout << "##############" << endl;
	t1.push_back(Test(1));
	cout << "##############" << endl;
	t1.emplace_back(3, 3.3);	//��������ڰ� delete�� ��Ȳ������ �� ����
	cout << "##############" << endl;

	for (auto iter = t1.begin(); iter != t1.end(); iter++)
		iter->print();

	return 0;
}