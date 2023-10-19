#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct person
{
	int x;
	int y;
	int score;
};

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<person> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		person p;
		int x, y;
		cin >> x >> y;

		p.x = x;
		p.y = y;
		p.score = 1;

		vec.push_back(p);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j) continue;

			if (vec[i].x < vec[j].x && vec[i].y < vec[j].y)
			{
				vec[i].score++;
			}
		}
	}

	for (auto ele : vec)
		cout << ele.score << " ";

	return 0;
}