#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (auto ch : s) {
        if (ch == 'L' || ch == 'R') {
            cout << ch;
        } else if (ch == 'U') {
            cout << 'D';
        } else {
            cout << 'U';
        }
    }
    cout << '\n';
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