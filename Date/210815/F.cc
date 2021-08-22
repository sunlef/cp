#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    struct DSU{ //冰茶几
        int n;
        std::vector<int> f, sz;
        DSU(int n) : n(n), f(n+1), sz(n+1, 1) { std::iota(f.begin(), f.end(), 0); }
        int big_brother(int u) {
            if(u > n) return -1;
            while (u != f[u]) u = f[u] = f[f[u]];
            return u;
        }
        bool same(int u, int v) {
            int a = big_brother(u), b = big_brother(v);
            if(a == b && a != -1) return true;
            else return false;
        }
        bool merge(int u, int v){
            if(u > n || v > n) return false;
            int a = big_brother(u), b = big_brother(v);
            if(a == b) return false;
            if(sz[a] > sz[b]) f[b] = a, sz[a] += sz[b];
            else f[a] = b, sz[b] += sz[a];
            return true;
        }
        int size(int u) { return sz[big_brother(u)]; }
    }; 
    
    int n, m;
    cin >> n >> m;
    DSU s(n);

    while(m--){
        int z, x, y;
        cin >> z >> x >> y;
        if(z == 1) s.merge(x, y);
        else cout << (s.same(x,y) ? "Y" : "N") << '\n';
    }

    return 0;
}
