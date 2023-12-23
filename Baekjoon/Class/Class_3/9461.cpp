#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	vector<long long> dp(101, 0);
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	for (int i = 6; i <= 100; i++)
	{
		dp[i] = dp[i - 3] + dp[i - 2];
	}

	while (t--)
	{
		int n;
		cin >> n;
		
		cout << dp[n] << '\n';
	}

	return 0;
}