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

	//Start : 10:01
	//End : 10:06

	int N;
	deque<int> Cards;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		Cards.push_front(i);
	}

	while (Cards.size() > 1)
	{
		Cards.pop_back();
		if (Cards.size() == 1) break;
		Cards.push_front(Cards.back());
		Cards.pop_back();
	}

	cout << Cards[0];

	return 0;
}