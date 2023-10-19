#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> vec;
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		vec.push_back(i);
	}

	for (int i = 0; i < m; i++)
	{
		int I, J, K;
		cin >> I >> J >> K;

		int* pa = (int*)malloc(sizeof(int) * (J - K + 1));
		//미드 -> 엔드
		for (int i = K; i <= J; i++)
		{
			pa[i - K] = vec[i - 1];
		}

		int* pb = (int*)malloc(sizeof(int) * (K - I));
		//비긴 -> 미드
		for (int i = I; i < K; i++)
		{
			pb[i - I] = vec[i - 1];
		}

		for (int i = I; i <= I + (J - K); i++)
		{
			vec[i - 1] = pa[i - I];
		}

		for (int i = I + (J - K + 1); i <= J; i++)
		{
			vec[i - 1] = pb[i - (I + (J - K + 1))];
		}

		free(pb);
		free(pa);
	}

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << " ";
	}

	return 0;
}