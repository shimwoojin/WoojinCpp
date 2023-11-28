#include <string>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

int dfs(const vector<vector<int>>& tree, vector<bool>& visit, int start)
{
    if (visit[start])
    {
        return -1;
    }

    int answer = 0;
    stack<int> st;

    st.push(start);

    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        visit[top] = true;
        ++answer;

        for (auto t : tree[top])
        {
            if (visit[t] == false)
            {
                st.push(t);
            }
        }
    }

    return answer;
}

int gap(const vector<vector<int>>& tree, vector<bool>& visit)
{
    int answer = 0;

    int start = 1;
    int end = visit.size() - 1;
    vector<int> v;

    for (int i = start; i <= end; i++)
    {
        int dfs_answer = dfs(tree, visit, i);
        if (dfs_answer != -1)
        {
            v.push_back(dfs_answer);
        }
    }

    answer = abs(v[0] - v[1]);

    return answer;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> tree(n + 1, vector<int>());
        vector<bool> visit(n + 1, false);

        for (int j = 0; j < wires.size(); j++)
        {
            if (j == i)
            {
                continue;
            }

            tree[wires[j][0]].push_back(wires[j][1]);
            tree[wires[j][1]].push_back(wires[j][0]);
        }

        answer = min(answer, gap(tree, visit));
    }

    return answer;
}