#include <bits/stdc++.h>
using namespace std;

constexpr int p = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    using i64 = int64_t;
    int n, m;
    cin >> n >> m;

    vector dpa(m + 1, vector<i64>(n + 1));
    for (int i = 1; i <= n; ++i) {
        dpa[1][i] = 1;
    }

    vector dpb = dpa;

    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            i64 &x = dpa[i][j];
            for (int k = 1; k <= j; ++k) {
                x = (x + dpa[i - 1][k]) % p;
            }
        }
    }

    for (int i = 2; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            i64 &x = dpb[i][j];
            for (int k = n; k >= j; --k) {
                x = (x + dpb[i - 1][k]) % p;
            }
        }
    }

    i64 ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            ans = (ans + (dpa[m][i] * dpb[m][j] % p)) % p;
        }
    }

    cout << ans << '\n';


    return 0;
}