#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int64_t> A(N);
    for (int64_t &i : A) {
        cin >> i;
        i *= i;
    }

    for (int i = 1; i < N; ++i) {
        A[i] += A[i - 1];
    }

    int64_t ans = LLONG_MAX;
    for (int i = 0; i + M - 1 < N; ++i) {
        ans = min(ans, A[i + M - 1] - (i == 0 ? 0 : A[i - 1]));
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}