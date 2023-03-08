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

	while (true)
	{
		vector<int> vec;
		int max = -1;
		int sum = 0;

		for (int i = 0; i < 3; i++)
		{
			int a;
			cin >> a;

			max = std::max(max, a);

			vec.push_back(a);
		}

		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0) break;

		for (int i = 0; i < 3; i++)
		{
			if (max == vec[i]) continue;

			sum += pow(vec[i], 2);
		}

		if (pow(max, 2) == sum) cout << "right" <<"\n";
		else cout << "wrong" << "\n";
	}

	return 0;
}