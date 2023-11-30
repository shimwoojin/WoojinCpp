#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int main()
{
	long long answer = 0;
	set<long long> s;
	queue<long long> q;
	long long h;
	int a, b, c;
	cin >> h >> a >> b >> c;

	q.push(a);
	q.push(b);
	q.push(c);

	while (!q.empty())
	{
		long long front = q.front();
		q.pop();
		++answer;
		
		if (front + a <= h && s.count(front + a) < 1)
		{
			s.insert(front + a);
			q.push(front + a);
		}
		if (front + b <= h && s.count(front + b) < 1)
		{
			s.insert(front + b);
			q.push(front + b);
		}
		if (front + c <= h && s.count(front + c) < 1)
		{
			s.insert(front + c);
			q.push(front + c);
		}
	}


	cout << answer << endl;

	return 0;
}