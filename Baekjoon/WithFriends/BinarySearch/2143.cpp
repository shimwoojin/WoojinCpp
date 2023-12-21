#include <bits/stdc++.h>
using namespace std;

int main()
{
	//start : 13:55
	//end : 14:14

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	long long answer = 0;

	int T;
	cin >> T;

	int n, m;
	cin >> n;
	vector<int> A(n + 1, 0);
	for (int i = 1; i <= n; i++)
	{
		int a;
		cin >> a;
		A[i] = A[i - 1] + a;
	}
	cin >> m;
	vector<int> B(m + 1, 0);
	for (int i = 1; i <= m; i++)
	{
		int b;
		cin >> b;
		B[i] = B[i - 1] + b;
	}

	map<int, int> m_A;
	map<int, int> m_B;

	for (int i = 0; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			m_A[A[j] - A[i]]++;
		}
	}

	for (int i = 0; i <= m; i++)
	{
		for (int j = i + 1; j <= m; j++)
		{
			m_B[B[j] - B[i]]++;
		}
	}

	for (auto ele : m_A)
	{
		int a = ele.first;
		int b = T - a;
		int a_num = ele.second;

		if (m_B.count(b) > 0)
		{
			answer += (long long)a_num* m_B[b];
		}
	}

	cout << answer;

	return 0;
}