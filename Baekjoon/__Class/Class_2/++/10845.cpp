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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	queue<int> queue;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push")
		{
			int a;
			cin >> a;

			queue.push(a);
		}
		else if (str == "front")
		{
			if (queue.empty() == false)
			{
				cout << queue.front() <<"\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "pop")
		{
			if (queue.empty() == false)
			{
				cout << queue.front() << "\n";
				queue.pop();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "size")
		{
			cout << queue.size() << "\n";
		}
		else if (str == "empty")
		{
			if (queue.empty() == false)
			{
				cout << 0 << "\n";
			}
			else cout << 1 << "\n";
		}
		else if (str == "back")
		{
			if (queue.empty() == false)
			{
				cout << queue.back() << "\n";
			}
			else cout << -1 << "\n";
		}
	}

	return 0;
}