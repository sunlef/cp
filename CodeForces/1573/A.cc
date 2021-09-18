#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '#' + s;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != '0') {
            ans += s[i] - '0';
            if (i != n) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
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