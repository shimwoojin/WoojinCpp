#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	unordered_map<string, string> my_map;

	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;

		my_map[s1] = s2;
	}

	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		cout << my_map[s] << '\n';
	}

	return 0;
}