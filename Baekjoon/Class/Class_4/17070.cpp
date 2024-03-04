#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

enum class EDirection
{
	Right,
	RightDown,
	Down
};

int BuildPipe(const vector<vector<int>>& house)
{
	int answer = 0;
	EDirection start_direction = EDirection::Right;
	pair<int, int> start_position = { 1, 0 };
	queue<tuple<EDirection, int, int>> q;

	q.push(make_tuple(start_direction, start_position.first, start_position.second));

	while (q.empty() == false)
	{
		auto front = q.front();
		q.pop();

		EDirection direction = get<0>(front);
		int x = get<1>(front);
		int y = get<2>(front);

		if (x == y && x == house.size() - 1)
		{
			++answer;
			continue;
		}

		if (direction == EDirection::Right)
		{
			tuple<EDirection, int, int> ele1 = make_tuple(EDirection::Right, x + 1, y);
			tuple<EDirection, int, int> ele2 = make_tuple(EDirection::RightDown, x + 1, y + 1);

			if (x + 1 < house.size() && house[y][x + 1] == 0)
			{
				q.push(ele1);
			}

			if (x + 1 < house.size() && y + 1 < house.size() && house[y][x + 1] == 0 && house[y + 1][x] == 0 && house[y + 1][x + 1] == 0)
			{
				q.push(ele2);
			}
		}
		else if (direction == EDirection::RightDown)
		{
			tuple<EDirection, int, int> ele1 = make_tuple(EDirection::Right, x + 1, y);
			tuple<EDirection, int, int> ele2 = make_tuple(EDirection::RightDown, x + 1, y + 1);
			tuple<EDirection, int, int> ele3 = make_tuple(EDirection::Down, x, y + 1);

			if (x + 1 < house.size() && house[y][x + 1] == 0)
			{
				q.push(ele1);
			}

			if (x + 1 < house.size() && y + 1 < house.size() && house[y][x + 1] == 0 && house[y + 1][x] == 0 && house[y + 1][x + 1] == 0)
			{
				q.push(ele2);
			}

			if (y + 1 < house.size() && house[y + 1][x] == 0)
			{
				q.push(ele3);
			}
		}
		else
		{
			tuple<EDirection, int, int> ele1 = make_tuple(EDirection::RightDown, x + 1, y + 1);
			tuple<EDirection, int, int> ele2 = make_tuple(EDirection::Down, x, y + 1);

			if (x + 1 < house.size() && y + 1 < house.size() && house[y][x + 1] == 0 && house[y + 1][x] == 0 && house[y + 1][x + 1] == 0)
			{
				q.push(ele1);
			}

			if (y + 1 < house.size() && house[y + 1][x] == 0)
			{
				q.push(ele2);
			}
		}
	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<vector<int>> house(n, vector<int>(n, 0));
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> house[i][j];
		}
	}

	cout << BuildPipe(house);

	return 0;
}

//0ms DP 정석 풀이
#ifdef DP
#include<iostream>
using namespace std;
/*
map[i][j][x] -> (i, j) 위치에 대한
이동 가능 여부(0), 가로로 놓이는 경우(1), 세로로 놓이는 경우(2), 대각선으로 놓이는 경우(3)
*/
int N;
int map[22][22][4] = { 0 };
bool garo(int y, int x) {
	if (x + 1 > N || map[y][x + 1][0]) {
		return false;
	}
	else {
		return true;
	}
}
bool sero(int y, int x) {
	if (y + 1 > N || map[y + 1][x][0]) {
		return false;
	}
	else {
		return true;
	}
}
bool daegak(int y, int x) {
	if (y + 1 > N || x + 1 > N || map[y + 1][x][0] || map[y][x + 1][0] || map[y + 1][x + 1][0]) {
		return false;
	}
	else {
		return true;
	}
}
int main() {
	int i, j, x, tmp;
	map[1][2][1] = 1;
	cin >> N;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp) {
				map[i][j][0] = 1;
			}
		}
	}
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (garo(i, j)) {
				map[i][j + 1][1] += map[i][j][1] + map[i][j][3];
			}
			if (sero(i, j)) {
				map[i + 1][j][2] += map[i][j][2] + map[i][j][3];
			}
			if (daegak(i, j)) {
				map[i + 1][j + 1][3] += map[i][j][1] + map[i][j][2] + map[i][j][3];
			}
		}
	}
	cout << map[N][N][1] + map[N][N][2] + map[N][N][3] << '\n';
}
#endif