#include <bits/stdc++.h>
using namespace std;

void solve(){
    int ans = 0;
    int n;
    cin >> n;
    vector<int> a(n);
    int maxx = -0x3f3f3f3f;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        maxx = max(maxx, a[i]);
    }
    for(int i = 0; (1 << i) <= maxx; ++i){
        int flag = false;
        for(int j = 0; j < n; ++j){
            if(! (a[j]>>i & 1)){
                flag = true;
                break;
            }
        }
        if(!flag)
            ans += (1 << i);
    }
    cout << ans << endl;
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
