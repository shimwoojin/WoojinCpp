#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int check[101][101]; // 시작점으로부터의 거리 표시
int visit[101][101]; // 방문표시
char map[101][101]; // 미로
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{
	visit[x][y] = 1; // 방문표시

	queue<pair<int, int> > q; // 큐 생성
	q.push(make_pair(x, y)); // 시작점 넣기

	while (!q.empty()) // 큐에 데이터가 없을때까지
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); // 큐 맨 앞 데이터 제거

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) // 미로의 범위
			{
				// 길이 존재하고 이전에 방문했던적이 없는 경우
				if (map[next_x][next_y] == '1' && visit[next_x][next_y] == 0)
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); // 큐에 데이터 밀어넣기
				}

			}

		}
	}

}

int main(void)
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
	{
		scanf("%s", map[i]);
	}

	BFS(0, 0);
	printf("%d\n", check[N - 1][M - 1] + 1);

	return 0;
}

// 무방향
//class Graph
//{
//public:
//    Graph(int nodeCount)
//        : nodeCount(nodeCount)
//    {
//        graph = new bool* [nodeCount];
//        for (int i = 0; i < nodeCount; i++)
//            graph[i] = new bool[nodeCount];
//
//        for (int i = 0; i < nodeCount; i++)
//        {
//            for (int j = 0; j < nodeCount; j++)
//            {
//                graph[i][j] = 0;
//            }
//        }
//
//        visit = new int[nodeCount];
//        for (int i = 0; i < nodeCount; i++)
//            visit[i] = 0;
//    }
//
//    ~Graph()
//    {
//        for (int i = 0; i < nodeCount; i++)
//            delete[] graph[i];
//        delete graph;
//
//        delete[] visit;
//    }
//
//    void MakeLink(int x, int y)
//    {
//        if (nodeCount <= x || nodeCount <= y)
//        {
//            cout << "용량초과" << endl;
//            return;
//        }
//        else
//        {
//            graph[y][x] = 1;
//            graph[x][y] = 1;
//        }
//    }
//
//    void Display()
//    {
//        for (int i = 0; i < nodeCount; i++)
//        {
//            for (int j = 0; j < nodeCount; j++)
//            {
//                cout << graph[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//
//    int BFS(int start, int target)
//    {
//        q.push(start);
//        int depth = 1;
//        int back = -1;
//
//        while (q.empty() == false)
//        {
//            int now = q.front();
//
//            if (now == target) break;
//
//            q.pop();
//
//            if (visit[now] == 0)
//            {
//                visit[now] = 1;
//                //cout << now << " ";
//
//                for (int i = 0; i < nodeCount; i++)
//                {
//                    if (graph[now][i] == 1 && visit[i] == 0)
//                    {
//                        q.push(i);
//                    }
//                }
//                if (back == -1 || back == now)
//                {
//                    ++depth;
//                    back = q.back();
//                }
//            }
//        }
//
//        return depth;
//    }
//public:
//    int count = 0;
//
//private:
//    // 노드의 개수가 5개라면 
//    bool** graph = nullptr; // graph[5][5]
//    int* visit = nullptr;  // visit[5]
//
//    int nodeCount = 0;
//    queue<int> q;
//
//};

//int main()
//{
//    cin.tie(NULL);
//    ios::sync_with_stdio(false);
//
//    int n, m;
//    int node_count = 0;
//    cin >> n >> m;
//
//    node_count = n * m;
//
//    Graph graph(node_count);
//
//    string* str = new string[n];
//
//    for (int i = 0; i < n; i++)
//    {
//        cin >> str[i];
//    }
//
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            if (str[i][j] == '1')
//            {
//                int left = j - 1;
//                int right = j + 1;
//                int down = i + 1;
//                int up = i - 1;
//
//                if (left >= 0)
//                {
//                    if (str[i][left] == '1')
//                    {
//                        graph.MakeLink(i * m + j, i * m + left);
//                    }
//                }
//
//                if (right < m)
//                {
//                    if (str[i][right] == '1')
//                    {
//                        graph.MakeLink(i * m + j, i * m + right);
//                    }
//                }
//
//                if (up >= 0)
//                {
//                    if (str[up][j] == '1')
//                    {
//                        graph.MakeLink(i * m + j, up * m + j);
//                    }
//                }
//
//                if (down < n)
//                {
//                    if (str[down][j] == '1')
//                    {
//                        graph.MakeLink(i * m + j, down * m + j);
//                    }
//                }
//            }
//        }
//    }
//
//    int depth = graph.BFS(0, node_count - 1);
//
//    cout << depth;
//
//    delete[] str;
//
//    return 0;
//}