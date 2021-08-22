#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        vec[i] = make_pair(x,i+1);
    }
    sort(vec.begin(), vec.end());

    cout << vec[n-2].second << '\n';
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