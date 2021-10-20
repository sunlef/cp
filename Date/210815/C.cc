#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    if (a[1] == 1){
        cout << n+1 << " ";
        for(int i = 1; i <= n; ++i)
            cout << i << " ";
        cout << '\n';
        return;
    } else if (a[n] == 0) {
        for(int i = 1; i <= n + 1; ++i)
            cout << i << " ";
        cout << endl;
        return;
    } else {
        for(int i = 1; i < n; ++i) {
            if(a[i] == 0 && a[i+1] == 1) {
                for(int j = 1; j <= i; ++j)
                    cout << j << " ";
                cout << n + 1 << " ";
                for(int j = i+1; j <= n; ++j)
                    cout << j << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
