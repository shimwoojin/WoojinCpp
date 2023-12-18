#include <bits/stdc++.h>
using namespace std;

bool check(const string& str)
{
	int answer = 0;
	string temp;

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			temp += str[i];
		}
	}

	string num;
	deque<int> nums;
	deque<char> ops;

	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == '+' || temp[i] == '-')
		{
			nums.push_back(stoi(num));
			num.clear();
			ops.push_back(temp[i]);
		}
		else
		{
			num += temp[i];
		}
	}
	nums.push_back(stoi(num));
	
	while (!ops.empty())
	{
		int temp = 0;
		char op = ops.front();
		ops.pop_front();
		int first = nums.front();
		nums.pop_front();
		int second = nums.front();
		nums.pop_front();

		if (op == '+')
		{
			temp = first + second;
		}
		else
		{
			temp = first - second;
		}
		nums.push_front(temp);
	}
	
	answer = nums.back();

	return answer == 0;
}

void back_tracking(string str, int where, int limit, vector<string>& answers)
{
	if (where >= limit)
	{
		if (check(str))
		{
			answers.push_back(str);
		}

		return;
	}

	string str1(str);
	str1.insert(str1.begin() + where * 2 - 1, ' ');
	string str2(str);
	str2.insert(str2.begin() + where * 2 - 1, '+');
	string str3(str);
	str3.insert(str3.begin() + where * 2 - 1, '-');

	back_tracking(str1, where + 1, limit, answers);
	back_tracking(str2, where + 1, limit, answers);
	back_tracking(str3, where + 1, limit, answers);
}


void solution(int a)
{
	vector<string> answers;
	string str;
	for (int i = 1; i <= a; i++)
	{
		str += i + 48;
	}

	back_tracking(str, 1, a, answers);

	for (const string& answer : answers)
	{
		cout << answer << '\n';
	}
}

int main()
{
	//start : 13:16
	//end : 13:56

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		solution(a);
		cout << '\n';
	}

	return 0;
}