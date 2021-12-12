#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (auto &ai : a) {
        cin >> ai;
    }
    for (auto &bi : b) {
        cin >> bi;
    }

    vector dp(n, vector<int64_t>(3));
    dp[0][0] = 0;
    dp[0][1] = a[0];
    dp[0][2] = b[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = a[i] + max(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = b[i] + max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << max({dp[n - 1][0], dp[n - 1][1], dp[n - 1][2]}) << '\n';

    return 0;
}