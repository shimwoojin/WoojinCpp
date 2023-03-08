#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int check = 1000000;
	int n, m;
	cin >> n >> m;

	vector<vector<char>> chess(n);

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		for (int j = 0; j < m; j++)
		{
			chess[i].push_back(str[j]);
		}
	}

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int _64_BW = 64;
			int _64_WB = 64;

			for (int k = i; k < i + 8; k++)
			{
				for (int l = j; l < j + 8; l++)
				{
					//1. BWBW
					if (l % 2 == 0 && k % 2 == 0)
					{
						if (chess[k][l] == 'B') _64_BW -= 1;
						if (chess[k][l] == 'W') _64_WB -= 1;
					}
					if (l % 2 == 1 && k % 2 == 0)
					{
						if (chess[k][l] == 'W') _64_BW -= 1;
						if (chess[k][l] == 'B') _64_WB -= 1;
					}
					if (l % 2 == 0 && k % 2 == 1)
					{
						if (chess[k][l] == 'W') _64_BW -= 1;
						if (chess[k][l] == 'B') _64_WB -= 1;
					}
					if (l % 2 == 1 && k % 2 == 1)
					{
						if (chess[k][l] == 'B') _64_BW -= 1;
						if (chess[k][l] == 'W') _64_WB -= 1;
					}
				}
			}

			check = min(check, min(_64_BW, _64_WB));
		}
	}

	cout << check;

	return 0;
}