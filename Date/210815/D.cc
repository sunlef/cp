#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    struct DisjointSet{
        int n;
        std::vector<int> fa;
        std::vector<int> sz;
        DisjointSet(int n) : n(n), fa(n+1), sz(n+1) {
            for(int i = 1; i <= n; ++i)
                fa[i] = i, sz[i] = 1;
        }
        int get(int u) {
            if(u > n) return -1;
            return fa[u] == u ? u : fa[u] = get(fa[u]);
        }
        void merge(int x, int y){
            if(x > n || y > n) return;
            int u = get(x), v = get(y);
            if(sz[u] > sz[v]) fa[v] = u, sz[u] += sz[v];
            else fa[u] = v, sz[v] += sz[u];
        }
    } s1(n), s2(n);
    
    for(int i = 1; i <= m1; ++i){
        int u, v;
        cin >> u >> v;
        s1.merge(u,v);
    }
 
    for(int i = 1; i <= m2; ++i){
        int u, v;
        cin >> u >> v;
        s2.merge(u,v);
    }
 
    vector<pair<int, int>> ans;
 
    for(int i = 1; i <= n; ++i){
        for(int j = i+1; j <= n; ++j){
            if((s1.get(i) == s1.get(j)) || (s2.get(i) == s2.get(j)))
                continue;
            ans.emplace_back(make_pair(i, j));
            s1.merge(i,j);
            s2.merge(i,j);
        }
    }
 
    debug(ans);
 
    return 0;
}
