#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> arr;
	stack<int> s;
	while (n--)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	stack<int> answers;

	for (auto iter = arr.rbegin(); iter != arr.rend(); iter++)
	{
		int size = answers.size();
		s.push(*iter);
		while (s.empty() == false)
		{
			int top = s.top();
			s.pop();

			if (top > *iter)
			{
				answers.push(top);
				s.push(top);
				s.push(*iter);
				break;
			}
		}

		if (size == answers.size())
		{
			answers.push(-1);
			s.push(*iter);
		}
	}

	while (answers.empty() == false)
	{
		cout << answers.top() << ' ';
		answers.pop();
	}

	return 0;
}