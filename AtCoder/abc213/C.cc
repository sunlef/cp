#include <bits/stdc++.h>
using namespace std;

void solve(){
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> h(N), w(N), nh(N), nw(N);

    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        h[i] = nh[i] = x;
        w[i] = nw[i] = y;
    }

    sort(nh.begin(), nh.end());
    sort(nw.begin(), nw.end());

    nh.erase(unique(nh.begin(), nh.end()), nh.end());
    nw.erase(unique(nw.begin(), nw.end()), nw.end());

    for(int i = 0; i < N; ++i){
        cout << 1 + lower_bound(nh.begin(), nh.end(), h[i]) - nh.begin() << ' ';
        cout << 1 + lower_bound(nw.begin(), nw.end(), w[i]) - nw.begin() << '\n';
    }
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