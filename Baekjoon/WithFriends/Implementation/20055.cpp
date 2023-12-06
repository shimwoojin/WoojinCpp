#include <bits/stdc++.h>

using namespace std;

int main()
{
	//start : 15:30
	//end : 15:54

	int n, k;
	cin >> n >> k;
	deque<int> belt(2 * n, 0);
	deque<bool> robot_exist(2 * n, false);

	for (int i = 0; i < 2 * n; i++)
	{
		cin >> belt[i];
	}

	int level = 1;
	int zero_count = 0;

	while (true)
	{
		{
			//�κ��� ��Ʈ�� ���� �̵�
			belt.push_front(belt.back());	
			belt.pop_back();
			robot_exist.push_front(robot_exist.back());
			robot_exist.pop_back();

			//�������� ������ ��ġ�� �ִ� �κ��� ����
			if (robot_exist[n - 1] == true)
			{
				robot_exist[n - 1] = false;
			}
		}	//1��

		{
			//�κ��� ������ ������
			//n-2�� ������ ������ ��ġ�� n-1�� �̹� ������ ���� ����
			//1) ���� ĭ�� �κ��� �ְ� 2) ���� ĭ�� �������� 1 �̻� �̰� 3) ���� ĭ�� �κ��� ����� ��
			for (int i = n - 2; i >= 0; i--)
			{
				if (robot_exist[i] && belt[i + 1] >= 1 && !robot_exist[i + 1])
				{
					--belt[i + 1];
					robot_exist[i] = false;
					robot_exist[i + 1] = true;

					if (belt[i + 1] == 0)
					{
						++zero_count;
					}
				}
			}

			//�������� ������ ��ġ�� �ִ� �κ��� ����
			if (robot_exist[n - 1] == true)
			{
				robot_exist[n - 1] = false;
			}
		}	//2��

		{
			//�ø��� ĭ(dq�� ù ��°)�� �������� 1 �̻��̸� �κ� ��ġ
			if (belt.front() >= 1)
			{
				robot_exist.front() = true;
				--belt.front();

				if (belt.front() == 0)
				{
					++zero_count;
				}
			}
		}	//3��

		{
			//�������� �˳����� üũ �� break Ȥ�� �ܰ� ����
			if (zero_count >= k)
			{
				break;
			}
			else
			{
				++level;
			}
		}	//4��
	}

	cout << level;

	return 0;
}