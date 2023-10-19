#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int SnakeGame(vector<vector<int>>& Board, vector<pair<int, string>>& Dirs)
{
	int Count = 0;
	deque<pair<int, int>> Snake;
	Snake.push_back(make_pair(0, 0));
	string Dir;
	pair<int, int> Move = make_pair(1, 0);
	bool bStop = false;

	while (true)
	{
		bool bInput = false;

		pair<int, int> Front = Snake.front();

		Front.first += Move.first;
		Front.second += Move.second;
		Snake.push_front(Front);

		++Count;

		if (Front.first < 0 || Front.first >= Board.size() ||	//벽 충돌
			Front.second < 0 || Front.second >= Board.size())
		{
			bStop = true;
			break;
		}

		for (int i = 1; i < Snake.size(); i++)	//몸 충돌
		{
			if (Front.first == Snake[i].first && Front.second == Snake[i].second)
			{
				bStop = true;
			}
		}

		if (Board[Front.second][Front.first] == 1)	//아이템 획득
		{
			Board[Front.second][Front.first] = 0;
		}
		//아이템 획득 x
		else
		{
			Snake.pop_back();
		}


		for (int i = 0; i < Dirs.size(); i++)	//방향 전환 키 입력 있는지
		{
			if (Dirs[i].first == Count)
			{
				Dir = Dirs[i].second;
				bInput = true;
			}
		}

		if (bInput)	//방향 전환
		{
			if (Dir == "L")
			{
				if (Move.first == 1)
				{
					Move.first = 0;
					Move.second = -1;
				}
				else if (Move.first == -1)
				{
					Move.first = 0;
					Move.second = 1;
				}
				else if (Move.second == 1)
				{
					Move.first = 1;
					Move.second = 0;
				}
				else if (Move.second == -1)
				{
					Move.first = -1;
					Move.second = 0;
				}
			}
			else if (Dir == "D")
			{
				if (Move.first == 1)
				{
					Move.first = 0;
					Move.second = 1;
				}
				else if (Move.first == -1)
				{
					Move.first = 0;
					Move.second = -1;
				}
				else if (Move.second == 1)
				{
					Move.first = -1;
					Move.second = 0;
				}
				else if (Move.second == -1)
				{
					Move.first = 1;
					Move.second = 0;
				}
			}
		}

		if (bStop)
		{
			break;
		}
	}

	return Count;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//Start : 16:13
	//End : 17:26

	int N, K;
	cin >> N >> K;

	vector<vector<int>> Board(N, vector<int>(N, 0));

	for (int i = 0; i < K; i++)
	{
		int A, B;
		cin >> A >> B;
		Board[A - 1][B - 1] = 1;
	}

	int L;
	cin >> L;

	vector<pair<int, string>> Dirs;

	for (int i = 0; i < L; i++)
	{
		int A; string B;
		cin >> A >> B;
		pair<int, string> Dir = make_pair(A, B);
		Dirs.push_back(Dir);
	}

	cout << SnakeGame(Board, Dirs);

	return 0;
}