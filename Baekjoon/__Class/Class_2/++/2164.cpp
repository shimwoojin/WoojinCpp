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

	for (int i = 1; i <= n; i++)
	{
		queue.push(i);
	}

	int top = 0;

	while (queue.empty() == false)
	{
		top = queue.front();
		queue.pop();

		if (queue.empty() == true) break;

		top = queue.front();
		queue.push(queue.front());
		queue.pop();
	}

	cout << top;

	return 0;
}