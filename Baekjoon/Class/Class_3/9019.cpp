#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

int a, b;

int MakeL(string& num)
{
	/*string temp;
	temp.reserve(4);
	char a, b, c, d;
	a = num[0];
	b = num[1];
	c = num[2];
	d = num[3];

	temp += b;
	temp += c;
	temp += d;
	temp += a;*/
	char temp = *num.begin();
	num.erase(num.begin());
	num += temp;

	return stoi(num);
}

int MakeR(string& num)
{
	//string temp;
	//temp.reserve(4);
	//char a, b, c, d;
	//a = num[0];
	//b = num[1];
	//c = num[2];
	//d = num[3];

	//temp += d;
	//temp += a;
	//temp += b;
	//temp += c;

	char temp = *(num.end() - 1);
	num.erase(num.begin());
	num.insert(num.begin(), temp);

	return stoi(num);
}

string bfs()
{
	string answer;
	queue<pair<int, string>> q;
	bool Visit[10001] = {false};

	q.push({ a, answer });

	while (!q.empty())
	{
		auto front = q.front();
		q.pop();
		int num = front.first;
		string s_num = to_string(num);
		string temp;
		int size = 4 - s_num.size();
		s_num.reserve(4);

		if (num == b)
		{
			return front.second;
		}

		while (size--)
		{
			temp += '0';
		}

		s_num = temp + s_num;

		int D = num * 2 % 10000;
		int S = num - 1;
		if (S == -1)
		{
			S = 9999;
		}
		//int L = MakeL(s_num);
		//int R = MakeR(s_num);

		int L = (num % 1000) * 10 + num / 1000;
		int R = (num % 10) * 1000 + num / 10;

		if (Visit[D] == false)
		{
			Visit[D] = true;
			q.push({ D, front.second + "D" });
		}
		if (Visit[S] == false)
		{
			Visit[S] = true;
			q.push({ S, front.second + "S"});
		}
		if (Visit[L] == false)
		{
			Visit[L] = true;
			q.push({ L, front.second + "L" });
		}
		if (Visit[R] == false)
		{
			Visit[R] = true;
			q.push({ R, front.second + "R" });
		}

	}

	return answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> a >> b;

		cout << bfs() << '\n';
	}

	return 0;
}