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

			stack.push(a);
		}
		else if (str == "top")
		{
			if (stack.empty() == true) cout << -1 << "\n";
			else cout << stack.top() << "\n";
		}
		else if (str == "pop")
		{
			if (stack.empty() == true) cout << -1 << "\n";
			else
			{
				cout << stack.top() << "\n";
				stack.pop();
			}
		}
		else if (str == "size")
		{
			cout << stack.size() << "\n";
		}
		else if (str == "empty")
		{
			if (stack.empty() == true) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
	}

	return 0;
}