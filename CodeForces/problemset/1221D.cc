#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    constexpr int64_t INF = 0x3f3f3f3f3f3f3f3f;
    vector dp(n, vector<int64_t>(3, INF));
    dp[0][0] = 0;
    dp[0][1] = b[0];
    dp[0][2] = 2 * b[0];

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= 2; ++j) {
            for (int k = 0; k <= 2; ++k) {
                int64_t A = a[i - 1] + j;
                int64_t B = a[i] + k;
                if (A != B) {
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + k * b[i]);
                }
            }
        }
    }

    cout << min({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';
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