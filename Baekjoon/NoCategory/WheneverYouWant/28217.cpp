#include <iostream>
#include <vector>
using namespace std;

int Compare(const vector<vector<int>>& triangle1, const vector<vector<int>>& triangle2, int n)
{
	int answer = 0;

	int count = 0;
	for (int i = 0; i < n; i++)
	{
		++count;
		for (int j = 0; j < count; j++)
		{
			if (triangle1[i][j] != triangle2[i][j])
			{
				++answer;
			}
		}
	}

	return answer;
}

void Swap(int& a, int& b, int& c)
{
	int temp1 = a, temp2 = b, temp3 = c;
	a = temp2;
	b = temp3;
	c = temp1;
}

void Right(vector<vector<int>>& triangle)
{
	int count = triangle.size();
	int repeat = 0;

	while (count > 1)
	{
		pair<int, int> a{repeat, repeat * 2};
		pair<int, int> b{repeat, triangle.size() - repeat - 1};
		pair<int, int> c{ triangle.size() - repeat * 2 - 1, triangle.size() - repeat - 1 };
		for (int i = 0; i < count - 1; i++)
		{
			Swap(triangle[a.second + i][a.first + i], triangle[b.second - i][b.first], triangle[c.second][c.first - i]);
		}

		++repeat;
		count -= 3;
	}
}

void Reverse(vector<vector<int>>& triangle)
{
	for (int i = 0; i < triangle.size(); i++)
	{
		int size = triangle[i].size();
		for (int j = 0; j < size / 2; j++)
		{
			swap(triangle[i][j], triangle[i][size - j - 1]);
		}
	}
}

void Show(vector<vector<int>>& triangle)
{
	int n = triangle.size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		++count;
		for (int j = 0; j < count; j++)
		{
			cout << triangle[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int answer = 2'000'000'000;
	int n;
	cin >> n;

	vector<vector<int>> triangle1(n, vector<int>());
	vector<vector<int>> triangle2(n, vector<int>());

	int count1 = 0;
	for (int i = 0; i < n; i++)
	{
		++count1;
		for (int j = 0; j < count1; j++)
		{
			int temp;
			cin >> temp;
			triangle1[i].push_back(temp);
		}
	}

	int count2 = 0;
	for (int i = 0; i < n; i++)
	{
		++count2;
		for (int j = 0; j < count2; j++)
		{
			int temp;
			cin >> temp;
			triangle2[i].push_back(temp);
		}
	}

	answer = min(answer, Compare(triangle1, triangle2, n));
	Right(triangle1);
	//Show(triangle1);
	answer = min(answer, Compare(triangle1, triangle2, n));
	Right(triangle1);
	//Show(triangle1);
	answer = min(answer, Compare(triangle1, triangle2, n));
	Reverse(triangle1);
	//Show(triangle1);
	answer = min(answer, Compare(triangle1, triangle2, n));
	Right(triangle1);
	//Show(triangle1);
	answer = min(answer, Compare(triangle1, triangle2, n));
	Right(triangle1);
	//Show(triangle1);
	answer = min(answer, Compare(triangle1, triangle2, n));

	cout << answer;

	return 0;
}