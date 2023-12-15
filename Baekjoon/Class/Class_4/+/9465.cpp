#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int answer = 0;
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<vector<int>> stickers(2, vector<int>(n + 2, 0));
		vector<vector<int>> dp(2, vector<int>(n + 2, 0));

		for (int j = 0; j < 2; j++)
		{
			for (int k = 2; k < n + 2; k++)
			{
				cin >> stickers[j][k];
			}
		}

		int max_line0 = 0;
		int max_line1 = 0;

		for (int j = 2; j < n + 2; j++)
		{
			max_line0 = max(dp[0][j - 2], max_line0);
			max_line1 = max(dp[1][j - 2], max_line1);

			dp[0][j] = max(max_line0 + stickers[1][j - 1], max_line1) + stickers[0][j];
			dp[1][j] = max(max_line1 + stickers[0][j - 1], max_line0) + stickers[1][j];
		}

		auto max1 = max_element(dp[0].begin(), dp[0].end());
		auto max2 = max_element(dp[1].begin(), dp[1].end());

		answer = max(*max1, *max2);

		cout << answer << '\n';
	}

	return 0;
}