#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int BFS(vector<vector<int>> vec, vector<int> visit, int start, int target)
{
	int depth = 0;

	visit[start] = 1;
	queue<int> q;
	q.push(start);

	while (q.empty() == false)
	{
		for (int i = 0; i < q.size(); i++)
		{
			int node = q.front();
			q.pop();

			if (node == target) return depth;

			for (int i = 0; i < vec.size(); i++)
			{
				if (vec[node][i] == 1 && visit[i] == 0)
				{
					visit[i] = 1;
					q.push(i);
				}
			}
		}

		++depth;
	}

	return depth;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> vec(n, vector<int>(n));

	auto make_link = [](vector<vector<int>>& vec, int a, int b) 
	{
		vec[a - 1][b - 1] = 1;
		vec[b - 1][a - 1] = 1;
	};

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		make_link(vec, a, b);
	}
	
	vector<pair<int, int>> result;

	for (int i = 0; i < n; i++)
	{
		int sum = 0;

		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;

			vector<int> visit(n);
			sum += BFS(vec, visit, i, j);
		}

		result.push_back(make_pair(sum, i));
	}

	sort(result.begin(), result.end());

	cout << result[0].second + 1;

	return 0;
}
