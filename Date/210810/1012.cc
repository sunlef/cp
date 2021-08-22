#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    s = " " + s;
    vector<vector<int>> pos(26, vector<int>());

    for(int i = 0; i < 26; ++i)
        pos[i].emplace_back(0);
    for(int i = 1; i < s.size(); ++i)
        pos[s[i] - 'a'].emplace_back(i);
    for(int i = 0; i < 26; ++i)
        pos[i].emplace_back(s.size());

    const int mod = 998244353;
    using LL = long long;
    auto calc = [&] (int x) {
        LL res = 0;
        LL pre = 0, d = 0;
        for(int i = 1; i < pos[x].size(); ++i){
            res = (res + (pre * (pos[x][i] - pos[x][i-1]) % mod)) % mod;
            d = (d + 2 * pos[x][i-1] + pos[x][i] - pos[x][i-1]) % mod;
            pre = (pre + d) % mod;
        }
        return res;
    };

    LL ans = 0;
    for(int i = 0; i < 26; ++i)
        ans = (ans + calc(i)) % mod;
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