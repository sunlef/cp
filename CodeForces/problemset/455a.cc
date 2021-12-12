#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int64_t> a(n);
    vector<int64_t> cnt(1e5 + 1);

    for (int64_t &ai : a) {
        cin >> ai;
        ++cnt[ai];
    }

    vector dp(1e5 + 1, vector<int64_t>(2));


    for (int i = 1; i <= 1e5; ++i) {
        dp[i][1] = i * cnt[i];
        dp[i][1] += dp[i - 1][0];
        dp[i][0] += std::max(dp[i - 1][0], dp[i - 1][1]);
    }

    cout << std::max(dp[1e5][0], dp[1e5][1]) << '\n';
    return 0;
}