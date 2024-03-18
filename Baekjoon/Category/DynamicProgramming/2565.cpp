#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int main()
{
	int correct_line = 0;
	int n;
	cin >> n;
	vector<pii> lines;
	vector<int> dp(n + 1, 0);

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		lines.push_back({a, b});
	}

	sort(lines.begin(), lines.end());
	
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (lines[i].second > lines[j].second)
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}

		correct_line = max(correct_line, dp[i]);
	}

	cout << n - correct_line;

	return 0;
}