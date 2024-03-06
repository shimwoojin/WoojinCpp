#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 2'000'000'000;

int Dijkstra(const vector<vector<pii>>& graph, int start, int end)
{
	int answer = 0;
	vector<int> lengths(graph.size(), INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	lengths[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		pii top = pq.top();
		pq.pop();

		int length = top.first;
		int vertex = top.second;

		if (length > lengths[vertex]) continue;

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			int n_vertex = graph[vertex][i].first;
			int n_length = graph[vertex][i].second;

			if (lengths[n_vertex] > length + n_length)
			{
				lengths[n_vertex] = length + n_length;
				pq.push({ lengths[n_vertex], n_vertex });
			}
		}
	}

	answer = lengths[end];

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	int temp = m;
	vector<vector<pii>> graph(n + 1, vector<pii>());

	while (temp--)
	{
		int start, end, cost;
		cin >> start >> end >> cost;

		graph[start].push_back({end, cost});
	}
	
	int start, end;
	cin >> start >> end;

	cout << Dijkstra(graph, start, end);

	return 0;
}