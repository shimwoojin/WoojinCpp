#include <bits/stdc++.h>
using namespace std;

int main()
{
	priority_queue<pair<int, bool>, vector<pair<int, bool>>, greater<pair<int, bool>>> pq;

	int n;
	cin >> n;
	vector<int> answer;

	while (n--)
	{
		int a;
		cin >> a;
		
		if (a == 0)
		{
			if (pq.empty())
			{
				answer.push_back(0);
			}
			else
			{
				auto top = pq.top();
				if (top.second == false)
				{
					top.first = -top.first;
				}
				pq.pop();
				answer.push_back(top.first);
			}
		}
		else
		{
			if (a > 0)
			{
				pq.push({abs(a), true});
			}
			else
			{
				pq.push({abs(a), false});
			}
		}
	}

	for (int ele : answer)
	{
		cout << ele << '\n';
	}

	return 0;
}