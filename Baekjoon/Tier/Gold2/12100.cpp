#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Data
{
	vector<vector<int>> board;
	int count;
};

enum class Dir
{
	up,
	down,
	left,
	right
};

int MoveAndPush(const vector<vector<int>>& board, queue<Data>& q, Dir dir, int count)
{
	if (count >= 5) return 0;

	int biggest = 0;
	vector<vector<int>> temp(board.size(), vector<int>(board[0].size(), 0));

	switch (dir)
	{
	case Dir::up: 
	{
		for (int x = 0; x < board[0].size(); x++)
		{
			queue<int> que;
			int value = board[0][x];

			for (int y = 1; y < board.size(); y++)
			{
				if (board[y][x] == 0) continue;
				
				if (value == board[y][x])
				{
					que.push(board[y][x] * 2);
					value = 0;
				}
				else
				{
					if (value != 0)	que.push(value);
					value = board[y][x];
				}
			}

			if (value != 0) que.push(value);

			int y_index = 0;
			while (que.empty() == false)
			{
				temp[y_index][x] = que.front();
				biggest = max(biggest, que.front());
				que.pop();
				y_index++;
			}
		}
	}
		break;
	case Dir::down:
	{
		for (int x = 0; x < board[0].size(); x++)
		{
			queue<int> que;
			int value = board[board.size() - 1][x];

			for (int y = board.size() - 2; y >= 0; y--)
			{
				if (board[y][x] == 0) continue;

				if (value == board[y][x])
				{
					que.push(board[y][x] * 2);
					value = 0;
				}
				else
				{
					if (value != 0)	que.push(value);
					value = board[y][x];
				}
			}

			if (value != 0) que.push(value);

			int y_index = board.size() - 1;
			while (que.empty() == false)
			{
				temp[y_index][x] = que.front();
				biggest = max(biggest, que.front());
				que.pop();
				y_index--;
			}
		}
	}
		break;
	case Dir::left:
	{
		for (int y = 0; y < board.size(); y++)
		{
			queue<int> que;
			int value = board[y][0];

			for (int x = 1; x < board[0].size(); x++)
			{
				if (board[y][x] == 0) continue;

				if (value == board[y][x])
				{
					que.push(board[y][x] * 2);
					value = 0;
				}
				else
				{
					if (value != 0)	que.push(value);
					value = board[y][x];
				}
			}

			if (value != 0) que.push(value);

			int x_index = 0;
			while (que.empty() == false)
			{
				temp[y][x_index] = que.front();
				biggest = max(biggest, que.front());
				que.pop();
				x_index++;
			}
		}
	}
		break;
	case Dir::right:
	{
		for (int y = 0; y < board.size(); y++)
		{
			queue<int> que;
			int value = board[y][board[0].size() - 1];

			for (int x = board[0].size() - 2; x >= 0; x--)
			{
				if (board[y][x] == 0) continue;

				if (value == board[y][x])
				{
					que.push(board[y][x] * 2);
					value = 0;
				}
				else
				{
					if (value != 0)	que.push(value);
					value = board[y][x];
				}
			}

			if (value != 0) que.push(value);

			int x_index = board[0].size() - 1;
			while (que.empty() == false)
			{
				temp[y][x_index] = que.front();
				biggest = max(biggest, que.front());
				que.pop();
				x_index--;
			}
		}
	}
		break;
	}

	q.push({ temp, count + 1 });

	return biggest;
}

int Game(vector<vector<int>>& board)
{
	int answer = 0;
	queue<Data> q;

	q.push({board, 0});

	while (q.empty() == false)
	{
		vector<vector<int>> new_board = move(q.front().board);
		int count = q.front().count;
		q.pop();

		answer = max(answer, MoveAndPush(new_board, q, Dir::up, count));
		answer = max(answer, MoveAndPush(new_board, q, Dir::down, count));
		answer = max(answer, MoveAndPush(new_board, q, Dir::left, count));
		answer = max(answer, MoveAndPush(new_board, q, Dir::right, count));
	}

	return answer;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> board(n, vector<int>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	cout << Game(board);

	return 0;
}