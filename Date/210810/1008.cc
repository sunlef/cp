#include <bits/stdc++.h>
using namespace std;

void solve(){
    int nowx, nowy, d;
    cin >> nowx >> nowy >> d;

    auto haha = [] (int nx, int ny, int tx, int ty){
        if(tx > nx && ty > ny) return 1;
        else if(tx < nx && ty > ny) return 2;
        else if(tx < nx && ty < ny) return 3;
        else return 4;
    };
    auto F = [] (int tt){
        for(int i = 0; i < tt; ++i)
            cout << 'f';
    };
    auto C = [] () { cout << 'c'; };
    auto U = [] () { cout << 'u'; };
    int x, y;
    auto SET = [&](int c) { nowx = x; nowy = y; d = c; };

    int n;
    cin >> n;
    while(n--){
        cin >> x >> y;
        int t = haha(nowx, nowy, x, y);
        int dx = abs(x - nowx);
        int dy = abs(y - nowy);

        if(d == 0){
            if(t == 1){
                F(dy);C();F(dx);
                SET(1);
            } else if(t == 2){
                F(dy);U();F(dx);
                SET(3);
            } else if(t == 3){
                U();F(dx);U();F(dy);
                SET(2);
            } else{
                C();F(dx);C();F(dy);
                SET(2);
            }
        } else if(d == 1){
            if(t == 1){
                F(dx);U();F(dy);
                SET(0);
            } else if(t == 2){
                U();F(dy);U();F(dx);
                SET(3);
            } else if(t == 3){
                C();F(dy);C();F(dx);
                SET(3);
            } else{
                F(dx);C();F(dy);
                SET(2);
            }
        } else if(d == 2){
            if(t == 1){
                U();F(dx);U();F(dy);
                SET(0);
            } else if(t == 2){
                C();F(dx);C();F(dy);
                SET(0);
            } else if(t == 3){
                F(dy);C();F(dx);
                SET(3);
            } else{
                F(dy);U();F(dx);
                SET(1);
            }

        } else{
            if(t == 1){
                C();F(dy);C();F(dx);
                SET(1);
            } else if(t == 2){
                F(dx);C();F(dy);
                SET(0);
            } else if(t == 3){
                F(dx);U();F(dy);
                SET(2);
            } else{
                U();F(dy);U();F(dx);
                SET(1);
            }
        }
    }
    cout << '\n';
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