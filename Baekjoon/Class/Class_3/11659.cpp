#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
		
	int n, m;
	cin >> n >> m;
	vector<int> dp(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i];
		dp[i] += dp[i - 1];
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << dp[b] - dp[a - 1] << '\n';
	}

	return 0;
}