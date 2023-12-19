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

typedef long long ll;

int divide_location(vector<vector<int>> vec, int size, int x, int y, int check)
{
	if (size == 1) return 1;
	bool AllLocationSame = true;

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (check != vec[i][j])
			{
				AllLocationSame = false;
				break;
			}
		}
	}

	if (AllLocationSame == true) return 1;

	return divide_location(vec, size / 2, x, y, check) +
		divide_location(vec, size / 2, x + size / 2, y, check) +
		divide_location(vec, size / 2, x, y + size / 2, check) +
		divide_location(vec, size / 2, x + size / 2, y + size / 2, check);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<vector<int>> vec(n, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;

			vec[i][j] = a;
		}
	}

	cout << divide_location(vec, n, 0, 0, 0) << "\n";
	cout << divide_location(vec, n, 0, 0, 1);

	return 0;
}