#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool Arr2_RangeCheck(const vector<vector<int>>& Arr, pair<int, int> Move, pair<int, int> Now, pair<int, int>& Result)
{
	int Size = Arr.size();

	if (Move.first + Now.first < 0 || Move.second + Now.second < 0 ||
		Move.first + Now.first >= Size || Move.second + Now.second >= Size)
	{
		return false;
	}
	else
	{
		Result.first = Move.first + Now.first;
		Result.second = Move.second + Now.second;

		return true;
	}

	return true;
}

int KnightMove(const vector<vector<int>>& Board)
{
	int Count = 0;
	pair<int, int> Now;
	vector<vector<int>> AlreayGoCheck(Board.size(), vector<int>(Board.size(), 0));
	for (int i = 0; i < Board.size(); i++)	//Now Check
	{
		for (int j = 0; j < Board.size(); j++)
		{
			if (Board[i][j] == 1)
			{
				Now.first = j;
				Now.second = i;
				break;
			}
		}
	}
	vector<pair<int, int>> Moves	//Can Moves
	{
		make_pair(-2, 1),
		make_pair(-1, 2),
		make_pair(1, 2),
		make_pair(2, 1),
		make_pair(2, -1),
		make_pair(1, -2),
		make_pair(-1, -2),
		make_pair(-2, -1)
	};
	queue<pair<int, int>> MoveCheck;

	AlreayGoCheck[Now.second][Now.first] = 1;
	
	for (auto Move : Moves)
	{
		pair<int, int> Result;
		if (Arr2_RangeCheck(Board, Move, Now, Result))
		{
			MoveCheck.push(Result);
		}
	}

	bool bKnightOnTravel = true;

	while (bKnightOnTravel)
	{
		queue<pair<int, int>> CountCheck = move(MoveCheck);

		while (CountCheck.empty() == false)
		{
			pair<int, int> Front = CountCheck.front();
			CountCheck.pop();
			
			if (AlreayGoCheck[Front.second][Front.first] == 1)
			{
				continue;
			}
			else
			{
				AlreayGoCheck[Front.second][Front.first] = 1;
			}

			if (Board[Front.second][Front.first] == 2)
			{
				bKnightOnTravel = false;
				break;
			}
			else
			{
				pair<int, int> Result;

				for (auto Move : Moves)
				{
					if (Arr2_RangeCheck(Board, Move, Front, Result))
					{
						MoveCheck.push(Result);
					}
				}

			}
		}

		++Count;
	}

	return Count;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	//Start : 19:13
	//End : 19:56

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int L;
		int A, B, C, D;
		cin >> L >> A >> B >> C >> D;
		vector<vector<int>> Board(L, vector<int>(L, 0));

		Board[B][A] = 1;	//Now
		Board[D][C] = 2;	//Aim

		if (B == D && A == C)
		{
			cout << 0 << "\n";
		}
		else
		{
			cout << KnightMove(Board) << "\n";
		}
	}

	return 0;
}