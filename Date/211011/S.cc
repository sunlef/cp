#include <bits/stdc++.h>
using namespace std;

using i64 = int64_t;

struct dsu {
    private:
    int n;
    std::vector<int> f, sz;

    public:
    dsu(int n) : n(n), f(n + 1), sz(n + 1, 1) { std::iota(f.begin(), f.end(), 0); }
    int big_brother(int u) {
        if (u > n) return -1;
        while (u != f[u]) u = f[u] = f[f[u]];
        return u;
    }
    bool same(int u, int v) {
        int a = big_brother(u), b = big_brother(v);
        if (a == b && a != -1)
            return true;
        else
            return false;
    }
    bool merge(int u, int v) {
        if (u > n || v > n) return false;
        int a = big_brother(u), b = big_brother(v);
        if (a == b) return false;
        if (sz[a] > sz[b])
            f[b] = a, sz[a] += sz[b];
        else
            f[a] = b, sz[b] += sz[a];
        return true;
    }
    int size(int u) { return sz[big_brother(u)]; }
};

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> vec(n);

    for (auto &pr : vec) {
        cin >> pr.first >> pr.second;
    }

    constexpr auto dist = [](pair<int, int> &A, pair<int, int> &B) {
        return i64(A.first - B.first) * (A.first - B.first) + i64(A.second - B.second) * (A.second - B.second);
    };

    vector<tuple<i64, int, int>> E;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                E.emplace_back(make_tuple(dist(vec[i], vec[j]), i, j));
            }
        }
    }

    dsu s(E.size());
    sort(E.begin(), E.end());

    int now_cnt = 0;
    i64 MAX = INT64_MIN;

    for (auto &x : E) {
        auto w = get<0>(x);
        auto u = get<1>(x);
        auto v = get<2>(x);

        if (s.same(u, v)) {
            continue;
        }
        ++now_cnt;
        MAX = max(MAX, w);
        s.merge(u, v);
        if (now_cnt == n - 1) {
            break;
        }
    }

    cout << MAX << endl;
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