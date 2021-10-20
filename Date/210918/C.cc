#include <bits/stdc++.h>
using namespace std;

template <typename T> struct prime {
    T max_num;
    vector<T> primes;
    vector<int> visted;
    prime(T max_num) : max_num(max_num), primes(), visted(max_num + 1, 0) {
        for (T i = 2; i <= max_num; ++i) {
            if (!visted[i]) primes.emplace_back(i);
            for (T j = 0; j < primes.size() && (__int128_t)(primes[j] * i) <= max_num; ++j) {
                visted[primes[j] * i] = 1;
                if (i % primes[j] == 0) break;
            }
        }
    }
    bool is_prime(T x) {
        if (x < 2 || x > max_num) return false;
        return !visted[x];
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;

    prime PRIME(1000000);

    while (cin >> n && n != 0) {
        int64_t ans = 1;
        for (auto P : PRIME.primes) {
            int64_t cnt = [n, P]() mutable -> int64_t {
                if (P > n) {
                    return 0;
                } else {
                    int res = 0;
                    while (n) {
                        res += n / P;
                        n /= P;
                    }
                    return res;
                }
            }();
            ans = ans * ((cnt + 1) * (cnt + 2) / 2) % 10000007;
        }
        cout << ans << '\n';
    }

    return 0;
}