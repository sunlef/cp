#include <bits/stdc++.h>
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int aa, bb, cc;
    int t = max(b, c);
    if (t < a) {
        aa = 0;
    } else {
        aa = t - a + 1;
    }

    t = max(a, c);
    if (t < b) {
        bb = 0;
    } else {
        bb = t - b + 1;
    }

    t = max(a, b);
    if (t < c) {
        cc = 0;
    } else {
        cc = t - c + 1;
    }
    cout << aa << ' ' << bb << ' ' << cc << '\n';
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