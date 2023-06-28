#include <iostream>
#include <vector>
using namespace std;

typedef void (*FuncPtrWithVector)();

void Print1()
{
	cout << "1" << endl;
}

void Print2()
{
	cout << "2" << endl;
}

void Print3()
{
	cout << "3" << endl;
}

void Print4()
{
	cout << "4" << endl;
}

int main()
{

	vector<FuncPtrWithVector> FPVector;

	FPVector.push_back(Print1);
	FPVector.push_back(Print2);
	FPVector.push_back(Print3);
	FPVector.push_back(Print4);

	for (const auto& FPV : FPVector)
	{
		FPV();
	}

	return 0;
}