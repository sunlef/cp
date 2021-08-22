#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

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
    
    DSU Mocha(n), Diana(n);

    for(int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        Mocha.merge(u, v);
    }

    for(int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        Diana.merge(u, v);
    }

    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            if(!Mocha.same(i, j) && !Diana.same(i, j)){
                ans.emplace_back(make_pair(i, j));
                Mocha.merge(i, j);
                Diana.merge(i, j);
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto &[u, v] : ans)
        cout << u << ' ' << v << '\n';
        
    return 0;
}
