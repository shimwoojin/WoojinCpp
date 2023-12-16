#include <bits/stdc++.h>
using namespace std;

void back_tracking(int n, int m, const vector<int>& v, vector<int> v2, set<int> s, int m2)
{
	if (m == 0)
	{
		if (v2.size() == m2)
		{
			for (int i = 0; i < m2; i++)
			{
				cout << v2[i] << " ";
			}
			cout << '\n';
		}

		return;
	}

	int before = 0;

	for (int i = 0; i < n; i++)
	{
		set<int> s2(s);
		vector<int> v3(v2);

		if (s.count(i) == 0 && before != v[i])
		{
			v3.push_back(v[i]);
			s2.insert(i);
			before = v[i];
			back_tracking(n, m - 1, v, v3, s2, m2);
		}
		else
		{
			continue;
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> temp;
	set<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	back_tracking(n, m, v, temp, s, m);

	return 0;
}