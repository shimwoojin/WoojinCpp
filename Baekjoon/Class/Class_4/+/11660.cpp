#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + board[i][j];
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		--x1;
		--y1;

		//cout << dp[y2][x2] - (dp[y2][x1] + dp[y1][x2] - dp[y1][x1]) << '\n';
		cout << dp[x2][y2] - (dp[x2][y1] + dp[x1][y2] - dp[x1][y1]) << '\n';
	}

	return 0;
}