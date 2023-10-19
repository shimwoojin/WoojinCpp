#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	stack<int> stack;
	int sum = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		if (a == 0) stack.pop();
		else stack.push(a);
	}

	while(stack.empty() == false)
	{
		sum += stack.top();
		stack.pop();
	}

	cout << sum;

	return 0;
}