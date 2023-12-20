#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		string s, s2;
		int n;
		cin >> s >> n >> s2;
		
		deque<int> dq;
		string temp;
		bool bReverse = false;
		string answer;

		for (char ele : s2)
		{
			if (ele == '[')
			{
				continue;
			}

			if (ele == ',')
			{
				dq.push_back(stoi(temp));
				temp.clear();
			}
			else if(isdigit(ele))
			{
				temp += ele;
			}

			if (ele == ']' && temp.size() > 0)
			{
				dq.push_back(stoi(temp));
			}
		}

		for (char ele : s)
		{
			if (ele == 'R')
			{
				bReverse = !bReverse;
			}
			else
			{
				if (dq.empty())
				{
					answer = "error";
					break;
				}
				else
				{
					if (bReverse)
					{
						dq.pop_back();
					}
					else
					{
						dq.pop_front();
					}
				}
			}
		}

		if (answer != "error")
		{
			answer += '[';

			if (bReverse)
			{
				for (auto iter = dq.rbegin(); iter != dq.rend(); iter++)
				{
					answer += to_string(*iter);
					answer += ',';
				}
			}
			else
			{
				for (int ele : dq)
				{
					answer += to_string(ele);
					answer += ',';
				}
			}

			if (answer[answer.end() - answer.begin() - 1] == ',')
			{
				answer.erase(answer.end() - 1);
			}
			answer += ']';
		}

		cout << answer << '\n';
	}

	return 0;
}