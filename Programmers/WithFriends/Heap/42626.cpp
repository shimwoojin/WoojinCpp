//https://school.programmers.co.kr/learn/courses/30/lessons/42626

#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }

    cout << pq.top();

    while (pq.top() < K)
    {
        int new_scoville = pq.top();
        pq.pop();
        if (pq.empty())
        {
            return -1;
        }
        new_scoville += pq.top() * 2;
        pq.pop();
        pq.push(new_scoville);
        ++answer;
    }

    return answer;
}