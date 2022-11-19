#include <iostream>
#include <vector>
using namespace std;

class Test
{
public:
	Test() = default;
	explicit Test(int data) : int_data(data), float_data(0) { cout << "매개변수 1개인 생성자 호출" << endl; }
	Test(int intdata, float floatdata) : int_data(intdata), float_data(floatdata) { cout << "매개변수 2개인 생성자 호출" << endl; }
	void print()
	{
		cout << "int형 data : " << int_data << endl;
		cout << "float형 data : " << float_data << endl;
	}
	//Test(const Test& test) = delete;
	Test(const Test& test)
	{
		int_data = 10;
		float_data = 10.5;
		cout << "복사생성자 호출" << endl;
	}
private:
	int int_data;
	float float_data;
};

int main()
{
	vector<Test> t1;

	t1.assign(5, { 1,2.5 });
	t1.push_back(Test(1, 2.5));	//복사생성자가 delete된 경우 오류
	cout << "##############" << endl;
	t1.push_back(Test());
	cout << "##############" << endl;
	t1.push_back(Test(1));
	cout << "##############" << endl;
	t1.emplace_back(3, 3.3);	//복사생성자가 delete된 상황에서도 잘 나옴
	cout << "##############" << endl;

	for (auto iter = t1.begin(); iter != t1.end(); iter++)
		iter->print();

	return 0;
}