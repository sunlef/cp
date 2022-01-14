#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string ans;
    for (int i = 1; i < n; ++i) {
        if (s[i] >= s.front()) {
            string ans = s.substr(0, i);
            ans += string(ans.rbegin(), ans.rend());
            cout << ans << '\n';
            return;
        }
        if (i == n - 1) {
            string ans = s + string(s.rbegin(), s.rend());
            cout << ans << '\n';
        }
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