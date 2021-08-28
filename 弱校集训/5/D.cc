#include <bits/stdc++.h>
using namespace std;

vector<int64_t> Fib(41, 1);

void solve() {
    int64_t n;
    int m;
    cin >> n >> m;

    int64_t x = 0, y = Fib[m];

    int64_t t = 1, k = 1;
    while (t <= n) {
        x = (x + n / t) % 1000000007;
        t = k * t / __gcd(k, t);
        ++k;
    }

    int64_t ans = 0;
    int CUTOFF = 100000;
    for (int64_t i = 1; i <= y - 1; ++i) {
        if (i > CUTOFF || i * i > x - 2 * i) {
            break;
        }
        int64_t l = i + 1, r = y;
        while (l < r) {
            int64_t mid = (l + r + 1) / 2;
            if (mid * i + i > x) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }
        ans += l - i;
    }

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    for (int i = 3; i <= 40; ++i) {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}