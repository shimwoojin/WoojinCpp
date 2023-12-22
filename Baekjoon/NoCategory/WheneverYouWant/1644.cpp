#include <bits/stdc++.h>
using namespace std;

void MakePrimes(int n, vector<bool>& primes)
{
	primes.assign(n + 1, true);
	primes[0] = false;
	primes[1] = false;

	for (int i = 2; i * i <= n; i++)
	{
		if (primes[i])
		{
			for (int k = i * 2; k <= n; k += i) 
			{
				primes[k] = false;
			}
		}
	}
}

int main()
{
	int answer = 0;
	int n;
	cin >> n;
	vector<bool> primes;
	
	MakePrimes(n, primes);

	int pointer_a = 0, pointer_b = 0;
	int sum = 0;

	while (pointer_b < n)
	{
		if (sum > n)
		{
			if (primes[pointer_a])
			{
				sum -= pointer_a;

				if (sum == n)
				{
					++answer;
				}
			}
			++pointer_a;
		}
		else
		{
			++pointer_b;
			if (primes[pointer_b])
			{
				sum += pointer_b;

				if (sum == n)
				{
					++answer;
				}
			}
		}
	}

	while (pointer_a < n)
	{
		if (primes[pointer_a])
		{
			sum -= pointer_a;

			if (sum == n)
			{
				++answer;
			}
		}
		++pointer_a;
	}

	cout << answer;

	return 0;
}