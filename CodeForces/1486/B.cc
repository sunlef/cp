#include <bits/stdc++.h>
using namespace std;
#define int int64_t

void solve() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    ranges::sort(x);
    ranges::sort(y);

    if (n % 2 == 0) {
        int xx, yy;
        xx = x[n / 2] - x[n / 2 - 1] + 1;
        yy = y[n / 2] - y[n / 2 - 1] + 1;
        cout << xx * yy << '\n';
    } else {
        cout << 1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}