#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		//입력
		int n, k;
		cin >> k >> n;
		vector<vector<int>>dp(n + 1, vector<int>(k + 1, 0));

		//문제 해결
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= k; j++) {
				if (j == 0 || i == j) dp[i][j] = 1;
				else dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]);
			}
		}

		//결과 출력
		cout << dp[n][k] << '\n';
	}




	return 0;
}