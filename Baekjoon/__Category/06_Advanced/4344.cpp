#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> vec;
		int m;
		cin >> m;

		int sum = 0;

		for (int i = 0; i < m; i++)
		{
			int l;
			cin >> l;
			vec.push_back(l);

			sum += l;
		}

		float average = (float)sum / m;
		float count = 0;

		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i] > average) ++count;
		}

		cout<<fixed;
		cout.precision(3);
		cout << (float)(count / m * 100) << "%\n";
	}


	return 0;
}