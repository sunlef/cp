#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> b(n), c(n);
    for(int i = 1; i < n; ++i)
        cin >> b[i];
    for(int i = 1; i < n; ++i)
        cin >> c[i];

    vector<int> ambs(n);
    for(int i = 1; i < n; ++i){
        ambs[i] = c[i] - b[i];
        if(ambs[i] < 0){
            cout << 0 << '\n';
            return;
        }
    }

    long long ans = 1;
    auto check = [&] (int x, int bi) {
        for(int i = 1; i < n; ++i){
            int ap = (ambs[i] >> bi) & 1;
            int op = (b[i] >> bi) & 1;
            if(!ap && op) x = x ^ 1;
            if(ap && op && !x) return false;
            if(ap && !op) return false;
            if(!ap && !op && x) return false;
        }
        return true;
    };

    for(int i = 0; i < 32; ++i){
        bool b1 = check(1, i);
        bool b2 = check(0, i);
        if(b1 && b2)
            ans = ans * 2;
        else if(b1 ^ b2)
            continue;
        else{
            cout << 0 << '\n';
            return;
        }
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