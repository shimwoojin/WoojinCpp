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

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		int j;
		stack<char> stack;
		cin >> str;

		for (j = 0; j < str.size(); j++)
		{
			if (stack.empty() == true && str[j] == ')')
			{
				cout << "NO" << "\n";
				break;
			}

			if (str[j] == '(') stack.push('(');
			else if (str[j] == ')') stack.pop();
		}
		if (j == str.size())
		{
			if (stack.empty() == true)
				cout << "YES" << "\n";
			else cout << "NO" << "\n";
		}
	}




	return 0;
}