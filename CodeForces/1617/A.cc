#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    string t;
    cin >> s >> t;

    if (t != "abc") {
        ranges::sort(s);
        cout << s << '\n';
    } else {
        if (!ranges::count(s, 'a')) {
            ranges::sort(s);
            cout << s << '\n';
        } else {
            ranges::sort(s, [](char lhs, char rhs) {
                if (lhs == 'b' && rhs == 'c') {
                    return false;
                } else if (lhs == 'c' && rhs == 'b') {
                    return true;
                } else {
                    return lhs < rhs;
                }
            });
            cout << s << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}