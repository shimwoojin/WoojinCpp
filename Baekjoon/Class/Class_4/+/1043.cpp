#include <bits/stdc++.h>
using namespace std;

int find(vector<int>& union_find, int x) {
	if (union_find[x] == x) return x;
	return union_find[x] = find(union_find, union_find[x]);
}

void merge(vector<int>& union_find, int x, int y) {
	x = find(union_find, x);
	y = find(union_find, y);
	if (x == y) return;
	union_find[y] = x;
}

int main()
{
	int answer = 0;
	int n, m;
	cin >> n >> m;
	vector<int> union_set(n + 1, 0);
	vector<vector<int>> parties(m, vector<int>());

	for (int i = 0; i < n + 1; i++)
	{
		union_set[i] = i;
	}

	int trues;
	cin >> trues;

	set<int> knows;

	int parent = 0;

	for (int i = 0; i < trues; i++)
	{
		if (i == 0)
		{
			cin >> parent;
		}
		else
		{
			int a;
			cin >> a;
			merge(union_set, parent, a);
		}
	}

	

	for (int i = 0; i < m; i++)
	{
		int sub_parent = 0;
		int nums;
		cin >> nums;

		for (int j = 0; j < nums; j++)
		{
			if (j == 0)
			{
				cin >> sub_parent;
				parties[i].push_back(sub_parent);
			}
			else
			{
				int a;
				cin >> a;
				merge(union_set, sub_parent, a);
				parties[i].push_back(a);
			}
		}
	}

	if (parent == 0)
	{
		cout << m;
	}
	else
	{
		for (auto& party : parties)
		{
			bool bLie = true;

			for (int p : party)
			{
				if (find(union_set, parent) == find(union_set, p))
				{
					bLie = false;
					break;
				}
			}

			if (bLie)
			{
				++answer;
			}
		}

		cout << answer;
	}

	return 0;
}