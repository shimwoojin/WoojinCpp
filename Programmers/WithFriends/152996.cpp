#include <string>
#include <vector>
#include <algorithm>

using namespace std;

__inline bool Check(int big, int little, const vector<pair<int, int>>& length_couple)
{
    for (auto ele : length_couple)
    {
        if (big * ele.first == little * ele.second)
        {
            return true;
        }
    }

    return false;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    vector<pair<int, int>> length_couple
    {
        make_pair(2,2),
        make_pair(2,3),
        make_pair(3,4),
        make_pair(2,4)
    };

    sort(weights.begin(), weights.end(), greater<int>());

    for (int i = 0; i < weights.size() - 1; i++)
    {
        for (int j = i + 1; j < weights.size(); j++)
        {
            answer += (int)Check(weights[i], weights[j], length_couple);

            if (weights[i] > weights[j] * 2)
            {
                break;
            }
        }
    }

    return answer;
}