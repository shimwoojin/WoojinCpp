#include <iostream>
#include <vector>
using namespace std;

bool alphabets[200] = {};
int answer = 0;
int num = 1;

void Solution(vector<vector<char>>& board, int x, int y)
{
	answer = max(answer, num);

	if (x + 1 >= 1 && x + 1 < board[0].size() && y >= 1 && y < board.size() && alphabets[(int)board[y][x + 1]] == false)
	{
		alphabets[(int)board[y][x + 1]] = true;
		++num;
		Solution(board, x + 1, y);
		--num;
		alphabets[(int)board[y][x + 1]] = false;
	}

	if (x - 1 >= 1 && x - 1 < board[0].size() && y >= 1 && y < board.size() && alphabets[(int)board[y][x - 1]] == false)
	{
		alphabets[(int)board[y][x - 1]] = true;
		++num;
		Solution(board, x - 1, y);
		--num;
		alphabets[(int)board[y][x - 1]] = false;
	}

	if (x >= 1 && x < board[0].size() && y + 1 >= 1 && y + 1 < board.size() && alphabets[(int)board[y + 1][x]] == false)
	{
		alphabets[(int)board[y + 1][x]] = true;
		++num;
		Solution(board, x, y + 1);
		--num;
		alphabets[(int)board[y + 1][x]] = false;
	}

	if (x >= 1 && x < board[0].size() && y - 1 >= 1 && y - 1 < board.size() && alphabets[(int)board[y - 1][x]] == false)
	{
		alphabets[(int)board[y - 1][x]] = true;
		++num;
		Solution(board, x, y - 1);
		--num;
		alphabets[(int)board[y - 1][x]] = false;
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int r, c;
	cin >> r >> c;
	vector<vector<char>> board(r + 1, vector<char>(c + 1, '\0'));

	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			char temp;
			cin >> temp;
			board[i][j] = temp;
		}
	}

	alphabets[(int)board[1][1]] = true;
	Solution(board, 1, 1);

	cout << answer;

	return 0;
}