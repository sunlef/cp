#include<bits/stdc++.h>
using namespace std;
using LL = long long;

bool vis[10000100];
LL primes[1000100];
LL cnt;

void init() {
    memset(primes,0,sizeof primes);
    for(int i=2;i<=10000005;i++){
        if(!vis[i]) primes[cnt++]=i;
        for(int j = 0; primes[j]<=10000005/i;j++){
            vis[primes[j]*i] = true;
            if(i % primes[j] == 0)break;
        }
    }
}
bool isprime(LL x){
    if(x <= 1) return false;
    else return !vis[x];
}


bool is_prime(long long x){
    if(x==1)
        return false;
    if(x==2||x==3)
        return true;
    if(x%6!=1&&x%6!=5)
        return false;
    int s=sqrt(x);
    for(int i=5;i<=s;i+=6)
        if(x%i==0||x%(i+2)==0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    vector<int> f(10000001, -1);
    auto sg = [&] (int n){
        if(f[n] != -1) return f[n];
        int res = 0;
        for(int i=2;i<=n;i++){
            while(n % i==0){
                ++res;
                n = n/i;
            }
            if(is_prime(n)){
                ++res;
                break;
            }
        }
        return f[n] = res;
    };    

 
    int n;
    cin >> n;
    cout << sg(n) << endl;
    return 0;
}
