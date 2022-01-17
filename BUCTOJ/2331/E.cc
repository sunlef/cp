#include <bits/stdc++.h>
using namespace std;

struct prime {
    size_t max_num;
    std::vector<int> primes;
    std::deque<bool> visted;

    prime(int _max_num) : max_num(size_t(_max_num + 1)), primes(), visted(size_t(_max_num + 1), false) {
        for (size_t i = 2; i <= max_num; ++i) {
            if (!visted[i]) primes.emplace_back(i);
            for (size_t j = 0; j < primes.size() && (__int128_t)(primes[j] * i) <= max_num; ++j) {
                visted[primes[j] * i] = 1;
                if (i % primes[j] == 0) break;
            }
        }
    }

    bool is_prime(int x) {
        if (x < 2 || x > int(max_num)) return false;
        return !visted[x];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    prime pr(9999999);

    int X;
    cin >> X;

    for (auto p : pr.primes) {
        if (p < X) {
            cout << p << '\n';
        } else {
            break;
        }
    }

    return 0;
}