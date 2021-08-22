#include <bits/stdc++.h>
using namespace std;

int cnt[1000001];
int a[1000001];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        ++cnt[a[i]];
    }
    
    using LL = long long;
    LL ans = 0;

    function<void(int)> work = [&] (int x){
        int sq = sqrt(x);
        for(int l = 1; l <= sq; ++l)
            if(x % l == 0){
                if(l == x/l)
                    ans += cnt[l] * cnt[l];
                else
                    ans += 2 * cnt[l] * cnt[x / l];
            }
    };

    for(int i = 1; i <= n; ++i){
        work(a[i]);
    }

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