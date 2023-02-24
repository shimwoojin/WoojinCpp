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

	int m, n;
	vector<int> prime;
	cin >> m >> n;

	for (int i = m; i <= n; i++)
	{
		bool CheckPrime = true;

		if (i == 1) continue;

		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) CheckPrime &= false;
		}

		if (CheckPrime == true) prime.push_back(i);
	}

	if (prime.empty() == true)
	{
		cout << -1;
	}
	else
	{
		int sum = 0;

		for (int i = 0; i < prime.size(); i++)
		{
			sum += prime[i];
		}

		cout << sum << "\n" << prime[0];
	}

	return 0;
}