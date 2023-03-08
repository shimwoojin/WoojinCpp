#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;

	for (int i = 1; i <= 30; i++)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < 28; i++)
	{
		int a;
		cin >> a;

		vec[a - 1] = 0;
	}

	for (int i = 0; i < 30; i++)
	{
		if (vec[i] != 0) cout << vec[i] << "\n";
	}


	return 0;
}