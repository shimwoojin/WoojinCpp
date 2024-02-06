#include <bits/stdc++.h>
using namespace std;

pair<int, int> dfs(const vector<vector<pair<int, int>>>& graph, int vertex)
{
	int furthest = 0;
	int diameter = 0;

	stack<pair<int, int>> stk;
	vector<bool> visit(graph.size() + 1, false);

	stk.push(make_pair(vertex, 0));
	visit[vertex] = true;

	while (!stk.empty())
	{
		int current = stk.top().first;
		int accum_length = stk.top().second;
		stk.pop();

		int before_diameter = diameter;
		diameter = max(diameter, accum_length);
		if (before_diameter != diameter)
		{
			furthest = current;
		}

		for (const auto& ele : graph[current])
		{
			int next = ele.first;
			int length = ele.second;

			if (visit[next] == false)
			{
				visit[next] = true;
				stk.push(make_pair(next, accum_length + length));
			}
		}
	}

	return make_pair(furthest, diameter);
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0;
	int v;
	cin >> v;
	vector<vector<pair<int, int>>> graph(v + 1, vector<pair<int, int>>());
	set<int> vertices;

	while (v--)
	{
		int n1, n2, length;
		cin >> n1;

		while (true)
		{
			cin >> n2;
			if (n2 == -1)
			{
				break;
			}

			cin >> length;
			graph[n1].push_back(make_pair(n2, length));
		}
	}

	pair<int, int> first_dfs = dfs(graph, 1);
	pair<int, int> second_dfs = dfs(graph, first_dfs.first);
	answer = second_dfs.second;

	cout << answer;

	return 0;
}