#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n = 0;

	while (true)
	{
		vector<int> vec;
		int sum = 0;

		cin >> n;

		if (n == -1) break;

		for (int i = 1; i < n; i++)
		{
			if (n % i == 0) vec.push_back(i);
		}

		for (int i = 0; i < vec.size(); i++)
		{
			sum += vec[i];
		}

		if (n == sum)
		{
			cout << n << " = ";

			for (int i = 0; i < vec.size(); i++)
			{
				if (i != vec.size() - 1)
					cout << vec[i] << " + ";
				else cout << vec[i] << "\n";
			}
		}
		else
		{
			cout << n << " is NOT perfect.\n";
		}
	}

	return 0;
}