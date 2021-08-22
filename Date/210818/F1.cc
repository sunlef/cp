#include <bits/stdc++.h>
using namespace std;

void solve(){
    string n;
    int k;
    cin >> n >> k;
    int len = n.size();
    __int128_t a;
    if(k == 1) {
        if(len == 1) {
            cout << n << '\n';
        } else {
            bool flag = false;
            for(int i = 0; i < len - 1; ++i) {
                if(n[i] == n[i+1])
                    continue;
                if(n[i] > n[i+1]) {
                    for(int j = 0; j < len; ++j)
                        cout << n[0];
                    cout << '\n';
                    flag = true;
                    break;
                } else {
                    for(int j = 0; j < len; ++j)
                        cout << n[0] + 1 - '0';
                    cout << '\n';
                    flag = true;
                    break;   
                }
            }
            if(!flag) {
                for(int i = 0; i < len; ++i)
                    cout << n[0];
                cout << '\n';
            }
        }
    } else {
        if(len == 1 || len == 2) {
            cout << n << '\n';
        } else {
            bool flag1 = false;
            for(int i = 0; i < len - 1; ++i) {
                if(n[i] == n[i+1])
                    continue;
                else {
                    flag1 = true;
                    for(int j = 0; j <= i; ++j)
                        cout << n[0];

                    bool flag = true;
                    for(int j = i+1; j < len - 1; ++j) {
                        if(n[j] == n[j+1])
                            continue;
                        if(n[j] > n[j+1])
                            break;
                        else {
                            flag = false;
                            break;
                        }
                    }

                    if(flag) {
                        for(int j = i+1; j < len; ++j)
                            cout << n[i+1];
                        cout << '\n';
                    } else {

                        cout << n[i+1] + 1 - '0';
                        if(n[i+1] + 1 - '0' < n[0] - '0') {
                            for(int j = i+2; j < len; ++j)
                               cout << n[0] - '0';
                        } else {
                            for(int j = i+2; j < len; ++j)
                               cout << n[i+1] - '0' + 1; 
                        }
                        cout << '\n';
                    }
                    return;
                }
            }
            if(!flag1) {
                for(int i = 0; i < len; ++i)
                    cout << n[0];
                cout << '\n';
            }
        }
    }
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
