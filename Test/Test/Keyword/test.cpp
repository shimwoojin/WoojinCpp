#include <iostream>
#include <bitset>
int main()
{
	using namespace std;

	int a = 10;
	
	unsigned int a_val = reinterpret_cast<unsigned int>(&a);
	unsigned short a_result = a_val ^ (a_val >> 16);


	cout << bitset<16>(a_result) << endl;
	cout << bitset<16>(a_val>>16) << endl;
	cout << bitset<32>(a_val) << endl;

	return 0;
}