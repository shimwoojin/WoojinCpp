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

	//Start : 11:50
	//End : 12:39

	vector<pair<int, int>> PoolInfo;
	int PerfectSize = 0;
	int NeutralSize = 0;
	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
	{
		int Start, End;
		cin >> Start >> End;
	
		PoolInfo.push_back(make_pair(Start, End));
	}
	
	sort(PoolInfo.begin(), PoolInfo.end(), [](pair<int,int> a, pair<int, int> b) {
		return a < b;
		});

	for (int i = 0; i < PoolInfo.size(); i++)
	{
		int Gap = PoolInfo[i].second - PoolInfo[i].first;
		if (Gap <= 0) continue;

		int Quotient = Gap / L;
		PerfectSize += Quotient;

		if (Gap % L != 0)
		{
			++NeutralSize;

			if (i != PoolInfo.size() - 1)
			{
				int NewStart = PoolInfo[i].first + Quotient * L;

				for (int j = PoolInfo.size() - 1; j >= 0; j--)
				{
					if (PoolInfo[j].first < NewStart + L)
					{
						i = j - 1;

						PoolInfo[j].first = NewStart + L;

						break;
					}
				}
			}
		}
	}

	cout << PerfectSize + NeutralSize;

	return 0;
}