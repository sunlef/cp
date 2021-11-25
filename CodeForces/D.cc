#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

void solve() {
    i64 a, b, x;
    cin >> a >> b >> x;

    if (a > b) {
        swap(a, b);
    }

    while (a) {
        if (max(a, b) < x) {
            cout << "NO\n";
            return;
        } else if ((x - b % a) % a == 0) {
            cout << "YES\n";
            return;
        }
        swap(a, b);
        a %= b;
    }

    cout << "NO\n";
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