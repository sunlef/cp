#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

vector<i64> pw10(20, 1);

void solve() {
    int n;
    i64 k;
    cin >> n >> k;

    int a[n + 1];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    a[n] = 18;

    i64 ans = 0, now = k + 1;
    for (int i = 0; i < n; ++i) {
        int d = a[i + 1] - a[i];
        i64 d99 = pw10[d] - 1;
        i64 cnt = min(now, d99);
        ans += cnt * pw10[a[i]];
        now -= cnt;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i < 20; ++i) {
        pw10[i] = pw10[i - 1] * 10;
    }

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}