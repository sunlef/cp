#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
using LL = long long;
const LL INF = 0x3f3f3f3f3f3f3f3fll;

LL dp[2][5002][2];
bool visted[2][5002][2];
int a[5002];

void solve(){
    int n, m;
    cin >> n >> m;

    LL sum = 0;
    for(int i = 1; i <= n; ++i) { cin >> a[i]; sum += a[i]; }
    
    for(int i = 0; i <= m; ++i){
        dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = -INF;
        visted[0][i][0] = visted[0][i][1] = visted[1][i][0] = visted[1][i][1] = false;
    }

    visted[0][0][0] = 1;
    dp[0][0][0] = 0;

    for(int i = 1; i <= n; ++i){
        int pre = (i-1) % 2;
        for(int j = 0; j <= m; ++j){
            if(visted[pre][j][0]){
                dp[i%2][j+1][1] = max(dp[pre][j][0] + a[i], dp[i%2][j+1][1]);
                dp[i%2][j][0] = max(dp[pre][j][0], dp[i%2][j][0]);
                visted[i%2][j+1][1] = visted[i%2][j][0] = 1;
            }
            if(visted[pre][j][1]){
                dp[i%2][j+1][1] = max(dp[pre][j][1] + a[i], dp[i%2][j+1][1]);
                dp[i%2][j][1] = max(dp[pre][j][1] + a[i], dp[i%2][j][1]);
                dp[i%2][j][0] = max(dp[pre][j][1], dp[i%2][j][0]);
                visted[i%2][j+1][1] = visted[i%2][j][1] = visted[i%2][j][0] = 1;
            }
        }
        for(int j = 0; j <= m; ++j){
            dp[pre][j][0] = dp[pre][j][1] = -INF;
            visted[pre][j][0] = visted[pre][j][1] = 0;
        }
    }

    LL ans = max(dp[n%2][m][0], dp[n%2][m][1]);
    
    for(int i = 0; i <= m; ++i){
        dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = INF;
        visted[0][i][0] = visted[0][i][1] = visted[1][i][0] = visted[1][i][1] = false;
    }

    visted[1][0][0] = 1;
    dp[1][0][0] = 0;

    for(int i = 2; i < n; ++i){
        int pre = (i-1) % 2;
        for(int j = 0; j <= m; ++j){
            if(visted[pre][j][0]){
                dp[i%2][j+1][1] = min(dp[pre][j][0] + a[i], dp[i%2][j+1][1]);
                dp[i%2][j][0] = min(dp[pre][j][0], dp[i%2][j][0]);
                visted[i%2][j+1][1] = visted[i%2][j][0] = 1;
            }
            if(visted[pre][j][1]){
                dp[i%2][j][1] = min(dp[pre][j][1] + a[i], dp[i%2][j][1]);
                dp[i%2][j][0] = min(dp[pre][j][1], dp[i%2][j][0]);
                visted[i%2][j][1] = visted[i%2][j][0] = 1;
            }
        }
        for(int j = 0; j <= m; ++j){
            dp[pre][j][0] = dp[pre][j][1] = INF;
            visted[pre][j][0] = visted[pre][j][1] = 0;
        }
    }

    ans = max(ans, sum - min(dp[(n-1) % 2][m][0], dp[(n-1) % 2][m][1]));
    cout << ans << '\n';
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
