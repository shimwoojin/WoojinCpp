#include <iostream>
#include <vector>
using namespace std;
constexpr int div_val = 1'000'000'000;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));

	for (int i = 0; i <= n; i++)
	{
		dp[1][i] = 1;
	}

	for (int i = 0; i <= k; i++)
	{
		dp[i][0] = 1;
	}

	for (int i = 2; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % div_val;
		}
	}

	cout << dp[k][n];

	return 0;
}