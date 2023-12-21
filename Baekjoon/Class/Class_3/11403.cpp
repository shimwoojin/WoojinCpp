#include <bits/stdc++.h>
using namespace std;

void recursive(const vector<vector<int>>& graph, vector<vector<int>>& answer, int change, int fixed)
{
	for (int j = 0; j < graph[change].size(); j++)
	{
		int node = graph[change][j];

		if (answer[fixed][node] == 0)
		{
			answer[fixed][node] = 1;
			recursive(graph, answer, node, fixed);
		}
	}
}


int main()
{
	int n;
	cin >> n;
	vector<vector<int>> graph(n, vector<int>());
	vector<vector<int>> answer(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int a;
			cin >> a;

			if (a == 1)
			{
				graph[i].push_back(j);
			}
		}
	}

	for (int i = 0; i < graph.size(); i++)
	{
		recursive(graph, answer, i, i);
	}

	for (auto a : answer)
	{
		for (int ele : a)
		{
			cout << ele << " ";
		}
		cout << '\n';
	}

	return 0;
}