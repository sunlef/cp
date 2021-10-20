#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(unsigned CASE_NUM){
    int n, k, d;
    cin >> n >> k >> d;

    using VI = vector<int>;
    using VVI= vector<vector<int>>;
    
    VI D(k), U(k), L(k), R(k);
    for(int i = 0; i < k; ++i){
        int x, y;
        cin >> x >> y;
        D[i] = y - d, U[i] = y + d;
        L[i] = x - d, R[i] = x + d;
    }

    auto work = [n, k] (VI &a, VI &b){
        VI vec;
        for(int i = 0; i < k; ++i){
            for(int j = -1; j <= 1; ++j){
                int l = a[i] + j, r = b[i] + j;
                if(l >= 1 && l <= n)
                    vec.emplace_back(l);
                if(r >= 1 && r <= n)
                    vec.emplace_back(r);
            }
        }

        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());

        for(int i = 0; i < k; ++i){
            a[i] = find(vec.begin(), vec.end(), a[i]) - vec.begin();
            b[i] = find(vec.begin(), vec.end(), b[i]) - vec.begin();
        }

        return vec.size();
    };

    int H = work(D, U), W = work(L, R);

    VVI G(H, VI(W,0));

    for(int i = 0; i < k; ++i){
        for(int h = D[i]; h <= U[i]; ++h)
            for(int w = L[i]; w <= R[i]; ++w)
                G[h][w] = 1;
    }

    VVI visted(H,VI(W,0));
    auto check = [&] (int nowh, int noww){
        return nowh >= 0 && nowh < H && noww >= 0 && noww < W &&
               G[nowh][noww] == 0 && (!visted[nowh][noww]);
    };

    function<void(int,int)> dfs = [&] (int nowh, int noww){
        visted[nowh][noww] = 1;
        if(check(nowh-1, noww)) dfs(nowh-1, noww);
        if(check(nowh+1, noww)) dfs(nowh+1, noww);
        if(check(nowh, noww-1)) dfs(nowh, noww-1);
        if(check(nowh, noww+1)) dfs(nowh, noww+1);
    };

    dfs(0,0);
    if(visted[H-1][W-1]) cout << "快乐风男" << '\n';
    else cout << "孤儿亚索" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i)
        solve(i);

    return 0;
}