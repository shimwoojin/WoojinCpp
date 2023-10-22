//https://school.programmers.co.kr/learn/courses/30/lessons/12909

#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int Count = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            Count++;
        }
        else
        {
            Count--;
        }

        if (Count < 0) answer = false;
    }

    if (Count != 0) answer = false;

    return answer;
}