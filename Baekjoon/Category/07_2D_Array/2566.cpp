#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int row = 0, column = 0;
	int max = -1;
	vector<int> vec;

	for (int i = 0; i < 81; i++)
	{
		int a;
		cin >> a;

		if (max < a)
		{
			max = a;
			row = i / 9 + 1;
			column = i % 9 + 1;
		}

		vec.push_back(a);
	}
	cout << max << " \n";
	cout << row << " " << column;


	return 0;
}