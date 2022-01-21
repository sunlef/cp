#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
    }

    nth_element(A.begin(), A.begin() + N / 2, A.end());
    int64_t ans = 0;

    for (int i = 0; i < N; ++i) {
        ans += abs(A[i] - A[N / 2]);
    }

    cout << ans << '\n';
    return 0;
}