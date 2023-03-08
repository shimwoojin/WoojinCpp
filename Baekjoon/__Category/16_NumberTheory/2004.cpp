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

	int n, nn;
	cin >> n >> nn;

	int n5 = 0, n2 = 0;

	for (int i = 0; i < nn; i++)
	{
		int current1 = n - i;
		int current2 = i + 1;

		while (true)
		{
			if (current1 % 5 == 0)
			{
				++n5;
				current1 /= 5;
			}
			else if (current1 % 2 == 0)
			{
				++n2;
				current1 /= 2;
			}
			else break;
		}

		while (true)
		{
			if (current2 % 5 == 0)
			{
				--n5;
				current2 /= 5;
			}
			else if (current2 % 2 == 0)
			{
				--n2;
				current2 /= 2;
			}
			else break;
		}

	}

	cout << std::max(0, min(n5, n2));


	return 0;
}