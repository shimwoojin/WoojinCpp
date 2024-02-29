#include <iostream>
#include <vector>
using namespace std;
using pii = pair<int, int>;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> buses(n + 1, vector<int>(n + 1, 20'000'000));

	for (int i = 1; i <= n; i++)
	{
		buses[i][i] = 0;
	}

	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		buses[a][b] = min(buses[a][b], c);
	}

	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int temp = buses[i][k] + buses[k][j];
				if (temp < buses[i][j])
				{
					buses[i][j] = temp;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (buses[i][j] == 20'000'000)
			{
				cout << 0 << ' ';
			}
			else
			{
				cout << buses[i][j] << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
