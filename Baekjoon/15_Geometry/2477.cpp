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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//왼쪽 아래 파임		왼쪽 위에 파임		오른쪽 아래 파임		오른쪽 위에 파임
	//423131			424231				423131				424132

	vector<pair<int, int>> vec;
	vector<string> direction_vec;
	string direction = "";
	int n;
	cin >> n;

	for (int i = 0; i < 6; i++)
	{
		int dir, length;
		cin >> dir >> length;

		direction += char(dir + '0');

		vec.push_back(make_pair(dir, length));
	}

	direction_vec.push_back(direction);

	for (int i = 0; i < 5; i++)
	{
		char temp = direction[0];

		for (int j = 1; j <= 5; j++)
		{
			direction[j - 1] = direction[j];
		}
		direction[5] = temp;

		direction_vec.push_back(direction);
	}

	int index;
	struct pos
	{
		int x;
		int y;
	};
	pos pos_;

	for (int i = 0; i < direction_vec.size(); i++)
	{
		if (direction_vec[i] == "423131")
		{
			index = i;
			pos_.x = -1;
			pos_.y = -1;
			break;
		}
		if (direction_vec[i] == "424231")
		{
			index = i;
			pos_.x = -1;
			pos_.y = +1;
			break;
		}
		if (direction_vec[i] == "423131")
		{
			index = i;
			pos_.x = +1;
			pos_.y = -1;
			break;
		}
		if (direction_vec[i] == "424132")
		{
			index = i;
			pos_.x = +1;
			pos_.y = +1;
			break;
		}
	}


	return 0;
}