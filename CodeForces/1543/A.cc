#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 a, b;
    cin >> a >> b;

    if (a == b) {
        cout << "0 0\n";
        return;
    } else if (a > b) {
        swap(a, b);
    }

    i64 g = abs(a - b);
    i64 ans = min(a % g, g - a % g);

    cout << g << ' ' << ans << '\n';
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