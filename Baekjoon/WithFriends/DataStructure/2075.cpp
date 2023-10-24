#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class CMP
{
public:
	bool operator() (pair<int, int> A, pair<int, int> B)
	{
		return A.second < B.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;
	vector<stack<int>> VS(N);
	priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> PQ;
	map<int, int> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int T;
			cin >> T;
			VS[j].push(T);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int Top = VS[i].top();
		M.emplace(i, Top);
		PQ.push(make_pair(i, Top));
		VS[i].pop();
	}
	
	pair<int, int> PQ_Top;

	for (int i = 0; i < N; i++)
	{
		PQ_Top = PQ.top();
		PQ.pop();
		if (i != N - 1)
		{
			int First = PQ_Top.first;
			int Second = VS[First].top();
			VS[First].pop();
			PQ.push(make_pair(First, Second));
		}
	}

	cout << PQ_Top.second;

	return 0;
}