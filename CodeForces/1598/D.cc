#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (auto &pr : a) {
        cin >> pr.first >> pr.second;
        --pr.first, --pr.second;
    }

    vector<int> cnta(n), cntb(n);
    for (auto &pr : a) {
        ++cnta[pr.first], ++cntb[pr.second];
    }

    using i64 = int64_t;

    i64 ans = i64(n - 2) * (n - 1) * n / 6;

    for (auto &pr : a) {
        ans -= i64(cnta[pr.first] - 1) * i64(cntb[pr.second] - 1);
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