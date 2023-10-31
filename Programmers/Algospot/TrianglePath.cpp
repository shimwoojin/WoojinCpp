#include <iostream>
#include <vector>

using namespace std;

int Solution(const vector<vector<int>>& vec)
{
	int Answer = 0;
	int Size = vec.size();
	vector<vector<int>> Dp(Size, vector<int>(Size, 0));
	
	for (int i = 0; i < Size; i++)
	{
		Dp[Size - 1][i] = vec[Size - 1][i];
	}

	for (int i = Size - 2; i >= 0; i--)
	{
		for (int j = 0; j < Size - 1; j++)
		{
			Dp[i][j] = max(Dp[i + 1][j] + vec[i][j], Dp[i + 1][j + 1] + vec[i][j]);
		}
	}

	Answer = Dp[0][0];

	return Answer;
}

int main()
{
	int C;
	cin >> C;

	for (int i = 0; i < C; i++)
	{
		int n;
		cin >> n;
		vector<vector<int>> Triangle(n, vector<int>(n, 0));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
			{
				int Num;
				cin >> Num;

				Triangle[i][j] = Num;
			}
		}

		cout << Solution(Triangle) << "\n";
	}

	return 0;
}