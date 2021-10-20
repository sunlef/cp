#include <bits/stdc++.h>

using namespace std;

void solve() {
    int64_t l1, l2;
    int64_t l = 0, r = 1000000000ll;

    int64_t x;
    cin >> x;

    while (l < r) {
        int64_t mid = (r + l) >> 1;
        if(3 * mid + 1 > x) {
            r = mid;
            l1 = mid;
        } else {
            l = mid + 1;
        }
    }

    l2 = x / 2 + 1;
    r = x;

    int64_t ans = 0;
    if (l1 & 1) {
        ans += (r - l1) / 2 + 1;
    } else {
        if(r & 1) {
            ans += (r - l1) / 2 + 1;
        } else {
            ans += (r - l1) / 2;
        }
    }

    ans += r - l2 + 1;

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