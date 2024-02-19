#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--)
	{
		int M, N, x, y;
		int standard;
		cin >> M >> N >> x >> y;
		standard = x;

		int max_num = lcm(M, N);

		while (standard <= max_num)
		{
			int compare = standard % N;
			if (compare == y)
			{
				break;
			}
			else if (N == y && compare == 0)
			{
				break;
			}
			else
			{
				standard += M;
			}
		}

		if (standard <= max_num)
		{
			cout << standard << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}

	return 0;
}