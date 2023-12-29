#include <bits/stdc++.h>
using namespace std;

int main()
{
	//start : 13:55
	//end : 14:13

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;
		vector<string> numbers;
		string answer = "YES";

		while (n--)
		{
			string number;
			cin >> number;
			
			numbers.push_back(number);
		}

		sort(numbers.begin(), numbers.end());

		for (int i = 0; i < numbers.size() - 1; i++)
		{
			int count = min(numbers[i].size(), numbers[i + 1].size());
			bool bSame = true;

			for (int j = 0; j < count; j++)
			{
				if (numbers[i][j] != numbers[i + 1][j])
				{
					bSame = false;
					break;
				}
			}

			if (bSame)
			{
				answer = "NO";
				break;
			}
		}

		cout << answer << "\n";
	}

	return 0;
}