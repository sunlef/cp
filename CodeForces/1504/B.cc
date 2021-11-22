#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    auto flip = [&](int l, int r) -> void {
        for (int i = l; i < r; ++i) {
            if (s[i] == '1') {
                s[i] = '0';
            } else {
                s[i] = '1';
            }
        }
    };

    int a = 0, b = 0;
    int j = -1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            ++a;
        } else {
            ++b;
        }

        if (a == b) {
            if (s[i] != t[i]) {
                flip(j + 1, i + 1);
            }
            j = i;
        }
    }

    if (s == t) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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