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
#include <list>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int m, n;
	cin >> m >> n;

	vector<bool> IsPrime(1000001, true);

	IsPrime[0] = false, IsPrime[1] = false;

	for (int i = 2; i * i <= 1000000; i++)
	{
		if (IsPrime[i] == true)
		{
			for (int j = i * i; j <= n; j += i)
			{
				IsPrime[j] = false;
			}
		}
	}

	for (int i = m; i <= n; i++)
	{
		if (IsPrime[i] == true) cout << i << "\n";
	}

	return 0;
}