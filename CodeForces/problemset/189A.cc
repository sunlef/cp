#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    vector<int> a(3);
    cin >> n;
    for (int &x : a) {
        cin >> x;
    }

    vector dp(n + 1, INT_MIN);
    dp[0] = 0;

    for (int j = 0; j <= n; ++j) {
        for (int i = 0; i < 3; ++i) {
            if (j >= a[i]) {
                dp[j] = max(dp[j], dp[j - a[i]] + 1);
            }
        }
    }

    cout << dp[n] << '\n';
    return 0;
}