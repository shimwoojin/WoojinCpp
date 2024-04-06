#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int new_number = -1;
    int answer = 0;

    while (n != new_number)
    {
        if (answer == 0)
        {
            new_number = n;
        }

        int tens = new_number / 10;
        int ones = new_number % 10;
        int sum = tens + ones;

        new_number = ones * 10 + sum % 10;

        ++answer;
    }

    cout << answer;

    return 0;
}