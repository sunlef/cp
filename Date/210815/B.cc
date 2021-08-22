#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int idx = -1;
    for(int i = 0; i < n; ++i)
        if(s[i] != '?'){
            idx = i;
            break;
        }
    for(int i = idx - 1; i >= 0; --i){
        if(s[i] != '?')
            continue;
        if(s[i+1] == 'B')
            s[i] = 'R';
        else
            s[i] = 'B';
    }
    for(int i = idx + 1; i < n; ++i){
        if(s[i] != '?')
            continue;
        if(s[i-1] == 'B')
            s[i] = 'R';
        else
            s[i] = 'B'; 
    }
    debug(s);
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
