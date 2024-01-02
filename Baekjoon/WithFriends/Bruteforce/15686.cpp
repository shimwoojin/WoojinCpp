#include <bits/stdc++.h>
using namespace std;

int min_chicken(int n, int m, vector<pair<int, int>> chicken_houses, vector<pair<int, int>> houses)
{
	int answer = INT_MAX;
	int chicken_count = chicken_houses.size();
	vector<bool> cases(chicken_count - m, false);
	vector<pair<int, int>> live_chickens;

	for (int i = 0; i < m; i++)
	{
		cases.push_back(true);
	}

	do
	{
		int little_answer = 0;
		live_chickens.clear();

		for (int i = 0; i < cases.size(); i++)
		{
			if (cases[i] == true)
			{
				live_chickens.push_back(chicken_houses[i]);
			}
		}

		for (auto& house : houses)
		{
			int min_distance = INT_MAX;
			
			for (auto& live_chicken : live_chickens)
			{
				min_distance = min(min_distance, abs(live_chicken.first - house.first) + abs(live_chicken.second - house.second));
			}

			little_answer += min_distance;
		}
		
		answer = min(little_answer, answer);

	} while (next_permutation(cases.begin(), cases.end()));

	return answer;
}

int main()
{
	//start: 15:30
	//end: 16:26
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> chicken_houses;
	vector<pair<int, int>> houses;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int a;
			cin >> a;

			if (a == 2)
			{
				chicken_houses.push_back(make_pair(j, i));
			}
			else if(a == 1)
			{
				houses.push_back(make_pair(j, i));
			}
		}
	}

	cout << min_chicken(n, m, chicken_houses, houses);

	return 0;
}