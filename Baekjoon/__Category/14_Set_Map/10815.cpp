#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

//int main()	//시간 초과
//{
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	vector<int> card;
//	vector<int> HasCard;
//
//	int n;
//	cin >> n;
//
//	for (int i = 0; i < n; i++)
//	{
//		int a;
//		cin >> a;
//
//		card.push_back(a);
//	}
//
//	int m;
//	cin >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int a; 
//		cin >> a;
//
//		HasCard.push_back(a);
//	}
//
//	for (int i = 0; i < m; i++)
//	{
//		if (find(card.begin(), card.end(), HasCard[i]) != card.end()) cout << 1 << " ";
//		else cout << 0 << " ";
//	}
//
//
//	return 0;
//}

bool cards[20000001];

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;

		cards[10000000 + a] = 1;
	}

	int m;
	vector<int> HasCards;
	cin >> m;
	
	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;

		HasCards.push_back(a);
	}

	for (int i = 0; i < m; i++)
	{
		if (cards[10000000 + HasCards[i]] == 1) cout << 1 << " ";
		else cout << 0 << " ";
	}

	return 0;
}