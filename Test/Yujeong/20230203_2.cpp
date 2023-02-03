//#include <iostream>
//
//int main()
//{
//	//1.
//	char name[20] = { 's', 'h', 'i', 'm'};
//
//	//2.
//	const char* name2 = "shimwoo";
//	//"shimwoo" 라는 리터럴상수를 가리키는 char 포인터인거
//
//	name[3] = 'x';
//	//name2[3] = 'x';
//
//	//3.
//	std::string name3 = "shimwoojin";
//
//	name3[3] = 'x';
//
//	std::cout << name << std::endl;
//	std::cout << name2 << std::endl;
//	std::cout << name3 << std::endl;
//
//
//	return 0;
//}
//
//class MyString
//{
//public:
//	MyString(const char* name)
//	{
//
//
//		name = new char[10];
//		
//	}
//
//	~MyString()
//	{
//		delete[] name;
//	}
//
//private:
//	char* name;
//};

//#include <iostream>

//enum class Test : unsigned int
//{
//	t1,
//	t2,
//	t3
//};
//
//enum Test2
//{
//	Test_t1,
//	Test_t2,
//	Test_t3
//};
//
//int main()
//{
//	Test t = Test::t1;
//
//	Test2 t2 = Test_t1;
//
//	std::cout << Test_t1 << std::endl;
//	std::cout << Test_t2 << std::endl;
//	std::cout << static_cast<char>(Test::t2) << std::endl;
//
//	return 0;
//}

#include <iostream>
#include <vector>

int main()
{
	//int arr20[20] = { 1,2,3,4,5,6,7,8 };

	//for (int i = 0; i < 20; i++)
	//{
	//	std::cout << arr20[i] << std::endl;
	//}
	
	std::vector<int> arr20;

	arr20.push_back(1);
	arr20.push_back(2);
	arr20.push_back(3);
	arr20.push_back(4);
	arr20.push_back(5);

	arr20.pop_back();
	//arr20.clear();
	arr20.emplace_back(3);
	arr20.clear();
	if (arr20.empty())
		std::cout << "vector empty" << std::endl;
	else
		std::cout << "vector not empty" << std::endl;
	arr20.erase(arr20.begin() + 1, arr20.end() - 1);
	//arr20.shrink_to_fit();

	std::cout << "size : " << arr20.size() << std::endl;
	std::cout << "capacity : " << arr20.capacity() << std::endl;


	std::cout << arr20.back() << std::endl;

	for (const auto ele : arr20)
		std::cout << ele << std::endl;



	class Test
	{
	public:
		Test(int a, int b, int c) {}
	};

	std::vector<Test> T;

	Test t1(1, 2, 3);
	Test t2(0, 2, 3);
	Test t3(2, 2, 3);

	T.push_back(t1);
	T.push_back(t2);
	T.push_back(t3);

	T.push_back(Test(4, 5, 6));

	T.emplace_back(1, 2, 3);


	struct Person
	{
		//public:
		Person();
	};

	class Person2
	{
		//private:
	public:
		Person2();
	};

	Person p;
	Person2 p2;


	return 0;
}