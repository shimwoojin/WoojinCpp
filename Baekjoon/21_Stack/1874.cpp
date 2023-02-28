#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<int> stack;
	queue<char> queue;
	int i;
	int count = 0;
	int n;
	cin >> n;

	for (i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		while (count < a)
		{
			++count;
			stack.push(count);
			queue.push('+');
		}

		if (stack.top() == a)
		{
			queue.push('-');
			stack.pop();
		}
		else break;
	}

	if (i == n)
	{
		while (queue.empty() == false)
		{
			cout << queue.front() << "\n";
			queue.pop();
		}
	}
	else
		cout << "NO";


	return 0;
}