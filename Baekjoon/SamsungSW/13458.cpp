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

	int N;
	cin >> N;
	vector<int> Ai;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;

		Ai.push_back(temp);
	}

	int B, C;
	cin >> B >> C;

	long long Count = 0;

	for (int i = 0; i < N; i++)
	{
		int Remainder = Ai[i] - B;
		++Count;

		int Quotient = 0;

		if (Remainder > 0)
		{
			Quotient = Remainder / C;

			Count += Quotient;

			bool IsRemainderExist = false;
			IsRemainderExist = Remainder % C;

			if (IsRemainderExist)
			{
				++Count;
			}
		}
	}

	cout << Count;


	return 0;
}