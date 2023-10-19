#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool compare(pair<int, pair<int, string>> a, pair<int, pair<int, string>> b)
{
	if (a.second.first > b.second.first) return false;
	else if (a.second.first == b.second.first)
	{
		if (a.first > b.first) return false;
		else return true;
	}
	else return true;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<pair<int, pair<int, string>>> vec;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int age;
		string name;
		cin >> age >> name;

		vec.push_back(make_pair(i, make_pair(age, name)));
	}

	sort(vec.begin(), vec.end(), compare);

	for (auto ele : vec)
	{
		cout << ele.second.first << " " << ele.second.second << "\n";
	}

	return 0;
}