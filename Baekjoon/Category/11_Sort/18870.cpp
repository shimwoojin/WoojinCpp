#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	vector<int> temp;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		vec.push_back(a);
	}

	temp = vec;

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(vec.begin(), vec.end(), temp[i]) - vec.begin() << " ";
	}

	return 0;
}