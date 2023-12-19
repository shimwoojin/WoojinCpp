#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n + 1, 0);
	vector<pair<int, int>> dp(n + 1, {0, 0});
	
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++)
	{
		dp[i];
		int max = 0;

		for (int j = 0; j < i; j++)
		{
			if (arr[i] > dp[j].first)
			{
				max = std::max(max, dp[j].second);
			}
		}

		dp[i] = make_pair(arr[i], max + 1);
	}

	int answer = 0;

	for (auto ele : dp)
	{
		answer = std::max(answer, ele.second);
	}

	cout << answer;

	return 0;
}