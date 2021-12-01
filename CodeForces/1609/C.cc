#include <bits/stdc++.h>

using i64 = int64_t;

constexpr bool is_prime(const int x) {
    if (x <= 1) return false;
    for (int i = 2; i <= std::sqrt(x); ++i)
        if (x % i == 0) return false;
    return true;
}

void solve() {
    int n, e;
    std::cin >> n >> e;

    std::set<int> one, prime;
    for (int i = 0, x; i < n; ++i) {
        std::cin >> x;
        if (x == 1) one.insert(i);
        else if (is_prime(x)) prime.insert(i);
    }

    i64 ans = 0;
    for (auto x : prime) {
        i64 A = 0, B = 0;
        for (int i = x - e; i >= 0; i -= e)
            if (one.count(i)) ++A;
            else break;
        for (int i = x + e; i < n; i += e)
            if (one.count(i)) ++B;
            else break;
        ans += (A + B) + (A * B);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}