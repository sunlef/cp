#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> visted(301, 0);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        visted[a] = 1;
    }

    for(int i = 1; i < 301; ++i){
        if(!x) break;
        if(!visted[i]){
            visted[i] = 1;
            --x;
        }
    }    
    
    for(int i = 1; i <= 300; ++i){
        if(!visted[i]){
            cout << i-1 << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}