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

	int n;
	cin >> n;

	int n5 = 0, n2 = 0;

	for (int i = 1; i <= n; i++)
	{
		int temp = i;

		while (true)
		{
			if (temp % 5 == 0)
			{
				temp /= 5;
				++n5;
			}
			else if (temp % 2 == 0)
			{
				temp /= 2;
				++n2;
			}
			else break;
		}
	}

	cout << std::min(n5, n2);

	return 0;
}