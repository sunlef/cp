#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    int64_t a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;
    s.push_back('0');

    const int64_t INF = 0x3f3f3f3f3f3f3f3f;
    vector dp(n + 1, vector<int64_t>(2, INF));
    dp[0][0] = b;

    for (int i = 1; i <= n; ++i) {
        if (s[i - 1] == '1' || s[i] == '1') {
            dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + 2 * b;
            dp[i][0] = INF;
        } else {
            dp[i][1] = min(dp[i - 1][0] + 2 * a, dp[i - 1][1] + a) + 2 * b;
            dp[i][0] = min(dp[i - 1][0] + a, dp[i - 1][1] + 2 * a) + b;
        }
    }

    cout << dp[n][0] << '\n';
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