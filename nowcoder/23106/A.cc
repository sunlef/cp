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

    int N;
    cin >> N;

    auto root = [](int x) -> int {
        if (x % 9 == 0) {
            return 9;
        } else {
            return x % 9;
        }
    };

    vector<int> A(N);
    for (int &i : A) {
        cin >> i;
        i = root(i);
    }

    vector<vector<Z>> dp(N, vector<Z>(10));

    dp[0][A[0]] = 1;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            dp[i][root(j + A[i])] += dp[i - 1][j];
        }
        dp[i][A[i]] += 1;
        for (int j = 0; j <= 9; ++j) {
            dp[i][j] += dp[i - 1][j];
        }
    }

    for (int i = 1; i <= 9; ++i) {
        cout << dp.back()[i].val() << ' ';
    }
    cout << '\n';

    return 0;
}