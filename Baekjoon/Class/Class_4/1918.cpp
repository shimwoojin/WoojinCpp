#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

int main()
{
	string s, answer;
	map<char, int> m;
	cin >> s;

	stack<char> st;

	m['('] = 0;
	m[')'] = 0;
	m['+'] = 1;
	m['-'] = 1;
	m['*'] = 2;
	m['/'] = 2;

	for (int i = 0; i < s.size(); i++)
	{
		if(s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
		{
			while (st.empty() == false && m[st.top()] >= m[s[i]])
			{
				answer += st.top();
				st.pop();
			}
			st.push(s[i]);
		}
		else if (s[i] == '(' || s[i] == ')')
		{
			if (s[i] == '(')
			{
				st.push(s[i]);
			}
			else
			{
				while (true)
				{
					char temp = st.top();
					st.pop();
					if (temp == '(') break;
					answer += temp;
				}
			}
		}
		else
		{
			answer += s[i];
		}
	}

	while (st.empty() == false)
	{
		answer += st.top();
		st.pop();
	}

	cout << answer;

	return 0;
}