#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> g(n+1);
    for(int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        g[i] = x;
    }
    vector<int> colo(n+1, 0);
    vector<int> star;

    int c = 0;
    function<void(int)> dfs = [&] (int u){
        if(colo[u] == c){
            star.emplace_back(u);
            return;
        } else if(colo[u] == 0){
            colo[u] = c;
            dfs(g[u]);
        }
        else return;
    };

    for(int i = 1; i <= n; ++i){
        if(colo[i])
            continue;
        ++c;
        dfs(i);
    }

    vector<double> ans;
    function<void(int, int, int, long long)> dfs2 = [&] (int u, int fa, int cnt, long long sum){
        if(g[u] == fa){
            ans.emplace_back(1.0*(sum + u) / (cnt + 1));
            return;
        }
        dfs2(g[u], fa, cnt+1, sum + u);
    };

    for(auto i : star){
        dfs2(i, i, 0, 0);
    }

    if(ans.size() == 1) {
        cout << "YES" << '\n';
        return;
    }
    else {
        for(int i = 1; i < ans.size(); ++i){
            if(ans[i] != ans[i-1]){
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}