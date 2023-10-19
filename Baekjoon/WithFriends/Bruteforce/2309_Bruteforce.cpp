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
	//Ω√¿€ : 19 50
	//≥° : 20 10

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> Littles;
	int Sum = 0;
	int ExceptIndex1 = -1, ExceptIndex2 = -1;
	Littles.assign(9, 0);

	for (int i = 0; i < 9; i++)
	{
		int Height;
		cin >> Height;
		Littles[i] = Height;
	}

	sort(Littles.begin(), Littles.end(), less<int>());

	for (int i = 0; i < 8; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			Sum = 0;

			for (int k = 0; k < 9; k++)
			{
				if (k == i || k == j) continue;
				Sum += Littles[k];
			}

			if (Sum == 100)
			{
				ExceptIndex1 = i;
				ExceptIndex2 = j;

				break;
			}
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i != ExceptIndex1 && i != ExceptIndex2)
		{
			cout << Littles[i] << "\n";
		}
	}

	return 0;
}