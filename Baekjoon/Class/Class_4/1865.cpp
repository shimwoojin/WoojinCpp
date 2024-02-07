#include <bits/stdc++.h>
using namespace std;
#define INF 2000000000

bool BellmanFord(const vector<vector<pair<int, int>>>& graph, int start_vertex)
{
	bool result = false;

	int size = graph.size();
	vector<int> distances(size, INF);
	distances[start_vertex] = 0;

	for (int i = 1; i < size; i++)
	{
		for (int j = 1; j < graph.size(); j++)
		{
			for (int k = 0; k < graph[j].size(); k++)
			{
				int next = graph[j][k].first;
				int weight = graph[j][k].second;

				if (distances[next] > distances[j] + weight)
				{
					distances[next] = distances[j] + weight;
					if (i == size - 1)
					{
						return true;
					}
				}
			}
		}
	}

	if (distances[start_vertex] < 0)
	{
		result = true;
	}

	return result;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int TC;
	cin >> TC;

	while (TC--)
	{
		int N, M, W;
		cin >> N >> M >> W;
		vector<vector<pair<int, int>>> graph(N + 1, vector<pair<int, int>>());

		for (int i = 0; i < M; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;

			graph[S].push_back(make_pair(E, T));
			graph[E].push_back(make_pair(S, T));
		}

		for (int i = 0; i < W; i++)
		{
			int S, E, T;
			cin >> S >> E >> T;

			graph[S].push_back(make_pair(E, -T));
		}

		bool result = BellmanFord(graph, 1);

		if (result)
		{
			cout << "YES" << '\n';
		}
		else
		{
			cout << "NO" << '\n';
		}
	}

	return 0;
}