#include <iostream>
#include <memory>

void test(std::shared_ptr<int> shared)
{
	static int count = 30;
	count += 3;
	
	std::shared_ptr<int> another = shared;
	*shared = count;
	std::cout << shared.use_count() << std::endl;
}

void test2()
{
	std::cout << "hello world" << std::endl;
}

int main()
{
	using namespace std;

	//int test = 10;

	{
		//int* p_int = &test;
		shared_ptr<int> pi_test(new int(10));

		pi_test = make_shared<int>(20);

		test2();
		test(pi_test);
		test(pi_test);
		test(pi_test);
		//cout << *p_int << endl;
		cout << *pi_test << endl;
	}
	

	return 0;
}