#include <bits/stdc++.h>
using namespace std;

void solve(){
    using LL = long long;
    LL k;
    cin >> k;
    if(k == 1) {
        cout << 1 << ' ' << 1 << '\n';
        return;
    }

    int idx = sqrt(k-1);

    LL st = idx * idx + 1, ed = (idx+1) * (idx+1);
    LL m = st + ed >> 1;

    if(k == m) {
        cout << idx + 1 << ' ' << idx + 1 << '\n';
    } else if(k < m) {
        cout << k - st + 1 << ' ' << idx + 1 << '\n';
    } else {
        cout << idx + 1 << ' ' << ed - k + 1 << '\n';
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
