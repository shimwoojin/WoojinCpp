#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int solution(string s)
{
    int answer = 1;

    for (int i = 0; i < s.size(); i++)
    {
        int distance = 0;
        int pelindrom = 0;

        while (i - distance >= 0 && i + distance < s.size())
        {
            if (s[i - distance] == s[i + distance])
            {
                ++distance;
            }
            else
            {
                break;
            }
        }

        pelindrom = (distance - 1) * 2 + 1;
        answer = max(pelindrom, answer);
    }

    for (int i = 0; i < s.size() - 1; i++)
    {
        int distance = 0;
        int pelindrom = 0;

        while (i - distance >= 0 && i + distance + 1 < s.size())
        {
            if (s[i - distance] != s[i + distance + 1])
            {
                break;
            }

            ++distance;
        }

        pelindrom = distance * 2;
        answer = max(pelindrom, answer);
    }

    return answer;
}