#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 x, y;
    cin >> x >> y;

    if (x == y) {
        cout << x << '\n';
    } else if (x < y) {
        if (y % x == 0) {
            cout << x << '\n';
        } else {
            i64 mid = (x + y) / 2;
            i64 d = mid - x;
            if (d < x) {
                cout << mid << '\n';
            } else if (d == x) {
                cout << y << '\n';
            } else {
                i64 k = x * i64(y / x);
                cout << (k + y) / 2 << '\n';
            }
        }
    } else {
        cout << x + y << '\n';
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