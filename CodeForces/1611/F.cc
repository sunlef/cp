#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

template <class T> struct ST {
    int n;
    vector<vector<T>> info;

    T merge(const T &lhs, const T &rhs) {
        // TODO: 修改merge
        return std::min(lhs, rhs);
    }

    ST(const vector<T> &init) : n(int(init.size())), info(n + 1, vector<T>(__lg(n) + 1, INT_MAX)) {
        //TODO : 修改初值
        for (int x = 0; x <= __lg(n); ++x)
            for (int i = 0; i + (1 << x) <= n; ++i)
                if (x == 0)
                    info[i][x] = init[i];
                else
                    info[i][x] = merge(info[i][x - 1], info[i + (1 << (x - 1))][x - 1]);
    }

    T query(int l, int r) {  //[l, r)
        int len = r - l;
        assert(len > 0);
        return merge(info[l][__lg(len)], info[r - (1 << __lg(len))][__lg(len)]);
    }
};

void solve() {
    int n, s;
    cin >> n >> s;

    vector<i64> a(n);
    for (i64 &x : a) {
        cin >> x;
    }

    for (int i = 1; i < n; ++i) {
        a[i] += a[i - 1];
    }

    ST<i64> st(a);

    int ansl, ansr;
    auto check = [&](int x) -> bool {
        for (int i = x; i <= n; ++i) {
            if (st.query(i - x, i) >= (i - x == 0 ? 0 : a[i - x - 1]) -s) {
                ansl = i - x, ansr = i;
                return true;
            }
        }
        return false;
    };

    int l = 0, r = n;
    while (l < r) {
        int mid = (l + r + 1) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }

    if (l == 0) {
        cout << "-1\n";
    } else {
        cout << ansl + 1 << ' ' << ansr << '\n';
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