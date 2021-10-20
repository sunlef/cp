#include <bits/stdc++.h>
using namespace std;

long long mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
    unsigned int _m;
    unsigned long long im;
    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}
    unsigned int umod() const { return _m; }
    unsigned int mul(unsigned int a, unsigned int b) const {
        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x = (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};

// 快速米
long long pow_mod(long long x, long long n, int m) {
    assert(0 <= n && 1 <= m);
    if (m == 1) return 0;
    barrett bt((unsigned int)(m));
    unsigned int r = 1, y = (unsigned int)(mod(x, m));
    while (n) {
        if (n & 1) r = bt.mul(r, y);
        y = bt.mul(y, y);
        n >>= 1;
    }
    return r;
}



void solve() {
    vector<int> dp(10, 0);
    string s;
    cin >> s;
    vector<int> cnt(int(s.size()), 0);
    vector<int> cnta(int(s.size() + 1), 0);

    for (int i = 1; i <= s.size(); ++i) {
        cnta[i] = cnta[i - 1] + int(s[i - 1] == 'a');
    }

    constexpr int MOD = 998244353;

    auto geta = [&](int posl, int posr) -> int { return cnta[posr + 1] - cnta[posl]; };

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'n') {
            dp[3] = mod(dp[3] + dp[2], MOD);
            dp[1] = mod(dp[1] + 1, MOD);
        } else if (s[i] == 'u') {
            dp[2] = mod(dp[1] + dp[2], MOD);
        } else if (s[i] == 'h') {
            dp[9] = mod(dp[8] + dp[9], MOD);
            dp[7] = mod(dp[7] + dp[6], MOD);
            dp[6] = mod(dp[5] + dp[6], MOD);
            dp[4] = mod(dp[3] + dp[4], MOD);
        } else if (s[i] == 'e') {
            dp[8] = mod(dp[8] + dp[7], MOD);
            dp[5] = mod(dp[4] + dp[5], MOD);
        }
        cnt[i] = dp[9];
    }

    int64_t ans = 0;
    for (int i = 1; i < s.size(); ++i) {
        if (i + 1 <= s.size() - 1) {
            int cntpre = mod(cnt[i] - cnt[i - 1], MOD);

            int count_a = geta(i + 1, s.size() - 1);
            int64_t pow = mod(pow_mod(2, count_a, MOD) - 1, MOD);
            int64_t tmp = mod(pow * cntpre, MOD);
            ans = mod(ans + tmp, MOD);
        }
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