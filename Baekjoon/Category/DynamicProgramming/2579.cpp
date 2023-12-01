#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> vec(n + 1, 0);
	vector<vector<int>> dp(n + 1, vector<int>(2, 0));

	for (int i = 1; i <= n; i++)
	{
		cin >> vec[i];
	}

	if (n == 1)
	{
		cout << vec[1];
		return 0;
	}

	dp[1][0] = vec[1];
	dp[1][1] = vec[1];
	dp[2][0] = vec[2];
	dp[2][1] = vec[1] + vec[2];
	
	for (int i = 3; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 2][1], dp[i - 2][0]) + vec[i];
		dp[i][1] = dp[i - 1][0] + vec[i];
	}

	cout << max(dp[n][0], dp[n][1]);

	return 0;
}