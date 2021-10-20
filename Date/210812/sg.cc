#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    cout << log(n) / log(log(n)) << endl;
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