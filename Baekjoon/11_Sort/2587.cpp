#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;

		sum += a;

		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cout << sum / 5 << "\n";
	cout << vec[2];

	return 0;
}