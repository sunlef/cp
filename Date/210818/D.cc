#include <bits/stdc++.h>
using namespace std;

string s[71];
int len;

int calc(string x, int t, int idx) {
    int cnt = 0;
    string res;

    for(int i = 0; i < len; ++i) {
        if((t >> i) & 1) res.push_back(x[i]);
        else ++cnt;
    }

    int lenlen = res.size();

    if(s[idx].substr(0, lenlen) == res) {
        return s[idx].size() - lenlen + cnt;
    } else {
        return INT_MAX;
    }

}

void solve(){
    int ans = INT_MAX;
    string n;
    cin >> n;
    len = n.size();

    for(int i = 1; i <= 70; ++i) {
        for(int j = 0; j < (1 << len); ++j)
            ans = min(ans, calc(n, j, i));
    }
    
    cout << ans << ' '; 

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    __int128_t a = 1;
    for(int i = 1; i <= 70; ++i) {
        string res;
        __int128_t _a = a;
        while(_a) {
            res.push_back(_a % 10 + '0');
            _a /= 10;
        }
        reverse(res.begin(), res.end());
        s[i] = res;
        a = a * 2;
    }

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}
