#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <stack>
#include <unordered_set>

using namespace std;

//int main()
//{
//	int N;
//	cin >> N;
//	vector<pair<int, int>> Tree(N + 1, make_pair(0,0));
//	set<int> Leafs;
//
//	Tree[1] = make_pair(-1, 0);
//
//	for (int i = 2; i < N + 1; i++)
//	{
//		Leafs.insert(i);
//	}
//
//	for (int i = 0; i < N - 1; i++)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		if (Tree[a].first == 0)
//		{
//			Leafs.erase(b);	//b는 자식이 있게 되므로 leaf가 아님
//			Tree[a].first = b;	//b를 a의 부모로 설정
//			Tree[a].second = Tree[b].second + 1;	//루트까지 거리 1 멀어짐
//		}
//		else if (Tree[b].first == 0)
//		{
//			Leafs.erase(a);
//			Tree[b].first = a;
//			Tree[b].second = Tree[a].second + 1;
//		}
//		else
//		{
//			continue;
//		}
//	}
//
//	int Count = 0;
//
//	for (auto Leaf : Leafs)
//	{
//		Count += Tree[Leaf].second;
//	}
//
//	if (Count % 2 == 1)
//	{
//		cout << "Yes";
//	}
//	else
//	{
//		cout << "No";
//	}
//
//	return 0;
//}

int dfs(const multimap<int, int>& Tree, int Start)
{
	int count = 0;

	stack<pair<int, int>> st;
	unordered_set<int> uos;

	st.push(make_pair(Start, 0));
	uos.insert(Start);

	while (!st.empty())
	{
		pair<int, int> top = st.top();
		st.pop();

		if (Tree.count(top.first) == 1)
		{
			count += top.second;
		}

		for (auto iter = Tree.lower_bound(top.first); iter != Tree.upper_bound(top.first); iter++)
		{
			if (uos.find((*iter).second) == uos.end())
			{
				uos.insert((*iter).second);
				st.push(make_pair((*iter).second, top.second + 1));
			}
		}
	}

	return count;
}

int main()
{
	int N;
	int Count = 0;
	cin >> N;
	multimap<int, int> Tree;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		Tree.insert(make_pair(a, b));
		Tree.insert(make_pair(b, a));
	}

	Count += dfs(Tree, 1);

	if (Count % 2 == 1)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}

	return 0;
}