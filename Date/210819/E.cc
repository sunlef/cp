#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int res = 0;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        res += x;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_;
    cin >> _TvT_;
    bool flag = false;
    for(unsigned i = 1; i <= _TvT_; ++i){
        if(flag)
            cout << '\n';
        flag = true;
        solve();
    }

    return 0;
}
