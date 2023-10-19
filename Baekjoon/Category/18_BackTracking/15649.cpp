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

void BackTracking(vector<int> vec, set<int> s, int N, int M, int count)
{
	if (M == 0)
	{
		for (int i = 0; i < vec.size(); i++)
			cout << vec[i] << " ";
		cout << "\n";
		return;
	}

	if (count > 0)
	{
		s.insert(vec[count - 1]);
	}

	int next_count = count + 1;

	for (int i = 1; i <= N; i++)
	{
		if (s.find(i) != s.end()) continue;

		vec[count] = i;
		BackTracking(vec, s, N, M - 1, next_count);
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec;
	set<int> s;
	int count = 0;
	vec.assign(M, 0);

	BackTracking(vec, s, N, M, count);

	return 0;
}