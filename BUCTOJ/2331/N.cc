#include <bits/stdc++.h>
using namespace std;

struct dsu {
    private:
    int n;
    std::vector<int> f, sz;

    public:
    std::vector<int> rank;
    dsu(int n) : n(n), f(n + 1), sz(n + 1, 1), rank(n + 1, 0) { std::iota(f.begin(), f.end(), 0); }
    int big_brother(int u) {
        if (u > n) return -1;
        if (u != f[u]) {
            int v = f[u];
            f[u] = big_brother(v);
            rank[u] += rank[v];
        }
        return f[u];
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
        if (a == b)
            return false;
        else {
            f[b] = a, rank[b] = sz[a];
            sz[a] += sz[b];
            return true;
        }
    }
    int size(int u) { return sz[big_brother(u)]; }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    dsu s(30000);

    while (Q--) {
        char op;
        cin >> op;

        if (op == 'M') {
            int u, v;
            cin >> u >> v;
            s.merge(u, v);
        } else {
            int u;
            cin >> u;

            int a = s.big_brother(u);
            cout << s.size(a) - s.rank[u] - 1 << '\n';
        }
    }

    return 0;
}