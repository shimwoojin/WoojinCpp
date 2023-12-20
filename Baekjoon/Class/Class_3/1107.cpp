#include <bits/stdc++.h>
using namespace std;

int little = 2000000;
int Size = 0;

void back_tracking(const set<char>& limocon, int count, int max, int N, string result)
{
	if (result.size() > 0)
	{
		little = min((int)result.size() + abs((N - stoi(result))), little);
	}

	if (count >= max)
	{
		return;
	}
	
	for (char l : limocon)
	{
		back_tracking(limocon, count + 1, max, N, result + l);
	}
}

int main()
{
	string N;
	int  M;
	string temp;
	set<char> limocon;

	cin >> N >> M;

	for (char c = '0'; c <= '9'; c++)
	{
		limocon.insert(c);
	}

	for (int i = 0; i < M; i++)
	{
		char a;
		cin >> a;
		limocon.erase(a);
	}

	back_tracking(limocon, 0, N.size() + 1, stoi(N), temp);
	string s = to_string(little);

	int answer = min(little, abs(100 - stoi(N)));

	cout << answer;

	return 0;
}