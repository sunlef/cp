#include <bits/stdc++.h>

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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> points(n);

    for (auto &[x, y] : points) {
        std::cin >> x >> y;
    }

    auto sqr = [](int x) -> int64_t { return int64_t(x) * x; };

    auto get_dist = [&](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) -> double {
        return std::sqrt(std::abs(sqr(lhs.first - rhs.first) + sqr(lhs.second - rhs.second)));
    };

    dsu s(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        s.merge(u, v);
    }

    std::vector<std::tuple<double, int, int>> edge;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (s.same(i, j)) {
                continue;
            } else {
                edge.push_back({get_dist(points[i], points[j]), i, j});
            }
        }
    }

    double ans = 0;

    int CUTTOFF = 0;
    for (int i = 0; i < n; ++i) {
        if (s.big_brother(i) == i) {
            ++CUTTOFF;
        }
    }
    --CUTTOFF;

    int cnt = 0;

    std::sort(edge.begin(), edge.end());

    for (auto &[w, u, v] : edge) {
        if (cnt >= n - 1) {
            break;
        } else if (s.same(u, v)) {
            continue;
        } else {
            ans += w;
            s.merge(u, v);
        }
    }


    std::cout << std::fixed << std::setprecision(2) << ans << '\n';
    return 0;
}