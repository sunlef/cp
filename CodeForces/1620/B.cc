#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w, h;
    cin >> w >> h;

    array<vector<int64_t>, 4> a;

    int64_t ans = 0;
    for (int i = 0; i < 4; ++i) {
        int k;
        cin >> k;
        a[i].resize(k);
        for (int64_t &x : a[i]) {
            cin >> x;
        }
        ans = max(ans, (a[i].back() - a[i].front()) * (i < 2 ? h : w));
    }

    cout << ans << '\n';
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