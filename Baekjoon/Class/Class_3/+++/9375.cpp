#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int answer = 1;
		map<string, int> m;
		int n;
		cin >> n;

		for (int j = 0; j < n; j++)
		{
			string str1, str2;
			cin >> str1 >> str2;
			++m[str2];
		}

		for (auto ele : m)
		{
			answer *= (ele.second + 1);
		}

		cout << answer - 1 << '\n';
	}

	return 0;
}