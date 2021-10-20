#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans;

    int maxx = -0x3f3f3f3f;

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > maxx)
            maxx = a[i];
    }

    auto check = [&] (int la, int lb){
        if(la + lb != n || la * lb == 0)
            return false;

        vector<int> visteda(la+1, 0);
        for(int i = 0; i < la; ++i){
            if(a[i] > la) 
                return false;
            if(!visteda[a[i]])
                visteda[a[i]] = 1;
            else
                return false;
        }
        for(int i = 1; i <= la; ++i)
            if(!visteda[i])
                return false;
        
        vector<int> vistedb(lb+1, 0);
        for(int i = la; i < n; ++i){
            if(a[i] > lb)
                return false;
            if(!vistedb[a[i]])
                vistedb[a[i]] = 1;
            else
                return false;
        }
        for(int i = 1; i <= lb; ++i){
            if(!vistedb[i])
                return false;
        }
        return true;
    };

    if(check(maxx, n - maxx))
        ans.emplace_back(make_pair(maxx, n - maxx));
    if(n - maxx != maxx && check(n - maxx, maxx))
        ans.emplace_back(make_pair(n - maxx, maxx));

    cout << ans.size() << '\n';
    for(auto [i, j] : ans)
        cout << i << " " << j << '\n';
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