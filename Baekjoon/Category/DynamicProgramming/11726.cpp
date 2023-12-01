#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int answer = 0;

    int n;
    cin >> n;
    vector<int> vec(n + 1, 0);

    vec[1] = 1;
    vec[2] = 2;

    for (int i = 3; i <= n; i++)
    {
        vec[i] = vec[i - 1] % 10007 + vec[i - 2] % 10007;
    }

    answer = vec[n] % 10007;

    cout << answer;

	return 0;
}