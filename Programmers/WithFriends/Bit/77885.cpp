#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (auto number : numbers)
    {
        long long start = 1;

        if ((number & start) == 0)
        {
            answer.push_back(++number);
        }
        else
        {
            number++;

            while ((number & start) == 0)
            {
                start *= 2;
            }

            answer.push_back(number + start / 2 - 1);
        }
    }

    return answer;
}