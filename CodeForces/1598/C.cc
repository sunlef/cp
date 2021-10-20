#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> a(n);
    map<int64_t, int64_t> mp;

    int64_t sum = 0;
    for (auto &x : a) {
        cin >> x;
        sum += x;
        x *= n;
        ++mp[x];
    }

    int64_t ans = 0;
    int64_t T = 2 * sum;
    for (auto &X : a) {
        int64_t f = T - X;
        if (f == X) {
            ans += mp[f] - 1;
        } else {
            ans += mp[f];
        }
    }
    cout << ans / 2 << '\n';
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