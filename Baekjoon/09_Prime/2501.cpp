#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	vector<int> vec;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0) vec.push_back(i);
	}

	if (vec.size() < k) cout << 0;
	else cout << vec[k - 1];


	return 0;
}