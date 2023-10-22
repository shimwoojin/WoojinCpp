//https://school.programmers.co.kr/learn/courses/30/lessons/181188

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    vector<pair<int, int>> p_targets;

    for (int i = 0; i < targets.size(); i++)
    {
        pair<int, int> p;

        for (int j = 0; j < targets[i].size(); j++)
        {
            if (j == 0) p.first = targets[i][j];
            else if (j == 1) p.second = targets[i][j];
        }

        p_targets.push_back(p);
    }

    sort(p_targets.begin(), p_targets.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
        });

    int Min = p_targets[0].first;
    int Max = p_targets[0].second;
    ++answer;

    for (auto ele : p_targets)
    {
        if (ele.first < Max && ele.second >= Max)
        {
            continue;
        }
        else
        {
            Max = ele.second;
            ++answer;
        }
    }

    return answer;
}