#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define rep(i,a,b) for(int i=a; i<=b; i++) 
const int PI = 314159265;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--) {
        string a,b;
        cin>>a>>b;
        for(int i=0;i<a.length();i++) {
            if(a[i]=='.')a.erase(a.begin()+i);
        }
        for(int i=0;i<b.length();i++) {
            if(b[i]=='.')b.erase(b.begin()+i);
        }
        a.resize(9,'0');
        b.resize(9,'0');
        int aa = stoi(a);
        int bb = stoi(b);
        cout<<aa<<" "<<bb<<endl;
        cout<<2*(LL)(PI/min(aa,bb))+4<<endl;
    }
    return 0;
}