#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    i64 h;
    cin >> n >> h;

    vector<i64> a(n);
    for (i64 &ai : a) {
        cin >> ai;
    }

    cout << *ranges::partition_point(ranges::iota_view(0ll, h), [&](i64 x) {
        i64 now = x;
        for (int i = 0; i < n - 1; ++i) {
            now += min(a[i + 1] - a[i], x);
        }
        return now < h;
    }) << '\n';
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