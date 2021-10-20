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
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> a(n * m);

    for (int i = 0; i < n * m; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n * m; i += m) {
        sort(a.begin() + i, a.begin() + i + m, [](const pair<int, int> &A, const pair<int, int> &B) -> bool const {
            if (A.first == B.first) {
                return A.second > B.second;
            } else {
                return A.first < B.first;
            }
        });
    }

    for (int i = 0; i < n * m; ++i) {
        a[i].first = i + 1;
    }

    vector<int> b(n * m);
    for (auto &[x, y] : a) {
        b[y] = x;
    }

    fenwick<int> fen(n * m);

    int64_t ans = 0;
    for (auto &x : b) {
        int pos = int((x - 1) / m) * m;
        ans += fen.query(x) - fen.query(pos);
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