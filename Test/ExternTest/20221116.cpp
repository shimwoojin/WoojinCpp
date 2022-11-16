#include <iostream>
#include "20221116.h"

extern const int externInt;
extern int externInt2;

int main()
{
	using namespace std;

	cout << externInt << endl;
	print();
	print();
	print();
	print();
	print();
	cout << externInt2 << endl;

	externInt2 = 0;

	cout << externInt2 << endl;
	print2();

	return 0;
}