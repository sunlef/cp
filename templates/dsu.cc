//https://www.luogu.com.cn/problem/P3367

#include <bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

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

    int n, m;
    cin >> n >> m;
    dsu s(n);

    while (m--) {
        int op, u, v;
        cin >> op >> u >> v;
        if (op == 1) {
            s.merge(u, v);
        } else {
            cout << (s.same(u, v) ? "Y" : "N") << '\n';
        }
    }

    return 0;
}