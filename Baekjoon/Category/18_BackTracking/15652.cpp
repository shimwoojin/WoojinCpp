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

void BackTracking(vector<int> vec, int N, int M, int now ,int count)
{
	if (M == 0)
	{
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i] << " ";
		}
		cout << "\n";
		return;
	}

	int next_count = count + 1;

	for (int i = now; i <= N; i++)
	{
		vec[count] = i;
		BackTracking(vec, N, M - 1, i, next_count);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec;
	vec.assign(M, 0);

	BackTracking(vec, N, M, 1, 0);

	return 0;
}