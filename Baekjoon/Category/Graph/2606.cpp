#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<bool> visit(n + 1, false);
	stack<int> dfs;
	int count = 0;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	visit[1] = true;
	for (int i = 0; i < graph[1].size(); i++)
	{
		int node = graph[1][i];

		if (visit[node] == false)
		{
			dfs.push(node);
			visit[node] = true;
		}
	}

	while (!dfs.empty())
	{
		int top = dfs.top();
		dfs.pop();

		++count;

		for (int i = 0; i < graph[top].size(); i++)
		{
			int node = graph[top][i];

			if (visit[node] == false)
			{
				dfs.push(node);
				visit[node] = true;
			}
		}
	}

	cout << count;

	return 0;
}