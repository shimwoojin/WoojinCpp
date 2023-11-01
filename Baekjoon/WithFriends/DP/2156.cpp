#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//start : 19:17
	//end : 19:28

	//i-3, i-2, i-1, i..라고 했을 때

	int n;
	cin >> n;
	vector<int> wines(n + 3, 0);
	vector<int> dp(n + 3, 0);

	for (int i = 3; i < n + 3; i++)
	{
		cin >> wines[i];
	}

	for (int i = 3; i < n + 3; i++)
	{
		dp[i] = max(dp[i - 3] + wines[i - 1] + wines[i], dp[i]);	//3번째 전에 마셨고 1번째 전과 지금 마심
		dp[i] = max(dp[i - 2] + wines[i], dp[i]);	//2번째 전에 마셨고 지금 마심
		dp[i] = max(dp[i - 1], dp[i]);	//1번째 전에 마셨고 지금 안 마심
	}

	cout << dp[n + 2];

	return 0;
}