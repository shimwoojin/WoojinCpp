#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//start : 19:17
	//end : 19:28

	//i-3, i-2, i-1, i..��� ���� ��

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
		dp[i] = max(dp[i - 3] + wines[i - 1] + wines[i], dp[i]);	//3��° ���� ���̰� 1��° ���� ���� ����
		dp[i] = max(dp[i - 2] + wines[i], dp[i]);	//2��° ���� ���̰� ���� ����
		dp[i] = max(dp[i - 1], dp[i]);	//1��° ���� ���̰� ���� �� ����
	}

	cout << dp[n + 2];

	return 0;
}