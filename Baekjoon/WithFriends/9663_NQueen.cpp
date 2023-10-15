#include <iostream>
#include <vector>
#include <time.h>
using namespace std;

bool Check(const vector<int>& Board, int X)
{
	for (int i = 0; i < X; i++)
	{
		if (Board[i] == Board[X] || abs(Board[X] - Board[i]) == X - i) return false;
	}

	return true;
}

void NQueen(int Y, int& Count, vector<int>& Board, int N)
{
	if (Y == N)
	{
		++Count;
	}
	else
	{
		for (int X = 0; X < N; X++)
		{
			Board[Y] = X;
			if (Check(Board, Y))
			{
				NQueen(Y + 1, Count, Board, N);
			}
		}
	}
}

int main()
{
	int N;
	int Count = 0;
	cin >> N;
	vector<int> Board(15, 0);

	int Start = clock();
	NQueen(0, Count, Board, N);
	int End = clock();
	cout << End - Start << endl;
	cout << Count;

	return 0;
}