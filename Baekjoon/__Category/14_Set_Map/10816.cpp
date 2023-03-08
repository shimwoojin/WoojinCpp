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

//int main()	//시간초과
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	multiset<int> ms;
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//
//		ms.insert(a);
//	}
//
//	int m;
//	cin >> m;
//
//	for (int i = 0; i < m; i++)
//	{
//		int a;
//		cin >> a;
//	
//		cout << ms.count(a) << " ";
//	}
//
//	return 0;
//}

int my_set[20000001];

int main()	//시간초과
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		++my_set[10000000 + a];
	}

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a; 
		cin >> a;

		cout << my_set[10000000 + a] << " ";
	}



	return 0;
}