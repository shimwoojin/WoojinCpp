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

bool DFS(vector<vector<int>>& Field, int& Count)
{
	int Row = -1, Column = -1;
	stack<pair<int, int>> Stack;

	for (int i = 0; i < Field.size(); i++)
	{
		for (int j = 0; j < Field[0].size(); j++)
		{
			if (Field[i][j] == 1)
			{
				Row = i;
				Column = j;
				break;
			}
		}
	}

	if (Row == -1)
	{
		return false;
	}

	Stack.push(make_pair(Row, Column));

	while (Stack.empty() == false)
	{
		pair<int, int> Top = Stack.top();
		Stack.pop();
		if (Field[Top.first][Top.second] == 1)
		{
			Field[Top.first][Top.second] = 0;
			++Count;
		}

		if (Top.second > 0)	//Left
		{
			if (Field[Top.first][Top.second - 1] == 1)
			{
				Stack.push(make_pair(Top.first, Top.second - 1));
			}
		}

		if (Top.first > 0)	//Up
		{
			if (Field[Top.first - 1][Top.second] == 1)
			{
				Stack.push(make_pair(Top.first - 1, Top.second));
			}
		}

		if (Top.second < Field[0].size() - 1)	//Right
		{
			if (Field[Top.first][Top.second + 1] == 1)
			{
				Stack.push(make_pair(Top.first, Top.second + 1));
			}
		}

		if (Top.first < Field.size() - 1)	//Up
		{
			if (Field[Top.first + 1][Top.second] == 1)
			{
				Stack.push(make_pair(Top.first + 1, Top.second));
			}
		}
	}

	return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, Count = 0, Result = 0;
	vector<int> Houses;
	cin >> N;
	vector<vector<int>> Field(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		string Numbers;
		cin >> Numbers;

		for (int j = 0; j < Numbers.size(); j++)
		{
			string Number = { Numbers[j] };
			Field[i][j] = stoi(Number);
		}
	}

	while (DFS(Field, Count))
	{
		++Result;
		Houses.push_back(Count);
		Count = 0;
	}

	sort(Houses.begin(), Houses.end());

	cout << Result << "\n";
	for (int i = 0; i < Houses.size(); i++)
	{
		cout << Houses[i] << "\n";
	}

	return 0;
}