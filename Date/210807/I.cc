#include <bits/stdc++.h>
using namespace std;

void solve(){
    int x, s;
    cin >> x >> s;
    using LL = long long;
    LL ans = 1;
    for(int i = 0; i < 31; ++i){
        if((x>>i) & 1 && !((s >> i) & 1))
            ans *= 0;
        if((x>>i) & 1 && ((s >> i) & 1))
            ans *= 2;
    }

    if(x == s) --ans;
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