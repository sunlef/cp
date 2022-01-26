#include <bits/stdc++.h>
using namespace std;

vector<int64_t> a = {1, 2, 6, 30, 210, 2310, 30030, 510510, 9699690, 223092870, 6469693230};

struct barrett {
    uint32_t _m;
    uint64_t im;
    explicit barrett(uint32_t m) : _m(m), im((uint64_t)(-1) / m + 1) {}
    uint32_t umod() const { return _m; }
    uint32_t mul(uint32_t a, uint32_t b) const {
        uint64_t z = a;
        z *= b;
#ifdef _MSC_VER
        uint64_t x;
        _umul128(z, im, &x);
#else
        uint64_t x = (uint64_t)(((unsigned __int128)(z)*im) >> 64);
#endif
        uint32_t v = (uint32_t)(z - x * _m);
        if (_m <= v) {
            v += _m;
        }
        return v;
    }
};

constexpr uint32_t get_mod(int64_t x, int32_t p) {
    x %= p;
    if (x < 0) {
        x += p;
    }
    return x;
}

uint32_t pow_mod(int64_t x, int64_t n, int32_t p) {
    if (p == 1) {
        return 0;
    }
    barrett bt(p);
    uint32_t res = 1, y = get_mod(x, p);
    while (n) {
        if (n & 1) {
            res = bt.mul(res, y);
        }
        y = bt.mul(y, y);
        n >>= 1;
    }
    return res;
}

uint32_t mul_mod(int64_t _x, int64_t _y, int32_t p) {
    uint32_t res = 0, x = get_mod(_x, p), y = get_mod(_y, p);
    if (p == 1 || x == 0 || y == 0) {
        return 0;
    }
    barrett bt(p);
    while (y) {
        if (y & 1) {
            res = get_mod(res + x, p);
        }
        x = bt.mul(2, x);
        y >>= 1;
    }
    return res;
}

uint32_t inv_mod(int64_t a, int32_t p) { return pow_mod(a, p - 2, p); }

int64_t exgcd(int64_t a, int64_t b, int64_t &x, int64_t &y) {
    if (a == 0 && b == 0) {
        return -1;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int64_t d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

int64_t inv_gcd(int64_t a, int64_t p) {
    int64_t x, y;
    int64_t d = exgcd(a, p, x, y);
    if (d == 1)
        return (x % p + p) % p;
    else
        return -1;
}

bool is_prime(int32_t n) {
    if (n <= 1) {
        return false;
    }
    if (n == 2 || n == 7 || n == 61) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    int64_t d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    constexpr int64_t bases[3] = {2, 7, 61};
    for (int64_t a : bases) {
        int64_t t = d;
        int64_t y = pow_mod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "-1\n";
        return;
    }

    int l = 0, r = 10;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (a[mid] <= n) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    cout << a[l] << ' ';

    for (int i = n;; --i) {
        if (is_prime(i)) {
            cout << i << '\n';
            break;
        }
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