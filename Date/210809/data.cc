#include <bits/stdc++.h>
using namespace std;
#include<iomanip>

void solve(){
    cout << 1 << endl;
    srand(time(0) * time(0));

    double a = (rand() / double(RAND_MAX)) * 5;
    cout << fixed << setprecision(7) << a << ' ' << (rand() / double(RAND_MAX)) * 5 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned _TvT_ = 1;
    //cin >> _TvT_;
    for(unsigned i = 1; i <= _TvT_; ++i){
        solve();
    }

    return 0;
}