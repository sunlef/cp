#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int64_t> a(n);

    for (auto &x : a) {
        cin >> x;
    }

    int64_t cnt0 = count(a.begin(), a.end(), 0);

    int64_t ans = count(a.begin(), a.end(), 1);

    for (int i = 0; i < cnt0; ++i) {
        ans *= 2;
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