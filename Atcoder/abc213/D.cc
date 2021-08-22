#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> visted(n+1, 0), ans;
    vector<vector<int>> g(n+1);
    for(int i = 0; i < n-1; ++i){
        int x, y;
        cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }

    for(int i = 1; i <= n; ++i){
        sort(g[i].begin(), g[i].end());
    }

    function<void(int)> dfs = [&] (int u){
        visted[u] = 1;
        ans.emplace_back(u);
        for(auto v : g[u]){
            if(visted[v]) continue;
            dfs(v);
            ans.emplace_back(u);
        }
    };

    dfs(1);
    for(auto i : ans)
        cout << i << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}