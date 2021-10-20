//https://www.luogu.com.cn/problem/P1226

#include <bits/stdc++.h>
using namespace std;
namespace Math {

// @param m `1 <= m`
// @return x mod m
constexpr long long mod(long long x, long long m) {
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

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
// 用我看不懂的方法判断素数
bool is_prime(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod(a, t, n);
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

unsigned long long times(unsigned long long a, unsigned long long b, int p) {
    if (a == 0ull || b == 0ull) return 0;
    unsigned long long res = 0;
    for (; b; b >>= 1, a = 2 * a % p)
        if (b & 1) res = (res + a) % p;
    return res;
}

template <typename T, typename U> T gcd(T __m, U __n) {  //__gcd
    if (__m == 0) return __n;
    if (__n == 0) return __m;
    while (__n != 0) {
        T __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}

template <typename T, typename U> T lcm(T __m, U __n) {  //__lcm
    return (__m != 0 && __n != 0) ? (__m / gcd(__m, __n)) * __n : 0;
}

template <typename T, typename U> T getRevksm(T a, U p) {  //欧拉逆天
    return pow_mod(a, p - 2, p);
}

template <typename T, typename A, typename C, typename D> T exgcd(T a, A b, C& x, D& y) {
    if (a == 0 && b == 0) return -1;
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    T d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

template <typename T, typename U> T getRevexgcd(T a, U n) {  //扩展欧几里得逆天
    T x, y;
    T d = exgcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

}  // namespace Math


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, p;
    cin >> a >> b >> p;
    printf("%d^%d mod %d=%lld\n", a, b, p, Math::pow_mod(a, b, p));
    
    return 0;
}