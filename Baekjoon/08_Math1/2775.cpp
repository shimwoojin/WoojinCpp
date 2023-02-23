#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int result[15][14] = { 0 };

	for (int i = 0; i < 14; i++)
	{
		result[0][i] = i + 1;
	}

	for (int i = 1; i < 15; i++)
	{
		for (int j = 0; j < 14; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				result[i][j] += result[i - 1][k];
			}
		}
	}

	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		int k, n;
		cin >> k >> n;

		cout << result[k][n - 1];

		if (i != t - 1) cout << "\n";
	}

	return 0;
}