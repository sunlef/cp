#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i].first, a[i].second = i;
    
    sort(a.begin(), a.end());
    vector<int> na(n);
    for(int i = 0; i < n; ++i)
        na[a[i].second] = i+1;

    int idx = 0;
    for(int i = 0; i < n; ++i){
        if(i == 0 || na[i-1] + 1 != na[i])
            ++idx;
    }

    cout << (idx <= k ? "Yes" : "No") << '\n';
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