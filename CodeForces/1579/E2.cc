#include <bits/stdc++.h>
using namespace std;

template <typename T> struct fenwick {
    private:
    int n;
    std::vector<T> c;

    public:
    fenwick(int n) : n(n + 1), c(n + 1) {}
    void add(int pos, T val) {
        for (; pos < n; pos += pos & -pos) c[pos] += val;
    }
    T query(int pos) {
        T res = 0;
        for (; pos; pos -= pos & -pos) res += c[pos];
        return res;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> _a(n);
    for (auto &x : _a) {
        cin >> x;
    }
    auto a = _a;

    sort(_a.begin(), _a.end());
    _a.erase(unique(_a.begin(), _a.end()), _a.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lower_bound(_a.begin(), _a.end(), a[i]) - _a.begin() + 1;
    }

    int m = _a.size();
    fenwick<int64_t> fen(m + 10);

    int64_t ans = 0;
    for (auto &x : a) {
        int64_t t1 = fen.query(x - 1) - fen.query(0);
        int64_t t2 = fen.query(m + 5) - fen.query(x);
        ans += min(t1, t2);
        fen.add(x, 1);
    }

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    cin >> T;
    for (int TwT = 1; TwT <= T; ++TwT) {
        solve();
    }

    return 0;
}