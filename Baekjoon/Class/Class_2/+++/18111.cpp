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

	int n, m, b;
	cin >> n >> m >> b;

	vector<vector<int>> vec(n, vector<int>(m));

	int min = 300, max = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int a;
			cin >> a;

			max = std::max(max, a);
			min = std::min(min, a);

			vec[i][j] = a;
		}
	}

	//시간이 최소
	//시간이 같다면 땅 높이가 높은 것

	//제거 : 2초, 쌓는 건 1초




	return 0;
}