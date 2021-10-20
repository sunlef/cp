#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

using LL = long long;
vector<LL> f(200001);
void solve(){
    int n, k;
    cin >> n >> k;
    vector<LL> dp(k+1);
    dp[0] = 1;

    auto ksm = [] (LL a, int b) {
        LL res = 1;
        while(b){
            if(b & 1)
                res = res * a % mod;
            b >>= 1;
            a = a * a % mod;
        }
        return res;
    };

    if(n&1)
        for(int i = 1; i <= k; ++i)
            dp[i] = ((f[n-1] * dp[i-1] % mod) + dp[i-1]) % mod;
    else
        for(int i = 1; i <= k; ++i)
            dp[i] = (((ksm(f[n], i-1) + (f[n-1] * dp[i-1] % mod)) % mod) - dp[i-1]) % mod;
    
    cout << (dp[k] < 0 ? dp[k] + mod : dp[k] )<< '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    f[0] = 1;
    for(int i = 1; i <= 200000; ++i)
        f[i] = 2 * f[i-1] % mod;

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}