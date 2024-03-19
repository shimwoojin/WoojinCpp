#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[0] = 1;
	dp[2] = 3;

	if (n % 2 == 1)
	{
		cout << 0;
	}
	else
	{
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
			{
				dp[i] += dp[i - j] * 2;
			}
		}

		cout << dp[n];
	}

	return 0;
}