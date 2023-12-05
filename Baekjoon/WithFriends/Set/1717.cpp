#include <iostream>
#include <vector>

using namespace std;

void PrintYesOrNo(bool bYes)
{
	if (bYes)
	{
		cout << "YES\n";
	}
	else
	{
		cout << "NO\n";
	}
}

int find(vector<int>& union_set, int x)
{
	if (union_set[x] == x)
	{
		return x;
	}
	return union_set[x] = find(union_set, union_set[x]);
}

void merge(vector<int>& union_set, int x, int y)
{
	x = find(union_set, x);
	y = find(union_set, y);
	if (x == y)
	{
		return;
	}
	union_set[y] = x;
}

int main()
{
	//start : 15:06
	//end : 15:25

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<int> union_set(n + 1, 0);

	for (int i = 0; i < n + 1; i++)
	{
		union_set[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int x, a, b;
		cin >> x >> a >> b;
		
		if (x == 0)
		{
			merge(union_set, a, b);
		}
		else
		{
			if (find(union_set, a) == find(union_set, b))
			{
				PrintYesOrNo(true);
			}
			else
			{
				PrintYesOrNo(false);
			}
		}
	}

	return 0;
}