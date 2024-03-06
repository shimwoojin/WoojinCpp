#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;

constexpr int INF = 2'000'000'000;

int Dijkstra(const vector<vector<pii>>& graph, int start, int end, bool& bError)
{
	int answer = 0;
	vector<int> lengths(graph.size(), INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	lengths[start] = 0;
	pq.push({0, start});
	
	while (!pq.empty())
	{
		pii top = pq.top();
		pq.pop();

		int length = top.first;
		int vertex = top.second;

		for (int i = 0; i < graph[vertex].size(); i++)
		{
			int n_vertex = graph[vertex][i].first;
			int n_length = graph[vertex][i].second;

			if (lengths[n_vertex] > length + n_length)
			{
				lengths[n_vertex] = length + n_length;
				pq.push({lengths[n_vertex], n_vertex});
			}
		}
	}

	answer = lengths[end];

	if (answer == INF)
	{
		bError = true;
	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, e;
	cin >> n >> e;
	vector<vector<pii>> graph (n + 1, vector<pii>());

	while (e--)
	{
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].push_back({b,c});
		graph[b].push_back({a,c});
	}

	int v1, v2;
	cin >> v1 >> v2;

	bool ErrorCheck1 = false, ErrorCheck2 = false, ErrorCheck3 = false;
	bool ErrorCheck4 = false, ErrorCheck5 = false, ErrorCheck6 = false;
	int answer1 = Dijkstra(graph, 1, v1, ErrorCheck1) + Dijkstra(graph, v1, v2, ErrorCheck2) + Dijkstra(graph, v2, n, ErrorCheck3);
	int answer2 = Dijkstra(graph, 1, v2, ErrorCheck4) + Dijkstra(graph, v2, v1, ErrorCheck5) + Dijkstra(graph, v1, n, ErrorCheck6);

	if (ErrorCheck1 || ErrorCheck2 || ErrorCheck3)
	{
		cout << -1;
	}
	else
	{
		cout << (answer1 > answer2 ? answer2: answer1);
	}

	return 0;
}