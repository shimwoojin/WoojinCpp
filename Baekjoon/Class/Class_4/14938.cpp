#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pii = pair<int, int>;
constexpr int INF = 2'000'000'000;

int dijkstra(const vector<vector<pii>>& graph, int start, int m, const vector<int>& items)
{
	int answer = 0;
	vector<int> lengths(graph.size(), INF);
	priority_queue<pii, vector<pii>, greater<pii>> pq;

	lengths[start] = 0;
	pq.push(make_pair(0, start));

	while (pq.empty() == false)
	{
		pii top = pq.top();
		int length = top.first;
		int node = top.second;
		pq.pop();

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next_length = graph[node][i].first;
			int next_node = graph[node][i].second;

			if (lengths[next_node] > length + next_length)
			{
				lengths[next_node] = length + next_length;
				pq.push(make_pair(lengths[next_node], next_node));
			}
		}
	}

	for (int i = 1; i < lengths.size(); i++)
	{
		if (lengths[i] <= m)
		{
			answer += items[i];
		}
	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0;
	int n, m, r;
	cin >> n >> m >> r;
	vector<int> items(1, 0);
	vector<vector<pii>> graph(n + 1, vector<pii>());

	int temp = n;

	while (temp--)
	{
		int temp;
		cin >> temp;
		items.push_back(temp);
	}

	while (r--)
	{
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back( {l,b} );
		graph[b].push_back( {l,a} );
	}

	for (int start = 1; start <= n; start++)
	{
		answer = max(answer, dijkstra(graph, start, m, items));
	}

	cout << answer;

	return 0;
}