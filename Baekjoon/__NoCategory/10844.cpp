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
#include <numeric>
using namespace std;

typedef long long ll;

//개쓰레기같은문제 10억이뭐길래
int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> Numbers(11, 0);

	for (int i = 1; i < 10; i++)
	{
		Numbers[i] = 1;
	}

	for (int i = 1; i < N; i++)
	{
		vector<ll> Temp = Numbers;
			
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
			{
				Numbers[0] = Temp[1] % 1'000'000'000;
			}
			else
			{
				Numbers[j] = (Temp[j - 1] + Temp[j + 1]) % 1'000'000'000;
			}
		}
	}

	int Sum = 0;
	for (int i = 0; i < 10; i++)
	{
		Sum = (Sum + Numbers[i]) % 1'000'000'000;
	}

	Sum %= 1'000'000'000;

	cout << Sum;

	return 0;
}