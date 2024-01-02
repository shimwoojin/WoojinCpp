#include <iostream>

int main()
{
	using namespace std;

	union MyUnion
	{
		struct
		{
			int a, b;
		};

		int c[2];
	};

	MyUnion U;

	U.a = 10;
	U.b = 20;

	cout << U.a << endl;	//10
	cout << U.b << endl;	//20
	cout << U.c[0] << endl;	//10
	cout << U.c[1] << endl;	//20
	cout << sizeof(U) << endl;	//8

	return 0;
}