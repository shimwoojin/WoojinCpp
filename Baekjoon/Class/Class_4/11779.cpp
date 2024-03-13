#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>
using namespace std;

using pii = pair<int, int>;

struct Bus
{
	int start, end, cost;
};

int Dijkstra(const vector<vector<Bus>>& graph, int start, int end, vector<int>& paths)
{
	vector<int> costs(graph.size(), INT_MAX);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	costs[start] = 0;
	pq.push({0, start});

	while (pq.empty() == false)
	{
		pii top = pq.top();
		pq.pop();

		int cost = top.first;
		int now = top.second;

		if (costs[now] < cost) continue;

		for (int i = 0; i < graph[now].size(); i++)
		{
			Bus next = graph[now][i];

			if (next.cost + cost < costs[next.end])
			{
				costs[next.end] = next.cost + cost;
				paths[next.end] = now;
				pq.push({costs[next.end], next.end});
			}
		}
	}

	return costs[end];
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<Bus>> graph(n + 1, vector<Bus>());
	vector<int> paths(graph.size(), 0);

	while (m--)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		graph[start].push_back({start, end, cost});
	}

	int start, end;
	cin >> start >> end;

	cout << Dijkstra(graph, start, end, paths) << '\n';

	int now = end;
	stack<int> s;
	s.push(end);

	while (paths[now] > 0)
	{
		now = paths[now];
		s.push(now);
	}

	cout << s.size() << '\n';
	
	while (s.empty() == false)
	{
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}