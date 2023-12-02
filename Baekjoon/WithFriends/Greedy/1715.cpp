#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    long long answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        pq.push(a);
    }

    while (!pq.empty())
    {
        long long top = pq.top();
        pq.pop();

        if (!pq.empty())
        {
            long long second_top = pq.top();
            pq.pop();

            int merge = top + second_top;

            answer += merge;
            pq.push(merge);
        }
    }

    cout << answer;

    return 0;
}