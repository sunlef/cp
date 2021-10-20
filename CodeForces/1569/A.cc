#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    auto check = [&](int l, int r) -> bool {
        int a = 0, b = 0;
        for (int i = l - 1; i <= r - 1; ++i) {
            if (s[i] == 'a') {
                ++a;
            } else {
                ++b;
            }
        }
        return a == b;
    };

    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (check (i, j)) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
    cout << -1 << ' ' << -1 << '\n';
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