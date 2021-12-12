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
prime<int> PRIME(10000);

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << PRIME.primes[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}