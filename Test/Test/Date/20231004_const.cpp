#include <iostream>
using namespace std;

int main()
{
	const int a = 10;
	int b = 20;
	const int c = b;

	//constexpr int d = b;	//error

	cout << a << b << c << endl;

	return 0;
}