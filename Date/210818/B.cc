#include <bits/stdc++.h>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) 
        swap(a, b);
    
    int n = b - a << 1;
    if(a > n || b > n || c > n) {
        cout << -1 << '\n';
        return;
    }

    if(c > (n >> 1)) {
        cout << c - (n >> 1) << '\n';
    } else {
        cout << c + (n >> 1) << '\n';
    }
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
