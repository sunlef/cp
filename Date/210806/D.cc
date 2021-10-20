#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void solve(unsigned CASE_NUM){
    array<set<int>, 101> s;

    for(int i = 0; i < 10; ++i){
        int n;
        cin >> n;
        for(int j = 0; j < n; ++j){
            int x;
            cin >> x;
            s[x].insert(i);
        }
    }

    const int mod = 1e9 + 7;
    array<array<int, 1<<10>, 101> dp;
    dp[0][0] = 1;
    for(int i = 1; i <= 100; ++i){
        for(int j = 0; j < (1<<10); ++j){
            dp[i][j] = dp[i-1][j];
            for(auto k : s[i]){
                if((1<<k) & j)
                    dp[i][j] = (dp[i][j] + dp[i-1][j^(1<<k)]) % mod;
            }
        }
    }
    cout << dp[100][(1<<10) - 1] << '\n';
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