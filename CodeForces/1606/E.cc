#include <bits/stdc++.h>
using namespace std;

constexpr int P = 998244353;
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

    Z C[502][502], pw[502][502];
    for (int i = 0; i < 502; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
        pw[i][0] = 1;
        for (int j = 1; j < 502; ++j) {
            pw[i][j] = pw[i][j - 1] * i;
        }
    }

    int n, x;
    cin >> n >> x;

    vector dp(n + 1, vector<Z>(x + 1));
    for (int i = 1; i <= x; ++i) {
        dp[1][i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = i; j <= x; ++j) {
            for (int k = 1; k <= i; ++k) {
                dp[i][j] += dp[k][j - (i - 1)] * C[i][k] * pw[i - 1][i - k];
            }
        }
    }

    cout << (pw[x][n]-dp[n][x]).x << '\n';
    return 0;
}