#include <iostream>
#include <algorithm>

using namespace std;

int N;
int A[1000];

int Solution() {
    sort(A, A + N);

    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (sum + 1 < A[i])  break;
        sum += A[i];
    }

    return ++sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << Solution();

    return 0;
}