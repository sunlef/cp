#include <bits/stdc++.h>
using namespace std;

void solve(){
    const double pi = acos(-1.0);
    double a, b;
    cin >> a >> b;
    double A = min(a, b), B = sqrt(a*a + b*b);

    double cpA = 2 / A, cpB = 3 / B;
    if(cpA > cpB){
        cout << (int) (pi / A) * 2 + 4 << '\n';
    } else {
        cout << 4 + 3 * (int) (pi / B) + 2 * (int) ((pi - (int) (pi / B) * B ) / A) << '\n';
    }
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