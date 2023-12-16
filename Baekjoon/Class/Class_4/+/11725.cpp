#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<int>& parents)
{
	queue<int> q;
	vector<int> visit(graph.size(), false);

	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = 0; i < graph[front].size(); i++)
		{
			int node = graph[front][i];

			if (visit[node] == false)
			{
				parents[node] = front;
				q.push(node);
				visit[node] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<int> parents(n + 1, 0);

	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(graph, parents);

	for (int i = 2; i < parents.size(); i++)
	{
		cout << parents[i] << '\n';
	}

	return 0;
}