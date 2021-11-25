#include <bits/stdc++.h>
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;

    if ((x + y) & 1) {
        cout << "-1 -1\n";
    } else {
        if (x % 2 == 0) {
            cout << x / 2 << ' ' << y / 2 << '\n';
        } else {
            if (x > y) {
                cout << (x - y) / 2 << ' ' << y << '\n';
            } else {
                cout << x << ' ' << (y - x) / 2 << '\n';
            }
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