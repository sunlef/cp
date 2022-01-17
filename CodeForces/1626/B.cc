#include <bits/stdc++.h>
using namespace std;

void solve() {
    string x;
    cin >> x;

    int n = x.size();

    for (int i = 1; i < n; ++i) {
        int c = x[i] + x[i - 1] - 2 * '0';
        if (c > 9 && c >= 10 * (x[i - 1] - '0') + x[i] - '0') {
            cout << x.substr(0, i - 1);
            cout << c;
            if (i + 1 < n) {
                cout << x.substr(i + 1);
            }
            cout << '\n';
            return;
        }
    }

    for (int i = n - 1; i >= 1; --i) {
        int c = x[i] + x[i - 1] - 2 * '0';
        if (c > 9) {
            cout << x.substr(0, i - 1);
            cout << c;
            if (i + 1 < n) {
                cout << x.substr(i + 1);
            }
            cout << '\n';
            return;
        }
    }

    cout << x[0] + x[1] - 2 * '0';
    if (2 < n) {
        cout << x.substr(2);
    }
    cout << '\n';
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