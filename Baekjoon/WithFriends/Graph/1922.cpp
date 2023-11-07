#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	int answer = 0;
	int N, M;
	cin >> N >> M;
	
	vector<pair<int, pair<int, int>>> graph;
	vector<set<int>> kruskal;

	for (int i = 0; i < M; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		if (from != to)
		{
			graph.push_back(make_pair(cost, make_pair(from, to)));
		}
	}

	sort(graph.begin(), graph.end());

	for (const auto& g : graph)
	{
		bool bFirstFind = false;
		bool bSecondFind = false;
		int FirstIndex = -1, SecondIndex = -1;

		for (int i = 0; i < kruskal.size(); i++)
		{
			if (kruskal[i].find(g.second.first) != kruskal[i].end())
			{
				FirstIndex = i;
				bFirstFind = true;
			}
			if (kruskal[i].find(g.second.second) != kruskal[i].end())
			{
				SecondIndex = i;
				bSecondFind = true;
			}
		}

		if (bFirstFind)
		{
			kruskal[FirstIndex].insert(g.second.second);
		}
		if (bSecondFind)
		{
			kruskal[SecondIndex].insert(g.second.first);
		}

		if (bFirstFind == false && bSecondFind == false)
		{
			set<int> s{ g.second.first, g.second.second };
			kruskal.push_back(s);
			answer += g.first;
		}
		else if (bFirstFind == true && bSecondFind == false)
		{
			answer += g.first;
		}
		else if (bFirstFind == false && bSecondFind == true)
		{
			answer += g.first;
		}
		else
		{
			if (FirstIndex == SecondIndex)
			{
				continue;
			}
			else
			{
				answer += g.first;
				for (auto s : kruskal[SecondIndex])
				{
					kruskal[FirstIndex].insert(s);
				}
				kruskal.erase(kruskal.begin() + SecondIndex);
			}
		}
	}

	cout << answer;

	return 0;
}