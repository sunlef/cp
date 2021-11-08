#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 x, n;
    cin >> x >> n;
    int c = n % 4;
    if (x % 2 == 0) {
        if (c == 0) {
            cout << x << '\n';
        } else if (c == 1) {
            cout << x - n << '\n';
        } else if (c == 2) {
            cout << x + 1 << '\n';
        } else {
            cout << x + n + 1 << '\n';
        }
    } else {
        if (c == 0) {
            cout << x << '\n';
        } else if (c == 1) {
            cout << x + n << '\n';
        } else if (c == 2) {
            cout << x - 1 << '\n';
        } else {
            cout << x - (n + 1) << '\n';
        }
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