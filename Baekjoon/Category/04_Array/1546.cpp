#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<float> vec;
	int n;
	cin >> n;
	float max = 0.0f;

	for (int i = 0; i < n; i++)
	{
		float score;
		cin >> score;

		if (score > max) max = score;

		vec.push_back(score);
	}

	for (int i = 0; i < n; i++)
	{
		float score = vec[i];
		score = score / max * 100;
		vec[i] = score;
	}

	float average = 0.0f;

	for (int i = 0; i < n; i++)
	{
		average += vec[i];
	}

	cout << average / n << endl;

	return 0;
}