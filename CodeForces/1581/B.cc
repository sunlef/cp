#include <bits/stdc++.h>
using namespace std;

void solve() {
    int64_t n, m, k;
    cin >> n >> m >> k;

    if (n == 1) {
        if (m != 0) {
            cout << "NO\n";
            return;
        }
        if (k < 2) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }

    int64_t U = n * (n - 1) / 2;
    int64_t D = n - 1;

    if (!(D <= m && m <= U) || k - 2 < 1) {
        cout << "NO" << '\n';
        return;
    }

    if (k == 3) {
        if (m == U) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "YES\n";
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