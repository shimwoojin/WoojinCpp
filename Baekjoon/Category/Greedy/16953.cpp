#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath>

using namespace std;

int main()
{
	int answer = 1;
	int a, b;
	cin >> a >> b;

	if (a == b)
	{
		cout << answer;
		return 0;
	}

	queue<long long> q;
	set<long long> s;

	q.push(a);

	while (!q.empty())
	{
		queue<long long> temp;
		bool bBreak = false;
		long long min = 10e9;

		while (!q.empty())
		{
			long long front = q.front();
			q.pop();

			long long first = front * 2;
			long long second = front * 10 + 1;

			min = std::min(min, first);
			min = std::min(min, second);

			if (first == b || second == b)
			{
				bBreak = true;
				break;
			}

			if (s.count(first) < 1 && first < b)
			{
				s.insert(first);
				temp.push(first);
			}
			if (s.count(second) < 1 && second < b)
			{
				s.insert(second);
				temp.push(second);
			}
		}

		if (bBreak)
		{
			break;
		}

		if (min > b)
		{
			cout << -1;
			return 0;
		}

		q = move(temp);
		++answer;
	}

	cout << answer + 1;

	return 0;
}