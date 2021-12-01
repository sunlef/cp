#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n);

    for (i64 &x : a) {
        cin >> x;
    }

    i64 sum = 0;
    for (i64 &x : a) {
        while (x % 2 == 0) {
            ++sum;
            x /= 2;
        }
    }

    ranges::sort(a);

    a.back() *= 1ll << sum;

    i64 ans = accumulate(a.begin(), a.end(), 0ll);
    cout << ans << '\n';
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