#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Beads
{
	pair<int, int> red;
	pair<int, int> blue;
	int count;
};

enum class Dir
{
	up,
	down,
	left,
	right
};

enum class Result
{
	success,
	fail,
	nothing
};

Result Move(const vector<vector<char>>& board, pair<int, int>& red, pair<int, int>& blue, Dir dir)
{
	Result result = Result::nothing;

	switch (dir)
	{
	case Dir::up:
		if (red.second < blue.second)
		{
			while (red.second - 1 >= 0 && board[red.second - 1][red.first] == '.')
			{
				red.second--;
			}
			if (red.second - 1 >= 0 && board[red.second - 1][red.first] == 'O')
			{
				result = Result::success;
				red.second--;
			}

			while (blue.second - 1 >= 0 && board[blue.second - 1][blue.first] == '.' && !(blue.second - 1 == red.second && blue.first == red.first))
			{
				blue.second--;
			}
			if (blue.second - 1 >= 0 && board[blue.second - 1][blue.first] == 'O') return Result::fail;
		}
		else
		{
			while (blue.second - 1 >= 0 && board[blue.second - 1][blue.first] == '.')
			{
				blue.second--;
			}
			if (blue.second - 1 >= 0 && board[blue.second - 1][blue.first] == 'O') return Result::fail;

			while (red.second - 1 >= 0 && board[red.second - 1][red.first] == '.' && !(blue.second == red.second - 1 && blue.first == red.first))
			{
				red.second--;
			}
			if (red.second - 1 >= 0 && board[red.second - 1][red.first] == 'O') result = Result::success;
		}

		break;
	case Dir::down:
		if (red.second > blue.second)
		{
			while (red.second + 1 < board.size() && board[red.second + 1][red.first] == '.')
			{
				red.second++;
			}
			if (red.second + 1 < board.size() && board[red.second + 1][red.first] == 'O')
			{
				result = Result::success;
				red.second++;
			}

			while (blue.second + 1 < board.size() && board[blue.second + 1][blue.first] == '.' && !(blue.second + 1 == red.second && blue.first == red.first))
			{
				blue.second++;
			}
			if (blue.second + 1 < board.size() && board[blue.second + 1][blue.first] == 'O') return Result::fail;
		}
		else
		{
			while (blue.second + 1 < board.size() && board[blue.second + 1][blue.first] == '.')
			{
				blue.second++;
			}
			if (blue.second + 1 < board.size() && board[blue.second + 1][blue.first] == 'O') return Result::fail;

			while (red.second + 1 < board.size() && board[red.second + 1][red.first] == '.' && !(blue.second == red.second + 1 && blue.first == red.first))
			{
				red.second++;
			}
			if (red.second + 1 < board.size() && board[red.second + 1][red.first] == 'O') result = Result::success;
		}

		break;
	case Dir::left:
		if (red.first < blue.first)
		{
			while (red.first - 1 >= 0 && board[red.second][red.first - 1] == '.')
			{
				red.first--;
			}
			if (red.first - 1 >= 0 && board[red.second][red.first - 1] == 'O')
			{
				result = Result::success;
				red.first--;
			}

			while (blue.first - 1 >= 0 && board[blue.second][blue.first - 1] == '.' && !(blue.second == red.second && blue.first - 1 == red.first))
			{
				blue.first--;
			}
			if (blue.first - 1 >= 0 && board[blue.second][blue.first - 1] == 'O') return Result::fail;
		}
		else
		{
			while (blue.first - 1 >= 0 && board[blue.second][blue.first - 1] == '.')
			{
				blue.first--;
			}
			if (blue.first - 1 >= 0 && board[blue.second][blue.first - 1] == 'O') return Result::fail;

			while (red.first - 1 >= 0 && board[red.second][red.first - 1] == '.' && !(blue.second == red.second && blue.first == red.first - 1))
			{
				red.first--;
			}
			if (red.first - 1 >= 0 && board[red.second][red.first - 1] == 'O') result = Result::success;
		}

		break;
	case Dir::right:
		if (red.first > blue.first)
		{
			while (red.first + 1 < board[0].size() && board[red.second][red.first + 1] == '.')
			{
				red.first++;
			}
			if (red.first + 1 < board[0].size() && board[red.second][red.first + 1] == 'O')
			{
				result = Result::success;
				red.first++;
			}

			while (blue.first + 1 < board[0].size() && board[blue.second][blue.first + 1] == '.' && !(blue.second == red.second && blue.first + 1 == red.first))
			{
				blue.first++;
			}
			if (blue.first + 1 < board[0].size() && board[blue.second][blue.first + 1] == 'O') return Result::fail;
		}
		else
		{
			while (blue.first + 1 < board[0].size() && board[blue.second][blue.first + 1] == '.')
			{
				blue.first++;
			}
			if (blue.first + 1 < board[0].size() && board[blue.second][blue.first + 1] == 'O') return Result::fail;

			while (red.first + 1 < board[0].size() && board[red.second][red.first + 1] == '.' && !(blue.second == red.second && blue.first == red.first + 1))
			{
				red.first++;
			}
			if (red.first + 1 < board[0].size() && board[red.second][red.first + 1] == 'O') result = Result::success;
		}

		break;
	}

	return result;
}

int Bfs(const vector<vector<char>>& board, pair<int, int> red, pair<int, int> blue)
{
	int answer = -1;
	queue<Beads> q;

	q.push({ red, blue, 0 });

	while (q.empty() == false)
	{
		pair<int, int> r = q.front().red;
		pair<int, int> b = q.front().blue;
		int count = q.front().count;
		q.pop();

		if (count > 10) return -1;

		pair<int, int> r1 = r;
		pair<int, int> b1 = b;
		Result result1 = Move(board, r1, b1, Dir::up);
		if (result1 == Result::nothing && !(r1 == r && b1 == b)) q.push({ r1, b1, count + 1 });
		pair<int, int> r2 = r;
		pair<int, int> b2 = b;
		Result result2 = Move(board, r2, b2, Dir::down);
		if (result2 == Result::nothing && !(r2 == r && b2 == b)) q.push({ r2, b2, count + 1 });
		pair<int, int> r3 = r;
		pair<int, int> b3 = b;
		Result result3 = Move(board, r3, b3, Dir::left);
		if (result3 == Result::nothing && !(r3 == r && b3 == b)) q.push({ r3, b3, count + 1 });
		pair<int, int> r4 = r;
		pair<int, int> b4 = b;
		Result result4 = Move(board, r4, b4, Dir::right);
		if (result4 == Result::nothing && !(r4 == r && b4 == b)) q.push({ r4, b4, count + 1 });

		if (result1 == Result::success || result2 == Result::success || result3 == Result::success || result4 == Result::success)
		{
			return count + 1 > 10 ? -1 : count + 1;
		}
	}

	return answer;
}

int main()
{
	int n, m;
	cin >> n >> m;
	vector<vector<char>> board(n, vector<char>(m, 0));
	pair<int, int> red;
	pair<int, int> blue;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'R')
			{
				red = { j, i };
				board[i][j] = '.';
			}

			if (board[i][j] == 'B')
			{
				blue = { j, i };
				board[i][j] = '.';
			}
		}
	}

	cout << Bfs(board, red, blue);

	return 0;
}