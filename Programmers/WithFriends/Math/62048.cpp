#include <algorithm>
#include <numeric>

using namespace std;

long long solution(int w, int h) {
    long long answer = (long long)w * h;

    //start : 18:34
    //end : 18:55

    long long repeat_count = (long long)gcd(w, h);
    long long pattern_count = (long long)(w / repeat_count - 1) + (h / repeat_count - 1) + 1;

    answer = answer - repeat_count * pattern_count;

    return answer;
}

int main()
{
    auto s = solution(8, 12);


    return 0;
}