#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector ans(n + 1, vector<int>(n));
    for (auto &x : ans[0]) {
        cin >> x;
    }

    for (int i = 1; i <= n; ++i) {
        vector<int> cnt(n + 1);
        for (int j = 0; j < n; ++j) {
            ++cnt[ans[i - 1][j]];
        }
        for (int j = 0; j < n; ++j) {
            ans[i][j] = cnt[ans[i - 1][j]];
        }
    }

    int q;
    cin >> q;
    while (q--) {
        int x, k;
        cin >> x >> k;
        --x;
        k = min(n, k);
        cout << ans[k][x] << '\n';
    }
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