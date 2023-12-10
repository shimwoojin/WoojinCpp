#include <bits/stdc++.h>
using namespace std;

using p_ii = pair<int, int>;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k, e;
	cin >> k >> e;	//k : 정점의 개수, e : 간선의 개수

	int start;
	cin >> start;

	vector<vector<pair<int, int>>> graph(k + 1, vector<pair<int, int>>());
	vector<int> distances(k + 1, INT_MAX);
	priority_queue<p_ii, vector<p_ii>, greater<p_ii>> pq;

	for (int i = 0; i < e; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		graph[u].push_back({v,w});
	}

	distances[start] = 0;
	pq.push(make_pair(0, start));

	int weight;
	int cur_node;
	int next_node;
	int next_weight;

	while (!pq.empty())
	{
		weight = pq.top().first;
		cur_node = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur_node].size(); i++)
		{
			next_node = graph[cur_node][i].first;
			next_weight = graph[cur_node][i].second;

			if (distances[next_node] > weight + next_weight)
			{
				distances[next_node] = weight + next_weight;

				pq.push(make_pair(distances[next_node], next_node));
			}
		}
	}

	for (int i = 1; i <= k; i++)
	{
		if (distances[i] == INT_MAX)
		{
			cout << "INF" << '\n';
		}
		else
		{
			cout << distances[i] << '\n';
		}
	}

	return 0;
}