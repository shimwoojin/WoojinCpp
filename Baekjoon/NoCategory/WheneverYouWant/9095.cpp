#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	vector<int> dp(1, 0);

	dp.push_back(1);
	dp.push_back(2);
	dp.push_back(4);

	for (size_t i = 4; i <= 11; i++)
	{
		dp.push_back(dp[i - 3] + dp[i - 2] + dp[i - 1]);
	}

	for (int i = 0; i < t; i++)
	{
		int a;
		cin >> a;

		cout << dp[a] << endl;
	}

	return 0;
}