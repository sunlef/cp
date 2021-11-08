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

    int n, m;
    cin >> n >> m;

    vector e(n, vector<int>());
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> d(n), a;

    function<void(int, int, int)> dfs = [&](int u, int fa, int now) {
        if (d[u] != 0) {
            a.push_back(now - d[u]);
            return;
        } else {
            d[u] = now;
            for (auto &v : e[u]) {
                if (v != fa && d[v] < d[u]) {
                    dfs(v, u, now + 1);
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            dfs(i, -1, 1);
        }
    }

    Z ans = power(Z(2), m - accumulate(a.begin(), a.end(), 0));
    for (auto &x : a) {
        ans *= power(Z(2), x) - 1;
    }

    cout << ans.val() << '\n';
    return 0;
}