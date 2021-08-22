#include <bits/stdc++.h>
using namespace std;

void solve(){
    int i = 0;
    while(1){
        system("./data > data.out");
        system("./std < data >std.out");
        system("./k < data > k.out");
        if(system("diff std.out k.out")){
            cout << "WA on " << i << endl;
            break;
        }
        cout << ++i << "test cases completed" << endl;
        system("cat k.out");
        system("cat std.out");
    }
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