#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int a = 0, b = 0, c = 0;
		int answer = INT_MAX;

		int n;
		cin >> n;
		vector<string> mbtis(n);

		for (int i = 0; i < n; i++)
		{
			cin >> mbtis[i];
		}

		if (n > 32)
		{
			cout << 0 << '\n';
		}
		else
		{
			vector<vector<int>> value_map(n, vector<int>(n, 0));

			for (int i = 0; i < n; i++)
			{
				string now = mbtis[i];

				for (int j = 0; j < n; j++)
				{
					string compare = mbtis[j];

					if (i == j)
					{
						continue;
					}

					for (int k = 0; k < 4; k++)
					{
						if (now[k] != compare[k])
						{
							value_map[i][j]++;
						}
					}
				}
			}

			for (int i = 0; i < n - 2; i++)
			{
				for (int j = i + 1; j < n - 1; j++)
				{
					for (int k = j + 1; k < n; k++)
					{
						answer = min(answer, value_map[i][j] + value_map[j][k] + value_map[k][i]);
					}
				}
			}

			cout << answer << '\n';
		}
	}

	return 0;
}