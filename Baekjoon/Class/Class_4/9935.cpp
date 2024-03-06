#include <iostream>
#include <string>
#include <stack>
using namespace std;

string input, bomb;

string Solution()
{
	string answer;
	stack<char> st;
	stack<char> temp;

	for (int i = 0; i < input.size(); i++)
	{
		st.push(input[i]);

		int offset = bomb.size() - 1;
		while (!st.empty() && offset >= 0 && st.top() == bomb[offset])
		{
			temp.push(st.top());
			st.pop();
			offset--;
		}

		if (offset != -1)
		{
			while (!temp.empty())
			{
				st.push(temp.top());
				temp.pop();
			}
		}
		else
		{
			while (!temp.empty())
			{
				temp.pop();
			}
		}
	}

	answer.resize(st.size());
	int size = st.size() - 1;

	while (!st.empty())
	{
		answer[size--] = st.top();
		st.pop();
	}

	return answer;
}

int main()
{
	cin >> input >> bomb;

	string answer = Solution();

	if (answer.empty())
	{
		cout << "FRULA";
	}
	else
	{
		cout << answer;
	}

	return 0;
}