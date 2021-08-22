#include<iostream>
using namespace std;
void solve(){
    int d[13], f[13];

    d[1] = 1;
    for(int i = 2; i <= 12; ++i)
        d[i] = 2*d[i-1] + 1; 

    f[1] = 1;
    for(int i = 2; i <= 12; ++i){
        f[i] = 0x3f3f3f3f;
        for(int j = 1; j < i; ++j)
            f[i] = min(f[i], 2*f[j] + d[i-j]);
    }

    for(int i = 1; i <= 12; ++i)
        cout << f[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}