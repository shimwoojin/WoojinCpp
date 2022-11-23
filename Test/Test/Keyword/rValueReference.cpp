#include <iostream>
using namespace std;

class Test
{
public:
	Test() { cout << "default constructor" << endl; }
	Test(const Test& t) { cout << "copy constructor" << endl; }
	Test(Test&& t) noexcept {cout<<"move constructor" <<endl; }

	void print_hello() { cout << "hello world" << endl; }

private:
};
int main()
{
	Test t1;
	Test t2(t1);
	Test t3(move(t1));
	Test t4(Test());	//error

	t1.print_hello();
	t2.print_hello();
	t3.print_hello();


	return 0;
}