#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int a_size = a.size() + 1;
	int b_size = b.size() + 1;
	int answer = 0;

	vector<vector<int>> container(b_size, vector<int>(a_size, 0));

	for (int i = 1; i < b_size; i++)
	{
		for (int j = 1; j < a_size; j++)
		{
			if (b[i - 1] == a[j - 1])
			{
				container[i][j] = container[i - 1][j - 1] + 1;
			}
			else
			{
				container[i][j] = max(container[i - 1][j], container[i][j - 1]);
			}
		}
	}

	answer = container[b_size - 1][a_size - 1];
	cout << answer;

	return 0;
}