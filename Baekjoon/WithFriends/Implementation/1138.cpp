#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	//start : 19:22
	//end : 19:37
	int n;
	cin >> n;
	vector<int> tall_left(n);
	map<int, int> remember;
	vector<int> line;
	for (int i = 0; i < n; i++)
	{
		cin >> tall_left[i];
	}
	for (int i = 1; i <= n; i++)
	{
		remember[i] = tall_left[i - 1];
	}
	for (int i = 1; i <= n; i++)
	{
		line.push_back(i);
	}
	
	do
	{
		bool AllSuccess = true;
		for (int i = 0; i < line.size(); i++)
		{
			int height = line[i];
			int tallerthan = remember[height];
			int count = 0;
			for (int j = 0; j < i; j++)
			{
				if (line[j] > height)
				{
					++count;
				}
			}
			if (tallerthan != count)
			{
				AllSuccess = false;
				break;
			}
		}
		if (AllSuccess)
		{
			for (auto ele : line)
			{
				cout << ele << " ";
			}
			break;
		}
	} while (next_permutation(line.begin(), line.end()));
	

	return 0;
}