#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=a; i<=b; i++) 
int n, maxx, minn, ave;
bool allsame() {
    return maxx == minn && maxx == ave;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        bool ok = 1;
        cin >> n >> maxx >> minn >> ave;
        if(maxx < minn) {
            ok = 0;
        }
        if(n == 1 && !allsame()) {
            ok = 0;            
        } 
        if(n == 2) {
            if((maxx + minn) != ave * 2) {
                ok = 0;
            }
        }
        else {
            int t = n - 2;
            int rest = n*ave - maxx - minn;
            if((double)(rest/t) < minn && (double)(rest/t) > maxx) {
                ok = 0;
            }
        }
        if(ok) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}