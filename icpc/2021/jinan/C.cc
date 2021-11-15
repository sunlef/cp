#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998'244'353;
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

    vector<int> cnt(n + 1);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++cnt[x];
    }

    auto pre = cnt;
    for (int i = 1; i <= n; ++i) {
        pre[i] += pre[i - 1];
    }

    vector<Z> fac(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        fac[i] = fac[i - 1] * i;
    }

    auto C = [&](int m, int n) -> Z {
        Z res = fac[m];
        res /= fac[n];
        res /= fac[m - n];
        return res;
    };

    Z ans = 1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] == 0) {
            continue;
        }
        ans *= C(pre[i - 1] + cnt[i] / 2, pre[i - 1]) * fac[cnt[i]];
    }

    cout << ans.val() << '\n';
    return 0;
}