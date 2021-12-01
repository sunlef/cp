#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    if ((s.back() - '0') % 2 == 0) {
        cout << "0\n";
    } else if ((s.front() - '0') % 2 == 0) {
        cout << "1\n";
    } else {
        for (auto &ch : s) {
            if ((ch - '0') % 2 == 0) {
                cout << "2\n";
                return;
            }
        }
        cout << "-1\n";
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