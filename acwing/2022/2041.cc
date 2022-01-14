#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> A(N + 2);
    while (K--) {
        int l, r;
        cin >> l >> r;
        ++A[l];
        --A[r + 1];
    }

    for (int i = 1; i <= N; ++i) {
        A[i] += A[i - 1];
    }

    sort(A.begin() + 1, A.begin() + N + 1);
    cout << A[N / 2 + 1] << '\n';
    return 0;
}