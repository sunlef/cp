#include <bits/stdc++.h>
using namespace std;

void solve() {
    int c, d;
    cin >> c >> d;
    if (c == d) {
        if (c == 0) {
            cout << 0 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        if (abs(c - d) & 1) {
            cout << - 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}