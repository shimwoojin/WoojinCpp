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
			//로봇과 벨트가 같이 이동
			belt.push_front(belt.back());	
			belt.pop_back();
			robot_exist.push_front(robot_exist.back());
			robot_exist.pop_back();

			//언제든지 내리는 위치에 있는 로봇은 내림
			if (robot_exist[n - 1] == true)
			{
				robot_exist[n - 1] = false;
			}
		}	//1번

		{
			//로봇이 스스로 움직임
			//n-2인 이유는 내리는 위치인 n-1은 이미 내려서 없기 때문
			//1) 현재 칸에 로봇이 있고 2) 다음 칸의 내구도가 1 이상 이고 3) 다음 칸에 로봇이 없어야 함
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

			//언제든지 내리는 위치에 있는 로봇은 내림
			if (robot_exist[n - 1] == true)
			{
				robot_exist[n - 1] = false;
			}
		}	//2번

		{
			//올리는 칸(dq의 첫 번째)이 내구도가 1 이상이면 로봇 배치
			if (belt.front() >= 1)
			{
				robot_exist.front() = true;
				--belt.front();

				if (belt.front() == 0)
				{
					++zero_count;
				}
			}
		}	//3번

		{
			//내구도가 넉넉한지 체크 후 break 혹은 단계 증가
			if (zero_count >= k)
			{
				break;
			}
			else
			{
				++level;
			}
		}	//4번
	}

	cout << level;

	return 0;
}