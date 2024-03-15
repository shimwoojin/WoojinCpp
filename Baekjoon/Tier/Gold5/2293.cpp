#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> coins(n, 0);
	vector<int> dp(k + 1, 0);
	dp[0] = 1;

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j >= coins[i])
			{
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
	}

	cout << dp[k];

	return 0;
}