#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int recursion(const char* s, int l, int r, int* count) {
    (*count)++;
    if (l >= r) return 1;
    else if (s[l] != s[r]) return 0;
    else return recursion(s, l + 1, r - 1, count);
}

int isPalindrome(const char* s, int* count) {
    return recursion(s, 0, strlen(s) - 1, count);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        int count = 0;
        cin >> str;

        cout << isPalindrome(str.c_str(), &count) << " ";
        cout << count << "\n";
    }

	return 0;
}