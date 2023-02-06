#include <iostream>
#include <assert.h>
using namespace std;

//int add1(int& a)
//{
//	a += 1;
//
//	return a;
//}
//
//int main()
//{
//	int out_number = 10;
//
//	add1(out_number);	//add1(int a = out_number;)
//
//	cout << out_number << endl;
//
//	int test = add1(out_number);
//
//	test -= 10;
//
//	cout << test << endl;
//
//	return 0;
//}

//int main()
//{
//	assert(false);
//	assert(false);
//	assert(false);
//	assert(false);
//	cout << "Hello world" << endl;
//
//	return 0;
//}

//struct Test_Structure
//{
//	int a;
//	int b;
//	int c;
//	int d;
//
//	char c1;
//	char c2;
//
//	float f1;
//	float f2;
//};
//
//void function_for_structure(Test_Structure& structure)
//{
//	structure.a = 10;
//	structure.b = 10;
//	structure.c = 20;
//	structure.d = 30;
//
//	structure.c1 = 'd';
//	structure.c2 = 'f';
//
//	structure.f1 = 0.3f;
//	structure.f2 = 0.5f;
//}
//
//void function_for_structure(Test_Structure* structure)
//{
//	structure->a = 10;
//	structure->b = 10;
//	structure->c = 20;
//	structure->d = 30;
//
//	structure->c1 = 'd';
//	structure->c2 = 'f';
//
//	structure->f1 = 0.3f;
//	structure->f2 = 0.5f;
//}
//
//class Parent
//{
//public:
//
//
//protected:
//	int a;
//};
//
//class Child : public Parent
//{
//public:
//	void PrintA()
//	{
//		cout << "child의 a : " << a << endl;
//		cout << "Parent의 a : " << Parent::a << endl;
//	}
//	
//private:
//	int a;
//};

//int main()
//{
//	Test_Structure t1;
//
//	function_for_structure(t1);
//
//	function_for_structure(&t1);
//
//	a = 10;
//
//	Yujeong::a = 20;
//
//	return 0;
//}

//class UnderstandStatic
//{
//public:
//	UnderstandStatic()
//	{
//		a++;
//
//		cout << "static 변수가 변해요" << a << endl;
//	}
//
//	static void Print()
//	{
//		cout << "static이 붙은 class안의 함수는 네임스페이스만 붙이면 접근 가능" << endl;
//		cout << "static 함수 안에서는 static 변수만 사용 가능" << endl;
//		cout << "공용 변수 : " << a << endl;
//	}
//
//	void PrintB() { cout << b << endl; }
//
//private:
//	static int a;
//	int b = 0;
//};
//
//int UnderstandStatic::a = 0;
//
//int main()
//{
//	UnderstandStatic u1;
//	UnderstandStatic u2;
//	UnderstandStatic u3;
//	UnderstandStatic u4;
//	UnderstandStatic u5;
//	UnderstandStatic u6;
//	UnderstandStatic u7;
//
//	UnderstandStatic::Print();
//	u1.Print();
//
//	return 0;
//}

//namespace Test
//{
//	int a = 0;
//
//	void print() { a -= 1; }
//}
//
//class Test
//{
//public:
//	static void print() { cout << a << endl; }
//
//private:
//	static int a;
//};
//
//int Test::a = 10;
//
//int main()
//{
//	Test::print();	//a?
//
//
//	return 0;
//}
//
//class GUID_Generator final
//{
//public:
//	static const uint Generate();
//	static const std::string GenerateToString();
//};
//
////namespace GUID_Generator
////{
////	const uint Generate();
////	const std::string GenerateToString();
////}
//
////uint Generate();
//
//int main()
//{
//	GUID_Generator::Generate();
//
//
//	return 0;
//}
//
//enum class Color
//{
//	Red,
//	Orange,
//	Yellow
//};
//
//
//enum Yujeong
//{
//	babo,
//	meongchoeng
//};

//class Test
//{
//public:
//	Test(int a)
//		: a(a)	//2
//	{
//	}
//
//
//private:
//	int a;
//};
//
//class Child : public Test
//{
//public:
//	Child(int a)
//		: Test(a), c(20)
//	{
//
//	}
//
//private:
//	int c;
//};
//
//int main()
//{
//	Child c(3);
//
//
//
//	return 0;
//}

class Test
{
public:
	Test(int num)
	{
		name = new char[num];
	}

	void Init()
	{
		//생성자나 Init 함수, 즉 처음에 불리는 함수에서 동적할당을 하게되면
		//항상 소멸자 재작성 염두
	}

	~Test()
	{
		delete[] name;
	}


private:
	char* name;

};