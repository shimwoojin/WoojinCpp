#include <iostream>
#include "MyVector.h"
#include <vector>

int main()
{
	using namespace std;

	MyVector<double> mv(5);

	cout << mv.GetCapacity() << endl;
	cout << mv.GetLength() << endl;

	mv.push_back(5.3);
	mv.push_back(4.3);
	mv.push_back(3.3);
	mv.push_back(2.3);
	mv.push_back(2.3);
	mv.push_back(2.3);
	mv.push_back(2.3);
	mv.push_back(2.3);

	mv.pop_back();
	mv.pop_back();
	mv.pop_back();
	mv.pop_back();
	mv.pop_back();

	cout << mv.size() << endl;

	for (int i = 0; i < mv.size(); i++)
		cout << mv[i] << endl;

	return 0;
}