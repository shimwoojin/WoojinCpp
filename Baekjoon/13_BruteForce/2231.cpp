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

	int sum = 0, min = 0;
	int m;
	cin >> m;

	for (int i = 1; i < m; i++)
	{
		sum = 0;

		if (i >= 1 && i < 10)
		{
			sum = i + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i >= 10 && i < 100)
		{
			int _10 = i / 10;
			int _1 = i % 10;

			sum = _1 + _10 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i >= 100 && i < 1000)
		{
			int _100 = i / 100;
			int _10 = (i % 100) / 10;
			int _1 = i % 10;

			sum = _1 + _10 + _100 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i >= 1000 && i < 10000)
		{
			int _1000 = i / 1000;
			int _100 = (i % 1000) / 100;
			int _10 = (i % 100) / 10;
			int _1 = i % 10;

			sum = _1 + _10 + _100 + _1000 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i >= 10000 && i < 100000)
		{
			int _10000 = i / 10000;
			int _1000 = (i % 10000) / 1000;
			int _100 = (i % 1000) / 100;
			int _10 = (i % 100) / 10;
			int _1 = i % 10;

			sum = _1 + _10 + _100 + _1000 + _10000 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i >= 100000 && i < 1000000)
		{
			int _100000 = i / 100000;
			int _10000 = (i % 100000) / 10000;
			int _1000 = (i % 10000) / 1000;
			int _100 = (i % 1000) / 100;
			int _10 = (i % 100) / 10;
			int _1 = i % 10;

			sum = _1 + _10 + _100 + _1000 + _10000 + _100000 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
		else if (i == 1000000)
		{
			int _1000000 = i / 1000000;
			int _100000 = (i % 1000000)/ 100000;
			int _10000 = (i % 100000) / 10000;
			int _1000 = (i % 10000) / 1000;
			int _100 = (i % 1000) / 100;
			int _10 = (i % 100) / 10;
			int _1 = i % 10;

			sum = _1 + _10 + _100 + _1000 + _10000 + _100000 + _1000000 + i;

			if (sum == m)
			{
				min = i;
				break;
			}
		}
	}

	if (min != 0) cout << min;
	else cout << 0;

	return 0;
}