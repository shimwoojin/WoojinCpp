#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
int check[101][101]; // ���������κ����� �Ÿ� ǥ��
int visit[101][101]; // �湮ǥ��
char map[101][101]; // �̷�
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS(int x, int y)
{
	visit[x][y] = 1; // �湮ǥ��

	queue<pair<int, int> > q; // ť ����
	q.push(make_pair(x, y)); // ������ �ֱ�

	while (!q.empty()) // ť�� �����Ͱ� ����������
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); // ť �� �� ������ ����

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) // �̷��� ����
			{
				// ���� �����ϰ� ������ �湮�ߴ����� ���� ���
				if (map[next_x][next_y] == '1' && visit[next_x][next_y] == 0)
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); // ť�� ������ �о�ֱ�
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