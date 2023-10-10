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

void DFS(vector<vector<int>>& Graph, vector<bool>& Visited, int V)
{
	stack<int> Stack_DFS;

	sort(Graph[V - 1].begin(), Graph[V - 1].end(), greater<int>());

	for (int i = 0; i < Graph[V - 1].size(); i++)
	{
		Stack_DFS.push(Graph[V - 1][i]);
	}
	
	Visited[V - 1] = true;
	cout << V << " ";

	while (Stack_DFS.empty() == false)
	{
		int Top = Stack_DFS.top();
		Stack_DFS.pop();

		if (Visited[Top - 1] == false)
		{
			Visited[Top - 1] = true;
			cout << Top << " ";
		}
		
		sort(Graph[Top - 1].begin(), Graph[Top - 1].end(), greater<int>());

		for (int i = 0; i < Graph[Top - 1].size(); i++)
		{
			if (Visited[Graph[Top - 1][i] - 1] == false)
			{
				Stack_DFS.push(Graph[Top - 1][i]);
			}
		}
	}
}

void BFS(vector<vector<int>>& Graph, vector<bool>& Visited, int V)
{
	queue<int> Queue_BFS;

	sort(Graph[V - 1].begin(), Graph[V - 1].end(), less<int>());

	for (int i = 0; i < Graph[V - 1].size(); i++)
	{
		Queue_BFS.push(Graph[V - 1][i]);
	}

	Visited[V - 1] = true;
	cout << V << " ";

	while (Queue_BFS.empty() == false)
	{
		int Front = Queue_BFS.front();
		Queue_BFS.pop();

		if (Visited[Front - 1] == false)
		{
			Visited[Front - 1] = true;
			cout << Front << " ";
		}

		sort(Graph[Front - 1].begin(), Graph[Front - 1].end(), less<int>());

		for (int i = 0; i < Graph[Front - 1].size(); i++)
		{
			if (Visited[Graph[Front - 1][i] - 1] == false)
			{
				Queue_BFS.push(Graph[Front - 1][i]);
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//Start : 19:00
	//End : 19:46

	int N, M, V;
	vector<vector<int>> Graph(1000, vector<int>());
	cin >> N >> M >> V;
	vector<bool> Visited(N, 0);

	for (int i = 0; i < M; i++)
	{
		int First, Second;
		cin >> First >> Second;
		Graph[First - 1].push_back(Second);
		Graph[Second - 1].push_back(First);
	}

	DFS(Graph, Visited, V);

	Visited.clear();
	Visited.assign(N, 0);
	cout << "\n";

	BFS(Graph, Visited, V);

	return 0;
}