//https://school.programmers.co.kr/learn/courses/30/lessons/178870

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;

    int start = 0, end = 0;
    int size = sequence.size();
    int min = 1000001;
    int start_confirm, end_confirm;
    int sum = 0;

    while (start < size)
    {
        if (sum >= k)
        {
            sum -= sequence[start];
            start++;
        }
        else
        {
            if (end < size)
            {
                sum += sequence[end];
                end++;
            }
            else
            {
                start++;
            }
        }

        if (sum == k)
        {
            if (min > end - start - 1)
            {
                min = end - start - 1;
                start_confirm = start;
                end_confirm = end;
            }
        }
    }

    answer.push_back(start_confirm);
    answer.push_back(end_confirm - 1);

    return answer;
}