#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, W;
    cin >> N >> W;

    vector<int64_t> weights(N), values(N);
    for (int64_t &i : weights) {
        cin >> i;
    }

    for (int64_t &i : values) {
        cin >> i;
    }

    vector<int64_t> dp(10001, INT_MAX);
    dp.front() = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 10000; j >= values[i]; --j) {
            dp[j] = min(dp[j], dp[j - values[i]] + weights[i]);
        }
    }
    
    int ans = INT_MIN;
    for (int i = 0; i <= 10000; ++i) {
        if (dp[i] != INT_MAX && dp[i] <= W) {
            ans = max(ans, i);
        }
    }

    cout << ans << '\n';

    return 0;
}