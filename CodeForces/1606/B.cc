#include <bits/stdc++.h>
using namespace std;

void solve() {
    using i64 = int64_t;

    i64 n, k;
    cin >> n >> k;

    i64 ok = 1;
    i64 ans = 0;
    
    for (i64 i = 1; i <= k && ok < n && ok <= k; ++i) {
        ok += ok;
        ++ans;
    }

    if (ok < n) {
        i64 l = n - ok;
        i64 t = (l + k - 1) / k;
        ans += t;
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