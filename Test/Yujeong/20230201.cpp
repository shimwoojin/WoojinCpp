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
//	void test()	//부모한텐 없는 함수
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
////static		: 일반적
////dynamic		: 상속관계에서 다운캐스팅할 때 런타임중에 확인할 수 있는
////reinterpret	: 강력함. 보통 포인터의 형변환에서 씀. 1차 포인터 -> 2차로. 일반자료형에서 2차 포인터로. 이런 게 다 가능
////const			: const성을 부여. 혹은 제거
//
//int main()
//{
//	//float f1 = 6.2f;
//	//
//	//int i1 = f1;		//암시적 형변환
//	//int i2 = (int)f1;	//명시적 형변환
//	//
//	//char c1 = (char)f1;		//c
//	//char c2 = char(f1);		//c++
//	//char c3 = static_cast<char>(f1);	//c++ 스타일에서 형변환에 대해 4가지로 또 구분
//	//
//	//cout << i1 << endl;
//	//cout << i2 << endl;
//	//cout << c1 << endl;
//
//	////이런 형변환들에 대해선 static_cast라는 것
//	////int -> short
//	////float -> int
//	////enum -> int
//	////double ->float
//
//	////dynamic_cast
//	////이거 왜 쓰나 ?
//
//	Parent* parent = new Parent();
//	Parent* child = new Child();		//암시적으로 업캐스팅이 됨
//	//분명히 자식을 새로 만들었는데 가리키는 포인터는 부모포인터로 해서 실제로 가리킬수 있어
//	
//	//업캐스팅 굉장히 강력
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
//	////업캐스팅 굉장히 강력
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
//	//이중 포인터 라는 놈은
//	//포인터 변수의 주소를 들고있는 변수지
//
//	cout << "포인터의 실제 값 : " << test_p << endl;
//	cout << "포인터 본인의 주소 : " << &test_p << endl;
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