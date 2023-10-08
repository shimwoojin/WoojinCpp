#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//Start : 20231008, 19:45
	//End : 20231008, 20:44
	//Fail

	int N;
	cin >> N;
	vector<vector<int>> PaintingCost(N, vector<int>());

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int Num;
			cin >> Num;
			PaintingCost[i].push_back(Num);
		}
	}

	vector<int> MostLittleCosts(N, 0);
	int LittleCostSum = 0;

	for (int i = 0; i < N - 1; i++)
	{
		int Sum = 0;
		int SmallestCost = 0;

		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int LittleSum = PaintingCost[i][j];

				if (k == j)
				{
					continue;
				}

				LittleSum += PaintingCost[i + 1][k];

				if (i < N - 2)
				{
					for (int l = 0; l < 3; l++)
					{
						if (k == l)
						{
							continue;
						}

						LittleSum += PaintingCost[i + 2][l];

						if (Sum == 0)
						{
							Sum = LittleSum;
							SmallestCost = PaintingCost[i][j];
						}
						else
						{
							int BeforeSum = Sum;
							Sum = min(Sum, LittleSum);
							
							if (BeforeSum != Sum)
							{
								SmallestCost = min(SmallestCost, PaintingCost[i][j]);
							}
						}

						LittleSum -= PaintingCost[i + 2][l];
					}
				}
				else
				{
					if (Sum == 0)
					{
						Sum = LittleSum;
						SmallestCost = PaintingCost[i][j];
					}
					else
					{
						int BeforeSum = Sum;
						Sum = min(Sum, LittleSum);
						if (BeforeSum != Sum)
						{
							SmallestCost = min(SmallestCost, PaintingCost[i][j]);
						}
					}
				}
			}
		}

		if (i == N - 2)
		{
			LittleCostSum += Sum;
		}
		else
		{
			LittleCostSum += SmallestCost;
		}
	}

	cout << LittleCostSum << "\n";

	return 0;
}