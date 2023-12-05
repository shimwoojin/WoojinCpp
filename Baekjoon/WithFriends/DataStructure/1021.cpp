#include <bits/stdc++.h>
using namespace std;

int main()
{
	//start : 18:37
	//end : 18:50

	int answer = 0;
	int n, m;
	cin >> n >> m;

	deque<int> dq;
	for (int i = 1; i <= n; i++)
	{
		dq.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int find_ele;
		cin >> find_ele;
		int index_gap = 0;

		for (auto iter = dq.begin(); iter != dq.end(); iter++)
		{
			if (find_ele == *iter)
			{
				index_gap = iter - dq.begin();
				break;
			}
		}

		if (index_gap > dq.size() / 2)
		{
			while (dq.front() != find_ele)
			{
				dq.push_front(dq.back());
				dq.pop_back();
				++answer;
			}
		}
		else
		{
			while (dq.front() != find_ele)
			{
				dq.push_back(dq.front());
				dq.pop_front();
				++answer;
			}
		}

		dq.pop_front();
	}

	cout << answer;

	return 0;
}