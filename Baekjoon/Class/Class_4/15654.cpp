#include <bits/stdc++.h>
using namespace std;

void back_tracking(const vector<int>& v, int n, int m, vector<int> v2, set<int> s)
{
	if (m == 0)
	{
		for (int index : v2)
		{
			cout << v[index] << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		set<int> s2(s);
		if (s2.count(i) == 0)
		{
			s2.insert(i);
			vector<int> v3(v2);
			v3.push_back(i);
			back_tracking(v, n, m - 1, v3, s2);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> v2;
	set<int> s;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	back_tracking(v, n, m, v2, s);

	return 0;
}