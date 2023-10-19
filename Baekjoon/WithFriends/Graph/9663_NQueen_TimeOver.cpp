#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

int Time = 0;

bool CheckCondition(const vector<vector<int>>& Board, int X, int Y)
{
	int Size = Board.size();

	if (Board[Y][X] == 1)
	{
		int Gap = X - Y;
		int Gap2 = X + Y - (Size - 1);

		for (int i = 0; i < Size; i++)	//세로 체크
		{
			if (i == Y) continue;

			if (Board[i][X] != 0)
			{
				return false;
			}
		}

		for (int i = 0; i < Size - abs(Gap); i++)	//좌상 - 우하 대각선 체크
		{
			if (Gap >= 0)
			{
				if (i == Y) continue;

				if (Board[i][i + Gap] != 0)
				{
					return false;
				}
			}
			else
			{
				if (i == X) continue;

				if (Board[i - Gap][i] != 0)
				{
					return false;
				}
			}
		}

		for (int i = 0; i < Size - abs(Gap2); i++)	//좌하 - 우상 대각선 체크
		{
			if (Gap2 >= 0)
			{
				if ((i + Gap2) == X) continue;

				if (Board[Size - i - 1][i + Gap2] != 0)
				{
					return false;
				}
			}
			else
			{
				if (i == X) continue;

				if (Board[Size - i - 1 + Gap2][i] != 0)
				{
					return false;
				}
			}
		}
	}

	return true;
}

void NQueen(const vector<vector<int>>& Board, int Y, int& Count)
{
	int Size = Board.size();

	for (int i = 0; i < Size; i++)
	{
		int Start = clock();
		auto BackTrackedBoard = Board;
		BackTrackedBoard[Y][i] = 1;
		int End = clock();
		Time += End - Start;

		if (CheckCondition(BackTrackedBoard, i, Y))
		{
			if (Y == Size - 1)
			{
				++Count;
				break;
			}

			NQueen(BackTrackedBoard, Y + 1, Count);
		}
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	//Start : 11:32
	//End : 12:32
	
	int N;
	cin >> N;
	int Count = 0;
	vector<vector<int>> Board(N, vector<int>(N,0));
	
	int Start = clock();
	NQueen(Board, 0, Count);
	int End = clock();

	cout << End - Start <<"\n";
	cout << Time <<"\n";
	cout << Count;

	return 0;
}
