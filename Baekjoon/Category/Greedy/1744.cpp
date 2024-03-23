#include <iostream>
#include <queue>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	long long answer = 0;

	int n;
	cin >> n;
	priority_queue<int> pos_pq;
	priority_queue<int, vector<int>, greater<int>> neg_pq;
	int one = 0, zero = 0;

	while (n--)
	{
		int temp;
		cin >> temp;

		if (temp > 1)
		{
			pos_pq.push(temp);
		}
		else if (temp == 1)
		{
			++one;
		}
		else if (temp == 0)
		{
			++zero;
		}
		else
		{
			neg_pq.push(temp);
		}
	}

	while (pos_pq.empty() == false)
	{
		int top = pos_pq.top();
		pos_pq.pop();

		if (pos_pq.empty())
		{
			answer += top;
		}
		else
		{
			answer += top * pos_pq.top();
			pos_pq.pop();
		}
	}

	answer += one;

	while (neg_pq.empty() == false)
	{
		int top = neg_pq.top();
		neg_pq.pop();

		if (neg_pq.empty())
		{
			if (zero == 0)
			{
				answer += top;
			}
		}
		else
		{
			answer += top * neg_pq.top();
			neg_pq.pop();
		}
	}

	cout << answer;

	return 0;
}