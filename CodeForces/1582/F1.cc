#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }

    vector<int> dp(1001, INT_MAX);
    dp[0] = 0;

    int ans = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 1000; j >= 0; --j) {
            if (dp[j] < a[i]) {
                if (dp[j ^ a[i]] == INT_MAX) {
                    ++ans;
                }
                dp[j ^ a[i]] = min(dp[j ^ a[i]], a[i]);
            }
        }
    }

    cout << ans << '\n';
    for (int i = 0; i <= 1000; ++i) {
        if (dp[i] != INT_MAX) {
            cout << i << ' ';
        }
    }
    cout << '\n';

    return 0;
}