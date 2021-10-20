#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    long long k;
    cin >> n >> m >> k;
    
    vector<vector<int>> a(n+1, vector<int>(m+1));
    vector<int> row_max(n+1, -INT_MAX);
    vector<int> col_min(m+1, INT_MAX);

    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            row_max[i] = max(row_max[i], a[i][j]);
            col_min[j] = min(col_min[j], a[i][j]);
        }
    }

    int ans;
    if(k == 1) {
        ans = row_max[1];
    } else {
        if(k & 1) {
            ans = INT_MAX;
            for(int i = 1; i <= n; ++i)
                ans = min(ans, row_max[i]);
        } else {
            ans = -INT_MAX;
            for(int i = 1; i <= m; ++i) 
                ans = max(ans, col_min[i]);
        }
    }
    cout << max(ans, a[1][1]) << '\n';
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
