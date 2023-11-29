#include <iostream>
#include <vector>

using namespace std;

int main()
{
	//start : 19:07
	//end : 19:32

	int answer = 0;

	int h, w;
	cin >> h >> w;
	vector<int> bricks(w);

	for (int i = 0; i < w; i++)
	{
		cin >> bricks[i];
	}

	int max = 0;
	bool bFirst = false;
	int max_index = 0;

	for (int i = 0; i < bricks.size(); i++)
	{
		if (bFirst == false && bricks[i] > 0)
		{
			max = bricks[i];
			max_index = i;
			bFirst = true;
		}
		else if(bFirst)
		{
			if (bricks[i] > max)
			{
				for (int j = max_index + 1; j < i; j++)
				{
					answer += (max - bricks[j]);
				}

				max = bricks[i];
				max_index = i;
			}
		}
	}

	max = 0;
	bFirst = false;
	int second_max_index = 0;

	for (int i = bricks.size() - 1; i >= max_index; i--)
	{
		if (bFirst == false && bricks[i] > 0)
		{
			max = bricks[i];
			second_max_index = i;
			bFirst = true;
		}
		else if (bFirst)
		{
			if (bricks[i] >= max)
			{
				for (int j = second_max_index - 1; j > i; j--)
				{
					answer += (max - bricks[j]);
				}

				second_max_index = i;
				max = bricks[i];
			}
		}
	}

	cout << answer;

	return 0;
}
