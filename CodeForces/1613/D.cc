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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &ai : a) {
        cin >> ai;
    }

    vector dp(n + 3, vector<Z>(3));
    /*
        dp[i][0] : 以 i 结尾的，形如 [0, 0, 1, 2, ..., n - 2, n - 2, n, n, n - 2] 的序列的个数
        dp[i][1] : 以 i 结尾的，形如 [0, 0, 1, 2, 3, ..., n, n, n] 的序列的个数
        dp[i][2] : 以 i 结尾的，形如 [0, 0, 1, 2, ..., n - 2, n - 2, n, n, n , n] 的序列的个数 

        除了这两种序列，还有一种是 [1, 1, 1, 1, ..., 1, 1]，最后再统计 1 的个数
    */
    for (int &ai : a) {
        if (ai == 0) {
            dp[ai][1] *= 2;
            dp[ai][1] += 1;
        } else if (ai == 1) {
            dp[ai][1] *= 2;
            dp[ai][1] += dp[0][1];
        } else {
            dp[ai][1] *= 2;
            dp[ai][1] += dp[ai - 1][1];

            dp[ai][0] *= 2;
            dp[ai][0] += dp[ai - 2][1] + dp[ai - 2][2];
        }

        if (ai + 2 <= n) {
            dp[ai][2] *= 2;
            dp[ai][2] += dp[ai + 2][0];
        }
    }

    Z ans = 0;
    for (int i = 0; i <= n; ++i) {
        for (auto &res : dp[i]) {
            ans += res;
        }
    }

    ans += power(Z(2), int(ranges::count(a, 1))) - 1;
    cout << ans.val() << '\n';
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