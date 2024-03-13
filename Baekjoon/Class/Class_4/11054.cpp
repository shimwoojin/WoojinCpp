#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int answer = 0;
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 1);
	vector<int> r_dp(n, 1);

	for(int i = 0 ; i < n; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (arr[i] > arr[j])
			{
				r_dp[i] = max(r_dp[i], r_dp[j] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		answer = max(answer, dp[i] + r_dp[i]);
	}

	cout << answer - 1;

	return 0;
}