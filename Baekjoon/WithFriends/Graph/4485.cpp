#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int BIG_NUMBER = 2'100'000'000;

bool check(int size, int n)	//배열의 인덱스 범위 안인지를 체크
{
	if (n >= 0 && n < size)
	{
		return true;
	}
	return false;
}

//최단 경로 찾는 알고리즘
int dijkstra(const vector<vector<int>> &cave)
{
	using min_xy = pair<int, pair<int, int>>;	//pair를 2개 중첩해서 순서대로 현재까지의 <최솟값, <x좌표, y좌표>>의 순으로 사용하고자 함

	int size = cave.size();	//main에서 입력받은 N과 크기 동일 N * N 배열
	int x = 0, y = 0;	//시작 위치
	vector<vector<int>> dijkstra2d(size, vector<int>(size, BIG_NUMBER));	//다익스트라는 모든 정점을 무한대로 가정하고 시작함 -> 모든 2차원 배열 원소 21억으로 초기화
	vector <vector<bool>> visit(size, vector<bool>(size, false));	//방문한 노드는 재방문하지 않도록
	priority_queue<min_xy, vector<min_xy>, greater<min_xy>> q;	//다익스트라의 핵심 컨테이너 -> 현재 개척한 땅 중 제일 낮은 코스트를 가진 땅을 알 수 있음
	pair<int, int> dirs[4]	//상하좌우 방향
	{
		make_pair(1,0),
		make_pair(0,1),
		make_pair(-1,0),
		make_pair(0,-1)
	};
	
	q.push(make_pair(cave[y][x], make_pair(x, y)));	//우선순위 큐에 최소값, x좌표, y좌표 push
	dijkstra2d[y][x] = cave[y][x];	//방문한 노드는 무한대 -> 시작 위치 + 여기까지 도달한 현재까지의 최솟값으로 초기화
	visit[y][x] = true;	//0,0은 방문하게 됨

	while (!q.empty())
	{
		pair<int, pair<int, int>> front = q.top();	//현재 다익스트라로 연결된 노드들 중에서 최소의 연결 길이를 가지는 노드
		q.pop();

		for (pair<int, int> dir : dirs)	//상하좌우 움직임에 대해
		{
			int move_x = front.second.first + dir.first;	//현재를 기준으로 다음 어떻게 움직일지
			int move_y = front.second.second + dir.second;	//현재를 기준으로 다음 어떻게 움직일지

			if(check(size, move_x) && check(size, move_y))	//이 움직임이 유효한 인덱스라면
			{
				int now = dijkstra2d[front.second.second][front.second.first];	//현재까지의 최소 코스트와
				int move = cave[move_y][move_x];	//이 길로 움직이게 되면 추가될 코스트

				if (now + move < dijkstra2d[move_y][move_x])	//이 길로 움직였을 때 움직인 코스트가 더 작다면
				{
					dijkstra2d[move_y][move_x] = now + move;	//움직인 노드에 대해 최소값 초기화

					if (visit[move_y][move_x] == false)	//방문하지 않았다면
					{
						visit[move_y][move_x] = true;	//방문 처리 해주고
						q.push(make_pair(dijkstra2d[move_y][move_x], make_pair(move_x, move_y)));	//우선순위 큐에 이 노드 넣어줌
					}
				}
			}
		}
	}

	return dijkstra2d[size - 1][size - 1];
}

int main()
{
	int count = 0;
	while (true)
	{
		++count;
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}
		vector<vector<int>> cave(N, vector<int>(N, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >>cave[i][j];
			}
		}

		cout << "Problem " << count << ": " << dijkstra(cave) << "\n";
	}

	return 0;
}