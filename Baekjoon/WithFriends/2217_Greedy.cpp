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

typedef long long ll;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	//15 46 ����
	//15 49 ���� �� �� �о..
	//16 02 �׽�Ʈ1 -> ���

	vector<int> Lopes;
	int N;
	int Max = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int Lope;
		cin >> Lope;
		Lopes.push_back(Lope);
	}

	sort(Lopes.begin(), Lopes.end(), greater<int>());

	for (int k = 1; k <= N; k++)
	{
		int LopeCount = k;
	
		Max = (Lopes[k - 1] * LopeCount > Max ? Lopes[k - 1] * LopeCount : Max);
	}

	std::cout << Max << std::endl;

	return 0;
}