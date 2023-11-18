#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k)
{
    int answer = 987654321;
    deque<pair<int, int>> DQ;

    for (int i = 0; i < stones.size(); i++)
    {
        while (DQ.empty() == false && DQ.front().second < i - k + 1)
        {
            DQ.pop_front();
        }

        while (DQ.empty() == false && DQ.back().first < stones[i])
        {
            DQ.pop_back();
        }

        DQ.push_back(make_pair(stones[i], i));

        if (i >= k - 1 && DQ.front().first < answer)
        {
            answer = DQ.front().first;
        }
    }

    return answer;
}

/*
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;

    using p_ii = pair<int, int>;

    priority_queue<p_ii, vector<p_ii>, greater<p_ii>> pq;

    for(int i = 0; i < stones.size(); i++)
    {
        pq.push(make_pair(stones[i], i));
    }

    int accumulate = 0;

    while(!pq.empty())
    {
        bool bStop = false;
        pair<int, int> top = pq.top();
        vector<int> indexes;
        int value = top.first - accumulate;
        accumulate += value;
        answer += value;

        while(pq.top().first == top.first)
        {
            indexes.push_back(pq.top().second);
            pq.pop();

            if(pq.empty())
            {
                break;
            }
        }

        for(auto index : indexes)
        {
            int increase = index, decrease = index;
            int link = 1;

            while(true)
            {
                ++increase;

                if(increase >= stones.size())
                {
                    break;
                }

                if(stones[increase] > accumulate)
                {
                    break;
                }
                else
                {
                    ++link;
                }
            }

            while(true)
            {
                --decrease;

                if(decrease < 0)
                {
                    break;
                }

                if(stones[decrease] > accumulate)
                {
                    break;
                }
                else
                {
                    ++link;
                }
            }

            if(link >= k)
            {
                bStop = true;
                break;
            }
        }

        if(bStop)
        {
            break;
        }
    }

    return answer;
}
*/