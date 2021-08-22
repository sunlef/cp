#include <bits/stdc++.h>
using namespace std;

int su[5000010];
int cnt;  
bool notprime[10000010]; 

void prime()  
{  
    cnt=1;  
    notprime[0] = notprime[1] = 1;//0和1不是素数  
    for(long long i=2;i<=10000010;i++)  
    {  
        if(!notprime[i])  
            su[cnt++]=i;//保存素数i  
        for(long long j=1;j<cnt&&su[j]*i<10000010;j++)  
        {  
            notprime[su[j]*i]=1;//筛掉小于等于i的素数和i的积构成的合数  
        }  
    }  
}  

int main() {
    prime();
    vector<int> f(10000001, -1);
    auto sg = [&](long long n){//快速质因数分解
        int _n = n;
        if(_n == 1) return 0;
        if(f[_n] != -1) return f[n];
        int res = 0;
        long long i=0;
        if(n==1){
            return f[_n] = 0;
        }
        while(i<n){
            if(!notprime[n]){
                ++res;
                return f[_n] = res;
            }
            for(int i = 1; i <= cnt; ++i){
                if(n % su[i] == 0){
                    n /= su[i];
                    ++res;
                    break;
                }
            } 
        }
        ++res;
        return f[_n] = res;
    };

    int T;
    scanf("%d", &T);
    while(T--){
        int n;
        scanf("%d", &n);
        int res = 0;
        while(n--){
            int x;
            scanf("%d", &x);
            res ^= sg(x);
        }
        printf("%s\n", res > 0 ? "Alice" : "Bob");
    }
    
    return 0;
}