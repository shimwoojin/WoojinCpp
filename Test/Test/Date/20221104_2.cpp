#include <iostream>
#include <vector>


using namespace std;

int print(int&& x)
{
	cout << x << endl;
	return x;
}

int print(const int& x)
{
	cout << x << endl;
	return x;
}

template <typename T>
ostream& operator<<(ostream& os, T v)
{
	for (int i = 0; i < v.size(); i++)
		os << v[i];
	return os;
}

int main()
{
	int a = 10;

	int b = print(20);

	int c = print(a);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	vector<int> vc[5]{ {1,2,3},{4,5,6},{7,8,9},{2,3,4},{3,4,5} };
	vc[0].push_back(1);
	vc[1].push_back(2);
	vc[2].push_back(3);
	vc[3].push_back(4);
	vc[4].push_back(5);

	cout << vc[0] << endl;

	for (int i = 0; i < 5; i++)
		for(int j=0;j<4;j++)
			cout << vc[i][j] << endl;

	cout << vc[0][0] << endl;

	return 0;
}