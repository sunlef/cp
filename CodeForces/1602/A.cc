#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;
    char ch = 'z' + 1;
    for (auto &x : s) {
        ch = min(x, ch);
    }

    cout << ch << ' ';
    bool flag = false;
    for (auto &x : s) {
        if (x == ch && !flag) {
            flag = true;
        } else {
            cout << x;
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