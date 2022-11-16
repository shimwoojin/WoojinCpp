#include <iostream>
#include <iomanip>

int main()
{
	using namespace std;
	int hundred = 100;
	double PI = 23.141592;
	bool istrue = true;

	cout << showpoint << boolalpha << right;
	cout.precision(3);
	cout.width(10);
	cout << hundred << endl;
	cout << PI << endl;
	cout << istrue << endl;
	cout << hex << hundred << endl;
	cout << PI << endl;
	cout.width(10);
	cout << oct << hundred << endl;
	cout << PI << endl;

	cout << endl << endl;

	for (int i = 0; i < 10; i++)
	{
		cout.width(10);
		cout.fill('%');
		cout << "hello" << endl;
	}

	cout << setfill(' ') << setw(5) << "hello" << setw(14) << "world!!" << setw(10) << "C++" << endl;

	cout << setw(5) << setfill('.') << 5 << setfill(' ')
		<< setw(14) << 10 << setw(10) << 15 << endl;



	return 0;
}