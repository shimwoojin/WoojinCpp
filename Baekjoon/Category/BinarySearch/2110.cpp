#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	
	int n, c;
	cin >> n >> c;
	vector<int> houses(n, 0);

	for (int i = 0; i < n; i++)
	{
		cin >> houses[i];
	}

	sort(houses.begin(), houses.end());

	int left = 1, right = houses[n - 1] - houses[0], mid, max = 0, cnt, i, cur;
	while (left <= right) {
		mid = (left + right) / 2;
		i = cnt = cur = 0;
		while (i < n && mid != 0) {
			cnt++;
			while (i < n && houses[i] - houses[cur] < mid) i++;
			cur = i;
		}
		if (cnt >= c) left = mid + 1;
		else right = mid - 1;
	}

	cout << right;

	return 0;
}