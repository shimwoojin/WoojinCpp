#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 0;
	int N, M;
	string S;
	bool start = false;
	bool next_o = false;

	cin >> N >> M >> S;

	int combo = 0;

	for (int i = 0; i < M; i++)
	{
		if (start == false && S[i] == 'I')
		{
			start = true;
			next_o = true;
			continue;
		}

		if (start && next_o && S[i] == 'O')
		{
			next_o = false;
		}
		else if (start && !next_o && S[i] == 'I')
		{
			next_o = true;
			combo++;
			if (combo >= N)
			{
				answer++;
			}
		}
		else
		{
			combo = 0;
			
			if (S[i] == 'O')
			{
				start = false;
				next_o = false;
			}
			else
			{
				start = true;
				next_o = true;
			}
		}
	}

	cout << answer;

	return 0;
}