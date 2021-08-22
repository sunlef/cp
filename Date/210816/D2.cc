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
    stack<int> s1, s2;

    for(int u = 2; u <= n; ++u) {
        if(Mocha.same(1, u) && Diana.same(1, u)) {
            continue;
        } else if(!Mocha.same(1, u) && !Diana.same(1, u)) {
            ans.emplace_back(make_pair(1, u));
            Mocha.merge(1, u);
            Diana.merge(1, u);
        } else {
            if(!Mocha.same(1, u)) s1.push(u);
            if(!Diana.same(1, u)) s2.push(u);
        }
    }

    while(!s1.empty() && !s2.empty()) {
        int u = s1.top(), v = s2.top();
        if(Mocha.same(1, u) && Diana.same(1, u)) {
            s1.pop();
            continue;
        }
        if(Mocha.same(1, v) && Diana.same(1, v)) {
            s2.pop();
            continue;
        }
        ans.emplace_back(make_pair(u, v));
        Mocha.merge(u, v);
        Diana.merge(u, v);
        s1.pop(), s2.pop();
    }

    cout << ans.size() << '\n';
    for(auto &[u, v] : ans)
        cout << u << ' ' << v << '\n';
    
    return 0;
}
