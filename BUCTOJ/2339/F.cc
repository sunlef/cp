#pragma GCC optimize(3)
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

vector<Z> pp(50001, 1);

Z C(int M, int N) { return pp[M] / pp[N] / pp[M - N]; }
Z lucas(int M, int N) { return N == 0 ? 1 : lucas(M / P, N / P) * C(M % P, M % P); }

void solve() {
    int K;
    cin >> K;

    int l = 0, r = 50000;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (K >= mid * (mid - 1) / 2 + 1) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    int N = l;
    int M = K - (N * (N - 1) / 2 + 1) + 1;

    --N, --M;

    cout << C(N, M).val() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 1; i <= 50000; ++i) {
        pp[i] = pp[i - 1] * i;
    }

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}