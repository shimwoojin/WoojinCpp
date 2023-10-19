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

	deque<int> queue;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		if (str == "push_front")
		{
			int a;
			cin >> a;

			queue.push_front(a);
		}
		else if (str == "push_back")
		{
			int a;
			cin >> a;

			queue.push_back(a);
		}
		else if (str == "front")
		{
			if (queue.empty() == false)
			{
				cout << queue.front() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "pop_front")
		{
			if (queue.empty() == false)
			{
				cout << queue.front() << "\n";
				queue.pop_front();
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (str == "pop_back")
		{
			if (queue.empty() == false)
			{
				cout << queue.back() << "\n";
				queue.pop_back();
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