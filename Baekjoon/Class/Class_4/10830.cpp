#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void MatrixMulti(vector<vector<long long>>& m1, vector<vector<long long>>& m2)
{
	int size1 = m1.size();
	int size2 = m1[0].size();
	int size3 = m2[0].size();

	vector<vector<long long>> temp(size1, vector<long long>(size3, 0));

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			for (int k = 0; k < size3; k++)
			{
				temp[i][j] += (m1[i][k] % 1000) * (m2[k][j] % 1000);
			}
			temp[i][j] %= 1000;
		}
	}

	m1 = temp;
}

int main()
{
	long long n, b;
	cin >> n >> b;

	vector<vector<long long>> matrix(n, vector<long long>(n, 0));
	vector<vector<long long>> answer(n, vector<long long>(n, 0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
		answer[i][i] = 1;
	}

	while (b > 0)
	{
		if (b % 2 == 1)
		{
			MatrixMulti(answer, matrix);
		}
		MatrixMulti(matrix, matrix);

		b /= 2;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}

/*
int main()
{
	long long n, b;
	cin >> n >> b;

	vector<vector<long long>> matrix(n, vector<long long>(n, 0));
	vector<vector<long long>> answer(n, vector<long long>(n, 0));
	stack<long long> s;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	answer = matrix;

	while (b > 0)
	{
		s.push(b);
		b /= 2;
	}
	s.pop();

	if (s.empty())
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				answer[i][j] %= 1000;
			}
		}
	}

	long long before = 1;
	while (s.empty() == false)
	{
		long long top = s.top();
		s.pop();
		
		MatrixMulti(answer, answer);
		before *= 2;
		
		if (before < top)
		{
			MatrixMulti(answer, matrix);
			before++;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << answer[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
*/