#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<i64> A(N);
    for (i64 &i : A) {
        cin >> i;
    }

    for (int i = 1; i < N; ++i) {
        A[i] += A[i - 1];
    }

    auto sum = [&](int l, int r) -> i64 {
        if (l == 0) {
            return A[r];
        } else {
            return A[r] - A[l - 1];
        }
    };

    i64 ans = INT64_MIN;
    for (int i = M; i - 1 < N; ++i) {
        ans = max(ans, sum(i - M, i - 1));
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