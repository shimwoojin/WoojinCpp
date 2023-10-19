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

	priority_queue<int> q;

	q.push(3);
	q.push(2);
	q.push(3);
	q.push(5);
	q.push(4);

	while (q.empty() == false)
	{
		cout << q.top() << " ";
		q.pop();
	}

	return 0;
}