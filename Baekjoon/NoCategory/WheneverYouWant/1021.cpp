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
#include <deque>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	int Count = 0;
	deque<int> Deque;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		Deque.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		int Num;
		int Index = 0;
		int Middle = Deque.size() / 2 + Deque.size() % 2;
		cin >> Num;

		for (int j = 0; j < Deque.size(); j++)
		{
			if (Deque[j] == Num)
			{
				Index = j;
				break;
			}
		}

		if (Index < Middle)
		{
			for (int i = 0; i < Index; i++)
			{
				++Count;
				int First = Deque[0];
				Deque.pop_front();
				Deque.push_back(First);
			}
		}
		else
		{
			for (int i = 0; i < Deque.size() - Index; i++)
			{
				++Count;
				int Last = Deque.back();
				Deque.pop_back();
				Deque.push_front(Last);
			}
		}

		Deque.pop_front();
	}

	cout << Count;

	return 0;
}