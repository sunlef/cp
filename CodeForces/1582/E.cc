#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }

    int max_k = 0, r = 448;
    while (max_k < r) {
        int mid = (max_k + r) / 2;
        if ((1 + mid) * mid / 2 >= n) {
            r = mid;
        } else {
            max_k = mid + 1;
        }
    }

    auto acc = [&](int pos, int len) { return a[pos + len - 1] - (pos == 0 ? 0 : a[pos - 1]); };

    vector dp(n + 1, vector<int64_t>(max_k + 1, INT_MIN));
    dp[n][0] = INT_MAX;

    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j <= max_k; ++j) {
            dp[i][j] = dp[i + 1][j];
            if (i + j - 1 >= n || i + j - 1 < 0) {
                continue;
            } else {
                if (acc(i, j) < dp[i + j][j - 1]) {
                    dp[i][j] = max(dp[i][j], acc(i, j));
                }
            }
        }
    }

    for (int j = max_k; j >= 1; --j) {
        if (dp[0][j] != INT_MIN) {
            cout << j << '\n';
            return;
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}