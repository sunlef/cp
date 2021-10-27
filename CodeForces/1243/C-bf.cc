#include <bits/stdc++.h>
using namespace std;
#define int long long
bool bf_is_prime(long long x) {
    if (x < 2) return false;
    long long rt = sqrt(x);
    for (int i = 2; i <= rt; ++i)
        if (x % i == 0) return false;
    return true;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;

    if (bf_is_prime(n)) {
        cout << n << '\n';
        return 0;
    }

    int cnt = 0;
    int ans = 0;

    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            if (bf_is_prime(i)) {
                ++cnt;
                ans = i;
            }
            if (n / i != i && bf_is_prime(n / i)) {
                ++cnt;
                ans = n / i; 
            }
        }
    }

    if (cnt == 1) {
        cout << ans << '\n';
    } else {
        cout << "1\n";
    }

    return 0;
}