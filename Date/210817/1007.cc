#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<int> b(n);
    for(int i = 0; i < n; ++i)
        cin >> b[i];
    
    
    
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
