#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s;
    cin >> s;

    auto check = [&](const string &str) {
        int n = str.size();
        for (int i = 0; i < n; ++i) {
            if (str[i] != str[n - i - 1]) {
                return true;
            }
        }
        return false;
    };

    string s1 = 'a' + s, s2 = s + 'a';
    if (check(s1)) {
        cout << "YES\n" << s1 << '\n';
    } else if (check(s2)) {
        cout << "YES\n" << s2 << '\n';
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