#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> w(n);
    for (int64_t &i : w) {
        cin >> i;
    }

    auto s = w;
    for (int i = 1; i < n; ++i) {
        s[i] += s[i - 1];
    }

    int ans = 0;

    for (int i = 0; i < n - 1; ++i) {
        int L = i + 1, R = n - 1;
        while (L < R) {
            int mid = (L + R) / 2;
            int64_t sum = s.back() - s[mid - 1];
            if (sum <= s[i]) {
                R = mid;
            } else {
                L = mid + 1;
            }
        }

        if (s[i] == s.back() - s[L - 1]) {
            ans = max(ans, n - L + i + 1);
        }

        // cout << i << ' ' << L << ' ' << s[i] << ' ' << s.back() - s[L - 1] << ' ' << ans << '\n';
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int QvQ = 1; QvQ <= T; ++QvQ) {
        solve();
    }

    return 0;
}