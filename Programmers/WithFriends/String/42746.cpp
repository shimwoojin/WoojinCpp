#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool Cmp(string a, string b)
{
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s_numbers;

    for (int i = 0; i < numbers.size(); i++)
    {
        s_numbers.push_back(to_string(numbers[i]));
    }

    sort(s_numbers.begin(), s_numbers.end(), Cmp);

    for (int i = 0; i < s_numbers.size(); i++)
    {
        if (s_numbers[0][0] == '0')
        {
            answer = "0";
            break;
        }

        answer += s_numbers[i];
    }

    return answer;
}