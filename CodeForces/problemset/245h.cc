#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector a(s.size(), vector(s.size(), 0));
    vector f(s.size(), vector(s.size(), 0));

    function<bool(int, int)> is_pal = [&](int l, int r) -> bool {
        if (l == r || l == r + 1 || a[l][r]) {
            return true;
        }
        return a[l][r] = is_pal(l + 1, r - 1) && s[l] == s[r];
    };

    function<int(int, int)> dp = [&](int l, int r) -> int {
        if (f[l][r]) {
            return f[l][r];
        }
        return f[l][r] = dp(l + 1, r) + dp(l, r - 1) - dp(l + 1, r - 1) + is_pal(l, r);
    };

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        cout << dp(l, r) << '\n';
    }
    return 0;
}