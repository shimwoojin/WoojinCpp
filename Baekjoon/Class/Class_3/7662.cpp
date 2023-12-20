#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		int k;
		cin >> k;
		multiset<int> ms;

		while (k--)
		{
			char c;
			int n;
			cin >> c >> n;

			if (c == 'I')
			{
				ms.insert(n);
			}
			else
			{
				if (ms.empty())
				{
					continue;
				}

				if (n == -1)
				{
					ms.erase(ms.begin());
				}
				else
				{
					auto iter = ms.end();
					ms.erase(--iter);
				}
			}
		}

		if (ms.empty())
		{
			cout << "EMPTY" << '\n';
		}
		else
		{
			cout << *(--ms.end()) << " " << *ms.begin() << '\n';
		}
	}

	return 0;
}