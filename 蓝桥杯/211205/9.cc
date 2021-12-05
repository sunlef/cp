#include <bits/stdc++.h>
using namespace std;

constexpr int P = 1000000007;
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template <class T> constexpr T power(T a, int b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}

struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    int val() const { return x; }
    Z operator-() const { return Z(norm(P - x)); }
    Z inv() const { return power(*this, P - 2); }

    Z &operator*=(const Z &rhs) {
        x = int32_t(int64_t(x) * rhs.x % P);
        return *this;
    }
    Z &operator+=(const Z &rhs) {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { return *this *= rhs.inv(); }

    friend Z operator*(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) {
        Z res = lhs;
        res /= rhs;
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Z> fact(n + 1, 1);
    vector<Z> inv(n + 1, 1);

    for (int i = 1; i <= n; ++i) {
        fact[i] = fact[i - 1] * i;
        inv[i] = Z(1) / fact[i];
    }

    auto C = [&](int M, int N) -> Z {
        //assert(M - N >= 0);
        return fact[M] * inv[N] * inv[M - N];
    };
    function<Z(int, int)> lucas = [&](int M, int N) -> Z { return N == 0 ? Z(1) : lucas(M / P, N / P) * C(M % P, N % P); };

    cout << lucas(n, n / 2).val() << '\n';
    return 0;
}