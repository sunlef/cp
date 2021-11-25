#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 k, x;
    cin >> k >> x;

    if (x >= k * k) {
        cout << 2 * k - 1 << '\n';
        return;
    }

    if (x <= k * (k + 1) / 2) {
        i64 l = 1, r = k;
        while (l < r) {
            i64 mid = (l + r) / 2;
            if (mid * (mid + 1) / 2 >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l << '\n';
    } else {
        i64 left = x - k * (k + 1) / 2;
        i64 l = 1, r = k - 1;
        while (l < r) {
            i64 mid = (l + r) / 2;
            if ((2 * k - mid - 1) * mid / 2 >= left) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        cout << l + k << '\n';
    }
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