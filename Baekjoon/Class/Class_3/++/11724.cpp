#include <bits/stdc++.h>

using namespace std;

int dfs(const vector<vector<int>>& graph, vector<bool>& visit, int start)
{
	if (visit[start])
	{
		return 0;
	}

	stack<int> s;
	
	s.push(start);
	visit[start] = true;

	while (!s.empty())
	{
		int top = s.top();
		s.pop();
		
		for (int i = 0; i < graph[top].size(); i++)
		{
			int node = graph[top][i];
			if (visit[node] == false)
			{
				visit[node] = true;
				s.push(node);
			}
		}
	}

	return 1;
}

int connected_component(const vector<vector<int>>& graph, vector<bool>& visit)
{
	int count = 0;
	for (int i = 1; i < graph.size(); i++)
	{
		count += dfs(graph, visit, i);
	}
	return count;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<bool> visit(n + 1, false);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cout << connected_component(graph, visit);

	return 0;
}