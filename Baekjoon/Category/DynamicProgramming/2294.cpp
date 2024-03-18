#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coins(n, 0);
	vector<int> dp(k + 1, 100'000);
	dp[0] = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			dp[j] = min(dp[j], dp[j - coins[i]] + 1);
		}
	}

	if (dp[k] == 100'000) cout << -1;
	else cout << dp[k];

	return 0;
}