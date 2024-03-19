#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
using pii = pair<int, int>;

int Solution(const vector<vector<int>>& graph, const vector<int>& build_time, int start)
{
	int answer = 0;
	vector<int> answers(build_time.size(), 0);
	queue<int> q;

	q.push(start);
	answers[start] = build_time[start];

	while (q.empty() == false)
	{
		int node = q.front();
		q.pop();

		for (int i = 0; i < graph[node].size(); i++)
		{
			int next_node = graph[node][i];

			if (answers[next_node] < answers[node] + build_time[next_node])
			{
				answers[next_node] = answers[node] + build_time[next_node];
				q.push(next_node);
			}
		}
	}

	answer = *max_element(answers.begin(), answers.end());

	return answer;
}

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;

	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> build_time(n + 1, 0);
		vector<vector<int>> graph(n + 1, vector<int>());

		for (int i = 1; i <= n; i++)
		{
			cin >> build_time[i];
		}

		for (int i = 0; i < k; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[b].push_back(a);
		}

		int start;
		cin >> start;

		cout << Solution(graph, build_time, start) << '\n';
	}

	return 0;
}