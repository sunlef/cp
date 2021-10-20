#include<bits/stdc++.h>
using namespace std;

long long pw[200001]={1},n,k,P=1000000007;

int qpow(int x, int y){
    long long re=1;
    while(y) {
        if(y&1) re=1LL*re*x%P;
        x=1LL*x*x%P, y>>=1;
    }
    return re;
}
 
int solve(int x){
    if(!x) return 1;
    if(n&1) return 1LL*(pw[n-1]+1)*solve(x-1)%P;
    return DEB(qpow(pw[n], x-1)), (qpow(pw[n], x-1)+1LL*(pw[n-1]-1)*solve(x-1))%P;
}
 
int main(){
    int T; cin>>T;
    for(int i=1; i<=200000; ++i)
        pw[i]=1LL*pw[i-1]*2%P;  
    while(T--) {
        cin>>n>>k;
        printf("%d\n", solve(k));
    }
    return 0;
}

