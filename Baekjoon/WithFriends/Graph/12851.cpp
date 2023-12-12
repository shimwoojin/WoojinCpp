#include <iostream>
#include <queue>
#include <set>
#include <unordered_set>

using namespace std;

void bfs(int n, int k, int& time, int& cases)
{
	queue<int> q;
	unordered_set<int> s;

	q.push(n);

	if (n == k)
	{
		time = 0;
		cases = 1;
		return;
	}

	while(!q.empty())
	{
		queue<int> temp;
		bool bBreak = false;
		unordered_set<int> ss;

		while (!q.empty())
		{
			int front = q.front();
			q.pop();

			int case1 = front - 1;
			int case2 = front + 1;
			int case3 = front * 2;

			if (front == k)
			{
				bBreak = true;
				++cases;
			}

			if (s.count(case1) < 1 && case1 <= 200000 && case1 >= 0)
			{
				temp.push(case1);
				ss.insert(case1);
			}
			if (s.count(case2) < 1 && case2 <= 200000 && case2 >= 0)
			{
				temp.push(case2);
				ss.insert(case2);
			}
			if (s.count(case3) < 1 && case3 <= 200000 && case3 >= 0)
			{
				temp.push(case3);
				ss.insert(case3);
			}
		}

		if (bBreak)
		{
			break;
		}

		++time;
		q = move(temp);
		s.insert(ss.begin(), ss.end());
	}
}

int main()
{
	//start: 11:13
	//end: 11:40

	int time = 0, cases = 0;
	int n, k;
	cin >> n >> k;

	bfs(n, k, time, cases);

	cout << time << endl;
	cout << cases << endl;

	return 0;
}