#include <iostream>
#include <vector>
#include <stack>
using namespace std;
using pii = pair<int, int>;

pii dfs(const vector<vector<pii>>& tree, int start)
{
	pii answer = { 0, 0 };	//node, length
	vector<bool> visits(tree.size(), false);
	stack<pii> nodes;

	visits[start] = true;
	nodes.push(make_pair(start, 0));

	while (nodes.empty() == false)
	{
		pii top = nodes.top();
		nodes.pop();
		int node = top.first;
		int weight = top.second;

		for (const auto& ele : tree[node])
		{
			int next_node = ele.first;
			int next_weight = ele.second;

			if (visits[next_node] == false)
			{
				int can_be_answer = weight + next_weight;
				visits[next_node] = true;
				nodes.push(make_pair(next_node, can_be_answer));
				int before = answer.second;
				answer.second = max(answer.second, can_be_answer);

				if (before != answer.second)
				{
					answer.first = next_node;
				}
			}
		}
	}

	return answer;
}

int main()
{
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int temp = n;
	vector<vector<pii>> tree(n + 1, vector<pii>());

	temp--;
	while (temp--)
	{
		int parent, child, weight;
		cin >> parent >> child >> weight;

		tree[parent].push_back(make_pair(child, weight));
		tree[child].push_back(make_pair(parent, weight));
	}

	pii try1 = dfs(tree, n);
	pii try2 = dfs(tree, try1.first);

	cout << try2.second;

	return 0;
}