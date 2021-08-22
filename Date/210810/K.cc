#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    vector<long long> pre(n);
    for(int i = 0; i < n; ++i)
        pre[i] = i == 0 ? a[i] : a[i] + pre[i-1];

    long long ans = -0x3f3f3f3f;
    for(int i = m-1; i < n; ++i)
        ans = max(ans, pre[i] - (i-m >= 0 ? pre[i-m] : 0));
    cout << ans << '\n';
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