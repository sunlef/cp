#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, s;
    cin >> n >> s;
    n /= 2;
    int64_t l = 0, r = s + 1;
    while (l < r) {
        auto mid = (l + r + 1) / 2;
        if ([&](int64_t x) -> bool {
                int64_t sum = n * x;
                int64_t left = s - sum;
                return left >= x;
            }(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    cout << l << '\n';
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