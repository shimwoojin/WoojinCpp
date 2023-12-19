#include <bits/stdc++.h>
using namespace std;

void back_tracking(int n, int m, const vector<int>& v, int start, vector<int> v2)
{
	if (m == 0)
	{
		for (int ele : v2)
		{
			cout << ele << " ";
		}
		cout << '\n';
		return;
	}

	for (int i = start; i < n; i++)
	{
		vector<int> v3(v2);
		v3.push_back(v[i]);
		back_tracking(n, m - 1, v, i, v3);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	vector<int> temp;

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	back_tracking(n, m, v, 0, temp);

	return 0;
}