#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

constexpr int BIG_NUMBER = 2'100'000'000;

bool check(int size, int n)	//�迭�� �ε��� ���� �������� üũ
{
	if (n >= 0 && n < size)
	{
		return true;
	}
	return false;
}

//�ִ� ��� ã�� �˰���
int dijkstra(const vector<vector<int>> &cave)
{
	using min_xy = pair<int, pair<int, int>>;	//pair�� 2�� ��ø�ؼ� ������� ��������� <�ּڰ�, <x��ǥ, y��ǥ>>�� ������ ����ϰ��� ��

	int size = cave.size();	//main���� �Է¹��� N�� ũ�� ���� N * N �迭
	int x = 0, y = 0;	//���� ��ġ
	vector<vector<int>> dijkstra2d(size, vector<int>(size, BIG_NUMBER));	//���ͽ�Ʈ��� ��� ������ ���Ѵ�� �����ϰ� ������ -> ��� 2���� �迭 ���� 21������ �ʱ�ȭ
	vector <vector<bool>> visit(size, vector<bool>(size, false));	//�湮�� ���� ��湮���� �ʵ���
	priority_queue<min_xy, vector<min_xy>, greater<min_xy>> q;	//���ͽ�Ʈ���� �ٽ� �����̳� -> ���� ��ô�� �� �� ���� ���� �ڽ�Ʈ�� ���� ���� �� �� ����
	pair<int, int> dirs[4]	//�����¿� ����
	{
		make_pair(1,0),
		make_pair(0,1),
		make_pair(-1,0),
		make_pair(0,-1)
	};
	
	q.push(make_pair(cave[y][x], make_pair(x, y)));	//�켱���� ť�� �ּҰ�, x��ǥ, y��ǥ push
	dijkstra2d[y][x] = cave[y][x];	//�湮�� ���� ���Ѵ� -> ���� ��ġ + ������� ������ ��������� �ּڰ����� �ʱ�ȭ
	visit[y][x] = true;	//0,0�� �湮�ϰ� ��

	while (!q.empty())
	{
		pair<int, pair<int, int>> front = q.top();	//���� ���ͽ�Ʈ��� ����� ���� �߿��� �ּ��� ���� ���̸� ������ ���
		q.pop();

		for (pair<int, int> dir : dirs)	//�����¿� �����ӿ� ����
		{
			int move_x = front.second.first + dir.first;	//���縦 �������� ���� ��� ��������
			int move_y = front.second.second + dir.second;	//���縦 �������� ���� ��� ��������

			if(check(size, move_x) && check(size, move_y))	//�� �������� ��ȿ�� �ε������
			{
				int now = dijkstra2d[front.second.second][front.second.first];	//��������� �ּ� �ڽ�Ʈ��
				int move = cave[move_y][move_x];	//�� ��� �����̰� �Ǹ� �߰��� �ڽ�Ʈ

				if (now + move < dijkstra2d[move_y][move_x])	//�� ��� �������� �� ������ �ڽ�Ʈ�� �� �۴ٸ�
				{
					dijkstra2d[move_y][move_x] = now + move;	//������ ��忡 ���� �ּҰ� �ʱ�ȭ

					if (visit[move_y][move_x] == false)	//�湮���� �ʾҴٸ�
					{
						visit[move_y][move_x] = true;	//�湮 ó�� ���ְ�
						q.push(make_pair(dijkstra2d[move_y][move_x], make_pair(move_x, move_y)));	//�켱���� ť�� �� ��� �־���
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