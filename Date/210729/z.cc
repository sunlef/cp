#include <cstdio>
#include <algorithm>
long long f[55];

int main(){
    f[1]=f[2]=1;
    for(int i=3;i<=54;++i)
        f[i]=f[i-1]+f[i-2];

    long long n;
    while(scanf("%lld", &n) && n){
        int pos = std::lower_bound(f+1, f+55, n) - f;
        if(f[pos] == n) printf("Second win\n");
        else printf("First win\n");
    }
    
    return 0;
}