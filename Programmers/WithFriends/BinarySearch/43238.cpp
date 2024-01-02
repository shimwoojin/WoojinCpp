#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    //start:16:36
    //end:17:10

    long long right = (long long)(*max_element(times.begin(), times.end())) * n;
    long long left = 0;
    long long mid = right;
    long long count = 0;

    while (left <= right)
    {
        count = 0;
        mid = (left + right) / 2;

        for (int i = 0; i < times.size(); i++)
        {
            count += mid / times[i];
        }

        if (count < n)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            answer = mid;
        }
    }

    return answer;
}