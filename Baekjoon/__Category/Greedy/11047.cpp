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

	int N, K;
	cin >> N >> K;
	vector<int> Coins;

	for (int i = 0; i < N; i++)
	{
		int Coin;
		cin >> Coin;
		if (Coin <= K)
		{
			Coins.push_back(Coin);
		}
	}

	sort(Coins.rbegin(), Coins.rend());
	/*sort(Coins.begin(), Coins.end(), [](int a, int b) {
		return a > b;
		});*/

	int i = 0;
	int Count = 0;

	while (K != 0)
	{
		int LittleCount = K / Coins[i];
		K -= Coins[i] * LittleCount;
		Count += LittleCount;
		i++;
	}

	cout << Count << endl;

	return 0;
}