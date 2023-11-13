#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

string NFormation(int n, int k)
{
    string str;

    while (n != 0)
    {
        long long temp = n % k;
        n /= k;

        if (temp >= 10)
        {
            str += char(temp + 55);
        }
        else
        {
            str += to_string(temp);
        }
    }

    string result;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        result += str[i];
    }

    return result;
}

void MakePrimes(long long size, vector<bool>& primes)
{
    primes.assign(size + 1, true);
    primes[0] = false;
    primes[1] = false;

    for (long long i = 2; i < size + 1; i++)
    {
        if (primes[i] == false)
        {
            continue;
        }

        for (long long j = i * 2; j < size + 1; j += i)
        {
            primes[j] = false;
        }
    }
}

bool IsPrime(long long number)
{
    if (number <= 1)
    {
        return false;
    }

    for (long long i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
        {
            return false;
        }
    }

    return true;
}

int solution(int n, int k) {
    int answer = 0;

    string str = NFormation(n, k);
    vector<long long> IsPrimes;
    string temp;
    vector<bool> primes;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
        {
            if (temp.size() > 0)
            {
                IsPrimes.push_back(stol(temp));
            }
            temp.clear();

            continue;
        }
        else
        {
            temp += str[i];

            if (i == str.size() - 1)
            {
                IsPrimes.push_back(stol(temp));
            }
        }
    }

    //sort(IsPrimes.begin(), IsPrimes.end(), greater<long long>());

    for (auto p : IsPrimes)
    {
        answer += (int)IsPrime(p);
    }

    return answer;
}