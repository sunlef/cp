#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    int n;
    i64 h;
    cin >> n >> h;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    auto check = [&](i64 x) {
        i64 now = 0;

        for (int i = 0; i < n - 1; ++i){
            if (a[i + 1] - a[i] < x) {
                now += a[i + 1] - a[i];
            } else {
                now += x;
            }
        }

        now += x;

        return now >= h;
    };

    i64 l = 0, r = 1e18;
    while (l < r) {
        i64 mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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