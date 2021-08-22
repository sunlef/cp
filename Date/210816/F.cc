#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> pre(2*n+1, 0);
    for(int i = 1; i <= 2*n; ++i) {
        if(s[i - 1] == '(')
            pre[i] = pre[i-1] + 1;
        else
            pre[i] = pre[i-1] - 1;
    }

    vector<int> pos(n+1, -1);
    vector<vector<int>> son(2*n+1, vector<int>());
    pos[0] = 0;
    for(int i = 1; i <= 2*n; ++i) {
        if(pre[i] < pre[i-1]) continue;
        pos[pre[i]] = i;
        son[pos[pre[i] - 1]].emplace_back(i);
    }

    vector<int> ybb(n+1);
    vector<int> cnt(n+1, 0);
    for(int i = 1; i <= n; ++i) {
        cin >> ybb[i];
        ++cnt[ybb[i]];
    }
    vector<pair<int, int>> byb;
    for(int i = 1; i <= n; ++i) {
        if(cnt[i])
            byb.emplace_back(make_pair(cnt[i], i));
    }
    sort(byb.begin(), byb.end(), greater<pair<int, int>>());

    vector<int> ans(2*n+1, -1);
    function<void(int)> work = [&] (int u) {
        int n = son[u].size();
        vector<int> bx;
        for(int i = 0; i < byb.size(); ++i) {
            if(byb[i].first <= 0) continue;
            byb[i].first--;
            bx.emplace_back(byb[i].second);
            if(bx.size() >= n) break;
        }

        if(bx.size() < n) return;
        for(int i = 0; i < n; ++i) {
            int v = son[u][i];
            ans[v] = bx[i];
            if(son[v].size())
                work(v);
        }
    };

    work(0);

    bool ok = true;
    vector<int> bby;
    function<void(int)> dfs = [&] (int u) {
        if(u != 0) {
            bby.emplace_back(ans[u]);
            if(ans[u] == -1) 
                ok = false;
        }
        for(auto &v : son[u]){
            dfs(v);        
        }
    };

    dfs(0);
    if(ok) {
        cout << "YES" << '\n';
        for(auto &x : bby)
            cout << x << ' ';
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
