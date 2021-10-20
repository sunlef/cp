#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g1(n+1);
    vector<vector<int>> g2(n+1);
    
    for(int i = 2; i <= n; ++i){
        int x;
        cin >> x;
        g1[x].emplace_back(i);
    }
    for(int i = 2; i <= n; ++i){
        int x;
        cin >> x;
        g2[x].emplace_back(i);
    }

    vector<int> in(n+1), out(n+1);

    int stamp = 0;
    function<void(int)> dfs = [&] (int u){
        in[u] = ++stamp;
        for(auto v : g2[u])
            dfs(v);
        out[u] = stamp;
    };

    dfs(1);

    int ans = 0;
    set<pair<int, int>> s;
    dfs = [&] (int u){
        bool added = false, deled = false;
        pair<int, int> d;

        auto it = s.upper_bound({in[u], out[u]});
        if(it == s.end() || (*it).first > out[u]){
            added = true;
            if(it != s.begin()){
                --it;
                if((*it).second >= out[u]){
                    deled = true;
                    d = *it;
                    s.erase(it);
                }
            }
            s.insert({in[u], out[u]});
        }

        for(auto v : g1[u])
            dfs(v);

        ans = max(ans, (int) s.size());

        if(added)
            s.erase({in[u], out[u]});
        if(deled)
            s.insert(d);
    };
    
    dfs(1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}