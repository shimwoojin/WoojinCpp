#include <bits/stdc++.h>

using namespace std;

struct Load
{
	int to;
	int cost;
};

bool operator>(const Load& lhs, const Load& rhs)
{
	return lhs.cost > rhs.cost;
}

void dijkstra(int n, int x, const vector<vector<Load>>& graph, vector<int>& distance)
{
	priority_queue<Load, vector<Load>, greater<Load>> pq;
	distance.assign(n + 1, INT_MAX);
	distance[x] = 0;

	pq.push(Load{x, 0});

	while (!pq.empty())
	{
		Load now = pq.top();
		pq.pop();

		/*
			핵심로직

			1. 현재 노드를 기준으로 방문할 수 있는 노드를 전부 순회
			2. 현재 노드에서 길을 따라 갔을 때 그 노드의 값보다 싸다면 값을 갱신한다.
			3. 갱신하는 경우 갱신된 값을 기준으로 distance 혹은 cost를 설정한 값을 pq에 넣어준다.

			! pq에 들어가는 cost는 [노드 -> 노드]로 이동할 때의 cost가 아닌 현재 갱신된 distance 값을 기준으로 한다.
		*/
		for (auto next : graph[now.to])
		{
			if (distance[next.to] > distance[now.to] + next.cost)
			{
				distance[next.to] = distance[now.to] + next.cost;
				pq.push( Load {next.to, distance[next.to]} );
			}
		}
	}
}

int main()
{
	//start:15:25
	//end:16:50
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m, x;
	cin >> n >> m >> x;
	vector<vector<Load>> graph(n + 1, vector<Load>());
	vector<int> answers(n + 1, 0);
	vector<int> distance;

	for (int i = 0; i < m; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;

		Load load{ to, cost };

		graph[from].push_back(load);
	}

	dijkstra(n, x, graph, distance);

	for (int i = 1; i <= n; i++)
	{
		answers[i] += distance[i];
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == x)
		{
			continue;
		}

		dijkstra(n, i, graph, distance);

		answers[i] += distance[x];
	}

	cout << *max_element(answers.begin() + 1, answers.end());

	return 0;
}