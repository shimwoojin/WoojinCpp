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
	int Count = 0;
	int Increase = 1;

	while (Count < N)
	{
		Count += Increase;
		++Increase;
	}

	int Gap = Count - N;

	if (Increase % 2 == 0)
	{
		cout << 1 + Gap << "/" << Increase - 1 - Gap;
	}
	else
	{
		cout << Increase - 1 - Gap << "/" << 1 + Gap;
	}

	return 0;
}