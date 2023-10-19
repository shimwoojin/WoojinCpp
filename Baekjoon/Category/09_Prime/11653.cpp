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

	int n;
	vector<int> prime;
	cin >> n;

	while (true)
	{
		int before = n;

		for (int i = 2; i <= n; i++)
		{
			if (n % i == 0)
			{
				n /= i;
				prime.push_back(i);
				break;
			}
		}

		if (before == n) break;
	}

	for (int i = 0; i < prime.size(); i++)
	{
		cout << prime[i] << "\n";
	}

	return 0;
}