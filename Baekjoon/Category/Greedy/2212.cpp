#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
	int answer = 0;
	int n, k;
	cin >> n >> k;
	vector<int> sensors(n, 0);
	vector<int> distances;

	for(int i = 0 ; i < n; i++)
	{
		cin >> sensors[i];
	}

	sort(sensors.begin(), sensors.end());

	for (int i = 0; i < sensors.size() - 1; i++)
	{
		distances.push_back(sensors[i + 1] - sensors[i]);
	}

	sort(distances.begin(), distances.end());

	for (int i = 0; i < (int)distances.size() - k + 1; i++)
	{
		answer += distances[i];
	}

	//answer = accumulate(distances.begin(), distances.end() - k + 1, 0);

	cout << answer;

	return 0;
}