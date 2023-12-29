#include <bits/stdc++.h>
using namespace std;

bool CheckWin(const string& game, char who)
{
	for (int i = 0; i < 3; i++)
	{
		bool check = true;

		for (int j = 0; j < 3; j++)
		{
			if (game[i * 3 + j] != who)
			{
				check = false;
			}
		}

		if (check)
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		bool check = true;

		for (int j = 0; j < 3; j++)
		{
			if (game[i + j * 3] != who)
			{
				check = false;
			}
		}

		if (check)
		{
			return true;
		}
	}

	if (game[0] == who && game[4] == who && game[8] == who)
	{
		return true;
	}

	if (game[2] == who && game[4] == who && game[6] == who)
	{
		return true;
	}

	return false;
}

int main()
{
	//start : 13:07
	//end : 13:32

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string game;

	while (true)
	{
		int XCount = 0;
		int OCount = 0;

		cin >> game;

		if (game == "end")
		{
			break;
		}

		for (char g : game)
		{
			if (g == 'X')
			{
				++XCount;
			}
			else if (g == 'O')
			{
				++OCount;
			}
		}

		if (XCount == OCount)	// O ½Â¸®
		{
			if (CheckWin(game, 'O') && !CheckWin(game, 'X'))
			{
				cout << "valid" << '\n';
			}
			else
			{
				cout << "invalid" << '\n';
			}
		}
		else if (XCount == (OCount + 1))	// X ½Â¸®
		{
			if (XCount == 5)	//²Ë Âü
			{
				if (!CheckWin(game, 'O'))
				{
					cout << "valid" << '\n';
				}
				else
				{
					cout << "invalid" << '\n';
				}
			}
			else
			{
				if (CheckWin(game, 'X') && !CheckWin(game, 'O'))
				{
					cout << "valid" << '\n';
				}
				else
				{
					cout << "invalid" << '\n';
				}
			}
		}
		else
		{
			cout << "invalid" << '\n';
		}
	}


	return 0;
}