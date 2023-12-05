#include <iostream>
#include <queue>
#include <set>

using namespace std;

int main()
{
	int answer = 0;
	queue<int> bfs;
	set<int> s;
	int n, k;
	cin >> n >> k;

	bfs.push(n);

	while (!bfs.empty())
	{
		queue<int> temp;
		bool bBreak = false;

		while (!bfs.empty())
		{
			int front = bfs.front();
			bfs.pop();
			
			if (front == k)
			{
				bBreak = true;
				break;
			}

			int a = front - 1;
			int b = front + 1;
			int c = front * 2;

			if (s.count(a) < 1 && a >= 0 && a <= 200000)
			{
				temp.push(a);
				s.insert(a);
			}
			if (s.count(b) < 1 && b >= 0 && b <= 200000)
			{
				temp.push(b);
				s.insert(b);
			}
			if (s.count(c) < 1 && c >= 0 && c <= 200000)
			{
				temp.push(c);
				s.insert(c);
			}
		}

		if (bBreak)
		{
			break;
		}

		++answer;

		bfs = move(temp);
	}

	cout << answer;

	return 0;
}