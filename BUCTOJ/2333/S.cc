#include <bits/stdc++.h>
using namespace std;

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
    int N, M;
    cin >> N >> M;

    dsu s(2 * N);

    while (M--) {
        char op;
        int u, v;
        cin >> op >> u >> v;
        if (N == 2) {
            cout << "In different gangs.\n";
            return;
        } 
        if (op == 'D') {
            s.merge(u, v + N);
            s.merge(v, u + N);
        } else {
            if (s.same(u, v)) {
                cout << "In the same gang.\n";
            } else if (s.same(u, v + N)) {
                cout << "In different gangs.\n";
            } else {
                cout << "Not sure yet.\n";
            }
        }
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