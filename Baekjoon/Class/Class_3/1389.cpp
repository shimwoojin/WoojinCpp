#include <bits/stdc++.h>
using namespace std;

void cavin_bacon(const vector<vector<int>>& graph, vector<pair<int,int>>& results)
{
	for (int i = 1; i < graph.size(); i++)
	{
		vector<bool> visit(graph.size() + 1, false);
		queue<int> q;
		int count = 0;
		int bacon = 1;

		q.push(i);
		visit[i] = true;

		while (!q.empty())
		{
			queue<int> temp;
			while (!q.empty())
			{
				int front = q.front();
				q.pop();

				for (int ele : graph[front])
				{
					if (visit[ele] == false)
					{
						temp.push(ele);
						visit[ele] = true;
						count += bacon;
					}
				}
			}

			q = move(temp);
			++bacon;
		}

		results.push_back(make_pair(count, i));
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n + 1, vector<int>());
	vector<pair<int, int>> results;

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	cavin_bacon(graph, results);

	sort(results.begin(), results.end());
	cout << results[0].second;

	return 0;
}