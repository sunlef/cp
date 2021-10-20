#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    int _x = x;
    if(x % 10 == 3) return false;
    if(x % 3 == 0) return false;
    return true;
}

int a[1010];
void solve(){
    int x;
    cin >> x;
    cout << a[x] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 1;
    int x = 0;
    while(cnt <= 1000) {
        x ++ ;
        if(!check(x)) continue;
        a[cnt++] = x;
    }

    unsigned _TvT_;
    cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }




    return 0;
}
